#include "CGPACalculator.h"
#include "Theme.h"

#include <iostream>
#include <sstream>
#include <iomanip>

void CGPACalculator::centerIconInCircle(Label* iconLabel, const sf::CircleShape& circle)
{
    sf::Text& text = iconLabel->getText();

    sf::FloatRect bounds = text.getLocalBounds();

    text.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
        });

    sf::Vector2f circleCenter = circle.getPosition() +
        sf::Vector2f(circle.getRadius(), circle.getRadius());

    text.setPosition(circleCenter);
}

CGPACalculator::CGPACalculator(sf::RenderWindow& win)
    : window(win)
{
    if (!font.openFromFile("Assets/arial.ttf"))
    {
        std::cout << "Font Failed\n";
    }
    if (!iconFont.openFromFile("Assets/fa-solid.otf"))
    {
        std::cout << "Icon Font Failed\n";
    }

    //=====================================================
    // HEADER
    //=====================================================
    headerPanel.setSize({ Theme::WINDOW_WIDTH, 70.f });
    headerPanel.setPosition({ 0.f, 0.f });
    headerPanel.setFillColor(Theme::PrimaryColor);
    headerPanel.setOutlineThickness(0.f);

    headerIconBg.setRadius(14.f);
    headerIconBg.setFillColor(Theme::WhiteColor);
    headerIconBg.setPosition({ 590.f, 22.f });

    headerIconText = new Label(font, "", 20, { 596.f, 18.f });
    headerIconText->getText().setFont(iconFont);
    headerIconText->getText().setString(sf::String(U"\uf19d"));
    headerIconText->setFillColor(Theme::PrimaryColor);
    centerIconInCircle(headerIconText, headerIconBg);

    title = new Label(font, "CGPA CALCULATOR", Theme::TitleSize, { 630.f, 15.f });
    title->setCharacterSize(28);
    title->setFillColor(Theme::WhiteColor);
    title->setStyle(sf::Text::Bold);

    //=====================================================
    // STUDENT PANEL
    //=====================================================
    studentPanel.setSize({ 660.f, 260.f });
    studentPanel.setPosition({ 20.f, 85.f });
    studentPanel.setFillColor(Theme::PanelColor);
    studentPanel.setOutlineThickness(1.f);
    studentPanel.setOutlineColor(Theme::BorderColor);

    studentIconBg.setRadius(12.f);
    studentIconBg.setFillColor(sf::Color(227, 242, 253));
    studentIconBg.setPosition({ 40.f, 108.f });

    studentIconText = new Label(font, "", 16, { 47.f, 106.f });
    studentIconText->getText().setFont(iconFont);
    studentIconText->getText().setString(sf::String(U"\uf05a"));
    studentIconText->setFillColor(Theme::PrimaryColor);
    centerIconInCircle(studentIconText, studentIconBg);

    studentSectionTitle = new Label(font, "STUDENT INFORMATION", 16, { 72.f, 108.f });
    studentSectionTitle->setFillColor(Theme::PrimaryColor);
    studentSectionTitle->setStyle(sf::Text::Bold);

    nameLabel = new Label(font, "Student Name", 14, { 40, 145 });
    regLabel = new Label(font, "Registration No.", 14, { 40, 185 });
    semesterLabel = new Label(font, "Semester", 14, { 40, 225 });
    previousCGPALabel = new Label(font, "Previous CGPA", 14, { 40, 265 });
    previousCreditsLabel = new Label(font, "Previous Credits", 14, { 40, 305 });

    for (Label* l : { nameLabel, regLabel, semesterLabel, previousCGPALabel, previousCreditsLabel })
        l->setFillColor(Theme::MutedTextColor);

    nameBox = new TextBox(font, { 190, 138 }, { 460, 34 });
    regBox = new TextBox(font, { 190, 178 }, { 460, 34 });
    semesterBox = new TextBox(font, { 190, 218 }, { 460, 34 });
    previousCGPABox = new TextBox(font, { 190, 258 }, { 460, 34 }, "0.00");
    previousCreditsBox = new TextBox(font, { 190, 298 }, { 460, 34 });

    previousCGPABox->clear();

    //=====================================================
    // COURSE PANEL
    //=====================================================
    coursePanel.setSize({ 680.f, 260.f });
    coursePanel.setPosition({ 700.f, 85.f });
    coursePanel.setFillColor(Theme::PanelColor);
    coursePanel.setOutlineThickness(1.f);
    coursePanel.setOutlineColor(Theme::BorderColor);

    courseIconBg.setRadius(12.f);
    courseIconBg.setFillColor(sf::Color(227, 242, 253));
    courseIconBg.setPosition({ 720.f, 108.f });

    courseIconText = new Label(font, "", 16, { 727.f, 104.f });
    courseIconText->getText().setFont(iconFont);
    courseIconText->getText().setString(sf::String(U"\uf02d"));
    courseIconText->setFillColor(Theme::PrimaryColor);
    centerIconInCircle(courseIconText, courseIconBg);

    courseSectionTitle = new Label(font, "COURSE INFORMATION", 16, { 752.f, 108.f });
    courseSectionTitle->setFillColor(Theme::PrimaryColor);
    courseSectionTitle->setStyle(sf::Text::Bold);

    courseNameLabel = new Label(font, "Course Name", 14, { 720, 155 });
    creditHoursLabel = new Label(font, "Credit Hours", 14, { 720, 200 });
    gradeLabel = new Label(font, "Grade", 14, { 720, 245 });

    for (Label* l : { courseNameLabel, creditHoursLabel, gradeLabel })
        l->setFillColor(Theme::MutedTextColor);

    courseNameBox = new TextBox(font, { 870, 148 }, { 480, 38 });
    creditHoursBox = new TextBox(font, { 870, 193 }, { 480, 38 });
    gradeBox = new TextBox(font, { 870, 238 }, { 480, 38 });

    addCourseButton = new Button(font, "Add Course", { 870, 286 }, { 160, 40 });
    calculateButton = new Button(font, "Calculate", { 1045, 286 }, { 160, 40 });

    addCourseButton->setColors(Theme::PrimaryColor, Theme::SecondaryColor, Theme::SecondaryColor);
    calculateButton->setColors(Theme::PrimaryColor, Theme::SecondaryColor, Theme::SecondaryColor);

    //=====================================================
    // RESULT CARDS
    //=====================================================
    semesterCard.setSize({ 660.f, 70.f });
    semesterCard.setPosition({ 20.f, 355.f });
    semesterCard.setFillColor(Theme::SemesterCardBg);
    semesterCard.setOutlineThickness(1.f);
    semesterCard.setOutlineColor(Theme::SemesterCardBorder);

    semesterIconBg.setRadius(14.f);
    semesterIconBg.setFillColor(sf::Color::White);
    semesterIconBg.setPosition({ 40.f, 373.f });

    semesterIconText = new Label(font, "", 16, { 46.f, 421.f });
    semesterIconText->getText().setFont(iconFont);
    semesterIconText->getText().setString(sf::String(U"\uf080"));
    semesterIconText->setFillColor(Theme::SuccessColor);
    centerIconInCircle(semesterIconText, semesterIconBg);

    semesterGPATitle = new Label(font, "SEMESTER GPA", 14, { 75, 368 });
    semesterGPATitle->setFillColor(Theme::SuccessColor);
    semesterGPATitle->setStyle(sf::Text::Bold);

    semesterGPAValue = new Label(font, "0.00", 24, { 75, 390 });
    semesterGPAValue->setFillColor(Theme::SuccessColor);
    semesterGPAValue->setStyle(sf::Text::Bold);

    overallCard.setSize({ 680.f, 70.f });
    overallCard.setPosition({ 700.f, 355.f });
    overallCard.setFillColor(Theme::OverallCardBg);
    overallCard.setOutlineThickness(1.f);
    overallCard.setOutlineColor(Theme::OverallCardBorder);

    overallIconBg.setRadius(14.f);
    overallIconBg.setFillColor(sf::Color::White);
    overallIconBg.setPosition({ 720.f, 373.f });

    overallIconText = new Label(font, "", 16, { 727.f, 421.f });
    overallIconText->getText().setFont(iconFont);
    overallIconText->getText().setString(sf::String(U"\uf005"));
    overallIconText->setFillColor(Theme::PrimaryColor);
    centerIconInCircle(overallIconText, overallIconBg);

    overallCGPATitle = new Label(font, "OVERALL CGPA", 14, { 755, 368 });
    overallCGPATitle->setFillColor(Theme::PrimaryColor);
    overallCGPATitle->setStyle(sf::Text::Bold);

    overallCGPAValue = new Label(font, "0.00", 24, { 755, 390 });
    overallCGPAValue->setFillColor(Theme::PrimaryColor);
    overallCGPAValue->setStyle(sf::Text::Bold);

    //=====================================================
    // COURSE LIST TABLE
    //=====================================================
    tablePanel.setSize({ 1360.f, 340.f });
    tablePanel.setPosition({ 20.f, 435.f });
    tablePanel.setFillColor(Theme::PanelColor);
    tablePanel.setOutlineThickness(1.f);
    tablePanel.setOutlineColor(Theme::BorderColor);

    listIconBg.setRadius(0.f);
    listSectionTitle = new Label(font, "COURSE LIST", 16, { 40, 518 });
    listSectionTitle->setFillColor(Theme::PrimaryColor);
    listSectionTitle->setStyle(sf::Text::Bold);
    listSectionTitle->setPosition({ 40.f, 447.f });

    tableHeaderBar.setSize({ 1360.f, 32.f });
    tableHeaderBar.setPosition({ 20.f, 478.f });
    tableHeaderBar.setFillColor(Theme::TableHeaderColor);

    colHash = new Label(font, "#", 14, { 40,   486 });
    colCourseName = new Label(font, "Course Name", 14, { 120, 486 });
    colCredits = new Label(font, "Credits", 14, { 620,  486 });
    colGrade = new Label(font, "Grade", 14, { 880,  486 });
    colPoints = new Label(font, "Grade Point", 14, { 1130, 486 });

    for (Label* l : { colHash, colCourseName, colCredits, colGrade, colPoints })
    {
        l->setFillColor(Theme::WhiteColor);
        l->setStyle(sf::Text::Bold);
    }

    emptyStateLabel = new Label(font, "No courses added yet.", 16, { 600, 590 });
    emptyStateLabel->setFillColor(Theme::MutedTextColor);

    //=====================================================
    // FOOTER
    //=====================================================
    footerPanel.setSize({ 1360.f, 60.f });
    footerPanel.setPosition({ 20.f, 825.f });
    footerPanel.setFillColor(Theme::BackgroundColor);
    footerPanel.setOutlineThickness(0.f);

    saveButton = new Button(font, "Save", { 60,   833 }, { 160, 44 });
    loadButton = new Button(font, "Load", { 240,  833 }, { 160, 44 });
    deleteButton = new Button(font, "Delete Last", { 420,  833 }, { 160, 44 });
    clearButton = new Button(font, "Clear", { 600,  833 }, { 160, 44 });
    exitButton = new Button(font, "Exit", { 1180, 833 }, { 160, 44 });

    saveButton->setColors(Theme::TableHeaderColor, Theme::SecondaryColor, Theme::SecondaryColor);
    loadButton->setColors(Theme::TableHeaderColor, Theme::SecondaryColor, Theme::SecondaryColor);
    clearButton->setColors(Theme::TableHeaderColor, Theme::SecondaryColor, Theme::SecondaryColor);
    deleteButton->setColors(Theme::TableHeaderColor, Theme::DangerHoverColor, Theme::DangerHoverColor);
    exitButton->setColors(Theme::ExitColor, Theme::ExitHoverColor, Theme::ExitHoverColor);
}

