#include <iostream>
#include <string>
#include "List/AList.cpp"
#include "List/LList.cpp"
#include "Stack/AStack.cpp"
#include "Stack/LStack.cpp"
#include "Stack/Calculator.cpp"

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

//void test_calc_01()
//{
//    Calculator exp("3*(11-7)/6");
//    std::cout << exp.result() << std::endl;
//}
int main() {
    //test_AStack_01();
    test_LList_01();
    test_AStack_01();
    //test_calc_01();
    return 0;
}
