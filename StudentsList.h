#pragma once
#include <list>
#include "Student.h"

class StudentsList
{
private:
	std::list<Student> students;
public:
	std::list<Student> get_list();
};
