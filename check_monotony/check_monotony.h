#ifndef CHECK_MONOTONY_H
#define CHECK_MONOTONY_H

#include "../student/list_node/list_node.h"

enum ANSWER
{
	NOT_MONOTONY,
	INCREASE,
	DECREASE,
	CONSTANT,
	CAN_NOT_SAY
};

int check_monotony(list_node *head);

#endif
