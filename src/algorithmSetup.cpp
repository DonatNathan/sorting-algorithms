#include "algorithms/insertionSort.cpp"
#include "algorithms/selectionSort.cpp"
#include "algorithms/bubbleSort.cpp"
#include "algorithms/mergeSort.cpp"
#include "colors.hpp"

enum SortingAlgorithms {
    notDefined,
    insertionSortAlgorithm,
    selectionSortAlgorithm,
    bubbleSortAlgorithm,
    mergeSortAlgorithm,
};

std::map<std::string, SortingAlgorithms> s_mapSortingAlgorithms;

void InitializeAlgorithms() {
    s_mapSortingAlgorithms["insertion"] = insertionSortAlgorithm;
    s_mapSortingAlgorithms["selection"] = selectionSortAlgorithm;
    s_mapSortingAlgorithms["bubble"] = bubbleSortAlgorithm;
    s_mapSortingAlgorithms["merge"] = mergeSortAlgorithm;
}

std::vector<int> chooseAlgorithm(std::vector<int> unsortedList, std::string sortingAlgorithm, std::function<void(std::vector<int>, int)> updateVisualization)
{
    std::vector<int> sortedList;

    InitializeAlgorithms();

    switch (s_mapSortingAlgorithms[sortingAlgorithm]) {
        case insertionSortAlgorithm:
            sortedList = insertionSortDetails(unsortedList, updateVisualization);
            break;
        case selectionSortAlgorithm:
            sortedList = selectionSortDetails(unsortedList, updateVisualization);
            break;
        case bubbleSortAlgorithm:
            sortedList = bubbleSortDetails(unsortedList, updateVisualization);
            break;
        case mergeSortAlgorithm:
            sortedList = mergeSortDetails(unsortedList, updateVisualization);
            break;
        default:
            std::cout << BOLDRED << "Algorithm \"" << sortingAlgorithm << "\" does not exists" << RESET << std::endl;
            exit(84);
    }

    return sortedList;
}
