#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> unsortedList)
{
    for (int i = 0; i < unsortedList.size(); i++) {
        for (int j = i; j > 0 && unsortedList[j - 1] > unsortedList[j]; j--) {
            std::swap(unsortedList[j], unsortedList[j - 1]);
        }
    }

    return unsortedList;
}
