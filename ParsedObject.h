#ifndef PARSEDOBJECT_H_INCLUDED
#define PARSEDOBJECT_H_INCLUDED

#include "ParsedStack.h"
#include "Object.h"

namespace json {

class ParsedObject : public ParsedStack {

    public:
        ParsedObject();
        ParsedObject(const std::string& name);
        ~ParsedObject();

    private:
        ParsedObject(const ParsedObject& other);
        ParsedObject& operator= (const ParsedObject& other);

    public:
        BaseVariant *getVariant();

};

}

#endif // PARSEDOBJECT_H_INCLUDED

