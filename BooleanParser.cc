#include "BooleanParser.h"
#include "ParsedScalar.h"
#include "BooleanVariant.h"
#include "ParseException.h"
#include <sstream>

namespace json {

//BooleanParser::BooleanParser() {
//}

BooleanParser::BooleanParser(const std::string& name)
: ValueParser(name) {
}

BooleanParser::~BooleanParser() {
}

void BooleanParser::parse(std::istream& in) {

    char c = in.get();
    bool bvalue;
    std::ostringstream bstr;
    if (c == 't') {
        bstr << c;
        char buf[4] = { 0, 0, 0, 0 };
        in.read(buf, 3);
        // EOF means that we read less than three characters
        if (in.eof()) {
            throw ParseException("Unexpected end of input");
        }
        bstr << buf;
        if (bstr.str() != "true") {
            throw ParseException("Syntax error, invalid boolean value");
        }
        bvalue = true;
    }
    if (c == 'f') {
        bstr << c;
        char buf[5] = { 0, 0, 0, 0, 0 };
        in.read(buf, 4);
        // EOF means that we read less than four characters
        if (in.eof()) {
            throw ParseException("Unexpected end of input");
        }
        bstr << buf;
        if (bstr.str() != "false") {
            throw ParseException("Syntax error, invalid boolean value");
        }
        bvalue = false;
    }

    c = chomp(in);
    if (endOfValue(c, in)) {
        variant = new ParsedScalar<bool, BooleanVariant>(bvalue, name);
    }
    else {
        std::ostringstream estr;
        estr << "Unexpected '" << c << "' after boolean value";
        throw ParseException(estr.str());
    }

}

}

