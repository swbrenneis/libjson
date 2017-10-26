#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "Variant.h"
#include <iostream>
#include <string>
#include <map>

namespace json {

class ObjectVariant;
class Variant;

typedef std::map<std::string, Variant> VariantMap;

class Object {

    public:
        Object(const std::string& name = "");
        Object(ObjectVariant *var);     // Consumes the pointer
        Object(const VariantMap& map);
        Object(const Object& other);
        ~Object();

    public:
        Object& operator= (const Object& other);
        Variant& operator[] (const std::string& name);
        const Variant& operator[] (const std::string& name) const;

    public:
        ObjectVariant *getObject();
        void push(const Variant& var);
        // Get the UTF-8 representation of the JSON variant.
        void toJson(std::ostream& out) const;
        const VariantMap& toMap() const;

    private:
        ObjectVariant *object;

};

}

#endif // OBJECT_H_INCLUDED

