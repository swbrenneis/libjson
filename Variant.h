#ifndef VARIANT_H_INCLUDED
#define VARIANT_H_INCLUDED

#include <string>
#include <iostream>

namespace json {

class BaseVariant;
class Array;
class Object;
class VariantData;

class Variant {


    public:
        Variant();                  // Null variant
        Variant(BaseVariant* var);  // Consumes the pointer
        Variant(bool value);
        Variant(double value);
        Variant(int value);
        Variant(long value);
        Variant(const std::string& value);
        Variant(const char *value);
        Variant(const Array& value);
        Variant(const Object& value);
        Variant(const Variant& other);
        Variant& operator =(const Variant& other);
        ~Variant();

    public:
        bool isArray() const;
        bool isBool() const;
        bool isDouble() const;
        bool isInteger() const;
        bool isLong() const;
        bool isNull() const;
        bool isObject() const;
        bool isString() const;
        // Retrieve typed variables.
        // Throws an exception if the variant is the wrong type.
        Array toArray() const;
        bool toBool() const;
        double toDouble() const;
        int toInteger() const;
        long toLong() const;
        Object toObject() const;
        const std::string& toString() const;
        // Get the UTF-8 representation of the JSON variant.
        void toJson(std::ostream& out) const;
        // Manage the Variant's name.
        const std::string& getName() const;
        void setName(const std::string& name);

    private:
        BaseVariant *variant;

};

}

#endif // VARIANT_H_INCLUDED

