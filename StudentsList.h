#pragma once
#include <list>
#include "JSONSerializer.h"
#include "TXTSerializer.h"
#include "XMLSerializer.h"

class StudentsList
{
private:
	std::list<Student> students;
	std::string serialized_data;
public:
	std::list<Student> get_list();
	std::list<Student> filter(std::string(Student::* get_value)(), std::string parameter);
	std::list<Student> filter(size_t(Student::* get_value)(), size_t parameter);

	std::string serialize(JSONSerializer sr);
	std::string serialize(TXTSerializer sr);
	std::string serialize(XMLSerializer sr);
};

std::ostream& operator<<(std::ostream& os, StudentsList students);