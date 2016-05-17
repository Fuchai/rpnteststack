#include "stack.h"
#include <iostream>
#define debug

EmptyStackException::EmptyStackException(string message) {
    msg = message;
}

string EmptyStackException::getMessage() {
    return msg;
}