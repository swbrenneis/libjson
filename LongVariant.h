#ifndef LONGVARIANT_H_INCLUDED
#define LONGVARIANT_H_INCLUDED

#include "BaseVariant.h"

namespace json {

class LongVariant : public BaseVariant {

    public:
        LongVariant(long v, const std::string& n)
            : BaseVariant(long_type, n), value(v) {}

    protected:
        ~LongVariant() {}

    private:
        LongVariant(const LongVariant& other);
        LongVariant& operator= (const LongVariant& other);

    public:
        BaseVariant *clone() const { return new LongVariant(value, name); }
        bool isInteger() const { return std::abs(value) < 0x7fffffff; }
        bool isLong() const { return true; }
        int toInteger() const { return value; }
        long toLong() const { return value; }

    protected:
        void getValue(std::ostream& out) const { out << value; }

    private:
        long value;

};

}

#endif // LONGVARIANT_H_INCLUDED

