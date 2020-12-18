#include <list>
#include <algorithm>

//Union
template<typename TElem>
std::list<TElem> AuB( std::list<TElem>& A, std::list<TElem>& B)
{
    std::list<TElem> aub;

    for(auto n: A)
    {
        aub.push_back(n);
    }

    bool included = false;

    for(auto n: B)
    {
        for(auto m: aub)
        {
            if(n==m)
            {
                included = true;
                break;
            }
        }
        if(!included)
            aub.push_back(n);
        included = false;
    }

    return aub;
}

//Interseccion
template<typename TElem>
std::list<TElem> AnB( std::list<TElem>& A, std::list<TElem>& B)
{
   std::list<TElem> aub;

    for(auto n: A)
    {
      for(auto m: B)
      {
          if(n==m)
            aub.push_back(n);
      }
    }

    return aub;
}

//Diferencia
template<typename TElem>
std::list<TElem> AdB( std::list<TElem>& A, std::list<TElem>& B)
{
   std::list<TElem> aub;

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
            aub.push_back(n);
        included = false;
    }

    return aub;
}


template<typename TElem>
bool find(TElem elem, std::list<TElem>& A)
{
    for(auto n: A)
    {
        if(n==elem)
            return true;
    }

    return false;
}

template<typename TElem>
void borrar(TElem elem, std::list<TElem>& A)
{

    auto it = A.begin();

    for(auto i = A.begin(); i!=A.end(); i++)
    {
        if(*i == elem)
            it = i;
    }

    A.erase(it);

}