#ifndef MYSTL_LINKQUEUE_HPP
#define MYSTL_LINKQUEUE_HPP
#include "queue.h"
#include<cstdio>
#include <iostream>

template<class T>
class linkQueue : queue<T>
{
private:
    struct node
    {
        T item;
        node *next;
        node(const T &x,node *n = NULL)
        {
            item = x;
            next = n;
        }
        node():next(NULL) {}
        ~node() {}
    };
    node *front, *rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    void enQueue(const T &x);
    T deQueue();
    T getHead() const;
    void traverse() const;
};

template<class T>
linkQueue<T>::linkQueue()
{
    front = rear = NULL;
}

template<class T>
linkQueue<T>::~linkQueue()
{
    node *tmp;
    while(front != NULL)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class T>
bool linkQueue<T>::isEmpty() const
{
    return front == NULL;
}

template<class T>
void linkQueue<T>::enQueue(const T &x)
{
    if(rear == NULL)
    {
        front = rear = new node(x);
    }
    else
    {
        rear = rear->next = new node(x);
    }
}

template<class T>
T linkQueue<T>::deQueue()
{
    node *tmp = front;
    T val = tmp->item;
    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    delete tmp;
    return val;
}

template<class T>
T linkQueue<T>::getHead() const
{
    return front->item;
}

template<class T>
void linkQueue<T>::traverse() const
{
    if(front == NULL)
    {
        std::cout << "The queue is empty!" << std::endl;
    }
    else
    {
        node *pos = front;
        while(pos != rear)
        {
            std::cout << pos->item << "->";
            pos = pos->next;
        }
        std::cout << pos->item << std::endl;
    }
}

#endif
