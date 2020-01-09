#include <stdio.h>
#include <stdlib.h>

#define OBJCHK(o,s) ((o)>=(s) ? 1 : 0)

int main()
{
    int cases, obj, temp, sum;
    scanf("%d", &cases);
    while(cases--){
        sum=0; // Bad habits...
        scanf(" %d", &obj);
        for(register int i=0; i<9; ++i) {
            scanf("%d", &temp);
            sum += temp;
        }
        printf(OBJCHK(obj,sum) ? "YES\n" : "NO\n");
    }
    return  EXIT_SUCCESS;
}