#pragma once
#include <list>
#include "JSONSerializer.h"
#include "TXTSerializer.h"
#include "XMLSerializer.h"



class StudentsList
{
private:
	std::list<Student> students;
public:
	StudentsList() { }
	StudentsList(std::list<Student> students) : students(students) { }
	~StudentsList() { students.clear(); }

	std::list<Student>& get_list();
	void set_list(std::list<Student> list);
	std::list<Student> filter(std::string(Student::* get_value)(), std::string parameter);
	std::list<Student> filter(size_t(Student::* get_value)(), size_t parameter);
};