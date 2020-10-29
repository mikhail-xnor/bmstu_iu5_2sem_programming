#pragma once
#include "class_list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>

struct Date
{
	int day;
	int month;
	int year;
};

struct FileInfo
{
	std::string name;
	std::string date_of_creation;
	int count_of_open;
};

FileInfo get_file_info(std::string &str)
{
	FileInfo f;
	f.name = str.substr(0, str.find_first_of('|'));
	str.erase(0, str.find_first_of('|') + 1);
	f.date_of_creation = str.substr(0, str.find_first_of('|'));
	str.erase(0, str.find_first_of('|') + 1);
	f.count_of_open = atoi(str.substr(0, str.find_first_of('|')).c_str());
	str.erase(0, str.find_first_of('|') + 1);
	return f;
}

void stream_out_folder_info(const list<FileInfo> &folder)
{
	std::cout << "\n==============================================================\n";
	std::cout << "Name          Date of creation                  Count of opens";
	std::cout << "\n==============================================================\n";
	if (!folder.empty())
	{
		for (list<FileInfo>::iterator it = folder.begin(); it != folder.end(); ++it)
		{
			std::cout << "--------------------------------------------------------------\n";
			std::cout << std::left << (*it).name << std::right << std::setw(24 - (*it).name.length()) << (*it).date_of_creation << std::left << "                        " << (*it).count_of_open << "\n";
			std::cout << "--------------------------------------------------------------\n";
		}
	}
	else
	{
		std::cout << "No any folders here!\n";
	}
}

double date_to_age(Date comp, Date practicants)
{
	int mon[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	double year = comp.year - practicants.year, days = comp.day - practicants.day;
	int k = 0;
	if (comp.month < practicants.month)
		k = 1;
	while (comp.month != practicants.month)
	{
		comp.month += -1 + 2 * k;
		days += (1 - 2 * k) * mon[comp.month - k - 1];
		if ((!(comp.year % 4) && (comp.year % 100) || !(comp.year % 400)) && (comp.month - k == 2))
			days += 1 - 2 * k;
	}
	if (!(comp.year % 4) && (comp.year % 100) || !(comp.year % 400))
		year += days / 366;
	else
		year += days / 365;

	return year;
}

Date get_date(std::string str)
{
	Date d;
	d.day = atoi(str.substr(0, str.find_first_of('.')).c_str());
	str.erase(0, str.find_first_of('.') + 1);
	d.month = atoi(str.substr(0, str.find_first_of('.')).c_str());
	str.erase(0, str.find_first_of('.') + 1);
	d.year = atoi(str.substr(0, str.length()).c_str());
	str.erase(0, str.length());
	return d;
}