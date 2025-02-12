#include <iostream>
#include <chrono>
#include <map>
#include "colors.hpp"
#include "utils.cpp"
#include "algorithms/insertionSort.cpp"
#include "algorithms/selectionSort.cpp"

enum SortingAlgorithms {
    insertionSortAlgorithm,
    selectionSortAlgorithm,
};

std::map<std::string, SortingAlgorithms> s_mapSortingAlgorithms;

void InitializeAlgorithms() {
    s_mapSortingAlgorithms["insertion"] = insertionSortAlgorithm;
    s_mapSortingAlgorithms["selection"] = selectionSortAlgorithm;
}

std::vector<int> chooseAlgorithm(std::vector<int> unsortedList, std::string sortingAlgorithm)
{
    std::vector<int> sortedList;

    InitializeAlgorithms();

    switch (s_mapSortingAlgorithms[sortingAlgorithm]) {
        case insertionSortAlgorithm:
            sortedList = insertionSort(unsortedList);
            break;
        case selectionSortAlgorithm:
            sortedList = selectionSort(unsortedList);
            break;
        default:
            break;
    }

    return sortedList;
}

int main(int argc, char **argv)
{
    std::string fileContent = getUnsortedList(argv[2]);
    std::vector<int> unsortedList = stringToVector(fileContent);
    std::vector<int> sortedList;

    auto start = std::chrono::high_resolution_clock::now();
    sortedList = chooseAlgorithm(unsortedList, argv[1]);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << BOLDGREEN << "List sorted in " << duration.count() << " microseconds" << std::endl;

    return 0;
}