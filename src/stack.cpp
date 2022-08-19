#include "stack.h"

Stack::Stack(){};

VariableType Stack::pop(){
    VariableType value = vector.back();
    vector.pop_back();
    return value;
}

int Stack::size(){
    return vector.size();
}

VariableType Stack::back(){
    return vector.back();
}

