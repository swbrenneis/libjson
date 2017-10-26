#ifndef PARSERSTART_H_INCLUDED
#define PARSERSTART_H_INCLUDED

#include "ParserBase.h"

namespace json {

class ParserStart : public ParserBase {

    public:
        ParserStart();
        ~ParserStart();

    private:
        ParserStart(const ParserStart& other);
        ParserStart& operator= (const ParserStart& other);

    public:
        void parse(std::istream& in);

    private:
        ParserBase *base;

};

}

#endif // PARSERSTART_H_INCLUDED

