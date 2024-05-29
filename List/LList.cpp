#include <iostream>
#include "LList.h"

template<class T>
LList<T>::LList()
{
    head = new node;
    tail = new node;
    head->next = tail;
    tail->prev = head;
    currentSize = 0;
}

template<class T>
typename LList<T>::node* LList<T>::move(int index) const
{
    node *p = head;
    while(index-- >= 0)
    {
        p = p->next;
    }
    return p;
}

template<class T>
void LList<T>::insert(int i,const T &item)
{
    node *pos,*tmp;
    pos = move(i);
    tmp = new node(item,pos->prev,pos);
    pos->prev->next = tmp;
    pos->prev =tmp;
    currentSize++;
}

template<class T>
void LList<T>::remove(int i)
{
    node* pos;
    pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    currentSize--;
}

template<class T>
void LList<T>::clear()
{
    node* pos = head->next;
    while(pos != tail)
    {
        node* tmp = pos;
        pos = pos->next;
        delete tmp;
    }
    head->next = tail;
    tail->prev = head;
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
    node* pos = head->next;
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
    node* pos = move(index);
    return pos->item;
}

template<class T>
void LList<T>::push_front(T x)
{
    node* tmp = new node(x,head,head->next);
    head->next = tmp;
    tmp->next->prev = tmp;
    currentSize++;
}

template<class T>
void LList<T>::push_back(T x)
{
    node* tmp = new node(x,tail->prev,tail);
    tail->prev = tmp;
    tmp->prev->next = tmp;
    currentSize++;
}

template<class T>
void LList<T>::traverse() const
{
    node* pos = head->next;
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
    head->next = tail;
    tail->prev = head;
    node* current = other.head.next;
    while (current != &other.tail)
    {
        push_back(current->item);
        current = current->next;
    }
}
