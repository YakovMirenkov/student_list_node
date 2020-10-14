#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "../list_node.h"

enum ERRORS
{
	SUCCESS = 0,
	OPEN_ERROR,
	READ_ERROR,
	ALLOC_ERROR,
	UNKNOWN_ERROR
};

void print_list(list_node *head, int d);
int read_list(const char *name, list_node *&head);
void delete_list(list_node *head);

#endif
