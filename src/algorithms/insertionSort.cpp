#include <iostream>
#include <vector>
#include "colors.hpp"

void insertionSortDetails()
{
    std::cout << BOLDWHITE << "Insertion Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;
}

std::vector<int> insertionSort(std::vector<int> unsortedList)
{
    insertionSortDetails();

    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = i; j > 0 && unsortedList[j - 1] > unsortedList[j]; j--) {
            std::swap(unsortedList[j], unsortedList[j - 1]);
        }
    }

    return unsortedList;
}
