#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>

namespace json {

class ParsedVariant;

class Parser {

    public:
        Parser();
        ~Parser();

    private:
        Parser(const Parser& other);
        Parser& operator= (const Parser& other);

    public:
        ParsedVariant *getRoot() { return root; }
        // Parse a document from a stream.
        void parse(std::istream& in);

    private:
        ParsedVariant *root;

};

}

#endif // PARSER_H_INCLUDED

