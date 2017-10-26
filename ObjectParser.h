#ifndef OBJECTPARSER_H_INCLUDED
#define OBJECTPARSER_H_INCLUDED

#include "ParserBase.h"

namespace json {

class ParsedObject;

class ObjectParser : public ParserBase {

    public:
        //ObjectParser();
        ObjectParser(const std::string& name = "");
        ~ObjectParser();

    private:
        ObjectParser(const ObjectParser& other);
        ObjectParser& operator= (const ObjectParser& other);

    public:
        void parse(std::istream& in);

    private:
        ParsedObject *parsed;

};

}

#endif // OBJECTPARSER_H_INCLUDED

