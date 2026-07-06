#pragma once
#include <SFML/Graphics.hpp>
#include "Student.h"
#include "FileManager.h"
#include "Button.h"
#include "TextBox.h"
#include "Label.h"

class CGPACalculator
{
private:
private:
    void centerIconInCircle(Label* iconLabel, const sf::CircleShape& circle);
    sf::RenderWindow& window;
    sf::Font font;
    sf::Font iconFont;
    Student student;
    std::vector<Course> displayedCourses;
    FileManager fileManager;

    
    // Header
  
    Label* title;          
    sf::CircleShape headerIconBg;
    Label* headerIconText;  

   
    // Section headers (Student / Course / Course List)
  
    sf::CircleShape studentIconBg;
    Label* studentIconText;
    Label* studentSectionTitle;

    sf::CircleShape courseIconBg;
    Label* courseIconText;
    Label* courseSectionTitle;

    sf::CircleShape listIconBg;
    Label* listIconText;
    Label* listSectionTitle;

    // Student Information
  
    Label* nameLabel;
    Label* regLabel;
    Label* semesterLabel;
    Label* previousCGPALabel;
    Label* previousCreditsLabel;

    TextBox* nameBox;
    TextBox* regBox;
    TextBox* semesterBox;
    TextBox* previousCGPABox;
    TextBox* previousCreditsBox;

    // Course Input
    
    Label* courseNameLabel;
    Label* creditHoursLabel;
    Label* gradeLabel;

    TextBox* courseNameBox;
    TextBox* creditHoursBox;
    TextBox* gradeBox;

   
    // Buttons

    Button* addCourseButton;
    Button* calculateButton;
    Button* saveButton;
    Button* loadButton;
    Button* clearButton;
    Button* deleteButton;
    Button* exitButton;

    
    // Result cards
   
    sf::CircleShape semesterIconBg;
    Label* semesterIconText;
    Label* semesterGPATitle;
    Label* semesterGPAValue;

    sf::CircleShape overallIconBg;
    Label* overallIconText;
    Label* overallCGPATitle;
    Label* overallCGPAValue;

   
    // Table header labels
    
    Label* colHash;
    Label* colCourseName;
    Label* colCredits;
    Label* colGrade;
    Label* colPoints;

    Label* emptyStateLabel; 

public:
    CGPACalculator(sf::RenderWindow& window);
    ~CGPACalculator();

    void processEvents();
    void update();
    void render();
    void run();

    void addCourse();
    void calculateResults();
    void clearFields();
    void saveData();
    void loadData();
    void deleteLastCourse();

    sf::RectangleShape headerPanel;
    sf::RectangleShape studentPanel;
    sf::RectangleShape coursePanel;
    sf::RectangleShape tablePanel;
    sf::RectangleShape tableHeaderBar;   
    sf::RectangleShape semesterCard;     
    sf::RectangleShape overallCard;      
    sf::RectangleShape footerPanel;
};