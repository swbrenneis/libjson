#ifndef VARIANTEXCEPTION_H_INCLUDED
#define VARIANTEXCEPTION_H_INCLUDED

#include "Exception.h"

namespace json {

class VariantException : public Exception {

    protected:
        VariantException() {}

    public:
        VariantException(const std::string& msg)
                : Exception(msg) {}
        VariantException(const VariantException& other)
                : Exception(other) {}
        ~VariantException() {}

    private:
        VariantException& operator= (const VariantException& other);

};

}

#endif // VARIANTEXCEPTION_H_INCLUDED
