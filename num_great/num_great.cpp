#include "num_great.h"

int num_great(list_node *head)
{
	int num = 0;
	list_node *next;

	if( head==nullptr )
		return 0;

	while( (next = head->get_next())!=nullptr )
	{
		if( *next>*head )
			num++;
		head = next;
	}

	return num;
}
