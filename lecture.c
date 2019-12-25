#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PIECE 3
#define PROBMAX 1000
#define PROBMAXHALF 500

typedef char dbstr[PIECE];

int cmpdbstr(const void*, const void*);

char inp[PROBMAX];
dbstr pcs[PROBMAXHALF];

int main()
{
    int cases,i,k;
    scanf("%d", &cases);
    while(cases--){
        scanf("%s", inp);
        
        for(i=0, k=0; i<strlen(inp); i+=2, k++)
            strncpy(pcs[k], inp+i, 2);

	qsort(pcs, k, sizeof(dbstr), cmpdbstr);
	for(i=0; i<strlen(inp)/2; ++i)
		printf("%s", pcs[i]);
	printf("\n");
    }

    return EXIT_SUCCESS;
}

int cmpdbstr(const void* a, const void* b)
{
	const char* o = (const char*)a;
	const char* p = (const char*)b;

	return strcmp(o,p);
}
