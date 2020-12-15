#include "sorting_alg.h"
#include <algorithm>

void recQuick(std::vector<unsigned>& numbers, int lo, int hi)
{
    int i = lo; 
    int j = hi;
    int temp;
    int pivot = numbers[(lo + hi) / 2];

    while (i <= j) 
    {
        while (numbers[i] < pivot)
                i++;
        while (numbers[j] > pivot)
                j--;

        if (i <= j) 
        {
            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            i++;
            j--;
        }
    }
    if (lo < j)
        recQuick(numbers, lo, j);
    if (i < hi)
        recQuick(numbers, i, hi);
}

void quickSort(std::vector<unsigned>& numbers)
{
    recQuick(numbers, 0, numbers.size()-1);
}

void selectionSort(std::vector<unsigned>& numbers)
{
    for (int i = 0; i < numbers.size()-1; i++)
    {
        int max = i;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] < numbers[max])
                max = j;
        }

        int idx = max;
        int temp = numbers[i];
        numbers[i] = numbers[idx];
        numbers[idx] = temp;
    }
}
void insertionSort(std::vector<unsigned>& numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
       int j = i;

        while(j>0 && numbers[j-1] > numbers[j])
        {
            int temp = numbers[j-1];
            numbers[j-1] = numbers[j];
            numbers[j] = temp;

            j--;
        }
    }
}
void bubbleSort(std::vector<unsigned>& numbers)
{
    for(int i = 0; i<numbers.size()-1; i++)
    {
        for(int j = 0; j<numbers.size()-i-1; j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            } 
        }
    }
}
void cppSort(std::vector<unsigned>& numbers)
{
    std::sort(numbers.begin(), numbers.end());
}