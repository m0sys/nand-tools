#include "jcl_engine.h"
#include "../common/log.h"
#include <stdexcept>
#include <string>

JCLEngine::JCLEngine(std::string jack_fname, std::string out_fname)
    : tkz { Tokenizer(jack_fname) }
    , outfile { std::ofstream(out_fname) }
{
    LOG("Current JACK file: " << jack_fname);
}

void JCLEngine::compile_class()
{
    using std::logic_error;
    using std::string;

    auto ttk = tkz.token_type();

    // Handle class.
    if (ttk != TokenType::KWD && tkz.keyword() != Kwd::CLS) {
        throw logic_error(THROW_MSG("JCLEngine: .jack file must begin with 'class'"));
    }

    outfile << indent_lvl() << "<class>\n";
    indent += indent_amt;
    write_xml_kwd("class");

    // Handle className.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error(THROW_MSG("JCLEngine: 'class' must be followed by className"));

    ttk = tkz.token_type();
    if (ttk != TokenType::ID)
        throw logic_error(THROW_MSG("JCLEngine: 'class' must be followed by className"));
    write_xml_id(tkz.id());

    // Handle class '{'.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error(THROW_MSG("JCLEngine: 'className' must be followed by '{'"));

    ttk = tkz.token_type();
    if (ttk != TokenType::SYMB && tkz.symbol() != '{')
        throw logic_error(THROW_MSG("JCLEngine: 'className' must be followed by '{'"));
    write_xml_symb(tkz.symbol());
    tkz.advance();

    // Handle class content.
    while (tkz.has_more_tokens()) {
        LOG("LOOPING");
        ttk = tkz.token_type();

        if (ttk == TokenType::SYMB) {
            if (tkz.symbol() == '}') {
                write_xml_symb(tkz.symbol());
                tkz.advance();
                continue;
            } else {
                LOG("symbol: " << tkz.symbol());
                throw logic_error(THROW_MSG("JCLEngine: must be '}'"));
            }
        }

        if (ttk != TokenType::KWD) {
            LOG("class content: curtk = " << tkz.__debug_current_token__());
            throw logic_error(THROW_MSG("JCLEngine: 'classVarDec*' || 'subroutineDec*' must begin with keyword"));
        }

        auto kwd = tkz.keyword();

        // Handle classVarDec*.
        if (kwd == Kwd::FIELD || kwd == Kwd::STATIC) {
            LOG("var_dec*");
            compile_cls_var_dec();
        }
        // Handle subroutineDec*.
        else if (kwd == Kwd::CONSTR || kwd == Kwd::FUNC || kwd == Kwd::METH) {
            LOG("subroutine_dec");
            compile_subroutine();
        }

        // TODO: remove after impls.
        // tkz.advance();
    }

    indent -= indent_amt;
    outfile << indent_lvl() << "</class>";
    outfile.close();
}

void JCLEngine::compile_cls_var_dec()
{
    using std::logic_error;
    // Indent.
    outfile << indent_lvl() << "<classVarDec>\n";
    indent += indent_amt;

    // Handle ('static'|'field')
    auto kwd = tkz.keyword();
    if (kwd == Kwd::FIELD)
        write_xml_kwd("field");
    else
        write_xml_kwd("static");
    tkz.advance();

    // Handle type.
    write_type_or_throw();

    // Handle varName
    write_vname_or_throw();

    // Handle (',' varName)*
    write_star_vdec_or_throw();

    // Handle ';'
    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</classVarDec>\n";
}

void JCLEngine::write_type_or_throw()
{
    using std::logic_error;

    auto ttk = tkz.token_type();

    // type: 'int'|'char'|'boolean'|className
    if (ttk == TokenType::KWD) {
        auto kwd = tkz.keyword();
        switch (kwd) {
        case Kwd::INT:
            write_xml_kwd("int");
            break;
        case Kwd::CHAR:
            write_xml_kwd("char");
            break;
        case Kwd::BOOL:
            write_xml_kwd("boolean");
            break;
        default:
            throw logic_error(THROW_MSG("JCLEngine: type: 'int'|'char'|'boolean'"));
        }

    } else if (ttk == TokenType::ID)
        write_xml_id(tkz.id());

    else {
        throw logic_error(THROW_MSG("JCLEngine: type: 'int'|'char'|'boolean'|className"));
    }
    tkz.advance();
}

