#include "conjuntos.h"
#include <iostream>


int main()
{
    std::list<int> A = {2, 6, 4, 7};
    std::list<int> B = {2, 3, 5, 7};

    std::list<int> l1 = AuB(A,B);
    std::list<int> l2 = AnB(A,B);
    std::list<int> l3 = AdB(A,B);

    l1.sort();
    l2.sort();
    l3.sort();

    bool first=true;

    if(find(2, A))
        std::cout<<"Elemento encontrado\n";
    else
        std::cout<<"Elemento no encontrado\n";

    borrar(7, A);

    std::cout<< "Lista A: {";

    for(auto n: A)
    {
        if(first) first = false;
        else std::cout<< ", ";

        std::cout<< n;
    }
    std::cout<<"} \n";
    first = true;
    std::cout<< "Lista B: {";

    for(auto n: B)
    {
        if(first) first = false;
        else std::cout<< ", ";

        std::cout<< n;
    }
    std::cout<<"} \n";
    first = true;
    std::cout<< "Union de A y B: {";

    for(auto n: l1)
    {
        if(first) first = false;
        else std::cout<< ", ";

        std::cout<< n;
    }

    std::cout<<"} \n";

    first = true;
    std::cout<< "Interseccion de A y B: {";

    for(auto n: l2)
    {
        if(first) first = false;
        else std::cout<< ", ";

        std::cout<< n;
    }

    std::cout<<"} \n";
    
    first = true;
    std::cout<< "Diferencia de A y B: {";

    for(auto n: l3)
    {
        if(first) first = false;
        else std::cout<< ", ";

        std::cout<< n;
    }

    std::cout<<"} \n";

}