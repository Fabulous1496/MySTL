#ifndef MYSTL_CALCULATOR_H
#define MYSTL_CALCULATOR_H
#include "AStack.h"
#include <string>

class Calculator
{
    char* expression;
    enum token{OPAREN,ADD,SUB,MULTI,DIV,EXP,CPAREN,VALUE,EOL};
    void BinaryOp(token op,AStack<int> &dataStack);
    token getOp(int &value);
public:
    Calculator(char *s)
    {
        expression = new char[strlen(s)+1];
        strcpy(expression,s);
    }
    ~Calculator()
    {
        delete expression;
    }
    int result();
};
#endif
