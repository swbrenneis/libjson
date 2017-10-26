#include "NamedValueParser.h"
#include "ParseException.h"
#include "NumberParser.h"
#include "BooleanParser.h"
#include "StringParser.h"
#include "ObjectParser.h"
#include "ArrayParser.h"
#include "NullParser.h"
#include <sstream>
#include <memory>

namespace json {

static const std::string NUMERIC("+-01234567890");

NamedValueParser::NamedValueParser(bool c)
: ValueParser(""),
  contained(c) {
}

NamedValueParser::~NamedValueParser() {
}

void NamedValueParser::parse(std::istream& in) {

    std::ostringstream namestr;
    parseName(in, namestr);
    name = namestr.str();
    char colon = chomp(in);
    if (colon == ':') {
        variant = parseValue(in);
    }
    else {
        throw ParseException("Syntax error, missing ':' in declaration");
    }

    char c = chomp(in);
    if (!contained && c != 0) {
        throw ParseException("Named value list not allowed outside of object");
    }
    else {
        in.unget();
    }

}

void NamedValueParser::parseName(std::istream& in, std::ostream& out) {

    char c;
    in.get(c);
    if (c > 0) {
        if (c != '"') {
            out << c;
            parseName(in, out);
        }
    }
    else {
        throw ParseException("Unexpected end of input");
    }

}

ParsedVariant *NamedValueParser::parseValue(std::istream& in) {

    char c = chomp(in);

    ParserBase *pb;
    switch (c) {
        case 't':
        case 'f':
            in.unget();
            pb = new BooleanParser(name);
            break;
        case 'n':
            in.unget();
            pb = new NullParser(name);
            break;
        case '"':
            pb = new StringParser(name);
            break;
        case '{':
            pb = new ObjectParser(name);
            break;
        case '[':
            pb = new ArrayParser(name);
            break;
        default:
            if (NUMERIC.find(c) != std::string::npos) {
                in.unget();
                pb = new NumberParser(name);
            }
            else {
                throw ParseException("Syntax error, invalid value type");
            }
    }

    std::unique_ptr<ParserBase> base(pb);
    base->parse(in);
    return base->getVariant(true);

}

}

