#include "XMLSerializer.h"

std::string XMLSerializer::serialize(Student data) const
{
	std::string serialized_data = "<student>\n";
	serialized_data += "\t<surname>" + std::string(data.get_surname()) + "</surname>\n";
	serialized_data += "\t<name>" + std::string(data.get_name()) + "</name>\n";
	serialized_data += "\t<middlename>" + std::string(data.get_middlename()) + "</middlename>\n";
	serialized_data += "\t<course>" + std::to_string(data.get_course()) + "</middlename>\n";
	serialized_data += "\t<group>" + std::to_string(data.get_group()) + "</group>\n";
	serialized_data += "</student>\n";
	return serialized_data;
}
