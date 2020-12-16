#ifndef _SORT_H
#define _SORT_H

#include <list>
#include <algorithm>
#include <iostream>

// Sort a list using selection sort
template<typename TElem>
void sortList(std::list<TElem>& lst)
{
    typename std::list<TElem>::iterator i1;
    typename std::list<TElem>::iterator i2;
    typename std::list<TElem>::iterator i3;
    TElem max, temp;
    for(i1 = lst.begin(); i1 != lst.end(); i1++)
    {
        temp = max = *i1;
        i2 = i1;
        for(i2 = i1; i2 != lst.end(); i2++) {
            if(*i2 <= max) {
                max = *i2;
                i3 = i2;
            }    
        }
        *i1 = max;
        *i3 = temp;
        temp = max = *i1;
    }
}

#endif
