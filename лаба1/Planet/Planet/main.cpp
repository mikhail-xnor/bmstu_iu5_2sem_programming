#include <iostream>
#include "class_planet.h"

Planet set_planet(Planet *pl, int count)
{
	using std::string;
	using std::cout;
	using std::cin;
	string name;
	int diam, count_sat, is;
	bool exist = false;
	while (!exist)
	{
		std::cout << "\nEnter name: ";
		std::cin >> name;
		exist = Planet::check_name_planet(name, pl, count);
		if (!exist)
			cout << "\nError! This name is already is used!\n";
	}
	std::cout << "\nEnter diameter: ";
	std::cin >> diam;
	cout << "\nEnter count of satellites: ";
	cin >> count_sat;
	cout << "\nEnter life factor, 1 - exist, 0 - not exist: ";
	cin >> is;
	return Planet(name, diam, count_sat, is);
}

int main()
{
	using namespace std;
	char what_to_do = 1;
	int count;
	cout << "Count of planets: ";
	cin >> count;
	Planet *mas = new Planet[count];
	for (int i = 0; i != count; ++i)
	try
	{
			mas[i] = set_planet(mas, count);
	}
	catch (exception &ex)
	{
		--i;
		cout << "\n" << ex.what() << " Try again!";
	}
	while (what_to_do != '0')
	{
		try
		{
			cout << "\nEnter:\n\t";
			cout << "0 - exit\n\t";
			cout << "1 - change all params\n\t";
			cout << "2 - change specific param\n\t";
			cout << "3 - show all information about planets\n\t";
			cout << "4 - sorting planets\n";
			cin >> what_to_do;
			switch (what_to_do)
			{
			case '1':
			{
				int index;
				cout << "\n\tEnter number of planet: ";
				cin >> index;
				--index;
				if (index < 0 || index >= count)
					throw exception("Invalid number of planet!");
				else
					mas[index] = set_planet(mas, count);
			}
				break;
			case '2':
			{
				int index;
				cout << "\n\tEnter number of planet: ";
				cin >> index;
				--index;
				if (index < 0 || index >= count)
				{
					throw exception("Invalid number of planet!");
				}
				else
				{
					int choise;
					cout << "\n\t1 - change name: ";
					cout << "\n\t2 - change diameter: ";
					cout << "\n\t3 - change count of satellites: ";
					cout << "\n\t4 - change - life factor, 1 - exist, 0 - not exist: \n";
					cin >> choise;
					switch (choise)
					{
					case 1:
					{
						string new_name;
						bool exist = false;
						while (!exist)
						{
							std::cout << "\nEnter name: ";
							std::cin >> new_name;
							exist = Planet::check_name_planet(new_name, mas, count);
							if (!exist)
								cout << "\nError! This name is already is used!\n";
						}
						mas[index].set_name(new_name);
					}
					break;
					case 2:
					{
						int diam;
						cout << "\nEnter diameter: ";
						cin >> diam;
						mas[index].set_diam(diam);
					}
					break;
					case 3:
					{
						int count_s;
						cout << "\nEnter count of satellites: ";
						cin >> count_s;
						mas[index].set_count_of_satellites(count_s);
					}
					break;
					case 4:
					{
						bool is;
						cout << "\nEnter life factor, 1 - exist, 0 - not exist: ";
						cin >> is;
						mas[index].set_is_life(is);
					}
					break;
					}
				}
			}
				break;
			case '3':
			{
				for (int i = 0; i != count; ++i)
				{
					cout << "\nPlanet number is " << i + 1 << "\n";
					cout << mas[i];
				}
			}
				break;
			case '4':
			{
				int choise;
				cout << "\n\tEnter: ";
				cout << "\n\t1 - sorting name: ";
				cout << "\n\t2 - sorting diameter: ";
				cout << "\n\t3 - sorting count of satellites: \n";
				cin >> choise;
				Planet::sorting(mas, choise, count);
			}
				break;
			}
		}
		catch (exception &ex)
		{
			cout << "\n" << ex.what();
		}
	}
	system("pause");
	return 0;
}