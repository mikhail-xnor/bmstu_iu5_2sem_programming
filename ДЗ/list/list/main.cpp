#include <iostream>
#include "class_list.h"

int main()
{
	setlocale(0, "ru");
	list<int> a, c(a);
	for (int i = 0; i != 10; ++i)
		a.push_back(i);
	list<int> b(a);
	/*for (int i = 0; i != 10; ++i)
		std::cout << a.pop_back();*/
	list<int>::iterator it;
	for (it = b.begin(); it != b.end(); )
		if (*it == 6 || *it == 4 || *it == 9 || *it == 0 || *it == 5)
			b.erase(it);
		else
			++it;
	for (it = b.begin(); it != b.end(); ++it)
		std::cout << *it;
	it = b.begin();
	++it;
	*it = 6;
	std::cout << *it;
	for (it = b.begin(); it != b.end(); ++it)
		std::cout << *it;
	/*list<int>::iterator it = a.begin();
	for (it = a.begin(); it != a.end(); ++it)
		std::cout << *it;
	std::cout << "\n";
	it = a.begin();
	++it;
	++it;
	*it = 99;
	it.erase();
	for (it = a.begin(); it != a.end(); ++it)
		std::cout << *it;
	std::cout << "\n";
	*/
	system("pause");
	return 0;
}