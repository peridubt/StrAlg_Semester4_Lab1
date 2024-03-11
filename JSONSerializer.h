#pragma once
#include "Serializer.h"

class JSONSerializer : public Serializer
{
public:
	JSONSerializer() { }
	std::string serialize(Student data) const override;
};
