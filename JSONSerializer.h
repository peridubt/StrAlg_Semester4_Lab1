#pragma once
#include "Serializer.h"

class JSONSerializer : public Serializer
{
public:
	JSONSerializer() {}
	void set_data(Student data) override;
};
