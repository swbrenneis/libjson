#ifndef PARSEDVARIANT_H_INCLUDED
#define PARSEDVARIANT_H_INCLUDED

#include <string>

/*
 * Base parsing entity.
 */
namespace json {

class BaseVariant;

class ParsedVariant {

    protected:
        ParsedVariant() {}

    public:
        virtual ~ParsedVariant() {}

    private:
        ParsedVariant(const ParsedVariant& other);
        ParsedVariant& operator= (const ParsedVariant& other);

    public:
        virtual const std::string& getName() const=0;
        // Get the formal variant.
        virtual BaseVariant *getVariant()=0;

};

}

#endif // PARSEDVARIANT_H_INCLUDED

