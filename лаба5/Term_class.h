#pragma once
#include <iostream>
#include "Polinom_class.h"
class Polinom;
class Term
{
	int power;
	int koef;
public:
	Term();
	Term(int);
	Term(int, int);
	Term operator+(const Term&); //
	friend std::ostream &operator<<(std::ostream&, const Term&);
	friend class Polinom;
	friend std::ostream& operator<<(std::ostream&, const Polinom&);
	friend Polinom operator*(const Polinom&, const Polinom&);
};