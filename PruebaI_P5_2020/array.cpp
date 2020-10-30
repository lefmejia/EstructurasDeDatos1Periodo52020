#include <sstream>
#include "array.h"

template<typename TElem>
Array<TElem>::Array(const std::initializer_list<TElem>& init)
: size_ (init.size())
{
    arr = new TElem[size_];

    int index = 0;
    for (auto elem : init)
    {
        arr[index++] = elem;
    }
}

template<typename TElem>
Array<TElem>::Array(int size)
: size_ (size)
{
    arr = new TElem[size_];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

template <typename TElem>
void Array<TElem>::copyFrom(const Array& other)
{
    size_ = other.size_;
    arr = new TElem[size_];

    for (int i = 0; i < size_; i++)
    {
        arr[i] = other.arr[i];
    }
}

template<typename TElem>
Array<TElem>& Array<TElem>::operator=(const Array<TElem>& rhs)
{
    delete [] arr;

    copyFrom(rhs);
    return *this;
}

template<typename TElem>
std::string Array<TElem>::toString() const
{
    std::ostringstream out;

    out << "[";
    bool first = true;

    for (int i = 0; i < size_; i++)
    {
        if (first) first = false;
        else out << ",";

        out << arr[i];
    }
    out << "]";

    return out.str();
}

template<typename TElem>
bool Array<TElem>::isSorted() const
{
    for(int i = 1; i < size(); i++)
    {
        if(arr[i]<arr[i-1])
        break;
        else if(i==size()-1)
        return true;
        
    }

    return false;
}

template<typename TElem>
void Array<TElem>::reverse()
{
    Array newarr(size());
    TElem *arr2 = new TElem[size()];

    for(int i = 0; i<size(); i++)
    {
        arr2[i] = arr[size()-1-i];
    }

    arr = arr2;
    
}