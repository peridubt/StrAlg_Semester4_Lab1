#pragma once
#include "Student.h"
#include <string>

class Serializer
{
public:
	Serializer() { }
	~Serializer() { }
	virtual std::string serialize(Student data) const;
};
