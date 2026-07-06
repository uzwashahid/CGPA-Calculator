#pragma once

#include <string>

class Course
{
private:

    std::string courseName;
    int creditHours;
    std::string letterGrade;
    double gradePoint;

public:

    Course();

    Course(
        const std::string& name,
        int credits,
        const std::string& grade);

    void setCourseName(const std::string& name);
    void setCreditHours(int credits);
    void setLetterGrade(const std::string& grade);

    std::string getCourseName() const;
    int getCreditHours() const;
    std::string getLetterGrade() const;
    double getGradePoint() const;

    double calculateQualityPoints() const;
};