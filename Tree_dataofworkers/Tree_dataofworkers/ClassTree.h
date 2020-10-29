#pragma once
#include <string>

using namespace std;

class Tree;
class elem
{
	friend class Tree;
	string data;
	elem* right;
	elem* left;
public:
	elem()
	{
		data = "";
		right = nullptr;
		left = nullptr;
	}
	~elem()
	{
		data = "";
		if (right) delete right;
		if (left) delete left;
	}
	elem(elem* const E)
	{
		data = E->data;
		right = nullptr;
		left = nullptr;
		if (E->right)
		{
			right = new elem;
			*right = E->right;
		}
		if (E->left)
		{
			left = new elem;
			*left = E->left;
		}
	}
	elem& operator=(elem * const E)
	{
		data = E->data;
		right = nullptr;
		left = nullptr;
		if (E->right)
		{
			right = new elem;
			*right = E->right;
		}
		if (E->left)
		{
			left = new elem;
			*left = E->left;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& stream, const elem& E)
	{
			stream << E.data << "\n";
			if (E.right) stream << *E.right;
			if (E.left) stream << *E.left;
			return stream;
	}
};

class Tree
{
	elem* top;
public:
	Tree();
	Tree(const Tree&);
	~Tree();
	Tree& operator=(const Tree&);
	void push(const string&);
	bool empty() const;
	string* find(const string&);
	string* find_max();
	string search(const elem&, string*);

	friend ostream& operator<<(ostream& stream, const Tree& T)
	{
		if (!T.empty())
			stream << *T.top;
		else
			cout << "Нет данных!";
		return stream;
	}
};

Tree::Tree()
{
	top = nullptr;
}

Tree::Tree(const Tree& T)
{
	top = nullptr;
	if (T.top)
	{
		top = new elem;
		*top = T.top;
	}
}

Tree::~Tree()
{
	if (top) delete top;
}

Tree& Tree::operator=(const Tree& T)
{
	top = nullptr;
	if (T.top)
	{
		elem* el = new elem;
		*el = T.top;
	}
	return *this;
}

void Tree::push(const string& str)
{
	bool is_pos = false;
	elem* el = top;
	if (top)
	{
		while (!is_pos)
		{
			if (el->data > str)
			{
				if (el->left)
				{
					el = el->left;
				}
				else
				{
					is_pos = true;
					el->left = new elem;
					el->left->data = str;
				}
			}
			else
			{
				if (el->right)
				{
					el = el->right;
				}
				else
				{
					is_pos = true;
					el->right = new elem;
					el->right->data = str;

				}
			}
		}
	}
	else
	{
		top = new elem;
		top->data = str;
	}
}

bool Tree::empty() const
{
	return !top;
}

string* Tree::find(const string& str)
{
	bool is_find = false; 
	elem* el = top;
	string* s_name = new string;
	while (!is_find && el)
	{
		if (el->data.substr(0, el->data.find_first_of(' ')) == str)
		{
			s_name = &el->data;
			is_find = true;
		}
		else
		{
			if (el->data.substr(0, el->data.find_first_of(' ')) > str)
				el = el->left;
			else
				el = el->right;
		}
	}
	return s_name;
}

string* Tree::find_max()
{
	bool is_find = false;
	elem* el = top;
	string* s_name = new string;
	*s_name = search(el, s_name);
	return find(s_name->substr(0, s_name->find_first_of(' ')));
}

string Tree::search(const elem& el, string* str)
{
	if (el.left)
	{
		if (atoi(el.left->data.substr(el.left->data.find_last_of(' ') + 1, el.left->data.length() - el.left->data.find_last_of(' ') - 1).c_str()) > atoi(str->substr(str->find_last_of(' ') + 1, str->length() - str->find_last_of(' ') - 1).c_str()))
			str = &el.left->data;
		*str = search(el.left, str);
	}
	if (el.right)
	{
		if (atoi(el.right->data.substr(el.right->data.find_last_of(' ') + 1, el.right->data.length() - el.right->data.find_last_of(' ') - 1).c_str()) > atoi(str->substr(str->find_last_of(' ') + 1, str->length() - str->find_last_of(' ') - 1).c_str()))
			str = &el.right->data;
		*str = search(el.right, str);
	}
	return *str;
}
