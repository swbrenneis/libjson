#ifndef BASEVARIANT_H_INCLUDED
#define BASEVARIANT_H_INCLUDED

#include "VariantException.h"
#include <iostream>

namespace json {

class ObjectVariant;
class ArrayVariant;

/*
 * BaseVariant and all of its subclasses are reference counted. The semantics
 * are that any method that emits a BaseVariant or its subclasses increments
 * the reference count using ref(). Constructors and methods that receive
 * BaseVariant or its subclasses consume the pointer and are responsible
 * for releasing their reference using unref().
 */
class BaseVariant {

    public:
        enum Type { object_type, array_type, int_type, long_type, double_type,
                    boolean_type, string_type, null_type };

    protected:
        BaseVariant(Type type, const std::string& name);
        virtual ~BaseVariant() {}

    private:
        BaseVariant(const BaseVariant& other);
        BaseVariant& operator= (const BaseVariant& other);

    public:
        virtual BaseVariant *clone() const=0;   // Deep copy
        const std::string& getName() const { return name; }
        Type getType() const { return type; }
        virtual bool isNull() const { return false; }
        BaseVariant *ref();
        void setName(const std::string& n) { name = n; }
        void unref();

        virtual bool isArray() const { return false; }
        virtual bool isBool() const { return false; }
        virtual bool isDouble() const { return false; }
        virtual bool isInteger() const { return false; }
        virtual bool isLong() const { return false; }
        virtual bool isObject() const { return false; }
        virtual bool isString() const { return false; }

        virtual bool toBool() const
        { throw VariantException("Invalid variant type, not a boolean"); }
        virtual ArrayVariant* toArray()
        { throw VariantException("Invalid variant type, not an array"); }
        virtual int toInteger() const
        { throw VariantException("Invalid variant type, not an integer"); }
        virtual long toLong() const
        { throw VariantException("Invalid variant type, not a long integer"); }
        virtual ObjectVariant* toObject()
        { throw VariantException("Invalid variant type, not an object"); }
        virtual double toDouble() const
        { throw VariantException("Invalid variant type, not a double"); }
        virtual const std::string& toString() const
        { throw VariantException("Invalid variant type, not a string"); }

        virtual void toJson(std::ostream& out);

    protected:
        virtual void getValue(std::ostream& out) const=0;

    protected:
        mutable int refcount;
        Type type;
        std::string name;

};

}

#endif // BASEVARIANT_H_INCLUDED

