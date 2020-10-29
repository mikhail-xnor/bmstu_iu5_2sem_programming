#include <iostream>
#include "Polinom_class.h"


int main()
{
	Polinom a, b;
	char sym = 1;
	bool order = true;
	while (sym)
	{
		std::cin.ignore();
		std::cout << "Enter first polinom:\n";
		std::cin >> a;
		std::cout << a << "\n";
		std::cout << "Enter second polinom:\n";
		std::cin >> b;
		std::cout << b << "\n";
		std::cout << "Enter operator (enter 0 to exit or enter \"d\" to change sorting):\n";
		//std::cin.ignore();
		std::cin >> sym;
		std::cout << "Result: \n";
		switch (sym)
		{
		case '+':
			std::cout << a + b << "\n";
			break;
		case '*':
			std::cout << a * b << "\n";
			break;
		case 'd':
			Polinom::set_order(order = !order);
			break;
		}
	}
}