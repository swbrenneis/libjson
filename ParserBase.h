#ifndef PARSERBASE_H_INCLUDED
#define PARSERBASE_H_INCLUDED

#include <iostream>

namespace json {

class ParsedVariant;

class ParserBase {

    protected:
        ParserBase();
        ParserBase(const std::string& name);

    public:
        virtual ~ParserBase();

    private:
        ParserBase(const ParserBase& other);
        ParserBase& operator= (const ParserBase& other);

    public:
        ParsedVariant *getVariant(bool release = false);
        virtual void parse(std::istream& in)=0;

    protected:
        char chomp(std::istream& in);

    protected:
        std::string name;
        ParsedVariant *variant;

};

}

#endif // PARSERBASE_H_INCLUDED

