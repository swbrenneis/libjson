#include "ArrayVariant.h"
#include "VariantException.h"

namespace json {

ArrayVariant::ArrayVariant(const std::string& name)
: BaseVariant(array_type, name) {
}

ArrayVariant::~ArrayVariant() {
}

Variant& ArrayVariant::operator[] (unsigned index) {

    if (index >= variantArray.size()) {
        throw VariantException("Array index out of bounds");
    }

    return variantArray[index];

}

const Variant& ArrayVariant::operator[] (unsigned index) const {

    if (index >= variantArray.size()) {
        throw VariantException("Array index out of bounds");
    }

    return variantArray[index];

}

BaseVariant *ArrayVariant::clone() const {

    ArrayVariant *array = new ArrayVariant(name);
    for (const Variant& var : variantArray) {
        array->push(var);
    }
    return array;

}

void ArrayVariant::push(const Variant& var) {

    variantArray.push_back(var);

}

void ArrayVariant::toJson(std::ostream& out) const {

    out << "[ ";
    size_t index = 0;
    for (const Variant& var : variantArray) {
        var.toJson(out);
        if (++index < variantArray.size()) {
            out << " , ";
        }
    }
    out << " ]";

}

ArrayVariant *ArrayVariant::toArray() {

    return dynamic_cast<ArrayVariant*>(ref());

}

}

