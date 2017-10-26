#ifndef VALUEPARSER_H_INCLUDED
#define VALUEPARSER_H_INCLUDED

#include "ParserBase.h"

namespace json {

class ValueParser : public ParserBase {

    public:
        //ValueParser();
        ValueParser(const std::string& name);
        ~ValueParser();

    private:
        ValueParser(const ValueParser& other);
        ValueParser& operator= (const ValueParser& other);

    protected:
        bool endOfValue(char c, std::istream& in);

    protected:
        bool valueEnded;

};

}

#endif // VALUEPARSER_H_INCLUDED

