#ifndef NULLPARSER_H_INCLUDED
#define NULLPARSER_H_INCLUDED

#include "ValueParser.h"

namespace json {

class NullParser : public ValueParser {

    public:
        //NullParser();
        NullParser(const std::string& name = "");
        ~NullParser();

    private:
        NullParser(const NullParser& other);
        NullParser& operator= (const NullParser& other);

    public:
        void parse(std::istream& in);

};

}

#endif // NULLPARSER_H_INCLUDED

