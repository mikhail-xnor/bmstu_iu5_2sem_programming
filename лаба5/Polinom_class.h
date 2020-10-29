#pragma once
#include <string>
#include "Term_class.h"
#include "my_vector.h"
class Term;
class Polinom
{
	my_vector<Term> poly;
	static bool order;
public:
	Polinom();
	Polinom(int);
	Polinom(const Term&);
	Polinom(const Polinom&); //
	friend Polinom operator+(const Polinom&, const Polinom&); // friend
	friend Polinom operator*(const Polinom&, const Polinom&); // friend
	Polinom operator=(const Polinom&); //
	Polinom operator+=(const Polinom&); //
	Polinom operator*=(const Polinom&); //
	friend std::istream& operator>>(std::istream&, Polinom&);
	friend std::ostream& operator<<(std::ostream&, const Polinom&);
	friend std::ostream& operator<<(std::ostream&, const Term&);
	static void set_order(bool); // åñëè ïåðåäàòü çíà÷åíèå true, òî ïî âîçðàñòàíèþ, èíà÷å ïî óáûâàíèþ (ïîóìîë÷àíèþ true)
};