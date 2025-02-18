#include <iostream>
#include <vector>
#include "colors.hpp"
#include <bits/stdc++.h>

std::vector<int> bubbleSort(std::vector<int> unsortedList, std::function<void(std::vector<int>, int)> updateVisualization)
{
    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = 0; j < unsortedList.size() - 1; j++) {
            if (unsortedList[j] > unsortedList[j + 1]) {
                std::swap(unsortedList[j], unsortedList[j + 1]);
                updateVisualization(unsortedList, j + 1);
            }
        }
    }

    return unsortedList;
}

std::vector<int> bubbleSortDetails(std::vector<int> unsortedList, std::function<void(std::vector<int>, int)> updateVisualization)
{
    std::cout << BOLDWHITE << "Bubble Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(n²)\n" << std::endl;

    return bubbleSort(unsortedList, updateVisualization);
}
