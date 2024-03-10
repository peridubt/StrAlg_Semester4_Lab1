#pragma once
#include "Serializer.h"

class JSONSerializer : public Serializer
{
public:
	JSONSerializer() {}
	std::string operator()(const Student& student) override { return ""; }
};

