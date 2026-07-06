//
#pragma once
#include <SFML/Graphics.hpp>

class Theme
{
public:
    // Window
    static constexpr float WINDOW_WIDTH = 1400.f;
    static constexpr float WINDOW_HEIGHT = 900.f;

    // Colors
    static const sf::Color BackgroundColor;
    static const sf::Color PanelColor;
    static const sf::Color PrimaryColor;
    static const sf::Color SecondaryColor;
    static const sf::Color TextColor;
    static const sf::Color WhiteColor;
    static const sf::Color BorderColor;
    static const sf::Color SuccessColor;
    static const sf::Color DangerColor;
    

    // NEW
    static const sf::Color MutedTextColor;
    static const sf::Color TableHeaderColor;
    static const sf::Color SemesterCardBg;
    static const sf::Color SemesterCardBorder;
    static const sf::Color OverallCardBg;
    static const sf::Color OverallCardBorder;
    static const sf::Color ExitColor;
    static const sf::Color ExitHoverColor;
    static const sf::Color DangerHoverColor;
    static const sf::Color RowAltColor;

    // Sizes
    static constexpr float ButtonWidth = 150.f;
    static constexpr float ButtonHeight = 45.f;
    static constexpr float TextBoxWidth = 260.f;
    static constexpr float TextBoxHeight = 40.f;
    static constexpr unsigned int TitleSize = 34;
    static constexpr unsigned int LabelSize = 20;
    static constexpr unsigned int TextSize = 18;
    
};