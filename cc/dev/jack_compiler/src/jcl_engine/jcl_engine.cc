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
    outfile << indent_lvl() << "<keyword> class </keyword>\n";

    // Handle className.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error("JCLEngine: 'class' must be followed by className");

    ttk = tkz.token_type();
    if (ttk != TokenType::ID)
        throw logic_error("JCLEngine: 'class' must be followed by className");
    outfile << indent_lvl() << "<identifier> " << tkz.id() << " </identifier>\n";

    // Handle class '{'.
    if (tkz.has_more_tokens())
        tkz.advance();
    else
        throw logic_error("JCLEngine: 'className' must be followed by '{'");

    ttk = tkz.token_type();
    if (ttk != TokenType::SYMB)
        throw logic_error("JCLEngine: 'className' must be followed by '{'");
    outfile << indent_lvl() << "<symbol> " << tkz.symbol() << " </symbol>\n";

    // Handle classVarDec*.

    indent -= indent_amt;
    outfile << indent_lvl() << "</class>";
    outfile.close();
}

void JCLEngine::compile_cls_var_dec() { }

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
