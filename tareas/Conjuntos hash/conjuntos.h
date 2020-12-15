#include <unordered_set>
#include <iostream>

void print(std::unordered_set<int>& list)
{
    bool first = true;

    std::cout<<"{ ";
    for(auto n: list)
    {
        if(first) first = false;
        else std::cout<<", ";

        std::cout<<n;
    }
    std::cout<<" }\n";
}

//Union
std::unordered_set<int> AuB(std::unordered_set<int>& A, std::unordered_set<int>& B)
{
    std::unordered_set<int> nuevo;

    for(auto n: A)
    {
        nuevo.insert(n);
    }

    bool included = false;
    for(auto n: B)
    {
        for(auto m: nuevo)
        {
            if(n==m)
            {
                included = true;
                break;
            }
        }
        if(!included)
            nuevo.insert(n);
        included = false;
    }

    return nuevo;
}

//Interseccion
std::unordered_set<int> AnB(std::unordered_set<int>& A, std::unordered_set<int>& B)
{
    std::unordered_set<int> nuevo;

    for(auto n: A)
    {
      for(auto m: B)
      {
          if(n==m)
          {
            nuevo.insert(n);
            break;
          }
      }
    }

    return nuevo;
}


//Diferencia
std::unordered_set<int> AdB(std::unordered_set<int>& A, std::unordered_set<int>& B)
{
    std::unordered_set<int> nuevo;

    bool included = false;

    for(auto n: A)
    {
        for(auto m: B)
        {
            if(n==m)
            {
                included = true;
                break;
            }
        }
        if(!included)
            nuevo.insert(n);
        included = false;
    }

    return nuevo;
}