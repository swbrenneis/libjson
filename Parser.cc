#include "Parser.h"
#include "ParsedVariant.h"
#include "ParserStart.h"

namespace json {

Parser::Parser()
: root(0) {
}

Parser::~Parser() {

    delete root;

}

void Parser::parse(std::istream& in) {

    ParserStart start;
    start.parse(in);
    // Parser owns the pointer.
    root = start.getVariant(true);

}

}

