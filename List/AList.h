#ifndef MYSTL_ALIST_H
#define MYSTL_ALIST_H
#include "List.h"

template<class T>
class AList : public list<T> {
private:
    T *data;
    int currentSize;
    int maxSize;
    void resize();
public:
    AList(int initSize=10);
    ~AList();
    void clear();
    int length() const;
    void insert(int i, const T &item);
    void remove(int i);
    int search(const T &item) const;
    T get(int index);
    void traverse() const;
    void push_back(const T &item);

};

#endif
