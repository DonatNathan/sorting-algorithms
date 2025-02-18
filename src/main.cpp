#include <iostream>
#include <chrono>
#include <map>
#include "colors.hpp"
#include "utils.cpp"
#include "graphical/window.cpp"
#include <bits/stdc++.h>

void displayHelp()
{
    std::cout << BOLDWHITE << "--- Help Sorting Algorithms ---\n" << RESET << std::endl;
    std::cout << "Description: \n> Algortithm that take a file filled by unsorted number and sort them using different algorithms.\n" << std::endl;
    std::cout << "Usage: \n> ./sort [algorithm_name] [file_path]\n" << std::endl;
    std::cout << "Valid algorithm names: \n- insertion\n- selection\n- bubble\n- merge\n" << std::endl;
    std::cout << "Arguments: \n   --graphical: Open a graphical window that show how the algorithm works.\n" << std::endl;
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
    if (argc == 4 && std::string (argv[3]) == "--graphical") {
        sortedList = displayAlgorithm(unsortedList, argv[1]);   
    } else {
        auto updateVisualization = [&](std::vector<int> updatedList, int actual) {};
        sortedList = chooseAlgorithm(unsortedList, argv[1], updateVisualization);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << BOLDGREEN << "List sorted in " << duration.count() << " microseconds" << RESET << std::endl;
    
    writeOutputInFile(sortedList);

    return 0;
}