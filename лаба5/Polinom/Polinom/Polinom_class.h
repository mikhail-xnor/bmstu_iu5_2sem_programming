#pragma once
#include <string>
#include "Term_class.h"
#include "../../../../../MY_PROJECTS/VisualStudio/My_Vector/My_Vector/my_vector.h"
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
	static void set_order(bool); // если передать значение true, то по возрастанию, иначе по убыванию (поумолчанию true)
};