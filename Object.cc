#include "Object.h"
#include "ObjectVariant.h"
#include "NullVariant.h"

namespace json {

typedef VariantMap::iterator VarIter;
typedef VariantMap::const_iterator VarConstIter;

Object::Object(const std::string& name)
: object(new ObjectVariant(name)) {
}

Object::Object(ObjectVariant *var)
: object(var) {    // Consumes the pointer
}

Object::Object(const Object& other) {

    object = dynamic_cast<ObjectVariant*>(other.object->clone());

}

Object& Object::operator =(const Object& other) {

    object->unref();
    object = dynamic_cast<ObjectVariant*>(other.object->clone());
    return *this;

}

Object::~Object() {

    object->unref();

}

Variant& Object::operator[] (const std::string& name) {

    return (*object)[name];

}

const Variant& Object::operator[] (const std::string& name) const {

    return (*object)[name];

}

/*
 * Caller must unref.
 */
ObjectVariant *Object::getObject() {

    return dynamic_cast<ObjectVariant*>(object->ref());

}

/*const VariantMap& Object::toMap() const {

    return *this;

}*/

void Object::toJson(std::ostream& out) const {

    object->toJson(out);

}

}

