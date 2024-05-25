#ifndef MYSTL_LLIST_H
#define MYSTL_LLIST_H
#include "List.h"

template<class T>
class Node
{
public:
    T item;
    Node *prev;
    Node *next;
    Node(const T &x, Node *p = NULL, Node *n = NULL);
    Node();
    ~Node() {};
};



template<class T>
class LList : list<T>
{
public:
    int currentSize;
    Node<T> head,tail;
    Node<T>* move(int index) const;
public:
    LList();
    LList(const LList &other);
    ~LList();
    void clear();
    int length() const;
    void insert(int i, const T &item);
    void remove(int i);
    int search(const T &item) const;
    T get(int index);
    void traverse() const;
    void push_front(const T &item);
    void push_back(const T &item);
};

#endif