CGPACalculator::~CGPACalculator()
{
    delete title;
    delete headerIconText;

    delete studentIconText;
    delete studentSectionTitle;
    delete courseIconText;
    delete courseSectionTitle;
    delete listSectionTitle;

    delete nameLabel;
    delete regLabel;
    delete semesterLabel;
    delete previousCGPALabel;
    delete previousCreditsLabel;

    delete nameBox;
    delete regBox;
    delete semesterBox;
    delete previousCGPABox;
    delete previousCreditsBox;

    delete courseNameLabel;
    delete creditHoursLabel;
    delete gradeLabel;

    delete courseNameBox;
    delete creditHoursBox;
    delete gradeBox;

    delete addCourseButton;
    delete calculateButton;
    delete saveButton;
    delete loadButton;
    delete clearButton;
    delete deleteButton;
    delete exitButton;

    delete semesterIconText;
    delete semesterGPATitle;
    delete semesterGPAValue;

    delete overallIconText;
    delete overallCGPATitle;
    delete overallCGPAValue;

    delete colHash;
    delete colCourseName;
    delete colCredits;
    delete colGrade;
    delete colPoints;

    delete emptyStateLabel;
}

void CGPACalculator::addCourse()
{
    std::string courseName = courseNameBox->getText();
    std::string creditsText = creditHoursBox->getText();
    std::string grade = gradeBox->getText();

    if (courseName.empty() || creditsText.empty() || grade.empty())
        return;

    int credits = std::stoi(creditsText);

    Course course(courseName, credits, grade);

    student.addCourse(course);
    displayedCourses.push_back(course);

    courseNameBox->clear();
    creditHoursBox->clear();
    gradeBox->clear();
}

