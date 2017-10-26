#include "ObjectParser.h"
#include "ParsedObject.h"
#include "NamedValueParser.h"
#include "EmptyParser.h"
#include "ParseException.h"
#include <sstream>
#include <memory>

namespace json {

ObjectParser::ObjectParser(const std::string& name)
: ParserBase(name),
  parsed(new ParsedObject(name)) {

    variant = parsed;

}

/*ObjectParser::ObjectParser()
: parsed(new ParsedObject) {

    variant = parsed;

}*/

ObjectParser::~ObjectParser() {
    // parsed will be deleted in the base.
}

void ObjectParser::parse(std::istream& in) {

    char c = chomp(in);
    if (c == '}') {
        in.unget();
    }
    else {
        ParserBase *pb;
        switch (c) {
            case '"':
                pb = new NamedValueParser(true);
                break;
            case '{':
                pb = new ObjectParser;
                break;
            //case '}':
            //    pb = new EmptyParser;
            //    break;
            default:
                std::ostringstream estr;
                estr << "Unexpected '" << c << "' in object declaration";
                throw ParseException(estr.str());
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
    else if (c != '}') {
        std::ostringstream estr;
        estr << "Unexpected '" << c << "' in object declaration";
        throw ParseException(estr.str());
    }

}

}

