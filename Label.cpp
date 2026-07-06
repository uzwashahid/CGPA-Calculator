#include "Label.h"
#include "Theme.h"

Label::Label(sf::Font& font,
    const std::string& str,
    unsigned int size,
    sf::Vector2f position)
    : text(font)
{
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(Theme::TextColor);
    text.setPosition(position);
}

void Label::draw(sf::RenderWindow& window)
{
    window.draw(text);
}

void Label::setText(const std::string& str)
{
    text.setString(str);
}

void Label::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
}

void Label::setCharacterSize(unsigned int size)
{
    text.setCharacterSize(size);
}

void Label::setFillColor(sf::Color color)
{
    text.setFillColor(color);
}

void Label::setStyle(sf::Text::Style style)
{
    text.setStyle(style);
}

sf::Text& Label::getText()
{
    return text;
}