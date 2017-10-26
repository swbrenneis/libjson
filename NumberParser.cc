#include "NumberParser.h"
#include "ParseException.h"
#include "ParsedScalar.h"
#include "IntegerVariant.h"
#include "LongVariant.h"
#include "DoubleVariant.h"

namespace json {

static const std::string NUMBERS("01234567890");
static const std::string WHITESPACE(" \t\r\n");
static const int INT_MAX = 0x7fffffff;

//NumberParser::NumberParser()
//: numberStarted(false) {
//}

NumberParser::NumberParser(const std::string& name)
: ValueParser(name),
  numberStarted(false) {
}

NumberParser::~NumberParser() {
}

void NumberParser::endOfDouble(double integerPart) {

    std::istringstream dstr(doubleCollector.str());
    double decimal;
    dstr >> decimal;
    decimal += integerPart;
    variant = new ParsedScalar<double, DoubleVariant>(decimal, name);

}

void NumberParser::endOfLong() {

    std::istringstream istr(longCollector.str());
    long longvalue;
    istr >> longvalue;
    long longabs = std::abs(longvalue);
    if (longabs <= INT_MAX) {
        variant = new ParsedScalar<int, IntegerVariant>(longvalue, name);
    }
    else {
        variant = new ParsedScalar<long, LongVariant>(longvalue, name);
    }

}

void NumberParser::parse(std::istream& in) {

    char c = chomp(in);

    if (NUMBERS.find(c) != std::string::npos) {
        numberStarted = true;
        longCollector << c;
        parse(in);
    }
    else if ((c == '+' || c == '-') & !numberStarted) {
        doubleCollector << c;
        longCollector << c;
        numberStarted = true;
        parse(in);
    }
    else if (c == '.') {
        numberStarted = true;
        doubleCollector << c;
        std::istringstream lstr(longCollector.str());
        long longvalue;
        lstr >> longvalue;
        parseDouble(longvalue, in);
    }

    if (!valueEnded) {
        if (endOfValue(c, in)) {
            endOfLong();
        }
        else {
            std::ostringstream estr;
            estr << "Unexpected '" << c << "' after long value";
            throw ParseException(estr.str());
        }
    }

}

void NumberParser::parseDouble(double d, std::istream& in) {

    char c = chomp(in);
    if (NUMBERS.find(c) != std::string::npos) {
        doubleCollector << c;
        parseDouble(d, in);
    }

    if (!valueEnded) {
        if (endOfValue(c, in)) {
            endOfDouble(d);
        }
        else {
            std::ostringstream estr;
            estr << "Unexpected '" << c << "' after double value";
            throw ParseException(estr.str());
        }
    }

}

}

