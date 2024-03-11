#pragma once
#include "Serializer.h"

class XMLSerializer : public Serializer
{
public:
	XMLSerializer() { }
	virtual std::string serialize(Student data) const;
};

