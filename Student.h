#pragma once

#include <vector>
#include <string>
#include "Course.h"

class Student
{
private:

    std::string name;
    std::string registrationNumber;
    std::string semester;

    std::vector<Course> courses;

    int totalCredits;
    double totalGradePoints;
    double semesterGPA;
    double overallCGPA;

public:

    Student();

    // Setters
    void setName(const std::string& name);
    void setRegistrationNumber(const std::string& regNo);
    void setSemester(const std::string& sem);

    // Getters
    std::string getName() const;
    std::string getRegistrationNumber() const;
    std::string getSemester() const;

    // Course Functions
    void addCourse(const Course& course);
    void removeCourse(int index);
    void clearCourses();

    std::vector<Course>& getCourses();

    // Calculations
    int calculateTotalCredits();
    double calculateTotalGradePoints();
    double calculateSemesterGPA();

    double calculateOverallCGPA(
        double previousCGPA,
        int previousCredits);

    // Get Results
    int getTotalCredits() const;
    double getTotalGradePoints() const;
    double getSemesterGPA() const;
    double getOverallCGPA() const;
    const std::vector<Course>& getCourses() const;
};