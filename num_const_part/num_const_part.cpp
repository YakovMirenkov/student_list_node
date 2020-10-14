#include "num_const_part.h"

int num_const_part(list_node *head)
{
	int num = 0;
	list_node *next;

	if( head==nullptr )
		return 0;

	next = head;
	while( (next = next->get_next())!=nullptr )
	{
		if( head->cmp(*next)==0 )
		{
			num++;
			head = next;
			if( (next = next->get_next())==nullptr )
				return num;
			while( head->cmp(*next)==0 )
			{
				head = next;
				if( (next = next->get_next())==nullptr )
					return num;
			}
		}
		head = next;
	}

	return num;
}
