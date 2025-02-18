#include <iostream>
#include <vector>
#include "colors.hpp"
#include <bits/stdc++.h>

std::vector<int> insertionSort(std::vector<int> unsortedList, std::function<void(std::vector<int>, int)> updateVisualization)
{
    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = i; j > 0 && unsortedList[j - 1] > unsortedList[j]; j--) {
            std::swap(unsortedList[j], unsortedList[j - 1]);
            updateVisualization(unsortedList, j - 1);
        }
    }

    return unsortedList;
}

std::vector<int> insertionSortDetails(std::vector<int> unsortedList, std::function<void(std::vector<int>, int)> updateVisualization)
{
    std::cout << BOLDWHITE << "Insertion Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;

    return insertionSort(unsortedList, updateVisualization);
}
