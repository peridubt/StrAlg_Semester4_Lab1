#pragma once
#include "Serializer.h"

class TXTSerializer : public Serializer
{
public:
	TXTSerializer() {}
	void set_data(Student data) override;
};

