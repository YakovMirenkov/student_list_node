#include "max_len_monotony.h"

int max_len_monotony(list_node *head)
{
	int len = 2, equal = 0, max = 2;
	long long int cmp, cmp_tmp;
	list_node *next;

	if( head==nullptr || (next = head->get_next())==nullptr )
		return CAN_NOT_SAY;

	while( (cmp_tmp = head->cmp(*next))==0 )
	{
		len++;
		head = next;
		if( (next = next->get_next())==nullptr )
			return len;
	}

	for( head = next; (next = next->get_next())!=nullptr; head = next )
	{
		if( (cmp = head->cmp(*next))==0 )
		{
			equal++;
			len++;
			continue;
		}

		if( cmp_tmp*cmp>0 )
		{
			equal = 0;
			len++;
			continue;
		}

		if( len>max )
			max = len;

		len = 2 + equal;
		equal = 0;
		cmp_tmp = cmp;
	}
	if( len>max )
		max = len;

	return max;
}
