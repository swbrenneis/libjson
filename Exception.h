#ifndef SEJSONEXCEPTION_H_INCLUDED
#define SEJSONEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

#define EXCEPTION_THROW_SPEC noexcept

namespace json {

class Exception  : public std::exception {

    protected:
        Exception();
        Exception(const std::string& msg) : message(msg) {}
        Exception(const Exception& other) : message(other.message) {}

    private:
        Exception& operator= (const Exception& other);

    public:
        virtual ~Exception() EXCEPTION_THROW_SPEC {}

    public:
        virtual const char *what() const EXCEPTION_THROW_SPEC { return message.c_str(); }

    private:
        std::string message;

};

}

#endif // SEJSONEXCEPTION_H_INCLUDED
