#pragma once
#include <list>
#include "Student.h"

class StudentsList
{
private:
	std::list<Student> students;
	std::string serialized_data;
public:
	std::list<Student> get_list();
	std::list<Student> filter_by_name(std::string parameter);
	std::list<Student> filter_by_surname(std::string parameter);
	std::list<Student> filter_by_middlename(std::string parameter);
	std::list<Student> filter_by_course(unsigned char parameter);
	std::list<Student> filter_by_group(unsigned int parameter);
};
