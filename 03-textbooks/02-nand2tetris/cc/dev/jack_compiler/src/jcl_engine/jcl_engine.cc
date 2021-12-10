#include "jcl_engine.h"
#include <stdexcept>
#include <string>

JCLEngine::JCLEngine(std::string jack_fname, std::string out_fname)
    : tkz { Tokenizer(jack_fname) }
    , outfile { std::ofstream(out_fname) }
{
}

void JCLEngine::compile_class()
{
    using std::logic_error;
    using std::string;

    auto ttk = tkz.token_type();

    // Handle class.
    if (ttk != TokenType::KWD && tkz.keyword() != Kwd::CLS) {
        throw logic_error("JCLEngine: .jack file must begin with 'class'");
    }

    outfile << indent_lvl() << "<class>\n";
    indent += indent_amt;
    write_xml_kwd("class");

    // Handle className.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error("JCLEngine: 'class' must be followed by className");

    ttk = tkz.token_type();
    if (ttk != TokenType::ID)
        throw logic_error("JCLEngine: 'class' must be followed by className");
    write_xml_id(tkz.id());

    // Handle class '{'.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error("JCLEngine: 'className' must be followed by '{'");

    ttk = tkz.token_type();
    if (ttk != TokenType::SYMB && tkz.symbol() != '{')
        throw logic_error("JCLEngine: 'className' must be followed by '{'");
    write_xml_symb(tkz.symbol());

    // Handle class content.
    while (tkz.has_more_tokens()) {
        ttk = tkz.token_type();
        if (ttk != TokenType::KWD || (ttk == TokenType::SYMB && tkz.symbol() != '}'))
            throw logic_error("JCLEngine: 'classVarDec*' || 'subroutineDec*' must begin with keyword");

        if (ttk == TokenType::SYMB && tkz.symbol() == '}') {
            write_xml_symb('}');
            tkz.advance();
            continue;
        }

        auto kwd = tkz.keyword();

        // Handle classVarDec*.
        if (kwd == Kwd::FIELD || kwd == Kwd::STATIC)
            compile_var_dec();
        // Handle subroutineDec*.
        else if (kwd == Kwd::CONSTR || kwd == Kwd::FUNC || kwd == Kwd::METH)
            compile_subroutine();

        // TODO: remove after impls.
        tkz.advance();
    }

    indent -= indent_amt;
    outfile << indent_lvl() << "</class>";
    outfile.close();
}

void JCLEngine::compile_cls_var_dec()
{
    using std::logic_error;

    // Handle ('static'|'field')
    auto kwd = tkz.keyword();
    if (kwd == Kwd::FIELD)
        write_xml_kwd("field");
    else
        write_xml_kwd("static");
    tkz.advance();

    // Handle type.
    auto ttk = tkz.token_type();

    // type: 'int'|'char'|'boolean'|className
    if (ttk == TokenType::KWD) {
        kwd = tkz.keyword();
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
            throw logic_error("JCLEngine: type: 'int'|'char'|'boolean'");
        }

    } else if (ttk == TokenType::ID)
        write_xml_id(tkz.id());

    else {
        throw logic_error("JCLEngine: type: 'int'|'char'|'boolean'|className");
    }
    tkz.advance();

    // Handle varName
    ttk = tkz.token_type();
    if (ttk == TokenType::ID)
        write_xml_id(tkz.id());
    tkz.advance();

    // Handle (',' varName)*
    ttk = tkz.token_type();
    if (ttk == TokenType::SYMB && tkz.symbol() == ',') {
        while (tkz.has_more_tokens() && ttk == TokenType::SYMB && tkz.symbol() == ',') {
            write_xml_symb(tkz.symbol());
            tkz.advance();
            ttk = tkz.token_type();
            if (ttk == TokenType::ID)
                write_xml_id(tkz.id());
            else {
                throw logic_error("JCLEngine: (',' varName)");
            }
            if (tkz.has_more_tokens()) {
                tkz.advance();
                ttk = tkz.token_type();
            } else {
                throw logic_error("JCLEngine: (',' varName) end");
            }
        }
    }

    // Handle ';'
    if (ttk == TokenType::SYMB && tkz.symbol() == ';')
        write_xml_symb(';');
    else {
        throw logic_error("JCLEngine: ';'");
    }
    tkz.advance();
}

void JCLEngine::compile_subroutine() { }

void JCLEngine::compile_subroutine_body() { }

void JCLEngine::compile_var_dec() { }

void JCLEngine::compile_stmts() { }

void JCLEngine::compile_let() { }

void JCLEngine::compile_if() { }

void JCLEngine::compile_while() { }

void JCLEngine::compile_do() { }

void JCLEngine::compile_ret() { }

void JCLEngine::compile_expr() { }

void JCLEngine::compile_term() { }

int JCLEngine::compile_expr_lst() { return -1; }

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
