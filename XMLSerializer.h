#pragma once
#include "Serializer.h"

class XMLSerializer : public Serializer
{
public:
	XMLSerializer() {}
	void set_data(Student data) override;
};

