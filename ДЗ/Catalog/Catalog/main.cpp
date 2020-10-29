#include "main_functions.h"

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string name_of_file = "folder_info", str;
	std::fstream file;
	list<FileInfo> catalog;
	unsigned short int action;
	while (!file.is_open())
	{
		std::cout << "What do you want to do? \n\nCreate new empty catalog, enter - 0; \nLoad catalog from file, enter - 1; \nFill new catalog with random files, enter - 2:\n";
		std::cin >> action;
		std::cin.ignore();
		switch (action)
		{
		case 1:
			std::cout << "Enter name of file (without \".txt\"): ";
			std::getline(std::cin, name_of_file);
			file.open(name_of_file + ".txt", std::ios::in);
			if (file.is_open())
				while (!file.eof())
				{
					std::getline(file, str);
					if (str != "")
						catalog.push_back(get_file_info(str));
				}
			else
				std::cout << "This file not found!\n\n";
			break;
		case 0:
			file.open(name_of_file + ".txt", std::ios::out);
			break;
		case 2:
			file.open(name_of_file + ".txt", std::ios::out);
			srand(time(NULL));
			for (int i = 0; i != 10; ++i)
			{
				str = "";
				for (int j = 0; j != 4; ++j)
					str += (char)(rand() % 48 - 64);
				str += '|';
				str += std::to_string(rand() % 19 + 10) + '.';
				str += std::to_string(rand() % 3 + 10) + '.';
				str += std::to_string(rand() % 70 + 1950);
				str += '|';
				str += std::to_string(rand() % 10000);
				str += '|';
				catalog.push_back(get_file_info(str));
			}
			break;
		}
	}
	file.close();
	action = 1;
	while (action)
	{
		list<FileInfo>::iterator it;
		bool choice = false;
		stream_out_folder_info(catalog);
		std::cout << "\nWhat do you want to do?\n";
		std::cout << "Interact with file, enter - 1; \nDelete files with date earlier then, enter - 2; \nInteract with file, which have most of all interactions, enter - 3; \nAdd new file, enter - 4; \nSave and finish work, enter - 0:\n";
		std::cin >> action;
		std::cin.ignore();
		switch (action)
		{
		case 4:
		{
			FileInfo* f = new FileInfo;
			std::cout << "Enter name of file: ";
			std::getline(std::cin, str);
			f->name = str;
			std::cout << "Enter date (dd.mm.yyyy): ";
			std::getline(std::cin, str);
			f->date_of_creation = str;
			f->count_of_open = 0;
			catalog.push_back(*f);
			break;
		}
		case 2:
			if (!catalog.empty())
			{
				std::cout << "Enter date (dd.mm.yyyy): ";
				std::getline(std::cin, str);
				Date now = get_date(str);
				for (it = catalog.begin(); it != catalog.end();)
					if (date_to_age(now, get_date((*it).date_of_creation)) > 0)
						catalog.erase(it);
					else
						++it;
			}
			break;
		case 3:
			if (!catalog.empty())
			{
				choice = true;
				it = catalog.begin();
				int max = (*it).count_of_open;
				for (list<FileInfo>::iterator iter = catalog.begin(); iter != catalog.end(); ++iter)
					if ((*iter).count_of_open > max)
					{
						max = (*iter).count_of_open;
						it = iter;
					}
			}
			else
			{
				std::cout << "Catalog is empty!";
			}
			;
		case 1:
			if (action == 1)
			{
				std::cout << "Enter name of file: ";
				std::getline(std::cin, str);
				for (it = catalog.begin(); it != catalog.end() && !(choice = (*it).name == str); ++it);
			}
			if (choice)
			{
				std::cout << "Add count of interaction, enter - 1; \nDelete file, enter - 2:\n";
				std::cin >> action;
				std::cin.ignore();
				switch (action)
				{
				case 1:
					++(*it).count_of_open;
					break;
				case 2:
					catalog.erase(it);
					break;
				}
			}
		}
	}
	file.open(name_of_file + ".txt", std::ios::out);
	if (file.is_open())
		for (list<FileInfo>::iterator it = catalog.begin(); it != catalog.end(); ++it)
			file << (*it).name + '|' + (*it).date_of_creation + '|' + std::to_string((*it).count_of_open) + '|' + '\n';
	system("pause");
	return 0;
}