#pragma once

#include <string>
#include "Student.h"

class FileManager
{
public:

    bool saveStudent(const Student& student,
        const std::string& filename);

    bool loadStudent(Student& student,
        const std::string& filename);
};