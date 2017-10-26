#include "ParsedStack.h"

namespace json {

ParsedStack::ParsedStack() {
}

ParsedStack::ParsedStack(const std::string& n)
: name(n) {
}

ParsedStack::~ParsedStack() {

    while (members.size() > 0) {
        delete members.front();
        members.pop_front();
    }

}

void ParsedStack::push(ParsedVariant *var) {

    members.push_back(var);

}

}

