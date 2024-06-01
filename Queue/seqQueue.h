#ifndef MYSTL_SEQQUEUE_H
#define MYSTL_SEQQUEUE_H
#include "queue.h"

template<class T>
class seqQueue : queue<T>
{
private:
    T *data;
    int maxSize;
    int front, rear;
    void resize();
public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const T &x);
    T deQueue() ;
    T getHead() const;
    void traverse() const;

};


#endif
