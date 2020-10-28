#include <iostream>
#include "linked_list.h"

int main(int argc, char *argv[])
{
    LinkedList l1;
    std::cout<<"\n";

    l1.pushBack(10);
    l1.pushBack(20);
    l1.pushBack(30);

    l1.print();

    std::cout<<'\n';

    return 0;
}