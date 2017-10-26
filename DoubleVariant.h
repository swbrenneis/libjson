#ifndef DOUBLEVARIANT_H_INCLUDED
#define DOUBLEVARIANT_H_INCLUDED

#include "BaseVariant.h"

namespace json {

class DoubleVariant : public BaseVariant {

    public:
        DoubleVariant(double v, const std::string& n)
            : BaseVariant(double_type, n), value(v) {}

    protected:
        ~DoubleVariant() {}

    private:
        DoubleVariant(const DoubleVariant& other);
        DoubleVariant& operator= (const DoubleVariant& other);

    public:
        BaseVariant *clone() const { return new DoubleVariant(value, name); }
        double toDouble() const { return value; }

    protected:
        void getValue(std::ostream& out) const { out << value; }

    private:
        double value;

};

}

#endif // DOUBLEVARIANT_H_INCLUDED

