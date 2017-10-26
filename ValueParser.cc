#include "ValueParser.h"

namespace json {

//ValueParser::ValueParser()
//: valueEnded(false) {
//}

ValueParser::ValueParser(const std::string& name)
: ParserBase(name),
  valueEnded(false) {
}

ValueParser::~ValueParser() {
}

bool ValueParser::endOfValue(char c, std::istream& in) {

    bool valid = false;
    switch (c) {
        case ',':
        case '}':
        case ']':
            // Preserve this char for parent parser.
            in.unget();
        case 0:
            valid = true;
            valueEnded = true;
    }

    return valid;

}

}

