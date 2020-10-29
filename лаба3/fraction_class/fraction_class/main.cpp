#include "class_fraction.h"
#include <iomanip>

int main()
{
	Fraction a(6, 11), b(3, 5), c(99, 101);
	std::cout << 3.11 * a * ((b * a - b) / 2) + 4 * c * b << std::endl;
	system("pause");
	return 0;
}