#include "Serializer.h"

Serializer::Serializer(Student data)
{
    set_data(data);
}

std::string Serializer::get_serialized_data()
{
    return serialized_data;
}

void Serializer::set_data(Student data)
{
    this->data = data;
}
