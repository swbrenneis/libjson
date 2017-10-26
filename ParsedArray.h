#ifndef PARSEDARRAY_H_INCLUDED
#define PARSEDARRAY_H_INCLUDED

#include "ParsedStack.h"

namespace json {

class ParsedArray : public ParsedStack {

    public:
        ParsedArray();
        ParsedArray(const std::string& name);
        ~ParsedArray();

    private:
        ParsedArray(const ParsedArray& other);
        ParsedArray& operator= (const ParsedArray& other);

    public:
        BaseVariant *getVariant();

};

}

#endif // PARSEDARRAY_H_INCLUDED

