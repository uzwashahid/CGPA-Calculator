#include "FileManager.h"

#include <fstream>

bool FileManager::saveStudent(const Student& student,
    const std::string& filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
        return false;

    file << student.getName() << std::endl;
    file << student.getRegistrationNumber() << std::endl;
    file << student.getSemester() << std::endl;

    file << student.getCourses().size() << std::endl;

    for (const Course& course : student.getCourses())
    {
        file << course.getCourseName() << std::endl;
        file << course.getCreditHours() << std::endl;
        file << course.getLetterGrade() << std::endl;
    }

    file.close();

    return true;
}

bool FileManager::loadStudent(Student& student,
    const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    student.clearCourses();

    std::string name;
    std::string regNo;
    std::string semester;

    getline(file, name);
    getline(file, regNo);
    getline(file, semester);

    student.setName(name);
    student.setRegistrationNumber(regNo);
    student.setSemester(semester);

    int numberOfCourses;

    file >> numberOfCourses;

    file.ignore();

    for (int i = 0; i < numberOfCourses; i++)
    {
        std::string courseName;
        int credits;
        std::string grade;

        getline(file, courseName);

        file >> credits;

        file.ignore();

        getline(file, grade);

        Course course(courseName,
            credits,
            grade);

        student.addCourse(course);
    }

    student.calculateSemesterGPA();

    file.close();

    return true;
}