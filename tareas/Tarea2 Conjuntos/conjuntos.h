#include <list>

//Union
std::list<int> AuB( std::list<int>& A, std::list<int>& B)
{
    std::list<int> aub;

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
std::list<int> AnB( std::list<int>& A, std::list<int>& B)
{
   std::list<int> aub;

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
std::list<int> AdB( std::list<int>& A, std::list<int>& B)
{
   std::list<int> aub;

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
