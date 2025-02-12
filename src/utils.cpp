#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

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

    while (std::getline(file, fileContent));

    file.close();

    return fileContent;
}

void displayVector(std::vector<int> vector)
{
    for (auto i : vector)
        std::cout << i << " ";
    std::cout << std::endl;
}
