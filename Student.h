#pragma once
#include <iostream>

class Student
{
private:
	std::string name;
	std::string surname;
	std::string middlename;
	size_t course;
	size_t group;
public:
	Student(std::string name = "", std::string surname = "", std::string middlename = "",
		size_t course = 0, size_t group = 0) :
		name(name), surname(surname), middlename(middlename), 
		course(course), group(group) { }

	std::string get_name();
	std::string get_surname();
	std::string get_middlename();
	size_t get_coure();
	size_t get_group();

	void set_name(std::string name);
	void set_surname(std::string surname);
	void set_middlename(std::string middlename);
	void set_course(size_t course);
	void set_group(size_t group);
};

std::ostream& operator<<(std::ostream& os, Student student);