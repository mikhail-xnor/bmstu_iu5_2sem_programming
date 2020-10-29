#include "class_planet.h"

Planet::Planet(const std::string& n, const int& d, const int& count_sat, const bool& is_l)
{
	name = n;
	set_diam(d);
	set_count_of_satellites(count_sat);
	is_life = is_l;
}

Planet::Planet(const Planet& pl)
{
	name = pl.name;
	diam = pl.diam;
	count_of_satellites = pl.count_of_satellites;
	is_life = pl.is_life;
}

void Planet::set_name(const std::string &n)
{
	name = n;
}

void Planet::set_diam(const int &d)
{
	diam = d > 0 ? d : throw std::exception("Invalid diameter!");
}

void Planet::set_count_of_satellites(const int &count)
{
	count_of_satellites = count >= 0 ? count : throw std::exception("Invalid count!");
}

void Planet::set_is_life(const bool &is)
{
	is_life = is;
}

std::string Planet::get_name()
{
	return name;
}

int Planet::get_diam()
{
	return diam;
}

int Planet::get_count_of_satellites()
{
	return count_of_satellites;
}

bool Planet::get_is_life()
{
	return is_life;
}

std::ostream& operator<<(std::ostream &stream, const Planet &pl)
{
	stream << "Name of the planet: " << pl.name << "\n";
	stream << "Diameter of the planet: " << pl.diam << "\n";
	stream << "Count of satellites: " << pl.count_of_satellites << "\n";
	stream << "Life on the planet: " << (pl.is_life ? "exist" : "not exist") << "\n";
	return stream;
}

bool Planet::check_name_planet(std::string n, Planet *pl, int count)
{
	for (int i = 0; i != count; ++i)
		if (n == pl[i].get_name())
			return false;
	return true;
}

void Planet::sorting(Planet *pl, int choise, int count)
{
	switch (choise)
	{
	case 1:
		for (int i = 0; i != count; ++i)
			for (int j = i; j != count; ++j)
				if (pl[i].get_name() > pl[j].get_name())
					Planet::swap(pl[i], pl[j]);

		break;
	case 2:
		for (int i = 0; i != count; ++i)
			for (int j = i; j != count; ++j)
				if (pl[i].get_diam() < pl[j].get_diam())
					Planet::swap(pl[i], pl[j]);
		break;
	case 3:
		for (int i = 0; i != count; ++i)
			for (int j = i; j != count; ++j)
				if (pl[i].get_count_of_satellites() < pl[j].get_count_of_satellites())
					Planet::swap(pl[i], pl[j]);
		break;
	}
}

void Planet::swap(Planet &a, Planet &b)
{
	Planet c = a;
	a = b;
	b = c;
}
