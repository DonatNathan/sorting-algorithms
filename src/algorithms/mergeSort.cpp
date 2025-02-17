#include <iostream>
#include <vector>
#include "colors.hpp"

std::vector<int> merge(std::vector<int> begin, std::vector<int> end)
{
    std::vector<int> sortedList;

    while (begin.size() > 0 && end.size() > 0) {
        if (begin[0] > end[0]) {
            sortedList.push_back(end[0]);
            end.erase(end.begin());
        } else {
            sortedList.push_back(begin[0]);
            begin.erase(begin.begin());
        }
    }

    while (begin.size() > 0) {
        sortedList.push_back(begin[0]);
        begin.erase(begin.begin());
    }

    while (end.size() > 0) {
        sortedList.push_back(end[0]);
        end.erase(end.begin());
    }

    return sortedList;
}

std::vector<int> mergeSort(std::vector<int> unsortedList)
{
    if (unsortedList.size() == 1)
        return unsortedList;

    std::vector<int> begin(unsortedList.begin(), unsortedList.begin() + unsortedList.size() / 2);
    std::vector<int> end(unsortedList.begin() + unsortedList.size() / 2, unsortedList.end());

    begin = mergeSort(begin);
    end = mergeSort(end);

    return merge(begin, end);
}

std::vector<int> mergeSortDetails(std::vector<int> unsortedList)
{
    std::cout << BOLDWHITE << "Merge Sort algorithm:" << std::endl;
    std::cout << " - Complexity: O(nlog(n))\n" << std::endl;

    return mergeSort(unsortedList);
}