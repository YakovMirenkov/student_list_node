#include "max_distance_const.h"

int max_distance_const(list_node *head)
{
	int distance, max = NO_TWO_ERROR;
	list_node *next;

	if( head==nullptr )
		return 0;

	for( next = head; (next = next->get_next())!=nullptr; head = next )
	{
		if( head->cmp(*next)==0 )
		{
			head = next;
			if( (next = next->get_next())==nullptr )
				return max;
			while( head->cmp(*next)==0 )
			{
				head = next;
				if( (next = next->get_next())==nullptr )
					return max;
			}
			distance = 1;
			break;
		}
	}

	if( next==nullptr )
		return max;

	for( head = next; (next = next->get_next())!=nullptr; head = next )
	{
		if( head->cmp(*next)==0 )
		{
			if( (distance - 1)>max )
				max = distance - 1;
			distance = 0;
			head = next;
			if( (next = next->get_next())==nullptr )
				return max;
			while( head->cmp(*next)==0 )
			{
				head = next;
				if( (next = next->get_next())==nullptr )
					return max;
			}
		}
		distance++;
	}

	return max;
}
