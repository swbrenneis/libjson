#include "NullParser.h"
#include "ParsedScalar.h"
#include "NullVariant.h"
#include "ParseException.h"
#include <sstream>

namespace json {

//NullParser::NullParser() {
//}

NullParser::NullParser(const std::string& name)
: ValueParser(name) {
}

NullParser::~NullParser() {
}

void NullParser::parse(std::istream& in) {

    std::ostringstream nstr;
    char buf[5] = { 0, 0, 0, 0, 0 };
    in.read(buf, 4);
    // EOF means that we read less than four characters
    if (in.eof()) {
        throw ParseException("Unexpected end of input");
    }
    nstr << buf;
    if (nstr.str() != "null") {
        throw ParseException("Syntax error, invalid specifier in null variant");
    }

    char c = chomp(in);
    if (endOfValue(c, in)) {
        variant = new ParsedScalar<void*, NullVariant>(0, name);
    }
    else {
        std::ostringstream estr;
        estr << "Unexpected '" << c << "' after null specifier";
        throw ParseException(estr.str());
    }

}

}

