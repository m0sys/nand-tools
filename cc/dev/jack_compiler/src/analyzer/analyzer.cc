#include "analyzer.h"
#include "../common/log.h"
#include "../jcl_engine/jcl_engine.h"
#include "../tokenizer/tokenizer.h"
#include <filesystem>
#include <fstream>
#include <stdexcept>

Analyzer::Analyzer(std::string fname)
    : fname { fname }
{
    namespace fs = std::filesystem;
    // Check that fname exists before processing.
    if (!fs::exists(fname))
        throw std::logic_error("fname does not exist");

    if (fs::is_directory(fname)) {
        DEBUG_LOG("This is a directory!");
        for (const auto& entry : fs::directory_iterator(fname)) {
            DEBUG_LOG(entry.path());
            auto fn = entry.path().string();
            if (fn.find(".jack") != std::string::npos) {
                DEBUG_LOG(fn << " is .jack type!");
                paths.push_back(fn);
            }
        }
    } else
        paths.push_back(fname);
}

void Analyzer::tokenize()
{
    using std::string;

    for (const auto& f : paths) {
        auto xml_fname = create_ext_fname(f, ".xml", true);
        Tokenizer t(f);

        auto out = std::ofstream(xml_fname);
        out << "<tokens>\n";

        LOG("f: " << f);
        while (t.has_more_tokens()) {

            auto tt = t.token_type();
            if (tt == TokenType::KWD) {
                LOG("KWD!");
                auto kt = t.keyword();
                string ostr = "<keyword> ";
                if (kt == Kwd::CLS)
                    ostr += "class";

                else if (kt == Kwd::CONSTR)
                    ostr += "constructor";

                else if (kt == Kwd::FUNC)
                    ostr += "function";

                else if (kt == Kwd::METH)
                    ostr += "method";

                else if (kt == Kwd::FIELD)
                    ostr += "field";

                else if (kt == Kwd::STATIC)
                    ostr += "static";

                else if (kt == Kwd::VAR)
                    ostr += "var";

                else if (kt == Kwd::INT)
                    ostr += "int";

                else if (kt == Kwd::CHAR)
                    ostr += "char";

                else if (kt == Kwd::BOOL)
                    ostr += "boolean";

                else if (kt == Kwd::VOID)
                    ostr += "void";

                else if (kt == Kwd::T)
                    ostr += "true";

                else if (kt == Kwd::F)
                    ostr += "false";

                else if (kt == Kwd::N)
                    ostr += "null";

                else if (kt == Kwd::THIS)
                    ostr += "this";

                else if (kt == Kwd::LET)
                    ostr += "let";

                else if (kt == Kwd::DO)
                    ostr += "do";

                else if (kt == Kwd::IF)
                    ostr += "if";

                else if (kt == Kwd::ELSE)
                    ostr += "else";

                else if (kt == Kwd::WHILE)
                    ostr += "while";

                else if (kt == Kwd::RET)
                    ostr += "return";

                else {
                    throw std::logic_error("Analyzer: keyword is unsupported");
                }

                ostr += " </keyword>\n";
                out << ostr;
            }

            if (tt == TokenType::SYMB) {
                LOG("SYMB!");
                string ostr = "<symbol> " + std::string(1, t.symbol()) + " </symbol>\n";
                out << ostr;
            }

            if (tt == TokenType::ID) {
                LOG("ID!");
                string ostr = "<identifier> " + t.id() + " </identifier>\n";
                out << ostr;
            }

            if (tt == TokenType::INT_CONST) {
                LOG("INT_CONST!");
                string ostr = "<intConst> " + std::to_string(t.int_val()) + " </intConst>\n";
                out << ostr;
            }

            if (tt == TokenType::STR_CONST) {
                LOG("STR_CONST!");
                string ostr = "<stringConst> " + t.str_val() + " </stringConst>\n";
                out << ostr;
            }

            t.advance();
        }

        out << "</tokens>";
        out.close();
    }
}
void Analyzer::compile()
{

    for (const auto& f : paths) {
        auto xml_fname = create_ext_fname(f, ".xml");
        JCLEngine je(f, xml_fname);
        je.compile_class();
    }
}

std::string Analyzer::create_ext_fname(const std::string& jack_fname, const std::string& ext, bool T)
{
    using std::string;
    using std::to_string;

    // Parsing file name to find jack part of fname.
    auto ex_pos = jack_fname.find(".jack");
    auto last_slash_pos = jack_fname.rfind("/");
    if (ex_pos == string::npos) {
        throw std::logic_error("File must be a .jack file");
    }

    // Check for last occurance of backslash.
    string rpath = "";
    string prog_name = "";
    string ext_fname = "";
    auto npos = jack_fname.size() - 5;

    // Extract program name.
    if (last_slash_pos != string::npos) {
        // When fname has a rel/abs path.
        npos -= last_slash_pos;
        prog_name = jack_fname.substr(last_slash_pos + 1, npos - 1);
        rpath = jack_fname.substr(0, last_slash_pos + 1);
    } else {
        // When fname is curr dir.
        prog_name = jack_fname.substr(0, npos);
    }

    if (T)
        prog_name += "T";

    ext_fname = rpath + "gen/" + prog_name + ext;

    // Create gen directory if not already created.
    if (!std::filesystem::exists(rpath + "gen/")) {
        if (!std::filesystem::create_directory(rpath + "gen/"))
            throw std::domain_error("Error: could not create director");
    }

    return ext_fname;
}
