#include "AList.h"
#include<iostream>

template<class T>
AList<T>::AList(int initSize): currentSize(0), maxSize(initSize)
{
    data = new T[initSize];
}

template<class T>
void AList<T>::resize()
{
    T *tmp = data;
    maxSize *= 2;
    data = new T [maxSize];
    for(int i = 0; i < currentSize; i ++)
    {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

template<class T>
void AList<T>::clear()
{
    currentSize = 0;
}

template<class T>
int AList<T>::length() const
{
    return currentSize;
}

template<class T>
T AList<T>::get(int index)
{
    return data[index];
}

template<class T>
void AList<T>::traverse() const
{
    for(int i = 0; i < currentSize; i ++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
int AList<T>::search(const T &item) const
{
    for(int i = 0; i < currentSize ; ++i)
    {
        if(data[i] == item)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
void AList<T>::insert(int i, const T &item)
{
    if(currentSize == maxSize)
    {
        resize();
    }
    for(int j = currentSize; j > i ; j--)
    {
        data[j] = data[j-1];
    }
    data[i] = item;
    currentSize += 1;
}

template<class T>
void AList<T>::remove(int i)
{
    for(int j = i; j < currentSize - 1; j ++)
    {
        data[j] = data[j+1];
    }
    currentSize -= 1;
}

template<class T>
AList<T>::~AList()
{
    delete[] data;
}

template<class T>
void AList<T>::push_back(const T &item)
{
    if(currentSize == maxSize)
    {
        resize();
    }
    data[currentSize] = item;
    currentSize++;
}