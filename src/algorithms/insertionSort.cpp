#include <iostream>
#include <vector>
#include "colors.hpp"

std::vector<int> insertionSort(std::vector<int> unsortedList)
{
    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = i; j > 0 && unsortedList[j - 1] > unsortedList[j]; j--)
            std::swap(unsortedList[j], unsortedList[j - 1]);
    }

    return unsortedList;
}

std::vector<int> insertionSortDetails(std::vector<int> unsortedList)
{
    std::cout << BOLDWHITE << "Insertion Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;

    return insertionSort(unsortedList);
}
