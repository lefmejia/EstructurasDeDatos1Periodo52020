#include <iostream>
#include <chrono>
#include <algorithm>
#include "test_sort.h"

using sys_clock = std::chrono::system_clock;
using sys_time = std::chrono::time_point<sys_clock>;

void testSort(const std::string& desc,
              std::vector<unsigned>& numbers,
              std::function<void(std::vector<unsigned>&)> sort_alg)
{
    sys_time start_time = sys_clock::now();
    sort_alg(numbers);
    sys_time end_time = sys_clock::now();

    if (!std::is_sorted(numbers.begin(), numbers.end()))
    {
        std::cout << desc << " failed\n";
        return;
    }

    std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    std::cout << desc << " time: " << static_cast<double>(dur.count()) << "ms\n";
}