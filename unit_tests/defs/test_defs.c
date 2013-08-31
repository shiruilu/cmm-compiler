#include <stdio.h>
#include "defs.h"

int main()
{
/* test ck_malloc */
	int *pi = (int *)ck_malloc(sizeof(int));
	*pi = 5;
	printf("test@ck_malloc: int : %d\n", *pi);
/* test String */
	string str = String("test String ok");
	printf("test@String : %s\n", str);

	return 0;
}
