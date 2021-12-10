// JCLEngine (Jack Compilation Engine) is the backbone for Jack compilation.
// Date: 2021/12/08
// Author: m0sys

#pragma once
#include "../tokenizer/tokenizer.h"
#include <fstream>
#include <string>

class JCLEngine {
public:
    JCLEngine(std::string jack_fname, std::string out_fname);

    // Compiles a complete class.
    void compile_class();

private:
    // Compiles a static var declaration, or a field declaration.
    void compile_cls_var_dec();

    // Compiles a complete method, function, or constructor.
    void compile_subroutine();

    void compile_subroutine_body();

    // Compiles var declaration.
    void compile_var_dec();

    /*
     * Compiles a sequence of statements.
     *
     * Does not handle enclosing curly bracket tokens '{' and  '}'
     */
    void compile_stmts();

    // Compiles let statement.
    void compile_let();

    // Compiles if statement.
    void compile_if();

    // Compiles while statement.
    void compile_while();

    // Compiles do statement.
    void compile_do();

    // Compiles return statement.
    void compile_ret();

    // Compiles an expression.
    void compile_expr();

    /*
     * Compiles a term.
     *
     * If the current token is an ID, the routine will resolve it into a
     * variable, an array element, or a subroutine call.
     */
    void compile_term();

    /*
     * Compiles a (possibly empty) comma separated list of expressions.
     *
     * Returns the number of expressions in the list.
     */
    int compile_expr_lst();

    // XML methods.
    void write_xml_kwd(std::string kwd);
    void write_xml_symb(char symb);
    void write_xml_ic(int int_val);
    void write_xml_sc(std::string str_val);
    void write_xml_id(std::string id);

    // Structure checkers.
    bool is_type();

    // Structure writters.
    void write_type_or_throw();        // type
    void write_vname_or_throw();       // varName
    void write_star_vdec_or_throw();   // (',' varName)*
    void write_semicolon_or_throw();   // ';'
    void write_left_paren_or_throw();  // '('
    void write_right_paren_or_throw(); // ')'
    void write_left_bra_or_throw();    // '{'
    void write_right_bra_or_throw();   // '}'

    std::string indent_lvl();

private:
    Tokenizer tkz;
    std::ofstream outfile;
    int indent = 0;

    const int indent_amt = 4;
};
