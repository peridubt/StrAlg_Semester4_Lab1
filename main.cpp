#include "StudentsList.h"
#include <sstream>
#include <regex>
#include <fstream>
#include <Windows.h>

/*
������� ������, 91 ������

1. ���� ����� ������� (4-5 ����� �� �����). ���� ������� ����� ������������, �������
��������� ������ � �������� � ��������� ������. � ������������� ��� ����������, �������
��������� ������ � .xml, .json � ������� ����� ��������������. ��� ������ ���������
����������� ����������� ���������� �� �������� ���������� � ������������ ���� ������
� �������� �������.
*/

std::string serialize_list(Serializer sr, StudentsList students)
{
	std::string result;
	for (auto elem : students.get_list())
	{
		result += sr.serialize(elem);
	}
	return result;
}

// ������� �������� �������� ������

bool is_integer(std::string s, int& i) // �������� ������������ ����� ������ �����
{
	char c;
	std::stringstream ss(s);
	ss >> i;
	if (ss.fail() || ss.get(c))
		return false;
	return true;
}

void check_int(std::string input, int& num) // ���� ����� �����
{
	while (!is_integer(input, num))
	{
		std::cout << "������� ������������ ������!\n"
			<< "��������� ������� �����: \t";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, input);
	}
	num = stoi(input);
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

bool check_filename(std::string filename) // �������� ����� �����
{
	const std::regex file_regex("^.*[\\\\\\/:\\*\\?\"<>\\|\\+].*$");
	return !std::regex_match(filename, file_regex);
}



// ������� ������ � ����

void print_task_menu()
{
	std::cout << "��������� ���������� ��:\n";
	std::cout << "1) �������;\n"
		<< "2) �����;\n"
		<< "3) ��������;\n"
		<< "4) �����;\n"
		<< "5) ������.\n"
		<< "\n���\n"
		<< "0. ��������� �����.\n";
	std::cout << "\n->\t";
}

void print_serialization()
{
	std::cout << "��������� ��������� � �������:\n"
		<< "1) .json;\n"
		<< "2) .txt;\n"
		<< "3) .xml.\n"
		<< "\n���\n"
		<< "0. ��������� � ������� ����.";
	std::cout << "\n->\t";
}

void print_main_menu() // ������ ������ ���� � �������
{
	std::cout << "1. ������� ������ �� �����.\n"
		<< "2. ������������� ������ �� ��������� ���������\n(������������� �����).\n"
		<< "3. ������ ������ � �������.\n"
		<< "4. ������������ ����� ������.\n"
		<< "0. �����.\n";
	std::cout << "\n->\t";
}

int integer_input()
{
	int number;
	std::string input;
	std::getline(std::cin, input);
	check_int(input, number);
	return number;
}

std::string filename_input()
{
	std::string filename = "";
	std::cout << "������� ��� �����:\t";
	std::getline(std::cin, filename);
	while (!check_filename(filename))
	{
		std::cout << "� ����� ���������� ����������� �������!\n"
			<< "��������� ������� �����: \t";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::getline(std::cin, filename);
	}
	return filename;
}

void read_from_file(StudentsList& list)
{
	std::string filename = filename_input();
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		try
		{
			Student elem;
			while (fin >> elem)
			{
				list.get_list().push_back(elem);
			}
		}
		catch (const FailedToReadFile& exception)
		{
			std::cout << "� ����� ���������� ������������ ������! ������ �� ���� ������������.\n";
			return;
		}
		std::cout << "�������� ����� ������ �� �����!\n";
		fin.close();
	}
	else
		std::cout << "�� ������� ������� ����!\n";
}

void print_to_console(StudentsList students)
{
	std::cout << "���������� ������:\n";
	if (!students.get_list().empty())
	{
		int i = 0;
		std::list<Student> students_list = students.get_list();
		for (auto elem : students_list)
		{
			std::cout << "�" << ++i << "\n";
			std::cout << elem << "\n\n";
		}
	}
	else
		std::cout << "����!\n";
}

void serialization_execution(StudentsList list);

