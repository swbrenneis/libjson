#include "ParsedObject.h"
#include "ObjectVariant.h"

namespace json {

ParsedObject::ParsedObject() {
}

ParsedObject::ParsedObject(const std::string& name)
: ParsedStack(name) {
}

ParsedObject::~ParsedObject() {
}

BaseVariant *ParsedObject::getVariant() {

    ObjectVariant *obj = new ObjectVariant(name);
    for (ParsedVariant *var : members) {
        obj->push(var->getVariant());
    }

    return obj;

}

}

