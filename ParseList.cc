#include "ParseList.h"

namespace json {

ParseList::ParseList() {
}

ParseList::~ParseList() {
}

ParsedVariant *ParseList::pop() {

    if (members.size() > 0) {
        ParsedVariant *var = members.front();
        members.pop_front();
        return var;
    }
    else {
        return 0;
    }

}

}