void JCLEngine::write_vname_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::ID)
        write_xml_id(tkz.id());
    else
        throw std::logic_error("JCLEngine: must be varName");
    tkz.advance();
}

void JCLEngine::write_star_vdec_or_throw()
{
    using std::logic_error;

    auto ttk = tkz.token_type();
    while (tkz.has_more_tokens() && ttk == TokenType::SYMB && tkz.symbol() == ',') {
        write_xml_symb(tkz.symbol());
        tkz.advance();

        ttk = tkz.token_type();
        if (ttk == TokenType::ID) {
            write_xml_id(tkz.id());
            tkz.advance();
        } else {
            throw logic_error(THROW_MSG("JCLEngine: (',' varName)"));
        }

        ttk = tkz.token_type();
    }
}

void JCLEngine::write_semicolon_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == ';')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: ';'"));
    }
    tkz.advance();
}

void JCLEngine::compile_subroutine()
{
    using std::logic_error;
    // Indent.
    outfile << indent_lvl() << "<subroutineDec>\n";
    indent += indent_amt;

    // Handle ('constructor'|'function'|'method')
    auto kwd = tkz.keyword();
    switch (kwd) {
    case Kwd::CONSTR:
        write_xml_kwd("constructor");
        break;
    case Kwd::FUNC:
        write_xml_kwd("function");
        break;
    case Kwd::METH:
        write_xml_kwd("method");
        break;
    default:
        throw logic_error(THROW_MSG("JCLEngine: must be ('constructor'|'function'|'method')"));
    }
    tkz.advance();

    // Handle ('void'|type)
    auto ttk = tkz.token_type();
    if (ttk != TokenType::KWD && ttk != TokenType::ID)
        throw logic_error(THROW_MSG("JCLEngine: must be  ('void'|type)"));

    try {
        write_type_or_throw();
    } catch (const std::exception& e) {
        kwd = tkz.keyword();
        if (kwd == Kwd::VOID)
            write_xml_kwd("void");
        else
            throw logic_error(THROW_MSG("JCLEngine: type: 'void'|'int'|'char'|'boolean'"));
        tkz.advance();
    }

    // Handle subroutineName.
    ttk = tkz.token_type();
    if (ttk != TokenType::ID)
        throw logic_error(THROW_MSG("JCLEngine: must be  subroutineName"));
    write_xml_id(tkz.id());
    tkz.advance();

    // Handle '('.
    write_left_paren_or_throw();

    // Handle parameterList: ((type varName) (',' type varName)*)?
    ttk = tkz.token_type();
    if (ttk == TokenType::KWD || ttk == TokenType::ID) {
        // Handle (type varName).
        write_type_or_throw();
        write_vname_or_throw();

        // Handle (',' type varName)*.
        ttk = tkz.token_type();
        if (ttk == TokenType::SYMB && tkz.symbol() == ',') {
            while (tkz.has_more_tokens() && ttk == TokenType::SYMB && tkz.symbol() == ',') {
                write_xml_symb(tkz.symbol());
                tkz.advance();

                // Handle type.
                write_type_or_throw();

                // Handle varName.
                write_vname_or_throw();
            }
        }
    }

    // Handle ')'.
    write_right_paren_or_throw();

    LOG("compile_subroutine_body");
    compile_subroutine_body();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</subroutineDec>\n";
}

void JCLEngine::write_left_paren_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '(')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be '('"));
    }
    tkz.advance();
}

void JCLEngine::write_right_paren_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == ')')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be ')'"));
    }
    tkz.advance();
}
void JCLEngine::compile_subroutine_body()
{
    using std::logic_error;
    // Indent.
    outfile << indent_lvl() << "<subroutineBody>\n";
    indent += indent_amt;

    // Handle '{'.
    write_left_curl_or_throw();

    // Handle varDec*: 'var' type varName (',' varName)*';'
    // FIXME: *
    auto ttk = tkz.token_type();
    while (ttk == TokenType::KWD && tkz.keyword() == Kwd::VAR) {
        compile_var_dec();
        ttk = tkz.token_type();
    }

    LOG("compile_stmts");
    compile_stmts();
    write_right_curl_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</subroutineBody>\n";
}

void JCLEngine::write_left_curl_or_throw()
{
    auto ttk = tkz.token_type();
    LOG("in left curl: curtk = " << tkz.__debug_current_token__());
    if (ttk == TokenType::SYMB && tkz.symbol() == '{')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be '{'"));
    }
    tkz.advance();
}

