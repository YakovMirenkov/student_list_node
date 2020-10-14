#include <cstdio>
#include "list.h"

void print_list(list_node *head, int d)
{
	int i;

	for( i = 0; i<d && head; i++, head = head->get_next() )
		head->print();
}

int read_list(const char *name, list_node *&head)
{
	FILE *in;
	list_node *tmp, *current;
	int res_read;

	if( (in = fopen(name, "r"))==nullptr )
		return OPEN_ERROR;

	if( (head = new list_node)==nullptr )
	{
		fclose(in);
		return ALLOC_ERROR;
	}
	if( (res_read = head->read(in))!=student::SUCCESS )
	{
		if( res_read==student::EOF_ERROR )
		{
			fclose(in);
			delete head;
			head = nullptr;
			return SUCCESS;
		}

		fclose(in);
		delete head;
		if( res_read==student::ALLOC_ERROR )
			return ALLOC_ERROR;
		return READ_ERROR;
	}

	if( (tmp = new list_node)==nullptr )
	{
		fclose(in);
		delete head;
		return ALLOC_ERROR;
	}
	current = head;
	while( (res_read = tmp->read(in))==student::SUCCESS )
	{
		if( current->set_next(tmp)!=list_node::SUCCESS )
		{
			fclose(in);
			delete tmp;
			delete_list(head);
			return UNKNOWN_ERROR;
		}
		current = tmp;
		if( (tmp = new list_node)==nullptr )
		{
			fclose(in);
			delete_list(head);
			return ALLOC_ERROR;
		}
	}
	fclose(in);
	delete tmp;
	if( res_read==student::EOF_ERROR )
		return SUCCESS;
	delete_list(head);
	if( res_read==student::ALLOC_ERROR )
		return ALLOC_ERROR;
	return READ_ERROR;
}

void delete_list(list_node *head)
{
	list_node *tmp;

	for( tmp = head; tmp; head = tmp )
	{
		tmp = head->get_next();
		delete head;
	}
}
