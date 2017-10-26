#include "ArrayParser.h"
#include "BooleanParser.h"
#include "StringParser.h"
#include "NumberParser.h"
#include "ObjectParser.h"
#include "ParsedArray.h"
#include "ParseException.h"
#include <memory>

namespace json {

static const std::string NUMERIC("+-01234567890");

ArrayParser::ArrayParser(const std::string& name)
: ValueParser(name),
  parsed(new ParsedArray(name)) {

    variant = parsed;

}

/*ArrayParser::ArrayParser()
: parsed(new ParsedArray) {

    variant = parsed;

}*/

ArrayParser::~ArrayParser() {
    // parsed will be deleted in the base.
}

void ArrayParser::parse(std::istream& in) {

    char c = chomp(in);
    if (c == ']') {
        in.unget();
    }
    else {
        ParserBase *pb;
        switch (c) {
            case '"':
                pb = new StringParser;
                break;
            case '{':
                pb = new ObjectParser;
                break;
            case 't':
            case 'f':
                in.unget();
                pb = new BooleanParser;
                break;
            case '[':
                pb = new ArrayParser;
                break;
            default:
                if (NUMERIC.find(c) != std::string::npos) {
                    in.unget();
                    pb = new NumberParser;
                }
                else {
                    std::ostringstream estr;
                    estr << "Unexpected '" << c << "' in array declaration";
                    throw ParseException(estr.str());
                }
        }
        std::unique_ptr<ParserBase> base(pb);
        base->parse(in);
        parsed->push(base->getVariant(true));
    }

    // This should either be a closing brace or a comma.
    c = chomp(in);
    if (c == ',') {
        parse(in);
    }
    else if (c != ']') {
        std::ostringstream estr;
        estr << "Unexpected '" << c << "' in array declaration";
        throw ParseException(estr.str());
    }

}

}

