#include "Array.h"
#include "ArrayVariant.h"

namespace json {

Array::Array(const std::string& name)
: array(new ArrayVariant(name)) {
}

Array::Array(ArrayVariant *var)     // Consumes the pointer
: array(var) {
}

Array::~Array() {
}

Array::Array(const Array& other) {

    array = dynamic_cast<ArrayVariant*>(other.array->clone());

}

Array& Array::operator =(const Array& other) {

    array->unref();
    array = dynamic_cast<ArrayVariant*>(other.array->clone());
    return *this;

}

Variant& Array::operator[] (int index) {

    return (*array)[index];

}

const Variant& Array::operator[] (int index) const {

    return (*array)[index];

}

void Array::append(const Variant& var) {

    array->append(var);

}

VaIter Array::begin() {

    return array->begin();

}

VaConstIter Array::begin() const {

    return array->begin();

}

VaIter Array::end() {

    return array->end();

}

VaConstIter Array::end() const {

    return array->end();

}

/*
 * Caller must unref.
 */
ArrayVariant *Array::getArray() {

    return dynamic_cast<ArrayVariant*>(array->ref());

}

unsigned Array::length() const {

    return array->length();

}

void Array::toJson(std::ostream& out) const {

    array->toJson(out);

}

}

