#ifndef MYSTL_QUEUE_H
#define MYSTL_QUEUE_H

template <class T>
class queue
{
public:
    virtual bool isEmpty() const = 0;
    virtual void enQueue(const T &x) = 0;
    virtual T deQueue() = 0;
    virtual T getHead() const = 0;
    virtual ~queue() {}
};

#endif
