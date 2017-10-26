#ifndef PARSEDSCALAR_H_INCLUDED
#define PARSEDSCALAR_H_INCLUDED

#include "ParsedVariant.h"
#include <string>

namespace json {

template<typename S, class V> class ParsedScalar : public ParsedVariant {

    public:
        ParsedScalar(const S& s, const std::string& n) : sval(s), name(n) {}
        virtual ~ParsedScalar() {}

    private:
        ParsedScalar(const ParsedScalar& other);
        ParsedScalar& operator= (const ParsedScalar& other);

    public:
        const std::string& getName() const { return name; }
        BaseVariant *getVariant() { return new V(sval, name); }

    private:
        S sval;
        std::string name;

};

}

#endif // PARSEDSCALAR_H_INCLUDED

