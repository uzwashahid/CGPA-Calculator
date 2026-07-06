#include "Student.h"

Student::Student()
{
    name = "";
    registrationNumber = "";
    semester = "";

    totalCredits = 0;
    totalGradePoints = 0.0;
    semesterGPA = 0.0;
    overallCGPA = 0.0;
}

void Student::setName(const std::string& n)
{
    name = n;
}

void Student::setRegistrationNumber(const std::string& regNo)
{
    registrationNumber = regNo;
}

void Student::setSemester(const std::string& sem)
{
    semester = sem;
}

std::string Student::getName() const
{
    return name;
}

std::string Student::getRegistrationNumber() const
{
    return registrationNumber;
}

std::string Student::getSemester() const
{
    return semester;
}

void Student::addCourse(const Course& course)
{
    courses.push_back(course);
}

void Student::removeCourse(int index)
{
    if (index >= 0 && index < courses.size())
        courses.erase(courses.begin() + index);
}

void Student::clearCourses()
{
    courses.clear();
}

std::vector<Course>& Student::getCourses()
{
    return courses;
}

int Student::calculateTotalCredits()
{
    totalCredits = 0;

    for (const Course& course : courses)
        totalCredits += course.getCreditHours();

    return totalCredits;
}

double Student::calculateTotalGradePoints()
{
    totalGradePoints = 0;

    for (const Course& course : courses)
        totalGradePoints += course.calculateQualityPoints();

    return totalGradePoints;
}

double Student::calculateSemesterGPA()
{
    calculateTotalCredits();
    calculateTotalGradePoints();

    if (totalCredits == 0)
        semesterGPA = 0;

    else
        semesterGPA = totalGradePoints / totalCredits;

    return semesterGPA;
}

double Student::calculateOverallCGPA(
    double previousCGPA,
    int previousCredits)
{
    double previousPoints =
        previousCGPA * previousCredits;

    int overallCredits =
        previousCredits + totalCredits;

    if (overallCredits == 0)
    {
        overallCGPA = 0;
    }
    else
    {
        overallCGPA =
            (previousPoints + totalGradePoints)
            / overallCredits;
    }

    return overallCGPA;
}

int Student::getTotalCredits() const
{
    return totalCredits;
}

double Student::getTotalGradePoints() const
{
    return totalGradePoints;
}

double Student::getSemesterGPA() const
{
    return semesterGPA;
}

double Student::getOverallCGPA() const
{
    return overallCGPA;
}
const std::vector<Course>& Student::getCourses() const
{
    return courses;
}