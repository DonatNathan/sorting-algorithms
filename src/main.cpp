#include <iostream>
#include <chrono>
#include <map>
#include "colors.hpp"
#include "utils.cpp"
#include "algorithms/insertionSort.cpp"
#include "algorithms/selectionSort.cpp"
#include "algorithms/bubbleSort.cpp"
#include "algorithms/mergeSort.cpp"

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

std::vector<int> chooseAlgorithm(std::vector<int> unsortedList, std::string sortingAlgorithm)
{
    std::vector<int> sortedList;

    InitializeAlgorithms();

    switch (s_mapSortingAlgorithms[sortingAlgorithm]) {
        case insertionSortAlgorithm:
            sortedList = insertionSortDetails(unsortedList);
            break;
        case selectionSortAlgorithm:
            sortedList = selectionSortDetails(unsortedList);
            break;
        case bubbleSortAlgorithm:
            sortedList = bubbleSortDetails(unsortedList);
            break;
        case mergeSortAlgorithm:
            sortedList = mergeSortDetails(unsortedList);
            break;
        default:
            std::cout << BOLDRED << "Algorithm \"" << sortingAlgorithm << "\" does not exists" << RESET << std::endl;
            exit(84);
    }

    return sortedList;
}

void displayHelp()
{
    std::cout << BOLDWHITE << "--- Help Sorting Algorithms ---\n" << RESET << std::endl;
    std::cout << "Description: \n> Algortithm that take a file filled by unsorted number and sort them using different algorithms.\n" << std::endl;
    std::cout << "Usage: \n> ./sort [algorithm_name] [file_path]\n" << std::endl;
    std::cout << "Valid algorithm names: \n- insertion\n- selection\n- bubble\n- merge\n" << std::endl;
    std::cout << BOLDGREEN << "Output: \n> Sorted list is write in the sortedNumbers.txt file in the build directory.\n" << RESET << std::endl;
}

int checkArguments(int argc, char **argv)
{
    if (std::string (argv[1]) == "--help" || std::string (argv[1]) == "-h") {
        displayHelp();
    }

    if (argc < 3)
        return 84;
    
    return 0;
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

    writeOutputInFile(sortedList);

    // displayVector(sortedList);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << BOLDGREEN << "List sorted in " << duration.count() << " microseconds" << RESET << std::endl;

    return 0;
}