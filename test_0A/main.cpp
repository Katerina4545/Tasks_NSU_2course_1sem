#include "module1.h"
#include "module2.h"
#include <iostream>

namespace Module3 
{
	std::string getMyName() 
	{
		std::string name = "Peter";
		return name;
	}
}

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	using namespace Module1;
	std::cout << getMyName() << "\n"; // (A) ��������� "John"
	std::cout << Module2::getMyName() << "\n";

	//using namespace Module2; // (B)
	//std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (D) ��������� "James"

}

/*
	���������, ��� ������������������ ����� (B) � (C) � main.cpp �������� � ������ ����������. 
	���������, ������ ��� ������ ����������, � ���������� ���� � ����������.

1)
std::cout << Module2::getMyName() << "\n";

2)
������������ ���������� namespace ��� Module2,
����� ��� ��� ������� �� ����� ��������� ������������, � ��� Module1 ����� 


	���������, ��� ����� ���������� �� ������������� ������ std::cout � ������ ����� ������ ������ cout.

�������� std ��� ���������� ������������
using namespace std;
*/