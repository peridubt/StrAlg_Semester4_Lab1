#include "Student.h"

std::string Student::get_name()
{
    return name;
}

std::string Student::get_surname()
{
    return surname;
}

std::string Student::get_middlename()
{
    return middlename;
}

size_t Student::get_coure()
{
    return course;
}

size_t Student::get_group()
{
    return group;
}



void Student::set_name(std::string name)
{
    this->name = name;
}

void Student::set_surname(std::string surname)
{
    this->surname = surname;
}

void Student::set_middlename(std::string middlename)
{
    this->middlename = middlename;
}

void Student::set_course(size_t course)
{
    this->course = course;
}

void Student::set_group(size_t group)
{
    this->group = group;
}

std::ostream& operator<<(std::ostream& os, Student student)
{
    os << "�������: " << student.get_surname()
        << "\n���: " << student.get_name()
        << "\n��������" << student.get_middlename()
        << "\n����:" << student.get_coure()
        << "\n������:" << student.get_group();
    return os;
}