void filter_execution(StudentsList list, std::string(Student::* get_value)())
{
	std::string parameter;
	std::cout << "������� ��������, ������������ ��� ����������:\t";
	std::cin >> parameter;
	StudentsList filtered;
	filtered.set_list(list.filter(get_value, parameter));
	print_to_console(filtered);
	if (!filtered.get_list().empty())
		serialization_execution(filtered);
}

void filter_execution(StudentsList list, size_t(Student::* get_value)())
{
	std::cout << "������� ��������, ������������ ��� ����������:\t";
	size_t parameter = (size_t)integer_input();
	StudentsList filtered;
	filtered.set_list(list.filter(get_value, parameter));
	print_to_console(filtered);
	if (!filtered.get_list().empty())
		serialization_execution(filtered);
}

void serialize(JSONSerializer js, StudentsList list)
{
	std::string filename = filename_input();
	filename += ".json";
	std::ofstream fout(filename);
	std::list<Student> students = list.get_list();
	std::string result = "[\n";
	auto before_end = --students.end();

	for (auto iter = students.begin(); iter != students.end(); ++iter)
	{
		result += js.serialize(*iter);
		if (iter != before_end)
			result += ",\n";
	}

	result += "\n]";
	fout << result;
	fout.close();
}

void serialize(TXTSerializer txt, StudentsList list)
{
	std::string filename = filename_input();
	filename += ".txt";
	std::ofstream fout(filename);
	std::list<Student> students = list.get_list();
	for (auto elem : students)
	{
		fout << txt.serialize(elem);
	}
	fout.close();
}

void serialize(XMLSerializer xml, StudentsList list)
{
	std::string filename = filename_input();
	filename += ".xml";
	std::ofstream fout(filename);
	std::list<Student> students = list.get_list();
	fout << "<studentslist>\n";
	for (auto elem : students)
	{
		fout << xml.serialize(elem);
	}
	fout << "</studentslist>";
	fout.close();
}

void serialization_execution(StudentsList list)
{
	int choice = 10;
	print_serialization();
	while (choice > 3 || choice < 0)
	{
		choice = integer_input();
		switch (choice)
		{
		case 1:
		{
			JSONSerializer js;
			serialize(js, list);
		}
		break;
		case 2:
		{
			TXTSerializer txt;
			serialize(txt, list);
		}
		break;
		case 3:
		{
			XMLSerializer xml;
			serialize(xml, list);
		}
		break;
		case 0:
			std::cout << "������� � ������� ����...\n";
			break;
		default:
			std::cout << "�������� ����� �� �������� ������� ����!\n";
			break;
		}
	}
}

void task_menu(StudentsList& list)
{
	int choice = 10;
	print_task_menu();
	while (choice > 5 || choice < 0)
	{
		choice = integer_input();
		switch (choice)
		{
		case 1:
			filter_execution(list, &Student::get_surname);
			break;
		case 2:
			filter_execution(list, &Student::get_name);
			break;
		case 3:
			filter_execution(list, &Student::get_middlename);
			break;
		case 4:
			filter_execution(list, &Student::get_course);
			break;
		case 5:
			filter_execution(list, &Student::get_group);
			break;
		case 0:
			std::cout << "�������...\n";
			break;
		default:
			std::cout << " �������� ����� �� �������� ������� ����!\n";
			break;
		}
	}
}

void main_menu(StudentsList& list)
{
	int choice = 1;
	while (choice != 0)
	{
		print_main_menu();
		choice = integer_input();
		switch (choice)
		{
		case 1:
			read_from_file(list);
			break;
		case 2:
			if (!list.get_list().empty())
				task_menu(list);
			else
				std::cout << "���������� ������� ������ ����������!\n";
			break;
		case 3:
			print_to_console(list);
			break;
		case 4:
			serialization_execution(list);
			break;
		case 0:
			std::cout << "����� �� ���������...\n";
			break;
		default:
			std::cout << "�������� ����� �� �������� ������� ����!\n";
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	StudentsList students;
	main_menu(students);
	std::cin.get();
	return 0;
}