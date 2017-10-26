#ifndef NAMEDVALUEPARSER_H_INCLUDED
#define NAMEDVALUEPARSER_H_INCLUDED

#include "ValueParser.h"
#include <string>

namespace json {

class NamedValueParser : public ValueParser {

    public:
        NamedValueParser(bool contained);
        ~NamedValueParser();

    private:
        NamedValueParser(const NamedValueParser& other);
        NamedValueParser& operator= (const NamedValueParser& other);

    public:
        void parse(std::istream& in);

    private:
        void parseName(std::istream& in, std::ostream& out);
        ParsedVariant *parseValue(std::istream& in);

    private:
        bool contained;

};

}

#endif // NAMEDVALUEPARSER_H_INCLUDED

