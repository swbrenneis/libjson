#include "Variant.h"
#include "NullVariant.h"
#include "ObjectVariant.h"
#include "ArrayVariant.h"
#include "StringVariant.h"
#include "LongVariant.h"
#include "BooleanVariant.h"
#include "Object.h"
#include "Array.h"
#include "VariantException.h"

namespace json {

Variant::Variant()
: variant(new NullVariant) {
}

Variant::Variant(BaseVariant* var)  // Consumes the pointer
: variant(var) {

    if (var == 0) {
        throw VariantException("Illegal null variant");
    }

}

Variant::Variant(const Array& object) {

    variant = const_cast<Array&>(object).getArray();

}

Variant::Variant(const std::string& value)
: variant(new StringVariant(value, "")) {
}

Variant::Variant(const char *value)
: variant(new StringVariant(value, "")) {
}

Variant::Variant(int value)
: variant(new LongVariant(value, "")) {
}

Variant::Variant(long value)
: variant(new LongVariant(value, "")) {
}

Variant::Variant(bool value)
: variant(new BooleanVariant(value, "")) {
}

Variant::Variant(const Object& object) {

    variant = const_cast<Object&>(object).getObject();

}

Variant::Variant(const Variant& other) {

    variant = other.variant->ref();

}

Variant::~Variant() {

    variant->unref();

}

Variant& Variant::operator =(const Variant& other) {

    if (other.variant == 0) {
        throw VariantException("Illegal null variant");
    }

    // Preserve the current name
    std::string name = variant->getName();
    // Release the current variant.
    variant->unref();
    variant = other.variant->ref();
    // Restore the current name if the new variant doesn't have one.
    if (variant->getName().length() == 0) {
        variant->setName(name);
    }
    return *this;

}

const std::string& Variant::getName() const {

    return variant->getName();

}

bool Variant::isArray() const {

    return variant->isArray();

}

bool Variant::isInteger() const {

    return variant->isInteger();

}

bool Variant::isLong() const {

    return variant->isLong();

}

bool Variant::isNull() const {

    return variant->isNull();

}

bool Variant::isObject() const {

    return variant->isObject();

}

bool Variant::isString() const {

    return variant->isString();

}

void Variant::setName(const std::string& name) {

    variant->setName(name);

}

Array Variant::toArray() const {

    return variant->toArray();

}

bool Variant::toBool() const {

    return variant->toBool();

}

int Variant::toInteger() const {

    return variant->toInteger();

}

void Variant::toJson(std::ostream& out ) const {

    variant->toJson(out);

}

long Variant::toLong() const {

    return variant->toLong();

}

const std::string& Variant::toString() const {

    return variant->toString();

}

Object Variant::toObject() const {

    if (variant->getType() != BaseVariant::object_type) {
        throw VariantException("Not an object");
    }

    return Object(dynamic_cast<ObjectVariant*>(variant->clone()));

}

}

