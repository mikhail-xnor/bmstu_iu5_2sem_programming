#include "Term_class.h"

Term::Term()
{
	power = 0;
	koef = 0;
}

Term::Term(int k)
{
	power = 0;
	koef = k;
}

Term::Term(int k, int p)
{
	power = p;
	koef = k;
}

Term Term::operator+(const Term &t)
{
	if (t.power != power)
		throw std::exception("The powers of Terms is not equal!");
	return Term(t.koef + koef, power);
}

std::ostream& operator<<(std::ostream &stream, const Term &t)
{
	stream << (t.koef < 0 ? "- " : "");
	if (t.koef != -1 && t.koef != 1 || t.power == 0)
		stream << (t.koef < 0 ? -t.koef : t.koef);
	if (t.koef != 0)
		stream << (t.power > 0 ? "x" : "") << (t.power > 1 && t.koef ? "^" + std::to_string(t.power) : "");
	return stream;
}


