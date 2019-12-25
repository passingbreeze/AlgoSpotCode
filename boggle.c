#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

clock_t start;

int main()
{
	start = clock();

	printf("total exec time : %lf sec(s)\n", (double)((clock()-start)/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}
