#include "Course.h"
#include "GradeUtils.h"

Course::Course()
{
    courseName = "";
    creditHours = 0;
    letterGrade = "F";
    gradePoint = 0.0;
}

Course::Course(
    const std::string& name,
    int credits,
    const std::string& grade)
{
    courseName = name;
    creditHours = credits;
    letterGrade = grade;
    gradePoint = GradeUtils::getGradePoint(grade);
}

void Course::setCourseName(const std::string& name)
{
    courseName = name;
}

void Course::setCreditHours(int credits)
{
    creditHours = credits;
}

void Course::setLetterGrade(const std::string& grade)
{
    letterGrade = grade;
    gradePoint = GradeUtils::getGradePoint(grade);
}

std::string Course::getCourseName() const
{
    return courseName;
}

int Course::getCreditHours() const
{
    return creditHours;
}

std::string Course::getLetterGrade() const
{
    return letterGrade;
}

double Course::getGradePoint() const
{
    return gradePoint;
}

double Course::calculateQualityPoints() const
{
    return gradePoint * creditHours;
}