#include "AStack.h"
#include<iostream>

template<class T>
void AStack<T>::resize()
{
    maxSize *= 2;
    T* tmp = data;
    data = new T[maxSize];
    for(int i = 00; i <= top; i++)
    {
        data[i] = tmp[i];
    }
    delete tmp;
}

template<class T>
AStack<T>::AStack(int initSize)
{
    maxSize = initSize;
    data = new T[initSize];
    top = -1;
}

template<class T>
AStack<T>::~AStack()
{
    delete[] data;
}

template<class T>
bool AStack<T>::isEmpty() const
{
    return top==-1;
}

template<class T>
void AStack<T>::push(const T &x)
{
    if(top == maxSize-1)
    {
        resize();
    }
    data[++top] = x;
}

template<class T>
T AStack<T>::pop()
{
    return data[top--];
}

template<class T>
T AStack<T>::getTop() const
{
    return data[top];
}

template<class T>
void AStack<T>::traverse()
{
    if (this->isEmpty())
    {
        std::cout << "The Stack is empty!" << std::endl;
    }
    else
    {
        for(int i = 0; i<= top; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
}

#include "Calculator.h"
// 显式实例化 AStack<Calculator::token>
template class AStack<Calculator::token>;
