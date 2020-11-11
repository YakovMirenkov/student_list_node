#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "../student.h"

class list_node: public student
{
private:
	list_node *next = nullptr;
public:
	enum ERRORS
	{
		SUCCESS = 0,
		NOT_NULL_ERROR
	};

	list_node *get_next() const { return next; }
	int set_next(list_node *new_next);
	list_node() = default;
	list_node(const char *name, int value): student(name, value) { next = nullptr; }
	list_node(const list_node &x): student(x) { next = nullptr; }
	list_node(list_node &&x): student(static_cast<student &&>(x)) { next = x.next; x.next = nullptr; }
	~list_node() { next = nullptr; }
	list_node &operator=(const list_node &x);
	list_node &operator=(list_node &&x);
};

#endif// LIST_NODE_H
