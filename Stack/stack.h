#ifndef MYSTL_STACK_H
#define MYSTL_STACK_H

template<class T>
class stack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const T &x) = 0;
    virtual T pop() = 0;
    virtual T getTop() const = 0;
    virtual ~stack() {};
};

#endif
