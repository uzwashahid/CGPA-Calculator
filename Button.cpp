#include "Button.h"
#include "Theme.h"

Button::Button(sf::Font& f,
    const std::string& title,
    sf::Vector2f position,
    sf::Vector2f size)
    : font(&f),
    text(f)
{
    body.setPosition(position);
    body.setSize(size);

    normalColor = Theme::PrimaryColor;
    hoverColor = Theme::SecondaryColor;
    pressedColor = Theme::SuccessColor;

    body.setFillColor(normalColor);

    body.setOutlineThickness(2.f);
    body.setOutlineColor(Theme::BorderColor);

    text.setString(title);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });

    text.setPosition({
        position.x + size.x / 2.f,
        position.y + size.y / 2.f
        });

    hovered = false;
}

bool Button::isMouseOver(const sf::RenderWindow& window) const
{
    auto mouse =
        window.mapPixelToCoords(
            sf::Mouse::getPosition(window));

    return body.getGlobalBounds().contains(mouse);
}

void Button::update(const sf::RenderWindow& window)
{
    if (isMouseOver(window))
    {
        body.setFillColor(hoverColor);
        hovered = true;
    }
    else
    {
        body.setFillColor(normalColor);
        hovered = false;
    }
}

bool Button::isClicked(const sf::Event& event,
    const sf::RenderWindow& window)
{
    if (const auto* mousePressed =
        event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left &&
            isMouseOver(window))
        {
            body.setFillColor(pressedColor);
            return true;
        }
    }

    return false;
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(body);
    window.draw(text);
}

void Button::setPosition(sf::Vector2f position)
{
    body.setPosition(position);

    auto size = body.getSize();

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });

    text.setPosition({
        position.x + size.x / 2.f,
        position.y + size.y / 2.f
        });
}

void Button::setText(const std::string& str)
{
    text.setString(str);

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });
}

void Button::setColors(sf::Color normal, sf::Color hover, sf::Color pressed)
{
    normalColor = normal;
    hoverColor = hover;
    pressedColor = pressed;
    body.setFillColor(normalColor);
}