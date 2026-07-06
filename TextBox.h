#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextBox
{
private:

    sf::RectangleShape box;
    sf::Text text;
    sf::Font* font;

    std::string value;
    std::string placeholder;

    bool selected;
    bool numbersOnly;
    bool lettersOnly;

    unsigned int maxLength;

public:

    TextBox(sf::Font& font,
        sf::Vector2f position,
        sf::Vector2f size,
        const std::string& placeholder = "");

    void draw(sf::RenderWindow& window);

    void handleEvent(const sf::Event& event);

    void update();

    void setSelected(bool state);

    bool contains(sf::Vector2f point) const;

    void setText(const std::string& str);

    std::string getText() const;

    void clear();

    void setNumbersOnly(bool state);

    void setLettersOnly(bool state);

    void setMaxLength(unsigned int length);
};