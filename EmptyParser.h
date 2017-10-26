#ifndef EMPTYPARSER_H_INCLUDED
#define EMPTYPARSER_H_INCLUDED

#include "ValueParser.h"

namespace json {

class EmptyParser : public ValueParser {

    public:
        EmptyParser() : ValueParser("") {}
        ~EmptyParser() {}

    private:
        EmptyParser(const EmptyParser& other);
        EmptyParser& operator= (const EmptyParser& other);

    public:
        void parse(std::istream& in) {}

};

}

#endif // EMPTYPARSER_H_INCLUDED

