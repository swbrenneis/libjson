#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include <string>
#include <iostream>

namespace coder {
    class ByteArray;
}

namespace json {

class Object;
class Array;
class Variant;
class BaseVariant;

class Document {

    protected:
        Document(BaseVariant *v);

    public:
        ~Document();

    private:
        Document(const Document& other);
        Document& operator= (const Document& other);

    public:
        static Document *fromJson(const coder::ByteArray& json);
        static Document *fromJson(const std::string& json);
        static Document *fromStream(std::istream& in);

        Array getArray();
        Object getObject();
        Variant getVariant();

    private:
        BaseVariant *variant;

};

}

#endif // DOCUMENT_H_INCLUDED

