#include <iostream>
#include <string>
#include "List/List.h"
#include "List/AList.h"
#include "List/AList.cpp"

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


int main() {
    test_AList_01();
    test_AList_02();

    return 0;
}
