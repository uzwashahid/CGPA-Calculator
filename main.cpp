//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(
//        sf::VideoMode({ 800, 600 }),
//        "CGPA Calculator");
//
//    while (window.isOpen())
//    {
//        while (const std::optional event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//                window.close();
//        }
//
//        window.clear(sf::Color::White);
//
//        window.display();
//    }
//
//    return 0;
//}

#include <SFML/Graphics.hpp>
#include "CGPACalculator.h"
#include "Theme.h"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(
            { (unsigned int)Theme::WINDOW_WIDTH,
             (unsigned int)Theme::WINDOW_HEIGHT }),
        "CGPA Calculator");
    
    CGPACalculator calculator(window);

    while (window.isOpen())
    {
        calculator.run();
    }

    return 0;
}