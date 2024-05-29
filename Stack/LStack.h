#ifndef MYSTL_LSTACK_H
#define MYSTL_LSTACK_H
#include "stack.h"

template<class T>
class LStack : stack<T>
{
private:
    struct node
    {
        T item;
        node *next;
        node(const T&x,node *N = NULL)
        {
            item = x;
            next = N;
        }
        node():next(NULL) {}
        ~node() {}
    };
    node *top;
public:
    LStack();
    ~LStack();
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T getTop() const;
    void traverse();
};


#endif
