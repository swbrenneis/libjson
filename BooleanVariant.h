#ifndef BOOLEANVARIANT_H_INCLUDED
#define BOOLEANVARIANT_H_INCLUDED

#include "BaseVariant.h"

namespace json {

class BooleanVariant : public BaseVariant {

    public:
        BooleanVariant(bool v, const std::string& n)
            : BaseVariant(boolean_type, n), value(v) {}

    protected:
        ~BooleanVariant() {}

    private:
        BooleanVariant(const BooleanVariant& other);
        BooleanVariant& operator= (const BooleanVariant& other);

    public:
        BaseVariant *clone() const { return new BooleanVariant(value, name); }
        bool toBool() const { return value; }

    protected:
        void getValue(std::ostream& out) const
                            { out << (value ? "true" : "false"); }

    private:
        bool value;

};

}

#endif // BOOLEANVARIANT_H_INCLUDED

