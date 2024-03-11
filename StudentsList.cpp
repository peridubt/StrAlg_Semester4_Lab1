#include "StudentsList.h"

std::list<Student>& StudentsList::get_list()
{
	return students;
}

void StudentsList::set_list(std::list<Student> list)
{
	students = list;
}

std::list<Student> StudentsList::filter(std::string(Student::* get_value)(), std::string parameter)
{
	std::list<Student> result;
	for (Student elem : students)
		if (parameter == (elem.*get_value)())
			result.push_back(elem);
	return result;
}

std::list<Student> StudentsList::filter(size_t(Student::* get_value)(), size_t parameter)
{
	std::list<Student> result;
	for (Student elem : students)
		if (parameter == (elem.*get_value)())
			result.push_back(elem);
	return result;
}
