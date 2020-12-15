#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "sorting_alg.h"
#include "test_sort.h"

using sys_clock = std::chrono::system_clock;
using sys_time = std::chrono::time_point<sys_clock>;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage " << argv[0] << " <input file>\n";
        return 1;
    }
    std::ifstream in(argv[1], std::ios::in);
    if (!in.is_open())
    {
        std::cerr << "Cannot open file " << argv[1] << '\n';
        return 1;
    }

    std::vector<unsigned> numbers_ss(10000);
    std::vector<unsigned> numbers_bs(10000);
    std::vector<unsigned> numbers_is(10000);
    std::vector<unsigned> numbers_qs(10000);
    std::vector<unsigned> numbers_cs(10000);

    sys_time start_time = sys_clock::now();
    in.read(reinterpret_cast<char *>(numbers_ss.data()), numbers_ss.size() * sizeof(char));
    sys_time end_time = sys_clock::now();
    numbers_bs = numbers_ss;
    numbers_is = numbers_ss;
    numbers_qs = numbers_ss;
    numbers_cs = numbers_ss;

    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Load time: " << static_cast<double>(duration.count()) << "us\n";

    in.close();

    testSort("CPP Sort", numbers_cs, cppSort);
    testSort("Selection Sort", numbers_ss, selectionSort);
    testSort("Bubble Sort", numbers_bs, bubbleSort);
    testSort("Insertion Sort", numbers_is, insertionSort);
    testSort("Quick Sort", numbers_qs, quickSort);

    return 0;
}
