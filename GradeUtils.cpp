#include "GradeUtils.h"

double GradeUtils::getGradePoint(const std::string& grade)
{
    if (grade == "A+" || grade == "A")
        return 4.00;

    if (grade == "A-")
        return 3.67;

    if (grade == "B+")
        return 3.33;

    if (grade == "B")
        return 3.00;

    if (grade == "B-")
        return 2.67;

    if (grade == "C+")
        return 2.33;

    if (grade == "C")
        return 2.00;

    if (grade == "C-")
        return 1.67;

    if (grade == "D+")
        return 1.33;

    if (grade == "D")
        return 1.00;

    return 0.0;
}

bool GradeUtils::isValidGrade(const std::string& grade)
{
    return grade == "A+" ||
        grade == "A" ||
        grade == "A-" ||
        grade == "B+" ||
        grade == "B" ||
        grade == "B-" ||
        grade == "C+" ||
        grade == "C" ||
        grade == "C-" ||
        grade == "D+" ||
        grade == "D" ||
        grade == "F";
}