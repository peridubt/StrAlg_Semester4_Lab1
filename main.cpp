#include <iostream>
#include "Serializer.h"
#include "JSONSerializer.h"

/*
������� ������, 91 ������

1. ���� ����� ������� (4-5 ����� �� �����). ���� ������� ����� ������������, �������
��������� ������ � �������� � ��������� ������. � ������������� ��� ����������, �������
��������� ������ � .xml, .json � ������� ����� ��������������. ��� ������ ���������
����������� ����������� ���������� �� �������� ���������� � ������������ ���� ������
� �������� �������.
*/

int main()
{
	Student st;
	JSONSerializer js;
	std::string lol = js(st);
	std::cin.get();
	return 0;
}