#include "Document.h"
#include "Object.h"
#include "Array.h"
#include "Parser.h"
#include "ParsedVariant.h"
#include "BaseVariant.h"
#include <coder/ByteArray.h>
#include <sstream>

namespace json {

Document::Document(BaseVariant *v)
: variant(v) {
}

Document::~Document() {

    variant->unref();

}

Document *Document::fromJson(const coder::ByteArray& json) {

    return fromJson(json.toLiteralString());

}

Document *Document::fromJson(const std::string& json) {

    std::istringstream jstr(json);
    return fromStream(jstr);
    
}

Document *Document::fromStream(std::istream& in) {

    Parser parser;
    // May throw a ParseException.
    parser.parse(in);
    ParsedVariant *parsed = parser.getRoot();
    return new Document(parsed->getVariant());
    
}

Array Document::getArray() {

    if (variant->getType() == BaseVariant::array_type) {
        return Array(variant->toArray());
    }
    else {
        throw VariantException("Document does not contain array");
    }

}

Object Document::getObject() {

    if (variant->getType() == BaseVariant::object_type) {
        return Object(variant->toObject());
    }
    else {
        throw VariantException("Document does not contain object");
    }

}

Variant Document::getVariant() {

    return Variant(variant->ref());

}

}

