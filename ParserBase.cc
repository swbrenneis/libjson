#include "ParserBase.h"
#include "ParsedVariant.h"

namespace json {

static const std::string WHITESPACE(" \t\r\n");

ParserBase::ParserBase()
: variant(0) {
}

ParserBase::ParserBase(const std::string& n)
: name(n),
  variant(0) {
}

ParserBase::~ParserBase() {

    delete variant;

}

/*
 * Consumes whitespace. Returns first non-whitespace character or 0
 * if end of stream.
 */
char ParserBase::chomp(std::istream& in) {

    char c;
    in.get(c);
    if (c < 0) {
        c = 0;
    }
    else if (WHITESPACE.find(c) != std::string::npos) {
        return chomp(in);
    }
    return c;

}

/*
 * Variant reference set to null is release is true.
 */
ParsedVariant *ParserBase::getVariant(bool release) {

    ParsedVariant *v = variant;
    if (release) {
        variant = 0;
    }
    return v;

}

}

