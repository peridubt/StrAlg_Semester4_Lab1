#pragma once
#include "Student.h"
#include <string>

class Serializer
{
protected:
	Student data;
	std::string serialized_data;
public:
	Serializer() { }
	Serializer(Student data);
	std::string get_serialized_data();
	virtual void set_data(Student data);
};
