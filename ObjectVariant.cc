#include "ObjectVariant.h"
#include "VariantException.h"
#include <sstream>

namespace json {

static Variant nullVariant;

ObjectVariant::ObjectVariant(const std::string& name)
: BaseVariant(object_type, name) {
}

ObjectVariant::~ObjectVariant() {
}

Variant& ObjectVariant::operator[] (const std::string& name) {

    for (Variant& var : variantList) {
        if (var.getName() == name) {
            return var;
        }
    }

    Variant var;    // Null variant.
    var.setName(name);
    VarIter it = variantList.insert(variantList.end(), var);
    return *it;

}

const Variant& ObjectVariant::operator[] (const std::string& name) const {

    for (const Variant& var : variantList) {
        if (var.getName() == name) {
            return var;
        }
    }

    return nullVariant;

}

BaseVariant *ObjectVariant::clone() const {

    ObjectVariant *obj = new ObjectVariant(name);
    for (const Variant& var : variantList) {
        obj->push(var);
    }
    return obj;

}

void ObjectVariant::push(const Variant& var) {

    std::string name = var.getName();
    for (Variant& var : variantList) {
        if (var.getName() == name) {
            std::ostringstream estr;
            estr << "Duplicate declaration of \"" << name << "\" in object";
            throw VariantException(estr.str());
        }
    }
    variantList.push_back(var);

}

void ObjectVariant::toJson(std::ostream& out) const {

    out << "{ ";
    size_t index = 0;
    for (const Variant& var : variantList) {
        var.toJson(out);
        if (++index < variantList.size()) {
            out << " , ";
        }
    }
    out << " }";

}

ObjectVariant *ObjectVariant::toObject() {

    return dynamic_cast<ObjectVariant*>(ref());

}

}

