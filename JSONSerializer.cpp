#include "JSONSerializer.h"

std::string JSONSerializer::serialize(Student data) const
{
	std::string serialized_data = "{\n";
	serialized_data += "\t\"surname\": \"" + std::string(data.get_surname()) + "\",\n";
	serialized_data += "\t\"name\": \"" + std::string(data.get_name()) + "\",\n";
	serialized_data += "\t\"middlename\": \"" + std::string(data.get_middlename()) + "\",\n";
	serialized_data += "\t\"course\": \"" + std::to_string(data.get_course()) + "\",\n";
	serialized_data += "\t\"group\": \"" + std::to_string(data.get_group()) + "\"\n";
	serialized_data += "}";
	return serialized_data;
}
