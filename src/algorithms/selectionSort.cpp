#include <iostream>
#include <vector>
#include "colors.hpp"

void selectionSortDetails()
{
    std::cout << BOLDWHITE << "Selection Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;
}

std::vector<int> selectionSort(std::vector<int> unsortedList)
{
    selectionSortDetails();

    for (int i = 0; i < unsortedList.size(); i++) {
        int min = i;
        for (int j = i + 1; j < unsortedList.size(); j++)
            if (unsortedList[j] < unsortedList[min])
                min = j;
        if (min != i)
            std::swap(unsortedList[i], unsortedList[min]);
    }

    return unsortedList;
}
