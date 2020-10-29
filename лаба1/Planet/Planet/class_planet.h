#pragma once
#include <string>

class Planet
{
	std::string name;
	int diam;
	int count_of_satellites;
	bool is_life;
public:
	Planet() {}
	Planet(const std::string&, const int&, const int&, const bool&);
	Planet(const Planet&);
	~Planet() {}

	void set_name(const std::string&);
	void set_diam(const int&);
	void set_count_of_satellites(const int&);
	void set_is_life(const bool&);

	std::string get_name();
	int get_diam();
	int get_count_of_satellites();
	bool get_is_life();
	
	friend std::ostream &operator<<(std::ostream&, const Planet&);
	static bool check_name_planet(std::string n, Planet *pl, int count);
	static void sorting(Planet *pl, int choise, int count);
	static void swap(Planet&, Planet&);
};
