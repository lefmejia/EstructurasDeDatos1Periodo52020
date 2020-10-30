#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iosfwd>
#include <initializer_list>
#include <string>

template <typename TElem>
class Array
{
public:
    Array(const std::initializer_list<TElem>& init);
    Array(int size);

    Array(const Array& other)
    { copyFrom(other); }

    ~Array()
    { delete [] arr; }

    TElem& operator[](unsigned idx)
    { return arr[idx]; }

    Array& operator=(const Array& rhs);

    std::string toString() const;

    bool isSorted() const;
    void reverse();

    int size() const
    { return size_; }

private:
    void copyFrom(const Array& other);

private:
    int size_;
    TElem *arr;
};

template<typename T>
std::ostream& operator << (std::ostream& out, const Array<T>& arr)
{
    arr.print();
    return out;
}

#include "array.cpp"

#endif
