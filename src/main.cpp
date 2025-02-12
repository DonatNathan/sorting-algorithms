#include <iostream>
#include "utils.cpp"
#include "algorithms/insertionSort.cpp"

int main(int argc, char **argv)
{
    std::string fileContent = getUnsortedList(argv[1]);
    std::vector<int> unsortedList = stringToVector(fileContent);

    displayVector(unsortedList);

    unsortedList = insertionSort(unsortedList);

    displayVector(unsortedList);

    return 0;
}