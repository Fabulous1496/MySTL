#include "Calculator.h"
#include <iostream>
#include <cmath>

Calculator::token Calculator::getOp(int &value)
{
    while(*expression && *expression==' ')
    {
        ++expression;
    }
    if(*expression == '\0')
    {
        return EOL;
    }
    if(*expression <= '9' && *expression >= '0')
    {
        value = 0;
        while(*expression >= '0' && *expression <= '9')
        {
            value = value*10 + (*expression - '0');
            expression++;
        }
        return VALUE;
    }

    switch (*expression)
    {
        case '(' :
            expression++;
            return OPAREN;
            break;
        case ')' :
            expression++;
            return CPAREN;
            break;
        case '+' :
            expression++;
            return ADD;
            break;
        case '-' :
            expression++;
            return SUB;
            break;
        case '*' :
            expression++;
            return MULTI;
            break;
        case '/' :
            expression++;
            return DIV;
            break;
        case '^' :
            expression++;
            return EXP;
            break;
    }
}

void Calculator::BinaryOp(token op, AStack<int> &dataStack)
{
    int num1,num2;
    if(dataStack.isEmpty())
    {
        std::cerr << "Lack right operand!" << std::endl;
        exit(1);
    }
    else
    {
        num2 = dataStack.pop();
    }
    if(dataStack.isEmpty())
    {
        std::cerr << "Lack left operand!" << std::endl;
        exit(1);
    }
    else num1 = dataStack.pop();

    switch(op)
    {
        case ADD:
            dataStack.push(num1+num2);
            break;
        case SUB:
            dataStack.push(num1-num2);
            break;
        case MULTI:
            dataStack.push(num1*num2);
            break;
        case DIV:
            dataStack.push(num1/num2);
            break;
        case EXP:
            dataStack.push(pow(num1,num2));
            break;
    }
}

int Calculator::result()
{
    token lastOp,topOp;
    int result_value,current_value;
    AStack<token> opStack;
    AStack<int> dataStack;
    char *str = expression;

    while((lastOp = getOp(current_value))!=EOF)
    {
        switch(lastOp)
        {
            case VALUE:
                dataStack.push(current_value);
                break;
            case CPAREN:
                while(!opStack.isEmpty() && (topOp == opStack.pop())!=OPAREN)
                {
                    BinaryOp(topOp,dataStack);
                }
                if(topOp != OPAREN)
                {
                    std::cerr << "Lack left bracket!" << std::endl;
                }
                break;
            case OPAREN:
                opStack.push(OPAREN);
                break;
            case EXP:
                opStack.push(EXP);
                break;
            case MULTI:
                while(!opStack.isEmpty() && opStack.getTop()>=MULTI)
                {
                    BinaryOp(opStack.pop(),dataStack);
                }
                opStack.push(lastOp);
                break;
            case DIV:
                while(!opStack.isEmpty() && opStack.getTop()>=MULTI)
                {
                    BinaryOp(opStack.pop(),dataStack);
                }
                opStack.push(lastOp);
                break;
            case ADD:
                while(!opStack.isEmpty() && opStack.getTop() != OPAREN)
                {
                    BinaryOp(opStack.pop(), dataStack);
                }
                opStack.push(lastOp);
                break;
            case SUB:
                while(!opStack.isEmpty() && opStack.getTop() != OPAREN)
                {
                    BinaryOp(opStack.pop(), dataStack);
                }
                opStack.push(lastOp);
                break;
        }
    }
    while(!opStack.isEmpty())
    {
        BinaryOp(opStack.pop(),dataStack);
    }
    if(dataStack.isEmpty())
    {
        std::cout << "No output!" << std::endl;
        return 0;
    }
    result_value = dataStack.pop();
    if(!dataStack.isEmpty())
    {
        std::cout << "Lack expressions!" << std::endl;
        return 0;
    }
    expression = str;
    return result_value;
}