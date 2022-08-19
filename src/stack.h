#pragma once

#include <vector>

#include <variableType.h>

class Stack{
private:
    std::vector<VariableType> vector; 
public:
    Stack();

    VariableType pop();
    int size();
    void push(VariableType var);
    VariableType back();
    std::vector<VariableType> data() {return vector;};
};