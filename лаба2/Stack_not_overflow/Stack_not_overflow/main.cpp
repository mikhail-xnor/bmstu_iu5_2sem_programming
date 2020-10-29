#include "class_stack.h"

int main()
{
	Stack a;
	int num;
	while (true)
	{
		std::cout << "Enter number: ";
		std::cin >> num;
		a = num;
		std::cout << "Simple factors:";
		std::cout << "\n" << a << "\n";
		a = num;
		a.reverse();
		std::cout << "Reverse simple factors:";
		std::cout << "\n" << a << "\n";
	}
	system("pause");
	return 0;
}