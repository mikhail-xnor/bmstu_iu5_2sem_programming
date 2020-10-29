#pragma once
#include <iostream>

class Stack
{
	struct element
	{
		int simple_num;
		element* previos_elem;
	};
	element* top;
public:
	Stack();
	Stack(Stack&);
	~Stack();
	void push(int);
	int pop();
	bool empty();
	void reverse();
	Stack operator=(int);
	friend std::ostream &operator<<(std::ostream&, Stack&);
	friend std::istream &operator>>(std::istream&, Stack&);
};