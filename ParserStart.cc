#include "ParserStart.h"
#include "ArrayParser.h"
#include "ObjectParser.h"
#include "NamedValueParser.h"
#include "ParseException.h"

namespace json {

ParserStart::ParserStart()
: base(0) {
}

ParserStart::~ParserStart() {

    delete base;

}

void ParserStart::parse(std::istream& in) {

    char c = chomp(in);

    switch (c) {
        case '[':
            base = new ArrayParser;
            break;
        case '{':
            base = new ObjectParser;
            break;
        case '"':
            base = new NamedValueParser(false);
            break;
        default:
            throw ParseException("JSON not well formed");
    }

    base->parse(in);
    variant = base->getVariant(true);

}

}

