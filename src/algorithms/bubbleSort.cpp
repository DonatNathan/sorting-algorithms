#include <iostream>
#include <vector>
#include "colors.hpp"

void bubbleSortDetails()
{
    std::cout << BOLDWHITE << "Bubble Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;
}

std::vector<int> bubbleSort(std::vector<int> unsortedList)
{
    bubbleSortDetails();

    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = 0; j < unsortedList.size() - 1; j++)
            if (unsortedList[j] > unsortedList[j + 1])
                std::swap(unsortedList[j], unsortedList[j + 1]);
    }

    return unsortedList;
}
