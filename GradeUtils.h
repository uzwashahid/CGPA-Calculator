#pragma once

#include <string>

class GradeUtils
{
public:

    static double getGradePoint(const std::string& grade);

    static bool isValidGrade(const std::string& grade);
};
