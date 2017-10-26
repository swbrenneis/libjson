#ifndef PARSEEXCEPTION_H_INCLUDED
#define PARSEEXCEPTION_H_INCLUDED

#include "Exception.h"

namespace json {

class ParseException : public Exception {

    protected:
        ParseException() {}

    public:
        ParseException(const std::string& msg)
                : Exception(msg) {}
        ParseException(const ParseException& other)
                : Exception(other) {}
        ~ParseException() {}

    private:
        ParseException& operator= (const ParseException& other);

};

}

#endif // PARSEEXCEPTION_H_INCLUDED
