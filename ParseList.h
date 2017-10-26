#ifndef PARSELIST_H_INCLUDED
#define PARSELIST_H_INCLUDED

#include "ParsedStack.h"

namespace json {

class ParseList : public ParsedStack {

    public:
        ParseList();
        ~ParseList();

    private:
        ParseList(const ParseList& other);
        ParseList& operator= (const ParseList& other);

    public:
        ParsedVariant *pop();

};

}

#endif // PARSELIST_H_INCLUDED

