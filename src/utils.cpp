#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "colors.hpp"

std::vector<int> stringToVector(std::string content)
{
    std::vector<int> unsortedList;
    std::stringstream stream(content);
    std::string number;

    while (std::getline(stream, number, ' ')) {
        unsortedList.push_back(stoi(number));
    }

    return unsortedList;
}

std::string getUnsortedList(std::string path)
{
    std::ifstream file(path);
    std::string fileContent;

    if (!file.is_open()) {
        std::cerr << BOLDRED << "Failed to open the file " << path << "." << RESET << std::endl;
        exit(84);
    }

    while (std::getline(file, fileContent));

    file.close();

    return fileContent;
}

void writeOutputInFile(std::vector<int> sortedList)
{
    std::ofstream outputFile("./sortedNumbers.txt");
    for (auto i : sortedList)
        outputFile << i << " ";
    outputFile << "\n";
}

void displayVector(std::vector<int> vector)
{
    for (auto i : vector)
        std::cout << i << " ";
    std::cout << std::endl;
}
