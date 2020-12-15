#ifndef _TEST_SORT_H
#define _TEST_SORT_H

#include <functional>
#include <vector>
#include <string>

void testSort(const std::string& desc,
              std::vector<unsigned>& numbers,
              std::function<void(std::vector<unsigned>&)> sort_alg);

#endif