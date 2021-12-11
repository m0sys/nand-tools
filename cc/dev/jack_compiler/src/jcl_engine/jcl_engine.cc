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

    // Indent.
    outfile << indent_lvl() << "<parameterList>\n";
    indent += indent_amt;

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

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</parameterList>\n";
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

    // Assume do subroutineCall === do expr.
    compile_expr(false);

    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</doStatement>\n";
}

void JCLEngine::compile_ret()
{
    // Indent.
    outfile << indent_lvl() << "<returnStatement>\n";
    indent += indent_amt;

    // Handle return;
    write_xml_kwd("return");
    tkz.advance();

    // Handle expr?
    auto ttk = tkz.token_type();
    if (ttk == TokenType::ID || ttk == TokenType::KWD) {
        compile_expr();
    }

    LOG("write_semicolon_or_throw: curtk = " << tkz.__debug_current_token__());
    write_semicolon_or_throw();

    // Unindent.
    indent -= indent_amt;
    outfile << indent_lvl() << "</returnStatement>\n";
}

void JCLEngine::compile_expr(bool to_indent)
{
    // Handle expr
    //
    // expr: term (op term)*.
    //
    // op: '+'|'-'|'*'|'/'|'&'|'|'|'<'|'>'|'='

    // Indent.
    if (to_indent) {
        outfile << indent_lvl() << "<expression>\n";
        indent += indent_amt;
    }

    compile_term(to_indent);

    // Handle (op term)*.
    auto ttk = tkz.token_type();
    constexpr char ops[10] = { '+', '-', '*', '/', '&', '|', '<', '>', '=', '\0' };
    while (ttk == TokenType::SYMB && strchr(ops, tkz.symbol())) {
        write_xml_symb(tkz.symbol());
        tkz.advance();
        compile_term();
        ttk = tkz.token_type();
    }
    // Unindent.
    if (to_indent) {
        indent -= indent_amt;
        outfile << indent_lvl() << "</expression>\n";
    }
}

void JCLEngine::compile_term(bool to_indent)
{
    using std::logic_error;
    // Indent.
    if (to_indent) {
        outfile << indent_lvl() << "<term>\n";
        indent += indent_amt;
    }

    // Handle term.
    //
    // term: intConst|strConst|kwdConst|varName|varName'['expr']|
    //       '('expr')'|(unaryOp term)|subroutineCall
    //
    // subroutineCall: subroutineName'('exprLst')'|(clsName|varName)'.'
    //                 subroutineName'('exprLst')'

    auto ttk = tkz.token_type();

    // Handle '('expr')'|(unaryOp term)
    if (ttk == TokenType::SYMB) {
        if (tkz.symbol() == '(') {
            write_left_paren_or_throw();
            compile_expr();
            write_right_paren_or_throw();

        } else if (tkz.symbol() == '-' || tkz.symbol() == '~') {
            write_xml_symb(tkz.symbol());
            tkz.advance();
            compile_term();
        }
    }

    // Handle intConst.
    else if (ttk == TokenType::INT_CONST) {
        write_xml_ic(tkz.int_val());
        tkz.advance();

    }

    // Handle strConst.
    else if (ttk == TokenType::STR_CONST) {
        write_xml_sc(tkz.str_val());
        tkz.advance();
    }

    // Handle kwdConst: 'true'|'false'|'null'|'this'
    else if (ttk == TokenType::KWD) {
        auto kwd = tkz.keyword();
        switch (kwd) {
        case Kwd::THIS:
            write_xml_kwd("this");
            break;
        case Kwd::T:
            write_xml_kwd("true");
            break;
        case Kwd::F:
            write_xml_kwd("false");
            break;
        case Kwd::N:
            write_xml_kwd("null");
            break;
        default:
            throw std::logic_error(THROW_MSG("JCLEngine: must be 'this'"));
        }
        tkz.advance();
    }

    // Handle varName|varName'['expr']'|subroutineCall
    else if (ttk == TokenType::ID) {
        // Must resolve to var, an arr elem, or subroutine call.
        write_xml_id(tkz.id());
        tkz.advance();

        ttk = tkz.token_type();
        if (ttk == TokenType::SYMB) {

            // Handle subroutine call.
            if (tkz.symbol() == '.' || tkz.symbol() == '(') {
                // Handle (clsName|varName)'.'subroutineName'('exprLst')'
                if (tkz.symbol() == '.') {

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
                LOG("compile_expr_lst: curtk = " << tkz.__debug_current_token__());
                compile_expr_lst();
                LOG("write_right_paren_or_throw: curtk = " << tkz.__debug_current_token__());
                write_right_paren_or_throw();
                LOG("DONE RIGHT PAREN ");
            }
            // Handle arr elem '['expr']'
            else if (tkz.symbol() == '[') {
                write_left_bra_or_throw();
                compile_expr();
                write_right_bra_or_throw();
            }
        }
    } else {
        throw logic_error(THROW_MSG("JCLEngine: invalid term"));
    }

    // Unindent.
    if (to_indent) {
        indent -= indent_amt;
        outfile << indent_lvl() << "</term>\n";
    }
}

int JCLEngine::compile_expr_lst()
{

    // Indent.
    outfile << indent_lvl() << "<expressionList>\n";
    indent += indent_amt;

    // Handle (expr (',' expr)*)?
    auto ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == ')') {
        // Unindent.
        indent -= indent_amt;
        outfile << indent_lvl() << "</expressionList>\n";
        return -1;
    } else {

        LOG("compile_expr: curtk" << tkz.__debug_current_token__());
        compile_expr();

        ttk = tkz.token_type();
        while (ttk == TokenType::SYMB && tkz.symbol() == ',') {
            write_xml_symb(tkz.symbol());
            tkz.advance();
            LOG("while -> compile_expr: curtk" << tkz.__debug_current_token__());
            compile_expr();
            ttk = tkz.token_type();
        }
        // Unindent.
        indent -= indent_amt;
        outfile << indent_lvl() << "</expressionList>\n";
        return -1;
    }
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
    using std::string;
    auto ssymb = tkz.symbol();
    string symb_str = "";
    if (ssymb == '<')
        symb_str = "&lt;";
    else if (ssymb == '&')
        symb_str = "&amp;";
    else if (ssymb == '>')
        symb_str = "&gt;";
    else {
        symb_str = string(1, symb);
    }
    outfile << indent_lvl() << "<symbol> " << symb_str << " </symbol>\n";
}

void JCLEngine::write_xml_ic(int int_val)
{
    //
    outfile << indent_lvl() << "<integerConstant> " << std::to_string(int_val) << " </integerConstant>\n";
}

void JCLEngine::write_xml_sc(std::string str_val)
{
    //
    outfile << indent_lvl() << "<stringConstant> " << str_val << " </stringConstant>\n";
}

void JCLEngine::write_xml_id(std::string id)
{
    //
    outfile << indent_lvl() << "<identifier> " << id << " </identifier>\n";
}
