#ifndef MYSTL_ASTACK_H
#define MYSTL_ASTACK_H
#include "stack.h"


template<class T>
class AStack : stack<T>
{
private:
    T* data;
    int top;
    int maxSize;
    void resize();
public:
    AStack(int initSize = 10);
    ~AStack();
    bool isEmpty();
    void push(const T& x);
    T pop();
    T getTop() const ;
    void traverse();
};


#endif