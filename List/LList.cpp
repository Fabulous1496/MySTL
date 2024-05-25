#include <iostream>
#include "LList.h"
template<class T>
Node<T>::Node(const T &x, Node *p, Node *n)
{
    item = x;
    prev = p;
    next = n;
}

template<class T>
Node<T>::Node()
{
    prev = NULL;
    next = NULL;
}

template<class T>
LList<T>::LList()
{
    head = Node<T>();
    tail = Node<T>();
    head.next = &tail;
    tail.prev = &head;
    currentSize = 0;
}

template<class T>
Node<T> *LList<T>::move(int index) const
{
    Node<T> *p = head;
    while(index-- >= 0)
    {
        p = p->next;
    }
    return p;
}

template<class T>
void LList<T>::insert(int i, const T &item)
{
    Node<T>* pos,tmp;
    pos = move(i);
    tmp = new Node(item,pos->prev,pos);
    pos->prev->next = tmp;
    pos->prev =tmp;
    currentSize++;
}

template<class T>
void LList<T>::remove(int i)
{
    Node<T>* pos;
    pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    currentSize--;
}

template<class T>
void LList<T>::clear()
{
    Node<T>* pos = head.next;
    while(pos != tail)
    {
        Node<T>* tmp = pos;
        pos = pos->next;
        delete tmp;
    }
    head.next = tail;
    tail.prev = head;
    currentSize = 0;
}

template<class T>
int LList<T>::length() const
{
    return currentSize;
}

template<class T>
int LList<T>::search(const T &item) const
{
    Node<T>* pos = head.next;
    int index = 0;
    while(pos != tail)
    {
        if(pos->item == item)
        {
            return index;
        }
        pos = pos->next;
        index++;
    }
    return -1;
}

template<class T>
T LList<T>::get(int index)
{
    Node<T>* pos = move(index);
    return pos->item;
}

template<class T>
void LList<T>::push_front(const T &item)
{
    Node<T>* tmp = new Node(item,head,head.next);
    head.next = tmp;
    tmp->next->prev = tmp;
    currentSize++;
}

template<class T>
void LList<T>::push_back(const T &item)
{
    Node<T>* tmp = new Node(item,tail.prev,tail);
    tail.prev = tmp;
    tmp->prev->next = tmp;
    currentSize++;
}

template<class T>
void LList<T>::traverse() const
{
    Node<T>* pos = head.next;
    if(pos == tail)
    {
        std::cout << "The List is empty!" << std::endl;
    }
    else
    {
        while(pos->next != tail)
        {
            std:: cout << pos->item << "->" ;
            pos = pos->next;
        }
        std:: cout << pos->item << std::endl;
    }
}

template<class T>
LList<T>::~LList()
{
    clear();
}

template<class T>
LList<T>::LList(const LList &other) : currentSize(0)
{
    head.next = tail;
    tail.prev = head;
    Node<T>* current = other.head.next;
    while (current != &other.tail)
    {
        push_back(current->item);
        current = current->next;
    }
}