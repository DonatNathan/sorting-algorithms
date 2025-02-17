#include <iostream>
#include <chrono>
#include <map>
#include "colors.hpp"
#include "utils.cpp"
#include "algorithms/insertionSort.cpp"
#include "algorithms/selectionSort.cpp"
#include "algorithms/bubbleSort.cpp"

enum SortingAlgorithms {
    notDefined,
    insertionSortAlgorithm,
    selectionSortAlgorithm,
    bubbleSortAlgorithm,
};

std::map<std::string, SortingAlgorithms> s_mapSortingAlgorithms;

void InitializeAlgorithms() {
    s_mapSortingAlgorithms["insertion"] = insertionSortAlgorithm;
    s_mapSortingAlgorithms["selection"] = selectionSortAlgorithm;
    s_mapSortingAlgorithms["bubble"] = bubbleSortAlgorithm;
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
        case bubbleSortAlgorithm:
            sortedList = bubbleSort(unsortedList);
            break;
        default:
            std::cout << BOLDRED << "Algorithm \"" << sortingAlgorithm << "\" does not exists" << std::endl;
            break;
    }

    return sortedList;
}

void displayHelp()
{

}

int checkArguments(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    
    if (argv[1] == "--help" || argv[1] == "-h") {
        displayHelp();
    }
}

int main(int argc, char **argv)
{

    if (checkArguments(argc, argv) == 84)
        return 84;

    std::string fileContent = getUnsortedList(argv[2]);
    std::vector<int> unsortedList = stringToVector(fileContent);
    std::vector<int> sortedList;

    auto start = std::chrono::high_resolution_clock::now();
    sortedList = chooseAlgorithm(unsortedList, argv[1]);
    auto stop = std::chrono::high_resolution_clock::now();

    // displayVector(sortedList);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << BOLDGREEN << "List sorted in " << duration.count() << " microseconds" << std::endl;

    return 0;
}