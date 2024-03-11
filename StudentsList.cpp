#include "StudentsList.h"

std::list<Student> StudentsList::get_list()
{
	return students;
}

std::list<Student> StudentsList::filter(size_t(Student::* get_value)(), size_t parameter)
{
	std::list<Student> result;
	for (Student elem : students)
		if (parameter == (elem.*get_value)())
			result.push_back(elem);
	return result;
}

std::list<Student> StudentsList::filter(std::string(Student::* get_value)(), std::string parameter)
{
	std::list<Student> result;
	for (Student elem : students)
		if (parameter == (elem.*get_value)())
			result.push_back(elem);
	return result;
}

std::string StudentsList::serialize(JSONSerializer sr)
{
	std::string result = "[\n";
	auto before_end = --students.end();
	for (auto iter = students.begin(); iter != students.end(); ++iter)
	{
		sr.set_data(*iter);
		result += sr.get_serialized_data();
		if (iter != before_end)
			result += ",\n";
	}
	result += "\n]";
	return result;
}

std::string StudentsList::serialize(TXTSerializer sr)
{
	std::string result = "";
	for (auto elem : students)
	{
		sr.set_data(elem);
		result += sr.get_serialized_data();
	}
	return result;
}

std::string StudentsList::serialize(XMLSerializer sr)
{
	std::string result = "<studentslist>\n";
	for (auto elem : students)
	{
		sr.set_data(elem);
		result += sr.get_serialized_data();
	}
	result += "</studentslist>";
	return result;
}

std::ostream& operator<<(std::ostream& os, StudentsList students)
{
	int i = 0;
	for (Student elem : students.get_list())
	{
		std::cout << "¹" << ++i << "\n";
		os << elem << "\n\n";
	}
	return os;
}
