#ifndef MYSTL_LIST_H
#define MYSTL_LIST_H
#include <cstdio>

template<class T>
class list
{
public :
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const T &item) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const T &item) const = 0;
    virtual T get(int index) = 0;
    virtual void traverse() const = 0;
    virtual ~list() {};
};

#endif
