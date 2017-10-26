#ifndef STRINGPARSER_H_INCLUDED
#define STRINGPARSER_H_INCLUDED

#include "ValueParser.h"

namespace json {

class StringParser : public ValueParser {

    public:
        //StringParser();
        StringParser(const std::string& name = "");
        ~StringParser();

    private:
        StringParser(const StringParser& other);
        StringParser& operator= (const StringParser& other);

    public:
        void parse(std::istream& in);

    private:
        void parse(std::istream& in, std::ostream& out);

};

}

#endif // STRINGPARSER_H_INCLUDED

