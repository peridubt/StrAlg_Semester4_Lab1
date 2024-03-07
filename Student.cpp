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

unsigned char Student::get_coure()
{
    return course;
}

unsigned int Student::get_group()
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

void Student::set_course(unsigned char course)
{
    this->course = course;
}

void Student::set_group(unsigned int group)
{
    this->group = group;
}
