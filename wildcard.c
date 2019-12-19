#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define LOOP for(;;)
#define STRMAX 100
#define CASEMAX 10

char probchrs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char markchrs[] = "?*";

clock_t start;

void makepattern(char* str);
void makefilename(char* str);

int main()
{
	int cases, flists;
	char inpsig;
	char pat[STRMAX]={0,}, filename[STRMAX]={0,};
	start = clock();
	srand(time(0));
	printf("string length : %ld\n", strlen(probchrs));
	LOOP{
		printf("Press q or Q to Quit\n");
		scanf(" %c", &inpsig);

		if(inpsig == 'q' || inpsig == 'Q')
	        break;

		cases =  (1+((int)(rand()/((RAND_MAX + 1u)/CASEMAX))));
		printf("cases : %d\n", cases);
		while(cases--){
			if(!strlen(pat))
				makepattern(pat);
			printf("Pattern is : %s\n", pat);
			flists = (1+((int)(rand()/((RAND_MAX + 1u)/CASEMAX))));
			while(flists--){
                makefilename(filename);
                printf("Given filename is : %s\n", filename);
                filename[0] = '\0';
			}
            pat[0] = '\0';
		}
	}
	printf("Total Exec Time : %lf sec(s)\n", ((double)(clock()-start)/CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}

void makepattern(char* str)
{
	int sig, flen, stridx, markidx, i=0;
	flen = (1+(int)(rand()/((RAND_MAX+1u)/STRMAX)));
	str[flen] = '\0';
	while(flen--){
		sig = (int)(rand()/((RAND_MAX+1u)/2));
		switch(sig){
			case 0:
				markidx = ((int)(rand()/((RAND_MAX + 1u)/(strlen(markchrs)))));
				str[i++] = markchrs[markidx];
				break;
			case 1:
				stridx = ((int)(rand()/((RAND_MAX + 1u)/(strlen(probchrs)))));
				str[i++] = probchrs[stridx];
				break;
			default:
				printf("signal not 0 and 1\n");
		
		}
	}
}

void makefilename(char* str)
{
    int flen=(1+(int)(rand()/((RAND_MAX+1u)/STRMAX))), stridx, i=0;
    str[flen] = '\0';
    while(flen--){
        stridx = ((int)(rand()/((RAND_MAX + 1u)/(strlen(probchrs)))));
        str[i++] = probchrs[stridx];
    }
}