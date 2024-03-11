#include "TXTSerializer.h"

std::string TXTSerializer::serialize(Student data) const
{
	std::string serialized_data = "";
	serialized_data += data.get_surname() + "\n";
	serialized_data += data.get_name() + "\n";
	serialized_data += data.get_surname() + "\n";
	serialized_data += std::to_string(data.get_course()) + "\n";
	serialized_data += std::to_string(data.get_group()) + "\n";
	return serialized_data;
}
