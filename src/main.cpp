#include <iostream>
#include <chrono>
#include "colors.hpp"
#include "utils.cpp"
#include "algorithms/insertionSort.cpp"

int main(int argc, char **argv)
{
    std::string fileContent = getUnsortedList(argv[1]);
    std::vector<int> unsortedList = stringToVector(fileContent);
    std::vector<int> sortedList;

    auto start = std::chrono::high_resolution_clock::now();
    sortedList = insertionSort(unsortedList);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << BOLDGREEN << "List sorted in " << duration.count() << " microseconds" << std::endl;

    return 0;
}