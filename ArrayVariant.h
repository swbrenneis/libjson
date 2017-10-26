#ifndef ARRAYVARIANT_H_INCLUDED
#define ARRAYVARIANT_H_INCLUDED

#include "Variant.h"
#include "Array.h"
#include "BaseVariant.h"
#include <vector>

namespace json {

typedef std::vector<Variant> VariantArray;
typedef VariantArray::iterator VaIter;
typedef VariantArray::const_iterator VaConstIter;

class Array;

class ArrayVariant : public BaseVariant {

    public:
        ArrayVariant(const std::string& name);

    protected:
        ~ArrayVariant();

    private:
        ArrayVariant(const ArrayVariant& other);
        ArrayVariant& operator= (const ArrayVariant& other);

    public:
        Variant& operator[] (unsigned index);
        const Variant& operator[] (unsigned index) const;

    public:
        void append(const Variant& var) { push(var); }
        VaIter begin() { return variantArray.begin(); }
        VaConstIter begin() const { return variantArray.begin(); }
        VaIter end() { return variantArray.end(); }
        VaConstIter end() const { return variantArray.end(); }
        BaseVariant *clone() const;
        void getValue(std::ostream& out) const { toJson(out); }
        virtual bool isArray() const { return true; }
        unsigned length() const { return variantArray.size(); }
        void push(const Variant& var);
        void toJson(std::ostream& out) const;
        ArrayVariant *toArray();

    private:
        VariantArray variantArray;

};

}

#endif // ARRAYVARIANT_H_INCLUDED

