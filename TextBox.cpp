#include "TextBox.h"
#include "Theme.h"
#include <cctype>

TextBox::TextBox(sf::Font& f,
    sf::Vector2f position,
    sf::Vector2f size,
    const std::string& place)
    : font(&f),
    text(f)
{
    box.setPosition(position);
    box.setSize(size);

    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(2.f);
    box.setOutlineColor(Theme::BorderColor);

    placeholder = place;
    value = "";

    selected = false;
    numbersOnly = false;
    lettersOnly = false;

    maxLength = 30;

    text.setCharacterSize(18);
    text.setFillColor(sf::Color(33, 33, 33));
    text.setPosition({
        position.x + 8.f,
        position.y + 8.f
        });

    text.setString(placeholder);
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);
}

void TextBox::update()
{
    if (value.empty())
    {
        text.setString(placeholder);
        text.setFillColor(sf::Color(120, 120, 120));
    }
    else
    {
        text.setString(value);
        text.setFillColor(sf::Color(33, 33, 33));
    }

    if (selected)
        box.setOutlineColor(Theme::PrimaryColor);
    else
        box.setOutlineColor(Theme::BorderColor);
}

bool TextBox::contains(sf::Vector2f point) const
{
    return box.getGlobalBounds().contains(point);
}

void TextBox::setSelected(bool state)
{
    selected = state;
}

void TextBox::setText(const std::string& str)
{
    value = str;
}

std::string TextBox::getText() const
{
    return value;
}

void TextBox::clear()
{
    value.clear();
}

void TextBox::setNumbersOnly(bool state)
{
    numbersOnly = state;
}

void TextBox::setLettersOnly(bool state)
{
    lettersOnly = state;
}

void TextBox::setMaxLength(unsigned int length)
{
    maxLength = length;
}

void TextBox::handleEvent(const sf::Event& event)
{
    // Mouse click
    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f mousePos(
                static_cast<float>(mousePressed->position.x),
                static_cast<float>(mousePressed->position.y));

            selected = contains(mousePos);
        }
    }

    // Text input
    if (!selected)
        return;

    if (const auto* textEntered = event.getIf<sf::Event::TextEntered>())
    {
        char c = static_cast<char>(textEntered->unicode);

        // Backspace
        if (c == 8)
        {
            if (!value.empty())
                value.pop_back();

            return;
        }

        // Ignore Enter
        if (c == 13)
            return;

        if (value.length() >= maxLength)
            return;

        if (numbersOnly)
        {
            if (std::isdigit(static_cast<unsigned char>(c)))
                value += c;

            return;
        }

        if (lettersOnly)
        {
            if (std::isalpha(static_cast<unsigned char>(c)) || c == ' ')
                value += c;

            return;
        }

        if (c >= 32 && c <= 126)
            value += c;
    }
}