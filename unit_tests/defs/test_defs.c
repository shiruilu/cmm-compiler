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
/* test full_atoi */
	char *strnum[] = { "123", "0", "000", "017", "0xaF", "#" };
	int i = 0;
	for( ; strcmp("#", strnum[i]); ++i) {
		printf("test@full_atoi : %s\t:%d\n"
		, strnum[i], full_atoi(strnum[i]));
	}
	return 0;
}
