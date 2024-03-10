#pragma once
#include <string>
#include "Student.h"

class Serializer
{
private:
	std::string data;
public:
	Serializer() {}
	virtual std::string operator()(const Student& student);
	std::string get_data();
};
