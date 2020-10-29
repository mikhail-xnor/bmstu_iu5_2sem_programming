#include "Polinom_class.h"
bool Polinom::order = true;

Polinom::Polinom()
{}

Polinom::Polinom(int k)
{
	for (int i = 0; i != k; ++i)
		poly.push_back(Term());
}

Polinom::Polinom(const Term& tm)
{
	poly.push_back(tm);
}

Polinom::Polinom(const Polinom &p)
{
	poly = p.poly;
	for (int i = 0; i != poly.size(); ++i)
		for (int j = i + 1; j != poly.size(); ++j)
			if (poly[i].power == poly[j].power)
			{
				poly[i] = poly[i] + poly[j];
				poly.erase(j, j);
				--j;
			}
	for (int i = 0; i != poly.size(); ++i)
		for (int j = 0; j != poly.size() - i - 1; ++j)
			if (order ? (poly[j].power > poly[j + 1].power) : (poly[j].power < poly[j + 1].power))
			{
				Term a = poly[j];
				poly[j] = poly[j + 1];
				poly[j + 1] = a;
			}
}

Polinom Polinom::operator=(const Polinom &p)
{
	poly = p.poly;
	for (int i = 0; i != poly.size(); ++i)
		for (int j = i + 1; j != poly.size(); ++j)
			if (poly[i].power == poly[j].power)
			{
				poly[i] = poly[i] + poly[j];
				poly.erase(j, j);
				--j;
			}
	/*for (int i = 0; i != poly.size(); ++i)
		for (int j = 0; j != poly.size() - 1 - i; ++j)
			if (poly[j].power > poly[j + 1].power)
			{
				Term a = poly[j];
				poly[j] = poly[j + 1];
				poly[j + 1] = a;
			}*/
	return *this;
}

Polinom Polinom::operator+=(const Polinom &p)
{
	return *this = *this + p;
}

Polinom Polinom::operator*=(const Polinom &p)
{
	return *this = *this + p;
}

void Polinom::set_order(bool q)
{
	order = q;
}

Polinom operator*(const Polinom& p1, const Polinom& p2)
{
	Polinom a;
	for (int i = 0; i != p1.poly.size(); ++i)
		for (int j = 0; j != p2.poly.size(); ++j)
			a.poly.push_back(Term(p1.poly[i].koef * p2.poly[j].koef, p1.poly[i].power + p2.poly[j].power));
	return a;
}

Polinom operator+(const Polinom& p1, const Polinom& p2)
{
	Polinom a;
	for (int i = 0; i != p1.poly.size(); ++i)
		a.poly.push_back(p1.poly[i]);
	for (int i = 0; i != p2.poly.size(); ++i)
		a.poly.push_back(p2.poly[i]);
	return a;
}

std::istream& operator>>(std::istream& stream, Polinom& p)
{
	int pos;
	p.poly.erase();
	std::string str;
	std::getline(stream, str);
	while ((pos = str.find_first_of(" ()")) != std::string::npos)
		str.erase(pos, 1);
	char zn = '+';
	while (str != "")
	{
		int tmp;
		if ((tmp = str.find_first_of("+-")) == std::string::npos)
			tmp = str.length();
		if (!tmp)
		{
			zn = str[0] == zn ? '+' : '-';
			str.erase(0, 1);
		}
		else
		{
			int tmp_sym;  
			p.poly.push_back((tmp_sym = str.find_first_of("x")) < tmp && tmp_sym != std::string::npos ? (str.find_first_of("^") < tmp && str.find_first_of("^") != std::string::npos ? Term((zn == '-' ? -1 : 1) * (tmp_sym == 0 ? 1 : atoi(str.substr(0, tmp_sym).c_str())), atoi(str.substr(tmp_sym + 2, tmp - tmp_sym - 2).c_str())) : Term((zn == '-' ? -1 : 1) * (tmp_sym == 0 ? 1 : atoi(str.substr(0, tmp_sym).c_str())), 1)) : Term((zn == '-' ? -1 : 1) * atoi(str.substr(0, tmp).c_str())));
			zn = '+';
			str.erase(0, tmp);
		}
	}
	p = Polinom(p);
	return stream;
}

std::ostream& operator<<(std::ostream &stream, const Polinom &p)
{
	for (int i = 0; i != p.poly.size(); ++i)
	{
		if (p.poly[i].koef != 0)
			stream << (p.poly[i].koef < 0 ? "- " : (i && p.poly[i].koef >= 0 ? "+ " : "")) << Term((p.poly[i].koef < 0 ? -1 : 1) * p.poly[i].koef, p.poly[i].power) << ' ';
	}
	return stream;
}