void CGPACalculator::processEvents()
{
    while (auto event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();

        nameBox->handleEvent(*event);
        regBox->handleEvent(*event);
        semesterBox->handleEvent(*event);
        previousCGPABox->handleEvent(*event);
        previousCreditsBox->handleEvent(*event);

        courseNameBox->handleEvent(*event);
        creditHoursBox->handleEvent(*event);
        gradeBox->handleEvent(*event);

        if (addCourseButton->isClicked(*event, window)) addCourse();
        if (calculateButton->isClicked(*event, window)) calculateResults();
        if (exitButton->isClicked(*event, window))       window.close();
        if (saveButton->isClicked(*event, window))       saveData();
        if (loadButton->isClicked(*event, window))       loadData();
        if (clearButton->isClicked(*event, window))      clearFields();
        if (deleteButton->isClicked(*event, window))     deleteLastCourse();
    }
}

void CGPACalculator::update()
{
    nameBox->update();
    regBox->update();
    semesterBox->update();
    previousCGPABox->update();
    previousCreditsBox->update();

    courseNameBox->update();
    creditHoursBox->update();
    gradeBox->update();

    addCourseButton->update(window);
    calculateButton->update(window);
    saveButton->update(window);
    loadButton->update(window);
    clearButton->update(window);
    deleteButton->update(window);
    exitButton->update(window);
}

