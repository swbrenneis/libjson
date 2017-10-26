#ifndef NULLVARIANT_H_INCLUDED
#define NULLVARIANT_H_INCLUDED

#include "BaseVariant.h"

/*
 * A null variant is essentially a placeholder. It can be morphed
 * into any other type of variant.
 */
namespace json {

class NullVariant : public BaseVariant {

    public:
        NullVariant() : BaseVariant(null_type, "") {}
        NullVariant(void *, const std::string& name)
                            : BaseVariant(null_type, name) {}

    protected:
        ~NullVariant() {}

    private:
        NullVariant(const NullVariant& other);
        NullVariant& operator= (const NullVariant& other);

    public:
        BaseVariant *clone() const { return new NullVariant(0, name); }
        void getValue(std::ostream& out) const { out << "null"; }
        bool isNull() const { return true; }

};

}

#endif // NULLVARIANT_H_INCLUDED

