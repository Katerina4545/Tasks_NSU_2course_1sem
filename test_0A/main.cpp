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
	std::cout << getMyName() << "\n"; // (A) выведетс€ "John"
	std::cout << Module2::getMyName() << "\n";

	//using namespace Module2; // (B)
	//std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

	using Module2::getMyName;
	std::cout << getMyName() << "\n"; // (D) выведетс€ "James"

}

/*
	”бедитьс€, что раскомментирование строк (B) и (C) в main.cpp приводит к ошибке компил€ции. 
	ќбъ€снить, почему эта ошибка происходит, и предложить пути еЄ устранени€.

1)
std::cout << Module2::getMyName() << "\n";

2)
использовать безым€нный namespace дл€ Module2,
тогда дл€ его функции не нужно указывать пространство, а дл€ Module1 нужно 


	ќбъ€снить, как можно избавитьс€ от необходимости писать std::cout и вместо этого писать просто cout.

объ€вить std как глобальное пространство
using namespace std;
*/