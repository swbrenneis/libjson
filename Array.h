#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include "Variant.h"
#include <iostream>
#include <vector>

namespace json {

class ArrayVariant;

typedef std::vector<Variant> VariantArray;
typedef VariantArray::iterator VaIter;
typedef VariantArray::const_iterator VaConstIter;

class Array {

    public:
        Array(const std::string& name = "");
        Array(ArrayVariant *var);   // Consumes the pointer
        Array(const VariantArray& array);
        Array(const Array& other);
        Array& operator= (const Array& other);
        ~Array();

    public:
        Variant& operator[] (int index);
        const Variant& operator[] (int index) const;

    public:
        void append(const Variant& var);
        VaIter begin();
        VaConstIter begin() const;
        VaIter end();
        VaConstIter end() const;
        ArrayVariant *getArray();
        unsigned length() const;
        void push(const Variant& var);
        // Get the UTF-8 representation of the JSON variant.
        void toJson(std::ostream& out) const;
        const VariantArray& toMap() const;

    private:
        ArrayVariant *array;

};

}

#endif // ARRAY_H_INCLUDED

