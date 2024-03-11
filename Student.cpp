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

size_t Student::get_course()
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
    os << "Ôàìèëèÿ: " << student.get_surname()
        << "\nÈìÿ: " << student.get_name()
        << "\nÎò÷åñòâî: " << student.get_middlename()
        << "\nÊóğñ:" << student.get_course()
        << "\nÃğóïïà:" << student.get_group();
    return os;
}

std::istream& operator>>(std::istream& is, Student& student)
{
    std::string surname = "", name = "", middlename = "";
    size_t course = 0, group = 0;
    is >> surname >> name >> middlename >> course >> group;
    student.set_surname(surname);
    student.set_name(name);
    student.set_middlename(middlename);
    student.set_course(course);
    student.set_group(group);
    return is;
}