void JCLEngine::write_right_curl_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '}')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be '}'"));
    }
    tkz.advance();
}

void JCLEngine::compile_var_dec()
{
    // Indent.
    outfile << indent_lvl() << "<varDec>\n";
    indent += indent_amt;

    write_xml_kwd("var");
    tkz.advance();
    write_type_or_throw();
    write_vname_or_throw();
    write_star_vdec_or_throw();
    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</varDec>\n";
}

void JCLEngine::compile_stmts()
{
    // Indent.
    outfile << indent_lvl() << "<statements>\n";
    indent += indent_amt;

    // Handle statement*
    auto ttk = tkz.token_type();
    if (ttk == TokenType::KWD) {
        // Handle statement: letStmt|ifStmt|whileStmt|doStmt|returnStmt
        auto kwd = tkz.keyword();
        bool done = false;
        do {
            switch (kwd) {
            case Kwd::LET:
                LOG("compile_let");
                compile_let();
                break;
            case Kwd::IF:
                LOG("compile_if");
                compile_if();
                break;
            case Kwd::WHILE:
                LOG("compile_while");
                compile_while();
                break;
            case Kwd::DO:
                LOG("compile_do");
                compile_do();
                break;
            case Kwd::RET:
                LOG("compile_ret");
                compile_ret();
                break;
            default:
                LOG("done");
                done = true;
                break;
            }
            if (!done && tkz.token_type() == TokenType::KWD) {
                ttk = tkz.token_type();
                kwd = tkz.keyword();
            }
        } while (!done && tkz.has_more_tokens() && tkz.token_type() == TokenType::KWD);
    }

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</statements>\n";
}

void JCLEngine::compile_let()
{
    // Indent.
    outfile << indent_lvl() << "<letStatement>\n";
    indent += indent_amt;

    // Handle letStmt: 'let' varName ('['expr']')? '=' expr;
    write_xml_kwd("let");
    tkz.advance();
    LOG("let id: " << tkz.id());
    write_vname_or_throw();

    // Handle ('['expr']')?
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '[') {
        LOG("HERE!");
        write_left_bra_or_throw();
        compile_expr();
        write_right_bra_or_throw();
    }

    // Handle '='.
    ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '=') {
        write_xml_symb(tkz.symbol());
        tkz.advance();
    } else {

        LOG("curtk: " << tkz.__debug_current_token__());
        throw std::logic_error(THROW_MSG("JCLEngine: must be '='"));
    }

    LOG("compile_expr");
    compile_expr();
    LOG("write_semicolon_or_throw");
    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</letStatement>\n";
}

void JCLEngine::write_left_bra_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '[')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be '['"));
    }
    tkz.advance();
}

void JCLEngine::write_right_bra_or_throw()
{
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == ']')
        write_xml_symb(tkz.symbol());
    else {
        throw std::logic_error(THROW_MSG("JCLEngine: must be ']'"));
    }
    tkz.advance();
}

void JCLEngine::compile_if()
{
    // Indent.
    outfile << indent_lvl() << "<ifStatement>\n";
    indent += indent_amt;

    // Handle ifStmt: if '('expr')' '{'stmts'}' ('else' '{'stmts'}')?
    write_xml_kwd("if");
    tkz.advance();

    write_left_paren_or_throw();
    compile_expr();
    write_right_paren_or_throw();

    LOG("write_left_curl_or_throw: curtk = " << tkz.__debug_current_token__() << "size: " << tkz.__debug_current_token__().size());
    write_left_curl_or_throw();
    compile_stmts();
    write_right_curl_or_throw();

    // Handle 'else'.
    auto ttk = tkz.token_type();
    if (ttk == TokenType::KWD && tkz.keyword() == Kwd::ELSE) {
        write_xml_kwd("else");
        tkz.advance();
        write_left_curl_or_throw();
        compile_stmts();
        write_right_curl_or_throw();
    }

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</ifStatement>\n";
}

void JCLEngine::compile_while()
{
    // Indent.
    outfile << indent_lvl() << "<whileStatement>\n";
    indent += indent_amt;

    // Handle whileStmt: 'while' '('expr')' '{'stmts'}'
    write_xml_kwd("while");
    tkz.advance();

    write_left_paren_or_throw();
    compile_expr();
    write_right_paren_or_throw();

    write_left_curl_or_throw();
    compile_stmts();
    write_right_curl_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</whileStatement>\n";
}

