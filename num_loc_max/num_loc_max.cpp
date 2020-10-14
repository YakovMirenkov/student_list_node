#include "num_loc_max.h"

int num_loc_max(list_node *head)
{
	int num = 0;
	long long int cmp, cmp_tmp;
	list_node *next;

	if( head==nullptr )
		return 0;
	if( (next = head->get_next())==nullptr )
		return 1;

	cmp = head->cmp(*next);
	if( cmp>=0 )
		num++;
	cmp_tmp = cmp;
	head = next;
	while( (next = head->get_next())!=nullptr )
	{
		cmp = head->cmp(*next);

		if( cmp_tmp<=0 && cmp>=0  )
			num++;

		cmp_tmp = cmp;
		head = next;
	}
	if( cmp<=0 )
		num++;

	return num;
}
