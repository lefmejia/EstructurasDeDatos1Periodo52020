#include <iostream>
#include "linked_list.h"

int main(int argc, char *argv[])
{
    LinkedList l1;
    std::cout<<"\n";

    l1.pushBack(10);
    l1.pushBack(20);
    l1.pushBack(30);
    l1.pushBack(40);
    l1.pushBack(50);

    std::cout << l1 <<'\n';

    std::cout<<"Max element: "<< l1.findMax() << "\n\n";
    std::cout<<"Min element: "<< l1.findMin() << "\n\n";

    int elem = 30;

    if(l1.find(elem)->data==elem)
    {
        std::cout<<"Elemento encontrado\n\n";
    }
    else
    {
        std::cout<<"Elemento no encontrado \n\n";
    }

    LinkedList l2(l1);

    std::cout<<l2<<'\n';

    l1.reverse();

    std::cout<<l1<<'\n';
    
    return 0;
}