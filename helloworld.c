#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cache[4];
char name[100];
int main()
{
	char *inp = fgets(cache, 3, stdin);
	char *end;

	long cases = strtol(inp, &end, 10);
	if(cases < 1 || cases > 50)
		return EXIT_FAILURE;
		
	while(cases--){
		inp = fgets(name, 50, stdin);
		inp[strlen(inp)-1] = '\0';
		printf("Hello, %s!\n", inp);
	}
	
	
	return EXIT_SUCCESS;
}
