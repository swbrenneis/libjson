#ifndef PARSEDSTACK_H_INCLUDED
#define PARSEDSTACK_H_INCLUDED

#include "ParsedVariant.h"
#include <deque>

namespace json {

class ParsedStack : public ParsedVariant {

    protected:
        ParsedStack();
        ParsedStack(const std::string& name);

    public:
        ~ParsedStack();

    private:
        ParsedStack(const ParsedStack& other);
        ParsedStack& operator= (const ParsedStack& other);

    public:
        const std::string& getName() const { return name; }
        void push(ParsedVariant *var);

    protected:
        ParsedVariant *pop();

    protected:
        const std::string name;
        typedef std::deque<ParsedVariant*> VariantStack;
        VariantStack members;

};

}

#endif // PARSEDSTACK_H_INCLUDED