void JCLEngine::compile_do()
{
    using std::logic_error;
    // Indent.
    outfile << indent_lvl() << "<doStatement>\n";
    indent += indent_amt;

    // Handle doStmt: 'do' subroutineCall ';'
    LOG("write_xml_kwd: curtk = " << tkz.__debug_current_token__());
    write_xml_kwd("do");
    tkz.advance();

    // Handle subroutineCall: subroutineName'('exprLst')'|(clsName|varName)'.'
    // subroutineName'('exprLst')'
    auto ttk = tkz.token_type();
    // Handle subroutineName|(clsName|varName).
    if (ttk == TokenType::ID) {
        LOG("write_xml_id: curtk = " << tkz.__debug_current_token__());
        write_xml_id(tkz.id());
        tkz.advance();
    } else {
        throw logic_error(THROW_MSG("JCLEngine: must be subroutineName|(clsName|varName)"));
    }

    ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == '.') {
        // Handle (clsName|varName)'.'subroutineName'('exprLst')'
        LOG("write_xml_symb: curtk = " << tkz.__debug_current_token__());
        write_xml_symb(tkz.symbol());
        tkz.advance();

        ttk = tkz.token_type();
        if (ttk == TokenType::ID) {
            LOG("write_xml_id: curtk = " << tkz.__debug_current_token__());
            write_xml_id(tkz.id());
            tkz.advance();
        } else {
            throw logic_error(THROW_MSG("JCLEngine: must be subroutineName"));
        }
    }

    // Handle ('exprLst')'
    LOG("write_left_paren_or_throw: curtk = " << tkz.__debug_current_token__());
    write_left_paren_or_throw();
    LOG("compile_expr_lst");
    compile_expr_lst();
    LOG("write_right_paren_or_throw: curtk = " << tkz.__debug_current_token__());
    write_right_paren_or_throw();

    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</doStatement>\n";
}

void JCLEngine::compile_ret()
{
    // Indent.
    outfile << indent_lvl() << "<retStatement>\n";
    indent += indent_amt;

    // Handle return;
    write_xml_kwd("return");
    tkz.advance();

    // TODO: assume possible id only.
    if (tkz.token_type() == TokenType::ID) {
        write_xml_id(tkz.id());
        tkz.advance();
    }

    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</retStatement>\n";
}

void JCLEngine::compile_expr()
{
    // TODO: assume that its and id until we add expressions.
    auto ttk = tkz.token_type();
    if (ttk == TokenType::ID) {
        write_xml_id(tkz.id());
        tkz.advance();
    } else if (ttk == TokenType::KWD) {
        auto kwd = tkz.keyword();
        if (kwd == Kwd::THIS)
            write_xml_kwd("this");
        else
            throw std::logic_error(THROW_MSG("JCLEngine: must be 'this'"));
        tkz.advance();
    }
}

void JCLEngine::compile_term() { }

int JCLEngine::compile_expr_lst()
{
    // TODO: assume that only id possible.
    // Handle (expr (',' expr)*)?
    auto ttk = tkz.token_type();
    if (ttk == TokenType::ID || ttk == TokenType::KWD) {
        compile_expr();
    }

    ttk = tkz.token_type();
    while (ttk == TokenType::SYMB && tkz.symbol() == ',') {
        write_xml_symb(tkz.symbol());
        tkz.advance();
        compile_expr();
        ttk = tkz.token_type();
    }

    return -1;
}

std::string JCLEngine::indent_lvl()
{
    std::string lvl = "";
    for (int i = 0; i < indent; i++)
        lvl += " ";
    return lvl;
}

// XML methods.
void JCLEngine::write_xml_kwd(std::string kwd)
{
    //
    outfile << indent_lvl() << "<keyword> " << kwd << " </keyword>\n";
}

void JCLEngine::write_xml_symb(char symb)
{
    //
    outfile << indent_lvl() << "<symbol> " << std::string(1, symb) << " </symbol>\n";
}

void JCLEngine::write_xml_ic(int int_val)
{
    //
    outfile << indent_lvl() << "<intConst> " << std::to_string(int_val) << " </intConst>\n";
}

void JCLEngine::write_xml_sc(std::string str_val)
{
    //
    outfile << indent_lvl() << "<stringConst> " << str_val << " </stringConst>\n";
}

void JCLEngine::write_xml_id(std::string id)
{
    //
    outfile << indent_lvl() << "<identifier> " << id << " </identifier>\n";
}