void CGPACalculator::render()
{
    window.clear(Theme::BackgroundColor);

    window.draw(headerPanel);
    window.draw(studentPanel);
    window.draw(coursePanel);
    window.draw(semesterCard);
    window.draw(overallCard);
    window.draw(tablePanel);
    window.draw(tableHeaderBar);

    window.draw(headerIconBg);
    headerIconText->draw(window);
    title->draw(window);

    window.draw(studentIconBg);
    studentIconText->draw(window);
    studentSectionTitle->draw(window);

    nameLabel->draw(window);
    regLabel->draw(window);
    semesterLabel->draw(window);
    previousCGPALabel->draw(window);
    previousCreditsLabel->draw(window);

    nameBox->draw(window);
    regBox->draw(window);
    semesterBox->draw(window);
    previousCGPABox->draw(window);
    previousCreditsBox->draw(window);

    window.draw(courseIconBg);
    courseIconText->draw(window);
    courseSectionTitle->draw(window);

    courseNameLabel->draw(window);
    creditHoursLabel->draw(window);
    gradeLabel->draw(window);

    courseNameBox->draw(window);
    creditHoursBox->draw(window);
    gradeBox->draw(window);

    addCourseButton->draw(window);
    calculateButton->draw(window);

    window.draw(semesterIconBg);
    semesterIconText->draw(window);
    semesterGPATitle->draw(window);
    semesterGPAValue->draw(window);

    window.draw(overallIconBg);
    overallIconText->draw(window);
    overallCGPATitle->draw(window);
    overallCGPAValue->draw(window);

    listSectionTitle->draw(window);

    colHash->draw(window);
    colCourseName->draw(window);
    colCredits->draw(window);
    colGrade->draw(window);
    colPoints->draw(window);

    if (displayedCourses.empty())
    {
        emptyStateLabel->draw(window);
    }
    else
    {
        float y = 522.f;
        int index = 1;

        for (const Course& c : displayedCourses)
        {
            sf::RectangleShape row({ 1360.f, 34.f });
            row.setPosition({ 20.f, y - 8.f });
            row.setFillColor(index % 2 == 0 ? Theme::RowAltColor : Theme::PanelColor);
            window.draw(row);

            Label idx(font, std::to_string(index), 14, { 40, y });
            idx.setFillColor(Theme::MutedTextColor);

            Label courseName(font, c.getCourseName(), 14, { 120, y });
            courseName.setFillColor(Theme::TextColor);

            Label credits(font, std::to_string(c.getCreditHours()), 14, { 620, y });
            credits.setFillColor(Theme::TextColor);

            Label grade(font, c.getLetterGrade(), 14, { 880, y });
            grade.setFillColor(Theme::TextColor);

            std::ostringstream gp;
            gp << std::fixed << std::setprecision(2) << c.getGradePoint();

            Label gradePoint(font, gp.str(), 14, { 1130, y });
            gradePoint.setFillColor(Theme::TextColor);

            idx.draw(window);
            courseName.draw(window);
            credits.draw(window);
            grade.draw(window);
            gradePoint.draw(window);

            y += 32.f;
            index++;
        }
    }

    saveButton->draw(window);
    loadButton->draw(window);
    deleteButton->draw(window);
    clearButton->draw(window);
    exitButton->draw(window);

    window.display();
}

