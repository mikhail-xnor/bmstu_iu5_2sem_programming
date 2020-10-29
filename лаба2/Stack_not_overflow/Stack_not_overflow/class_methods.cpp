#include "class_stack.h"

Stack Stack::operator=(int b)
{
	if (b > 1)
	{
		register int i = 2;
		for (; b > 1;)
			if (b % i)
				++i;
			else if (b /= i)
				push(i);
	}
	else
	{
		push(b);
	}
	return *this;
}

Stack::Stack() : top(nullptr) {}

Stack::Stack(Stack &b)
{
	Stack n;
	element *last = b.top;
	top = nullptr;
	while (last)
	{
		n.push(last->simple_num);
		last = last->previos_elem;
	}
	while (!n.empty())
	{
		push(n.pop());
	}
}

Stack::~Stack()
{
	while (top)
	{
		element* del = top;
		top = top->previos_elem;
		delete del;
	}
}

void Stack::push(int b)
{
	element *next = new element;
	next->simple_num = b;
	next->previos_elem = top;
	top = next;
}

int Stack::pop()
{
	if (empty())
		return -1;
	int buf = top->simple_num;
	element* del = top;
	top = top->previos_elem;
	delete del;
	return buf;
}

bool Stack::empty()
{
	return top ? false : true;
}

void Stack::reverse() 
{
	Stack *b = new Stack;
	while (!empty())
	{
		b->push(pop());
	}
	*this = *b;
}

std::ostream &operator<<(std::ostream& stream, Stack& b)
{
	while (b.top)
		stream << b.pop() << ' ';
	return stream;
}

std::istream & operator>>(std::istream &stream, Stack &b)
{
	int i;
	stream >> i;
	b = i;
	return stream;
}
