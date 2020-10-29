#include <iostream>
#include <windows.h>
#include <fstream>
#include "ClassTree.h"

using namespace std;

string format(string& str)
{
	string cop_str = str.substr(0, str.find_first_of(' '));
	str.erase(0, str.find_first_of(' ') + 1);
	int count = 28 - cop_str.length();
	for (int i = 0; i != count; ++i)
		cop_str += ' ';
	cop_str += str;
	return cop_str;
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name_of_file = "info", str;
	fstream file;
	Tree tree_of_workers;
	unsigned short int action;
	while (!file.is_open())
	{
		cout << "Чтобы создать новый файл введите - 0; \nЧтобы загрузить базу из файла введите - 1; \nЧтобы заполнить файл для теста введите - 2:\n";
		cin >> action;
		cin.ignore();
		switch (action)
		{
		case 1:
			cout << "Введите имя файла(без \".txt\"): ";
			getline(cin, name_of_file);
			file.open(name_of_file + ".txt", ios::in);
			if (file.is_open())
				while (!file.eof())
				{
					getline(file, str);
					if (str != "")
						tree_of_workers.push(str);
				}
			else
				cout << "Файл не найден!\n\n";
			break;
		case 0:
			cout << "Введите имя файла(без \".txt\"): ";
			getline(cin, name_of_file);
			file.open(name_of_file + ".txt", ios::out);
			break;
		case 2:
			file.open(name_of_file + ".txt", ios::out);
			tree_of_workers.push("Кравцов                     НА 2000 10000");
			tree_of_workers.push("Мошкин                      ВС 2000 10000");
			tree_of_workers.push("Кирилов                     ХА 2000 10009");
			tree_of_workers.push("Зноев                       АА 2000 10001");
			tree_of_workers.push("Мухов                       ЦЦ 2000 10004");
			tree_of_workers.push("Петрович                    ЭЭ 2000 200000");
			break;
		}
	}
	file.close();
	action = 1;
	while (action)
	{
		cout << "\n" << tree_of_workers;
		string* choice = new string;
		*choice = "";
		cout << "\nЧто вы хотите сделать?\n";
		cout << "Измеить информацию о сотруднике введите - 1; \nДобавить нового сотрудника введите - 2; \nСохранить и завершить работу введите - 0:\n";
		cin >> action;
		cin.ignore();
		switch (action)
		{
		case 1:
			cout << "Поиск сотрудника по фамилии введите - 1; \nСамый высокооплачиваемый сотрудник введите - 2:\n";
			cin >> action;
			cin.ignore();
			
			switch (action)
			{
			case 1:
				cout << "Введите фамилию: ";
				cin >> str;
				choice = tree_of_workers.find(str);
				break;
			case 2:
				choice = tree_of_workers.find_max();
				break;
			}
			cout << *choice << "\nЧтобы изменить информацию введите - 1; \nВ противном случае введите - 2\n";
			cin >> action;
			cin.ignore();
			if (action == 1)
			{
				cout << "\nВведите все данные в формате(Фамилия ИО гггг оклад):\n";
				getline(cin, str);
				str = format(str);
				*choice = str;
			}
			break;
		case 2:
			cout << "\nВведите все данные в формате(Фамилия ИО гггг оклад):\n";
			getline(cin, str);
			str = format(str);
			tree_of_workers.push(str);
			break;
		}
	}
	file.open(name_of_file + ".txt", ios::out);
	if (file.is_open());
		file << tree_of_workers;
	system("pause");
	return 0;
}