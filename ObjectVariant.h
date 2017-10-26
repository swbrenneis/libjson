#ifndef OBJECTVARIANT_H_INCLUDED
#define OBJECTVARIANT_H_INCLUDED

#include "BaseVariant.h"
#include "Variant.h"
#include <string>
#include <vector>

namespace json {

class ObjectVariant : public BaseVariant {

    public:
        ObjectVariant(const std::string& name);

    protected:
        ~ObjectVariant();

    private:
        ObjectVariant(const ObjectVariant& other);
        ObjectVariant& operator= (const ObjectVariant& other);

    public:
        Variant& operator[] (const std::string& name);
        const Variant& operator[] (const std::string& name) const;

    public:
        BaseVariant *clone() const;
        void getValue(std::ostream& out) const { toJson(out); }
        bool isObject() const { return true; }
        void push(const Variant& var);
        void toJson(std::ostream& out) const;
        ObjectVariant *toObject();

    private:
        typedef std::vector<Variant> VariantList;
        typedef VariantList::iterator VarIter;
        typedef VariantList::const_iterator VarConstIter;
        VariantList variantList;

};

}

#endif // OBJECTVARIANT_H_INCLUDED

