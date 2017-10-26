#ifndef NUMBERPARSER_H_INCLUDED
#define NUMBERPARSER_H_INCLUDED

#include "ValueParser.h"
#include <sstream>

namespace json {

class NumberParser : public ValueParser {

    public:
        //NumberParser();
        NumberParser(const std::string& name = "");
        ~NumberParser();

    private:
        NumberParser(const NumberParser& other);
        NumberParser& operator= (const NumberParser& other);

    public:
        void parse(std::istream& in);

    private:
        void endOfDouble(double integerPart);
        void endOfLong();
        void parseDouble(double ivalue, std::istream& in);

    private:
        bool numberStarted;
        std::ostringstream longCollector;
        std::ostringstream doubleCollector;

};

}

#endif // NUMBERPARSER_H_INCLUDED

