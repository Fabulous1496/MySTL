#include "seqQueue.h"
#include <iostream>

template<class T>
seqQueue<T>::seqQueue(int size)
{
    data = new T[size];
    maxSize = size;
    front = rear = 0;
}

template<class T>
seqQueue<T>::~seqQueue()
{
    delete[] data;
}

template<class T>
bool seqQueue<T>::isEmpty() const
{
    return front == rear;
}

template<class T>
void seqQueue<T>::resize()
{
    T *tmp = data;
    data = new T[maxSize*2];
    for(int i = 1; i < maxSize; i++)
    {
        data[i] = tmp[(front+i)%maxSize];
    }
    front = 0, rear = maxSize-1;
    maxSize *= 2;
    delete tmp;
}

template<class T>
void seqQueue<T>::enQueue(const T &x)
{
    if((rear+1)%maxSize == front)
    {
        resize();
    }
    rear = (rear+1)%maxSize;
    data[rear] = x;
}

template<class T>
T seqQueue<T>::deQueue()
{
    front = (front+1)%maxSize;
    return data[front];
}

template<class T>
T seqQueue<T>::getHead() const
{
    return data[(front+1)%maxSize];
}

template<class T>
void seqQueue<T>::traverse() const
{
    if(front == rear)
    {
        std::cout << "The queue is empty!" << std::endl;
    }
    else
    {
        int i = (front+1)%maxSize;
        while(i != rear)
        {
            std::cout << data[i] << " ";
            i = (i+1)%maxSize;
        }
        std::cout << data[i] << std::endl;
    }
}