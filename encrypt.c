#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAX 101

char inp[STRMAX], even[STRMAX], odd[STRMAX];

int main()
{
	int cases;
	register int i,j,e,o;

	scanf("%d",&cases);
	for(i=0; i<cases; ++i){
		scanf(" %s", inp);
		for(j=0, e=0, o=0; j<strlen(inp); ++j){
			if(j&1)
				odd[o++] = inp[j];
			else
				even[e++] = inp[j];
		}
		strcpy(even+e, odd);
		printf("%s\n", even);
		memset(even, 0, strlen(even));
		memset(odd, 0, strlen(odd));
	}

	return EXIT_SUCCESS;
}
