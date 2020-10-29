#include "class_fraction.h"

uint8_t Fraction::accuracy = 4;

Fraction::Fraction()
{
	isNegative = false;
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(const Fraction &n) 
{
	numerator = n.numerator;
	isNegative = n.isNegative;
	denominator = n.denominator;
	evqlid();
}

Fraction::Fraction(int b)
{
	numerator = abs(b);
	denominator = 1;
	isNegative = b < 0 ? true : false;
}

Fraction::Fraction(int b, int c)
{
	if (c != 0)
	{
		numerator = abs(b);
		denominator = abs(c);
		isNegative = b * c < 0 ? true : false;
		evqlid();
	}
	else
	{
		*this = Fraction();
	}
}

Fraction::Fraction(int a, int b, int c)
{
	if (c != 0)
	{
		numerator = abs(b) + abs(a) * abs(c);
		denominator = abs(c);
		isNegative = a * b * c < 0 ? true : false;
		evqlid();
	}
	else
	{
		*this = Fraction(); 
	}
}

Fraction::Fraction(double n)
{
	denominator = 1;
	for (int i = 0; i != accuracy; ++i)
	{
		n *= 10;
		denominator *= 10;
	}
	numerator = abs(n);
	numerator += (int)(n * 10) % 10 > 4 ? 1 : 0;
	isNegative = n < 0 ? true : false;
	evqlid();
}

void Fraction::set_accuracy(uint8_t n)
{
	accuracy = n;
}

void Fraction::evqlid()
{
	register int i = 2;
	while (numerator >= i && denominator >= i)
	{
		if (!(numerator % i) && !(denominator % i))
		{
			numerator /= i;
			denominator /= i;
		}
		else
		{
			++i;
		}
	}
	if (!numerator)
		denominator = 1;
}

Fraction Fraction::operator-()
{
	Fraction n = *this;
	n.isNegative = !n.isNegative;
	return n;
}

Fraction Fraction::operator=(const Fraction &n)
{
	numerator = n.numerator;
	isNegative = n.isNegative;
	denominator = n.denominator;
	return *this;
}

Fraction Fraction::operator=(int n)
{
	return *this = Fraction(n);
}

Fraction Fraction::operator=(double n)
{
	return *this = Fraction(n);
}

Fraction Fraction::operator*(int n)
{
	return *this * Fraction(n);
}

Fraction Fraction::operator*(double n)
{
	return *this * Fraction(n);
}

Fraction Fraction::operator*(const Fraction &n)
{
	Fraction new_f = n;
	new_f.numerator *= numerator;
	new_f.denominator *= denominator;
	new_f.isNegative = (new_f.isNegative || isNegative) && !(new_f.isNegative && isNegative);
	return new_f;
}

Fraction Fraction::operator/(int n)
{
	return *this / Fraction(n);
}

Fraction Fraction::operator/(double n)
{
	return *this / Fraction(n);
}

Fraction Fraction::operator/(const Fraction &n)
{
	Fraction new_f = n;
	int a = new_f.numerator;
	new_f.numerator = new_f.denominator;
	new_f.denominator = a;
	return *this * new_f;
}

Fraction Fraction::operator+(int n)
{
	return *this + Fraction(n);
}

Fraction Fraction::operator+(double n)
{
	return *this + Fraction(n);
}

Fraction Fraction::operator+(const Fraction &n)
{
	Fraction new_f = n;
	numerator *= isNegative ? -1 : 1;
	new_f.numerator *= new_f.isNegative ? -1 : 1;
	new_f.numerator *= denominator;
	new_f.numerator += numerator * new_f.denominator;
	new_f.denominator *= denominator;
	new_f.isNegative = new_f.numerator < 0 ? true : false;
	new_f.numerator = abs(new_f.numerator);
	numerator = abs(numerator);
	return new_f;
}

Fraction Fraction::operator-(int n)
{
	return *this - Fraction(n);
}

Fraction Fraction::operator-(double n)
{
	return *this - Fraction(n);
}

Fraction Fraction::operator-(const Fraction &n)
{
	return *this + -const_cast <Fraction&> (n);
}

bool Fraction::operator>(int n)
{
	return *this > Fraction(n);
}

bool Fraction::operator>(double n)
{
	return *this > Fraction(n);
}

bool Fraction::operator>(const Fraction &n)
{
	Fraction new_f = n;
	int n_1, n_2;
	evqlid();
	new_f.evqlid();
	if (!isNegative && new_f.isNegative)
		return true;
	else if (isNegative && !new_f.isNegative)
		return false;
	n_1 = numerator * new_f.denominator;
	n_2 = new_f.numerator * denominator;
	n_1 *= isNegative ? -1 : 1;
	n_2 *= new_f.isNegative ? -1 : 1;
	if (n_1 > n_2)
		return true;
	return false;
}

bool Fraction::operator==(int n)
{
	return *this == Fraction(n);
}

bool Fraction::operator==(double n)
{
	return *this == Fraction(n);
}

bool Fraction::operator==(const Fraction &n)
{
	Fraction new_f = n;
	evqlid();
	new_f.evqlid();
	return numerator == new_f.numerator && denominator == new_f.denominator && isNegative == new_f.isNegative;
}

bool Fraction::operator!=(int n)
{
	return *this != Fraction(n);
}

bool Fraction::operator!=(double n)
{
	return *this != Fraction(n);
}

bool Fraction::operator!=(const Fraction &n)
{
	return !(*this == n);
}

bool Fraction::operator<(int n)
{
	return *this < Fraction(n);
}

bool Fraction::operator<(double n)
{
	return *this < Fraction(n);
}

bool Fraction::operator<(const Fraction &n)
{
	return !(*this > n) && *this != n;
}

bool Fraction::operator>=(int n)
{
	return *this >= Fraction(n);
}

bool Fraction::operator>=(double n)
{
	return *this >= Fraction(n);
}

bool Fraction::operator>=(const Fraction &n)
{
	return !(*this < n);
}

bool Fraction::operator<=(int n)
{
	return *this <= Fraction(n);
}

bool Fraction::operator<=(double n)
{
	return *this <= Fraction(n);
}

bool Fraction::operator<=(const Fraction &n)
{
	return !(*this > n);
}


Fraction operator*(int n, Fraction &F)
{
	return Fraction(n) * F;
}

Fraction operator*(double n, Fraction &F)
{
	return Fraction(n) * F;
}

Fraction operator/(int n, Fraction &F)
{
	return Fraction(n) / F;
}

Fraction operator/(double n, Fraction &F)
{
	return Fraction(n) / F;
}

Fraction operator+(int n, Fraction &F)
{
	return F + n;
}

Fraction operator+(double n, Fraction &F)
{
	return F + n;
}

Fraction operator-(int n, Fraction & F)
{
	return Fraction(n) - F;
}

Fraction operator-(double n, Fraction & F)
{
	return Fraction(n) - F;
}

bool operator>(int n, Fraction &F)
{
	return Fraction(n) > F;
}

bool operator>(double n, Fraction &F)
{
	return Fraction(n) > F;
}

bool operator==(int n, Fraction &F)
{
	return Fraction(n) == F;
}

bool operator==(double n, Fraction &F)
{
	return Fraction(n) == F;
}

bool operator!=(int n, Fraction &F)
{
	return Fraction(n) != F;
}

bool operator!=(double n, Fraction &F)
{
	return Fraction(n) != F;
}

bool operator<(int n, Fraction &F)
{
	return Fraction(n) < F;
}

bool operator<(double n, Fraction &F)
{
	return Fraction(n) < F;
}

bool operator>=(int n, Fraction &F)
{
	return Fraction(n) >= F;
}

bool operator>=(double n, Fraction &F)
{
	return Fraction(n) >= F;
}

bool operator<=(int n, Fraction &F)
{
	return Fraction(n) <= F;
}

bool operator<=(double n, Fraction &F)
{
	return Fraction(n) <= F;
}

std::ostream &operator<<(std::ostream& stream, const Fraction& n)
{
	std::string s_1 = std::to_string(n.numerator % n.denominator), s_2 = std::to_string(n.numerator / n.denominator), s_3 = std::to_string(n.denominator);
	int length = s_1.length() > s_3.length() ? s_1.length() + 2 : s_3.length() + 2;
	stream << "\n" << std::setw(length + s_2.length()) << s_1;
	stream << "\n" << (n.isNegative ? '-' : ' ') << s_2 << ' ';
	for (int i = 0; i != length - 2; ++i)
		stream << '-';
	stream << "\n" << std::setw(length + s_2.length()) << s_3;
	return stream;
}

