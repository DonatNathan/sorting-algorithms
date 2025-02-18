#include <SFML/Graphics.hpp>
#include "../algorithmSetup.cpp"
#include <SFML/System.hpp>

void handleEvents(sf::RenderWindow *window, sf::Event *event)
{
    while (window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed)
            window->close();
    }
}

void drawStuff(sf::RenderWindow *window, std::vector<sf::RectangleShape> numberList)
{
    window->clear(sf::Color::Black);
    for (auto i : numberList) {
        window->draw(i);
    }
    window->display();
}

std::vector<sf::RectangleShape> createShapeList(std::vector<int> list, int actual, int windowX, int windowY)
{
    std::vector<sf::RectangleShape> numberList;
    float pos = 0;

    for (auto i : list) {
        float length = windowX / list.size() - 5;
        float heigth = windowY / *std::max_element(list.begin(), list.end());
        sf::RectangleShape newRectangle(sf::Vector2f(length, i * heigth));
        sf::Vector2f rectanglePosition = {pos * (length + 5), float(windowY - i * heigth)};
        newRectangle.setPosition(rectanglePosition);
        if (pos == actual)
            newRectangle.setFillColor(sf::Color::Green);
        numberList.push_back(newRectangle);
        pos += 1;
    }

    return numberList;
}

void displayAlgorithm(std::vector<int> list, std::string algorithm)
{
    int windowX = 800;
    int windowY = 600;
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Graphical Algorithm");
    sf::Event event;

    auto updateVisualization = [&](std::vector<int> updatedList, int actual) {
        std::vector<sf::RectangleShape> numberList = createShapeList(updatedList, actual, windowX, windowY);
        window.clear(sf::Color::Black);
        for (auto &rect : numberList) {
            window.draw(rect);
        }
        window.display();
        handleEvents(&window, &event);
        sf::sleep(sf::milliseconds(500));
    };

    chooseAlgorithm(list, algorithm, updateVisualization);

    while (window.isOpen()) {
        handleEvents(&window, &event);
        // drawStuff(&window, numberList);
    }
}