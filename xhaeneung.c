#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMMAX 11
#define OPERMAX 2
#define ALPHAMAX 30

void initcode(int*);
int getnum(char*);
bool iscorrect(const char*);

const char *nums[NUMMAX] = {
        "zero", "one", "two", "three", "four", \
        "five", "six", "seven", "eight", "nine", "ten"
};

int numcode[2][ALPHAMAX] = {
      // a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
         0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

char a[NUMMAX], b[NUMMAX], result[NUMMAX],\
        oper[OPERMAX], eq[OPERMAX];

int main()
{
    int cases, numresult;

    scanf("%d", &cases);
    while(cases--){
        numresult=0;
        initcode(numcode[0]);
        initcode(numcode[1]);
        scanf(" %s %s %s %s %s", a, oper, b, eq, result);
        if(!strcmp(oper,"+"))
            numresult = getnum(a) + getnum(b);
        else if(!strcmp(oper, "-"))
            numresult = getnum(a) - getnum(b);
        else if(!strcmp(oper, "*"))
            numresult = getnum(a) * getnum(b);

        if(numresult < 0 || numresult > 10)
            printf("No\n");
        else{
            for (register int i = 0; i < strlen(nums[numresult]); ++i)
                numcode[0][nums[numresult][i] - 'a']++;

            printf(iscorrect(result) ? "Yes\n" : "No\n");
        }
    }
    return EXIT_SUCCESS;
}

void initcode(int *arr)
{
    for(register int i=0; i<ALPHAMAX; ++i)
        arr[i]=0;
}

int getnum(char* num)
{
    for(register int i=0; i<NUMMAX; ++i)
        if(!strcmp(num, nums[i]))
            return i;
    return -1;
}

bool iscorrect(const char *strresult)
{
    for(register int i=0; i<strlen(strresult); ++i)
        numcode[1][strresult[i]-'a']++;
    for(register int i=0; i<ALPHAMAX; ++i){
        if(numcode[0][i]!=numcode[1][i])
            return false;
    }
    return true;
}