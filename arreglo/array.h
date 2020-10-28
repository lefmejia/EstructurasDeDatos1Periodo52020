#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <initializer_list>
#include <iosfwd>
template <typename TElem>
class Array
{
public:
    Array(const std::initializer_list<TElem>& init);
    Array(int size);
    Array(const Array<TElem> &arr2);

    ~Array()
    { delete [] arr; }

    TElem& operator[](unsigned idx)
    { return arr[idx]; }

    Array& operator=(const Array& rhs);

    void print() const;
    int find(TElem element);
    int findMinIndex(int pos);
    int findMaxIndex(int pos);

    TElem findMinElement()
    { return arr[findMinIndex(0)]; }
    
    TElem findMaxElement()
    { return arr[findMaxIndex(0)]; }

    void sort();
    void insertionSort();
    int size()
    { return size_; }

private:
    int size_;
    TElem *arr;
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Array<T> arr)
{
    arr.print();
    return out;
}

#include "array.cpp"

#endif
