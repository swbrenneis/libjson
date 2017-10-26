#include "StringParser.h"
#include "ParsedScalar.h"
#include "StringVariant.h"
#include "ParseException.h"
#include <sstream>

namespace json {

//StringParser::StringParser() {
//}

StringParser::StringParser(const std::string& name)
: ValueParser(name) {
}

StringParser::~StringParser() {
}

void StringParser::parse(std::istream& in) {

    std::ostringstream out;
    parse(in, out);

    char c = chomp(in);
    if (endOfValue(c, in)) {
        variant = new ParsedScalar<std::string, StringVariant>(out.str(), name);
    }
    else {
        std::ostringstream estr;
        estr << "Unexpected '" << c << "' after string value";
        throw ParseException(estr.str());
    }

}

void StringParser::parse(std::istream& in, std::ostream& out) {

    char c;
    in.get(c);
    if (c > 0) {
        if (c != '"') {
            out << c;
            parse(in, out);
        }
    }
    else {
        throw ParseException("Unexpected end of input");
    }

}

}

