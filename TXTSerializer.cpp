#include "TXTSerializer.h"

void TXTSerializer::set_data(Student data)
{
	this->data = data;
	serialized_data = "";
	serialized_data += data.get_surname() + "\n";
	serialized_data += data.get_name() + "\n";
	serialized_data += data.get_surname() + "\n";
	serialized_data += std::to_string(data.get_coure()) + "\n";
	serialized_data += std::to_string(data.get_group()) + "\n";
}
