#ifndef MYSTL_LLIST_H
#define MYSTL_LLIST_H
#include "List.h"

template<class T>
class LList : list<T>
{
private:
    int currentSize;
    class Node
    {
        T item;
        Node *prev;
        Node *next;
        Node(const T &x, Node *p = NULL, Node *n = NULL)
        {
            item = x;
            prev = p;
            next = n;
        }
        Node():prev(NULL), next(NULL) {};
        ~Node() {};
    };
    Node head,tail;
    Node* move(int index) const;
public:
    LList();
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
