#ifndef STRINGVARIANT_H_INCLUDED
#define STRINGVARIANT_H_INCLUDED

#include "BaseVariant.h"

namespace json {

class StringVariant : public BaseVariant {

    public:
        StringVariant(const std::string& v, const std::string& n)
            : BaseVariant(string_type, n), value(v) {}

    protected:
        ~StringVariant() {}

    private:
        StringVariant(const StringVariant& other);
        StringVariant& operator= (const StringVariant& other);

    public:
        BaseVariant *clone() const { return new StringVariant(value, name); }
        bool isString() const { return true; }
        const std::string& toString() const { return value; }

    protected:
        void getValue(std::ostream& out) const { out << '"' << value << '"'; }

    private:
        std::string value;

};

}

#endif // STRINGVARIANT_H_INCLUDED

