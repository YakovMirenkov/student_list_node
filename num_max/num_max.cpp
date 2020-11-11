#include "num_max.h"

int num_max(list_node *head)
{
	int num;
	long long int cmp;
	student *max;

	if( head==nullptr )
		return 0;

	max = head;
	num = 1;
	for( head = head->get_next(); head; head = head->get_next() )
	{
		if( (cmp = head->cmp(*max))>0 )
		{
			max = head;
			num = 1;
			continue;
		}
		if( cmp==0 )
			num++;
	}

	return num;
}
