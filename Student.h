#pragma once
#include <string>

class Student
{
private:
	std::string name;
	std::string surname;
	std::string middlename;
	unsigned char course;
	unsigned int group;
public:
	Student(std::string name = "", std::string surname = "", std::string middlename = "",
		unsigned char course = 0, unsigned int group = 0) : 
		name(name), surname(surname), middlename(middlename), 
		course(course), group(group) { }

	std::string get_name();
	std::string get_surname();
	std::string get_middlename();
	unsigned char get_coure();
	unsigned int get_group();

	void set_name(std::string name);
	void set_surname(std::string surname);
	void set_middlename(std::string middlename);
	void set_course(unsigned char course);
	void set_group(unsigned int group);
};
