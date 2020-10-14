#include "check_monotony.h"

int check_monotony(list_node *head)
{
	long long int cmp;
	list_node *next;

	if( head==nullptr || (next = head->get_next())==nullptr )
		return CAN_NOT_SAY;

	while( (cmp = head->cmp(*next))==0 )
	{
		head = next;
		if( (next = next->get_next())==nullptr )
			return CONSTANT;
	}

	while( cmp*( head->cmp(*next) )>=0 )
	{
		head = next;
		if( (next = next->get_next())==nullptr )
		{
			if( cmp>0 )
				return DECREASE;
			else
				return INCREASE;
		}
	}

	return NOT_MONOTONY;
}
