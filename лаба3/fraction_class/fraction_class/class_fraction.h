#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Fraction
{
	int numerator;
	int denominator;
	bool isNegative;
	static uint8_t accuracy;
public:
	Fraction();
	Fraction(const Fraction&);
	Fraction(int);
	Fraction(int, int);
	Fraction(int, int, int); 
	Fraction(double);
	~Fraction() {}
	// functions
	static void set_accuracy(uint8_t);
	void evqlid();
	// (-)
	Fraction operator-();
	// =
	Fraction operator=(const Fraction&);
	Fraction operator=(int);
	Fraction operator=(double);
	// *
	Fraction operator*(int);
	Fraction operator*(double);
	Fraction operator*(const Fraction&);
	friend Fraction operator*(int, Fraction&);
	friend Fraction operator*(double, Fraction&);
	// /
	Fraction operator/(int);
	Fraction operator/(double);
	Fraction operator/(const Fraction&);
	friend Fraction operator/(int, Fraction&);
	friend Fraction operator/(double, Fraction&);
	// +
	Fraction operator+(int);
	Fraction operator+(double);
	Fraction operator+(const Fraction &);
	friend Fraction operator+(int, Fraction&);
	friend Fraction operator+(double, Fraction&);
	// -
	Fraction operator-(int);
	Fraction operator-(double);
	Fraction operator-(const Fraction &);
	friend Fraction operator-(int, Fraction&);
	friend Fraction operator-(double, Fraction&);
	// >
	bool operator>(int);
	bool operator>(double);
	bool operator>(const Fraction&); 
	friend bool operator>(int, Fraction&);
	friend bool operator>(double, Fraction&);
	// ==
	bool operator==(int);
	bool operator==(double);
	bool operator==(const Fraction&);
	friend bool operator==(int, Fraction&);
	friend bool operator==(double, Fraction&);
	// !=
	bool operator!=(int);
	bool operator!=(double);
	bool operator!=(const Fraction&);
	friend bool operator!=(int, Fraction&);
	friend bool operator!=(double, Fraction&);
	// <
	bool operator<(int);
	bool operator<(double);
	bool operator<(const Fraction&);
	friend bool operator<(int, Fraction&);
	friend bool operator<(double, Fraction&);
	// >=
	bool operator>=(int);
	bool operator>=(double);
	bool operator>=(const Fraction&);
	friend bool operator>=(int, Fraction&);
	friend bool operator>=(double, Fraction&);
	// <=
	bool operator<=(int);
	bool operator<=(double);
	bool operator<=(const Fraction&);
	friend bool operator<=(int, Fraction&);
	friend bool operator<=(double, Fraction&);
	// stream out
	friend std::ostream &operator<<(std::ostream&, const Fraction&);
};