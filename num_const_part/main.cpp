#include <cstdio>
#include <ctime>
#include "../student/list_node/list/list.h"
#include "num_const_part.h"

#define ERROR (-1)

int main(int argc, const char **argv)
{
	int d, num, res_read;
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
	num = num_const_part(head);
	t = clock() - t;
	printf("Result:\t%d\nTime:\t%.2lf sec\n", num, static_cast<double>(t)/CLOCKS_PER_SEC);

	delete_list(head);
	return 0;
}
