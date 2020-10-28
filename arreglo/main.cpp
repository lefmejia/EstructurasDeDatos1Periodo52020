#include <iostream>
#include "array.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " <element>\n";
        return 1;
    }
    int element = std::strtol(argv[1], nullptr, 10);

    Array<int> arr({59, 13, 46, 9, 33, 55, 15, 79, 92, 6, 46});
    Array<int> arr2(32);
    Array<int> arr3(arr);
    
    arr2 = arr;

    std::cout << "Array 2\n";
    arr2.print();
    std::cout << '\n';

    int idx = arr.find(element);

    if (idx != -1)
        std::cout << element << " is at position " << idx << '\n';
    else
        std::cout << "Cannot find element in array\n";

    int min = arr.findMinIndex(0);
    std::cout << "Minimun is at position " << min << '\n';

    int max = arr.findMaxIndex(0);
    std::cout << "Maximum is at position " << max << '\n';

    std::cout<<"Maximum element is: "<<arr.findMaxElement()<<std::endl;

    //arr.sort();
    arr.insertionSort();
    //arr.print();
    std::cout << arr << '\n';

    std::cout << arr2 << '\n';

    arr3.print();
    std::cout << '\n';
    std::cout << '\n';

    Array<double> arrd({0.4545, 3.14159, 3.12, 0.004});
    Array<std::string> arrs({"juan", "pedro", "maria", "ana"});

    std::cout << "String array\n";
    arrs.insertionSort();
    arrs.print();
    std::cout << '\n';

    std::cout << "Double array\n";
    arrd.sort();
    arrd.print();
    std::cout << '\n';

    return 0;
}
