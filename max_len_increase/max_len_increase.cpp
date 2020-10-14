#include "max_len_increase.h"

int max_len_increase(list_node *head)
{
	int len, max;
	list_node *next;

	if( head==nullptr )
		return 0;

	len = 1;
	max = 1;
	next = head;
	while( (next = next->get_next())!=nullptr )
	{
		if( *next>*head )
		{
			len++;
		}
		else
		{
			if( len>max )
				max = len;
			len = 1;
		}
		head = next;
	}
	if( len>max )
		max = len;

	return max;
}
