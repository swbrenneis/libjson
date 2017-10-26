#ifndef INTEGERVARIANT_H_INCLUDED
#define INTEGERVARIANT_H_INCLUDED

#include "BaseVariant.h"

namespace json {

class IntegerVariant : public BaseVariant {

    public:
        IntegerVariant(int v, const std::string& n)
            : BaseVariant(int_type, n), value(v) {}

    protected:
        ~IntegerVariant() {}

    private:
        IntegerVariant(const IntegerVariant& other);
        IntegerVariant& operator= (const IntegerVariant& other);

    public:
        BaseVariant *clone() const { return new IntegerVariant(value, name); }
        bool isInteger() const { return true; }
        bool isLong() const { return true; }
        long toLong() const { return value; }
        int toInteger() const { return value; }

    protected:
        void getValue(std::ostream& out) const { out << value; }

    private:
        int value;

};

}

#endif // INTEGERVARIANT_H_INCLUDED

