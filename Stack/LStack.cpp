#include <iostream>
#include "LStack.h"

template<class T>
LStack<T>::LStack()
{
    top = NULL;
}

template<class T>
LStack<T>::~LStack()
{
    node *tmp;
    while(top != NULL)
    {
        tmp = top;
        top = top->next;
        delete tmp;
    }
}

template<class T>
bool LStack<T>::isEmpty() const
{
    return top == NULL;
}

template<class T>
void LStack<T>::push(const T &x)
{
    top = new node(x,top);
}

template<class T>
T LStack<T>::pop()
{
    node* tmp = top;
    T x = top->item;
    top = top->next;
    delete tmp;
    return x;
}

template<class T>
T LStack<T>::getTop() const
{
    return top->item;
}

template<class T>
void LStack<T>::traverse()
{
    if(top == NULL)
    {
        std::cout << "This stack is empty!" << std::endl;
    }
    else
    {
        node *pos = top;
        while(pos != NULL)
        {
            std::cout <<  pos->item << " ";
            pos = pos->next;
        }
        std::cout << std::endl;
    }
}