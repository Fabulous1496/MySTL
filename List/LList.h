#ifndef MYSTL_LLIST_H
#define MYSTL_LLIST_H
#include "List.h"

template<class T>
class LList : list<T>
{
private:
    int currentSize;
    struct node
    {
        T item;
        node* prev, *next;
        node(const T &x, node*p = NULL, node *n = NULL)
        {
            item = x;
            prev = p;
            next = n;
        }
        node():next(NULL),prev(NULL){}
        ~node() {}
    };

    node *head,*tail;
    node* move(int index) const;
public:
    LList();
    LList(const LList &other);
    ~LList();
    void clear();
    int length() const;
    void insert(int i,const T &item);
    void remove(int i);
    int search(const T &item) const;
    T get(int index);
    void traverse() const;
    void push_front(T x);
    void push_back(T x);
};

#endif
