#include "ParsedArray.h"
#include "ArrayVariant.h"

namespace json {

ParsedArray::ParsedArray() {
}

ParsedArray::ParsedArray(const std::string& name)
: ParsedStack(name) {
}

ParsedArray::~ParsedArray() {
}

BaseVariant *ParsedArray::getVariant() {

    ArrayVariant *array = new ArrayVariant(name);
    for (ParsedVariant *var : members) {
        array->push(var->getVariant());
    }

    return array;

}

}

