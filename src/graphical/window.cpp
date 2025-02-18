#include <SFML/Graphics.hpp>

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

std::vector<sf::RectangleShape> createShapeList(std::vector<int> list)
{
    std::vector<sf::RectangleShape> numberList;
    float pos = 0;

    for (auto i : list) {
        sf::RectangleShape newRectangle(sf::Vector2f(30, i * 30));
        sf::Vector2f rectanglePosition = {100 + pos * 35, float(500 - i * 30)};
        newRectangle.setPosition(rectanglePosition);
        numberList.push_back(newRectangle);
        pos += 1;
    }

    return numberList;
}

void displayAlgorithm(std::vector<int> list)
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Graphical Algorithm");
    sf::Event event;
    std::vector<sf::RectangleShape> numberList = createShapeList(list);

    while (window.isOpen()) {
        handleEvents(&window, &event);
        drawStuff(&window, numberList);
    }
}