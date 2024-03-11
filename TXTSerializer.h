#pragma once
#include "Serializer.h"

class TXTSerializer : public Serializer
{
public:
	TXTSerializer() { }
	virtual std::string serialize(Student data) const;
};

