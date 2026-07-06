#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:

    sf::RectangleShape body;

    sf::Font* font;

    sf::Text text;

    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color pressedColor;

    bool hovered;

public:

    Button(sf::Font& font,
        const std::string& title,
        sf::Vector2f position,
        sf::Vector2f size);

    void update(const sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);

    bool isMouseOver(const sf::RenderWindow& window) const;

    bool isClicked(const sf::Event& event,
        const sf::RenderWindow& window);

    void setPosition(sf::Vector2f position);

    void setText(const std::string& str);

    void setColors(sf::Color normal, sf::Color hover, sf::Color pressed);
};