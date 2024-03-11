#include "XMLSerializer.h"

void XMLSerializer::set_data(Student data)
{
	this->data = data;
	serialized_data = "<student>\n";
	serialized_data += "<surname>" + std::string(data.get_surname()) + "</surname>\n";
	serialized_data += "<name>" + std::string(data.get_name()) + "</name>\n";
	serialized_data += "<middlename>" + std::string(data.get_middlename()) + "</middlename>\n";
	serialized_data += "<course>" + std::to_string(data.get_coure()) + "</middlename>\n";
	serialized_data += "<group>" + std::to_string(data.get_group()) + "</group>\n";
	serialized_data += "</student>\n";
}
