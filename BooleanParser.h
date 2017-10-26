#ifndef BOOLEANPARSER_H_INCLUDED
#define BOOLEANPARSER_H_INCLUDED

#include "ValueParser.h"

namespace json {

class BooleanParser : public ValueParser {

    public:
        //BooleanParser();
        BooleanParser(const std::string& name = "");
        ~BooleanParser();

    private:
        BooleanParser(const BooleanParser& other);
        BooleanParser& operator= (const BooleanParser& other);

    public:
        void parse(std::istream& in);

};

}

#endif // BOOLEANPARSER_H_INCLUDED

