#pragma once
//#include <cstdlib>
const int size_l = 50;
using namespace std;

template<class T>
class my_vector
{
	int length;
	int length_of_used;
	T *ptr_;
	int add_memory(T);
public:
	my_vector<T>();
	my_vector<T>(const my_vector<T> &);
	~my_vector<T>();
	void push_back(T);
	void pop_back();
	void erase();
	my_vector<T> operator=(const my_vector<T>&);
	void erase(int);
	void erase(int, int);
	//void set_size(int);
	int size() const;
	T& operator[](int) const;
};

template<class T>
inline int my_vector<T>::add_memory(T b)
{
	length += size_l / 2;
	T *p = new T[length]; //
	//T *p = (T*)malloc(sizeof(T) * length);
	if (p == NULL)
	{
		length -= size_l / 2;
		throw std::exception("Memory is full!");
	}
	for (int i = 0; i != length_of_used; ++i)
		*(p + i) = *(ptr_ + i);
	delete[] ptr_; //
	//free(ptr_);
	ptr_ = p;
	push_back(b);
	return 0;
}

template<class T>
inline void my_vector<T>::push_back(T b)
{
	length > length_of_used ? *(ptr_ + length_of_used++) = b : add_memory(b);
}

template<class T>
inline void my_vector<T>::pop_back()
{
	if (length_of_used)
		*(ptr_ + --length_of_used) = 0;
}

template<class T>
inline void my_vector<T>::erase()
{
	while (length_of_used)
		*(ptr_ + --length_of_used) = 0;
}

template<class T>
inline my_vector<T> my_vector<T>::operator=(const my_vector<T>& b)
{
	length = b.length;
	length_of_used = b.length_of_used;
	ptr_ = new T[length]; //
	//ptr_ = (T*)malloc(sizeof(T) * length);
	//if (ptr_ == NULL) throw std::exception("Memory is full!");
	for (int i = 0; i != length_of_used; ++i)
		*(ptr_ + i) = *(b.ptr_ + i);
	return *this;
}

template<class T>
inline void my_vector<T>::erase(int b)
{
	if (b < 0 || b >= length_of_used)
		throw std::exception("Error! This area of memory is not available!");
	for (int i = b; i != length_of_used - 1; ++i)
		*(ptr_ + i) = *(ptr_ + i + 1);
	pop_back();
}

template<class T>
inline void my_vector<T>::erase(int b, int c)
{
	if (b < 0 || b >= length_of_used || c >= length_of_used)
		throw std::exception("Error! This area of memory is not available!");
	if (b > c)
		throw std::exception("Error! Range is not exist!");
	int delta = c - b + 1;
	for (int i = b; i != length_of_used - delta; ++i)
		*(ptr_ + i) = *(ptr_ + i + delta);
	delta = length_of_used - delta;
	for (int i = length_of_used; i != delta; --i)
		pop_back();
}

template<class T>
inline int my_vector<T>::size() const
{
	return length_of_used;
}

template<class T>
inline T & my_vector<T>::operator[](int b) const
{
	return length_of_used > b ? *(ptr_ + b) : throw std::exception("Error! This area of memory is not available!");
}

template<class T>
inline my_vector<T>::my_vector()
{
	length = size_l;
	length_of_used = 0;
	ptr_ = new T[length]; //
	//ptr_ = (T*)malloc(sizeof(T) * length);
	if (ptr_ == NULL)
	{
		length = 0;
		throw std::exception("Memory is full!");
	}
}

template<class T>
inline my_vector<T>::my_vector(const my_vector<T>& b)
{
	length = b.length;
	length_of_used = b.length_of_used;
	ptr_ = new T[length]; //
	//ptr_ = (T*)malloc(sizeof(T) * length);
	//if (ptr_ == NULL) throw std::exception("Memory is full!");
	for (int i = 0; i != length_of_used; ++i)
		*(ptr_ + i) = *(b.ptr_ + i);
}

template<class T>
inline my_vector<T>::~my_vector()
{
	delete[] ptr_; //
	//free(ptr_);
}
