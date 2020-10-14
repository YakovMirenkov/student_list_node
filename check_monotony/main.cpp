#include <cstdio>
#include <ctime>
#include "../student/list_node/list/list.h"
#include "check_monotony.h"

#define ERROR (-1)

int main(int argc, const char **argv)
{
	int d, res_check, res_read;
	list_node *head;
	clock_t t;

	if( argc!=3 || sscanf(argv[1], "%d", &d)!=1 || d<0 )
	{
		fprintf(stderr, "Usage:\n\t%s display file\n", argv[0]);
		return ERROR;
	}

	if( (res_read = read_list(argv[2], head))!=SUCCESS )
	{
		switch( res_read )
		{
			case OPEN_ERROR:
				fprintf(stderr, "Can not open %s!\n", argv[2]);
				break;
			case READ_ERROR:
				fprintf(stderr, "Can not read from %s!\n", argv[2]);
				break;
			case ALLOC_ERROR:
				fprintf(stderr, "Can not allocate memory!\n");
				break;
			default:
				fprintf(stderr, "Unknown error with code %d!\n", res_read);
		}
		return ERROR;
	}
	printf("Readed list:\n");
	print_list(head, d);
	printf("End of list.\n\n");

	t = clock();
	res_check = check_monotony(head);
	t = clock() - t;
	printf("Result:\t");
	switch( res_check )
	{
	case NOT_MONOTONY:
		printf("Not monotonic.\n");
		break;
	case INCREASE:
		printf("Monotonically increasing.\n");
		break;
	case DECREASE:
		printf("Monotonically decreasing\n");
		break;
	case CONSTANT:
		printf("Constant.\n");
		break;
	case CAN_NOT_SAY:
		printf("Can not say.\n");
		break;
	default:
		fprintf(stderr, "Unknown error!\n");
		delete_list(head);
		return ERROR;
	}
	printf("Time:\t%.2lf sec\n", static_cast<double>(t)/CLOCKS_PER_SEC);

	delete_list(head);
	return 0;
}
