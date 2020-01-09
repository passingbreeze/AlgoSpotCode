#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPMAX 100

void decodestr();
char inp[INPMAX];

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf(" %s", inp);
        decodestr();
        memset(inp, '\0', sizeof(inp));
    }
    return EXIT_SUCCESS;
}

void decodestr()
{
    char part[INPMAX], temp[INPMAX];
    int idx, slen;

    for(register int i=0; i<strlen(inp); ++i){
        if(inp[i] == '%' && inp[i+1] == '2'){
            switch(inp[i+2]){
                case '0':
                    inp[i] = ' ';
                    break;
                case '1':
                    inp[i] = '!';
                    break;
                case '4':
                    inp[i] = '$';
                    break;
                case '5':
                    inp[i] = '%';
                    break;
                case '8':
                    inp[i] = '(';
                    break;
                case '9':
                    inp[i] = ')';
                    break;
                case 'a':
                    inp[i] = '*';
                    break;
            }
            memmove(inp+i+1, inp+i+3, strlen(inp) - i);
        }
    }
    printf("%s\n", inp);
}