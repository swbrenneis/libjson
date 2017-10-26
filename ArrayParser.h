#ifndef ARRAYPARSER_H_INCLUDED
#define ARRAYPARSER_H_INCLUDED

#include "ValueParser.h"

namespace json {

class ParsedArray;

class ArrayParser : public ValueParser {

    public:
        //ArrayParser();
        ArrayParser(const std::string& name = "");
        ~ArrayParser();

    private:
        ArrayParser(const ArrayParser& other);
        ArrayParser& operator= (const ArrayParser& other);

    public:
        void parse(std::istream& in);

    private:
        ParsedArray *parsed;

};

}

#endif // ARRAYPARSER_H_INCLUDED