void CGPACalculator::run()
{
    processEvents();
    update();
    render();
}

void CGPACalculator::calculateResults()
{
    double semester = student.calculateSemesterGPA();

    double previousCGPA = 0;
    int previousCredits = 0;

    if (!previousCGPABox->getText().empty())
        previousCGPA = std::stod(previousCGPABox->getText());

    if (!previousCreditsBox->getText().empty())
        previousCredits = std::stoi(previousCreditsBox->getText());

    double overall = student.calculateOverallCGPA(previousCGPA, previousCredits);

    std::ostringstream semStream;
    semStream << std::fixed << std::setprecision(2) << semester;
    semesterGPAValue->setText(semStream.str());

    std::ostringstream ovStream;
    ovStream << std::fixed << std::setprecision(2) << overall;
    overallCGPAValue->setText(ovStream.str());
}

void CGPACalculator::saveData()
{
    student.setName(nameBox->getText());
    student.setRegistrationNumber(regBox->getText());
    student.setSemester(semesterBox->getText());

    if (fileManager.saveStudent(student, "StudentData.txt"))
        std::cout << "Data Saved Successfully\n";
    else
        std::cout << "Save Failed\n";
}

void CGPACalculator::loadData()
{
    if (fileManager.loadStudent(student, "StudentData.txt"))
    {
        nameBox->setText(student.getName());
        regBox->setText(student.getRegistrationNumber());
        semesterBox->setText(student.getSemester());

        displayedCourses = student.getCourses();

        calculateResults();

        std::cout << "Loaded Successfully\n";
    }
}

void CGPACalculator::clearFields()
{
    nameBox->clear();
    regBox->clear();
    semesterBox->clear();

    previousCGPABox->setText("0.00");
    previousCreditsBox->clear();

    courseNameBox->clear();
    creditHoursBox->clear();
    gradeBox->clear();

    displayedCourses.clear();
    student.clearCourses();

    semesterGPAValue->setText("0.00");
    overallCGPAValue->setText("0.00");
}

void CGPACalculator::deleteLastCourse()
{
    if (displayedCourses.empty())
        return;

    displayedCourses.pop_back();
    student.clearCourses();

    for (const Course& c : displayedCourses)
        student.addCourse(c);

    calculateResults();
}