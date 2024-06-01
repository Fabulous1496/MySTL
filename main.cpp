#include <iostream>
#include <string>
#include "List/AList.cpp"
#include "List/LList.cpp"
#include "Stack/AStack.cpp"
#include "Stack/LStack.cpp"
#include "Queue/seqQueue.cpp"
#include "Queue/linkQueue.hpp"

void test_AList_01()
{
    AList<int> num = AList<int>();
    for(int i = 0; i < 25; i ++)
    {
        num.push_back(i);
    }
    std::cout << num.search(6) << std::endl;
    num.insert(6,99);
    num.remove(7);
    num.traverse();
}

void test_AList_02()
{
    AList<std::string> str = AList<std::string>();
    str.push_back("hello, world!");
    str.insert(0,"K");
    str.traverse();
}

void test_LList_01()
{
    LList<int> num = LList<int>();
    num.traverse();
    for(int i = 0; i < 5; i++)
    {
        num.push_back(i);
    }
    num.insert(3,100);
    num.push_front(5);
    num.traverse();
}

void test_AStack_01()
{
    AStack<int> num = AStack<int>();
    std::cout << num.isEmpty() << std::endl;
    num.traverse();
    for(int i = 0; i < 10; i ++)
    {
        num.push(i);
    }
    num.traverse();
    num.pop();
    std::cout << num.getTop() << std::endl;
}

void test_LStack_01()
{
    LStack<int> num = LStack<int>();
    num.traverse();
    for(int i = 0; i < 10; i ++)
    {
        num.push(i);
    }
    num.traverse();
    num.pop();
    std::cout << num.getTop() << std::endl;
}

void test_Calculator_01()
{
    char str[] = "3*(11-7)/2";
    Calculator exp (str);
    std::cout << exp.result() << std::endl;
}

void test_seqQueue()
{
    seqQueue<int> num = seqQueue<int>();
    for(int i =1;i<=10;i++)
    {
        num.enQueue(i);
    }
    num.traverse();
}

void test_linkQueue()
{
    linkQueue<int> num = linkQueue<int>();
    for(int i =1;i<=10;i++)
    {
        num.enQueue(i);
    }
    std::cout << num.deQueue() << std::endl;
    num.traverse();
}

int main() {
    //test_AStack_01();
    //test_LList_01();
    //test_Calculator_01();
    test_seqQueue();
    test_linkQueue();
    return 0;
}
