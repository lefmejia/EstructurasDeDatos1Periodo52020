#include <vector>
#include <iostream>

using namespace std;

vector<int> insertionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
       int j = i;

        while(j>0 && arr[j-1] > arr[j])
        {
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }

    return arr;
}

vector<int> selectionSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int max = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[max])
                max = j;
        }

        int idx = max;
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
    }

    return arr;
}

vector<int> bubbleSort(vector<int> arr)
{
    for(int i = 0; i<arr.size()-1; i++)
    {
        for(int j = 0; j<arr.size()-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }

    return arr;
}

int partition(vector<int> &arr, int lo, int hi)
{
    // int pivot = arr[(hi - lo)/2];
    // int i = lo -1;
    // int j = hi + 1;

    // while(true)
    // {
    //     do{
    //         i++;
    //     }while(arr[i]<pivot);

    //     do{
    //         j--;
    //     }while(arr[j]>pivot);

    //     if(i>=j)
    //         return j;

    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;

    // }

    int pivot = arr[(hi - lo)/2];
    int i = lo;
    int j = hi;

   while(i < j)
   {
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] >= pivot);

        if(i < j)
            std::swap(arr[i], arr[j]);
   }

   return pivot;
}

void quickSort(vector<int> &arr, int lo, int hi)
{
    int i = lo; 
    int j = hi;
    int temp;
    int pivot = arr[(lo + hi) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
                i++;
        while (arr[j] > pivot)
                j--;

        if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
        }
    };
    if (lo < j)
        quickSort(arr, lo, j);
    if (i < hi)
        quickSort(arr, i, hi);
}

bool isSorted(vector<int> arr)
{
    for(int i=1; i< arr.size(); i++)
    {
        if(arr[i-1]>arr[i])
        {
            return false;
        }
    }

    return true;
}

void print(vector<int> arr)
{
    cout<< "{ ";
    for(int n: arr)
    {
        cout<< n << ", ";
    }

    cout<< "} \n";
}

int main()
{
    vector<int> arr = {12, 34, 10, 6, 40, 11, 9, 2, 18, 29, 42, 15};
    quickSort(arr, 0, arr.size()-1);

    print(arr);

    if(isSorted(arr))
        cout<<"En orden\n";
    else
    {
        cout<<"No ordenado\n";
    }
    

    return 0;
}