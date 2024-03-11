#include "JSONSerializer.h"

void JSONSerializer::set_data(Student data)
{
	this->data = data;
	serialized_data = "{\n";
	serialized_data += "\t\"surname\": " + data.get_surname() + ",\n";
	serialized_data += "\t\"name\": " + data.get_name() + ",\n";
	serialized_data += "\t\"middlename\": " + data.get_middlename() + ",\n";
	serialized_data += "\t\"course\": " + std::to_string(data.get_coure()) + ",\n";
	serialized_data += "\t\"group\": " + std::to_string(data.get_group()) + "\n";
	serialized_data = "}";
}
