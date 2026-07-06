#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Label
{
private:

    sf::Text text;

public:

    Label(sf::Font& font,
        const std::string& str,
        unsigned int size,
        sf::Vector2f position);

    void draw(sf::RenderWindow& window);

    void setText(const std::string& str);

    void setPosition(sf::Vector2f position);

    // NEW FUNCTIONS
    void setCharacterSize(unsigned int size);

    void setFillColor(sf::Color color);

    void setStyle(sf::Text::Style style);

    sf::Text& getText();
};