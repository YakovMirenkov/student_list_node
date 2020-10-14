#include "list_node.h"

int list_node::set_next(list_node *new_next)
{
	if( next!=nullptr )
		return NOT_NULL_ERROR;
	next = new_next;
	return SUCCESS;
}

list_node &list_node::operator=(const list_node &x)
{
	*(student *)(this) = x;
	next = x.next;
	return *this;
}

list_node &list_node::operator=(list_node &&x)
{
	*(student *)(this) = x;
	next = x.next;
	x.next = nullptr;
	return *this;
}
