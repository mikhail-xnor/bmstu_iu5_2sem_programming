#pragma once
#include "../../../../../MY_PROJECTS/VisualStudio/My_Vector/My_Vector/my_vector.h"
#include <string>

template <class T>
class Bunch
{
	my_vector<T> elements;
public:
	Bunch<T>() {}
	~Bunch<T>() {}
	
	Bunch<T> operator+(const Bunch<T>&); //объединение множеств
	Bunch<T> operator-(const Bunch<T>&); //вычитает одно множество из другого
	Bunch<T> operator*(const Bunch<T>&); //пересечение множеств
	T& operator[](int) const;
	bool operator==(const Bunch<T>&); //сравнивает 2 множества, если они равны возвращает true
	bool operator!=(const Bunch<T>&); //сравнивает 2 множества, если они не равны возвращает false

	void add(T); //добавляет элемент в множество
	int find(T) const; //возвращает индекс элемента
	void erase(int); //удаляет элемент под индексом


	friend std::ostream& operator<<(std::ostream& stream, const Bunch<T>& b)
	{
		for (int i = 0; i != b.elements.size(); ++i)
			stream << b[i] << ';';
		return stream;
	}

	friend std::istream& operator>>(std::istream& stream, Bunch<T>& b)
	{
		std::string str;
		stream >> str;
		b.elements.erase();
		while (str.find(';') != std::string::npos)
		{
			b.add(std::atoi((str.substr(0, str.find(';')).c_str())));
			str.erase(0, str.find(';') + 1);
		}
		return stream;
	}
};

template<class T>
inline void Bunch<T>::add(T b)
{
	if (find(b) == -1)
		elements.push_back(b);
}

template<class T>
inline int Bunch<T>::find(T b) const
{
	for (int i = 0; i != elements.size(); ++i)
		if (b == elements[i])
			return i;
	return -1;
}

template<class T>
inline void Bunch<T>::erase(int b)
{
	elements.erase(b);
}

template<class T>
inline Bunch<T> Bunch<T>::operator+(const Bunch<T> &b)
{
	Bunch new_bunch = *this;
	for (int i = 0; i != b.elements.size(); ++i)
			new_bunch.add(b[i]);
	return new_bunch;
}

template<class T>
inline Bunch<T> Bunch<T>::operator-(const Bunch<T> &b)
{
	Bunch new_bunch;
	for (int i = 0; i != elements.size(); ++i)
		if (b.find((*this)[i]) == -1)
			new_bunch.add((*this)[i]);
	return new_bunch;
}

template<class T>
inline Bunch<T> Bunch<T>::operator*(const Bunch<T>& b)
{
	Bunch new_bunch;
	if (elements.size() > b.elements.size())
	{
		for (int i = 0; i != elements.size(); ++i)
			if (b.find((*this)[i]) != -1)
				new_bunch.add((*this)[i]);
	}
	else
	{
		for (int i = 0; i != b.elements.size(); ++i)
			if (find(b[i]) != -1)
				new_bunch.add(b[i]);
	}
	return new_bunch;
}

template<class T>
inline T & Bunch<T>::operator[](int b) const
{
	return elements[b];
}

template<class T>
inline bool Bunch<T>::operator==(const Bunch<T> &b)
{
	if (elements.size() != b.elements.size())
		return false;
	for (int i = 0; i != elements.size(); ++i)
		if (find(b[i]) == -1)
			return false;
	return true;
}

template<class T>
inline bool Bunch<T>::operator!=(const Bunch<T> &b)
{
	return !(*this == b);
}
