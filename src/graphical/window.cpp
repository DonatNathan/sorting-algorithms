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

std::vector<sf::RectangleShape> createShapeList(std::vector<int> list, int actual)
{
    std::vector<sf::RectangleShape> numberList;
    float pos = 0;

    for (auto i : list) {
        sf::RectangleShape newRectangle(sf::Vector2f(30, i * 30));
        sf::Vector2f rectanglePosition = {100 + pos * 35, float(500 - i * 30)};
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
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Graphical Algorithm");
    sf::Event event;

    auto updateVisualization = [&](std::vector<int> updatedList, int actual) {
        std::vector<sf::RectangleShape> numberList = createShapeList(updatedList, actual);
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