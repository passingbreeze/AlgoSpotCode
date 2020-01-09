#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPMAX 100

char inp[INPMAX];
int main()
{
    int cases, idx, count=1;
    scanf("%d", &cases);
    while(cases--){
        scanf(" %d %s", &idx, inp);
        if(strlen(inp) > 80 || idx > strlen(inp))
            return EXIT_FAILURE;
        idx--;
        memmove(inp+idx, inp+idx+1, strlen(inp)-idx);
        printf("%d %s\n", count++, inp);
        memset(inp,0,sizeof(inp));
    }
    return EXIT_SUCCESS;
}
