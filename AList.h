#ifndef MYSTL_ALIST_HPP
#define MYSTL_ALIST_HPP
#include "List.h"

template<class T>
class Alist : public list<T> {
private:
    T *items;
    int currentSize;
    int maxSize;
    void resize();
public:
    Alist(){};
    ~Alist(){};

};

#endif
