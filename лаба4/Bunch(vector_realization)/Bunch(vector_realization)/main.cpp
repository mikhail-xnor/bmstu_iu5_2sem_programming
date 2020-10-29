#include <iostream>
#include "class_bunch.h"

int main()
{
	setlocale(0, "ru");
	Bunch<int> b, a;
	int num;
	char sign;
	while (true)
	{
		try
		{
			std::cout << "Enter first bunch: \n";
			std::cin >> a;
			std::cout << "Enter sign: \n";
			std::cin >> sign;
			if (sign != '/')
			{
				std::cout << "Enter second bunch: \n";
				std::cin >> b;
			}
			else
			{
				std::cout << "Enter element to delete: \n";
				std::cin >> num;
			}
			std::cout << "Result: \n";
			switch (sign)
			{
			case '+':
				std::cout << a + b;
				break;
			case '-':
				std::cout << a - b;
				break;
			case '=':
				std::cout << (a == b);
				break;
			case '*':
				std::cout << a * b;
				break;
			case '/':
				a.erase(a.find(num));
				std::cout << a;
				break;
			}
			std::cout << "\n\n";
		}
		catch (std::exception &ex)
		{
			std::cout << "\n" << ex.what() << "\n";
		}
	}
	system("pause");
	return 0;
}