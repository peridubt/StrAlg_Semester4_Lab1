#pragma once
#include "Student.h"
#include <string>

class Serializer
{
public:
	Serializer() { }
	virtual std::string serialize(Student data) const;
};
