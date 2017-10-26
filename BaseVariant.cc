#include "BaseVariant.h"

namespace json {

BaseVariant::BaseVariant(Type t, const std::string& n)
: refcount(1),
  type(t),
  name(n) {
}

BaseVariant *BaseVariant::ref() {

    refcount++;
    return this;

}

void BaseVariant::toJson(std::ostream& out) {

    if (name.length() > 0) {
        out << "\"" << name << "\" : ";
    }
    getValue(out);

}

void BaseVariant::unref() {

    refcount--;
    if (refcount == 0) {
        delete this;
    }

}

}

