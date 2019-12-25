#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PIECE 3
#define PROBMAX 1000
#define PROBMAXHALF 500

typedef char dbstr[PIECE];

bool cmpdbstr(char*, char*);
void msort(int, int);
void merge(int, int, int);

char inp[PROBMAX];
dbstr pcs[PROBMAXHALF], sorted[PROBMAXHALF];

int main()
{
    int cases,i,k;
    scanf("%d", &cases);
    while(cases--){
        scanf("%s", inp);
        printf("chk inp : %s\n", inp);
        for(i=0, k=0; i<strlen(inp); i+=2, k++){
            strncpy(pcs[k], inp+i, 2);
            printf("piece : %s\n", pcs[k]);
        }
	msort(0, k-1);
	for(i=0; i<strlen(inp)/2; ++i)
		printf("%s", sorted[i]);
	printf("\n");
	
    }

    return EXIT_SUCCESS;
}

void msort(int l, int r)
{
    int mid = 0;
    if (l < r){
        mid = l+(r-l)/2;
        msort(l, mid);
        msort(mid+1, r);
        merge(l, mid, r);
    }
}

void merge(int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while(i<=mid && j<=right){
		if(cmpdbstr(pcs[i],pcs[j]))
			strcpy(sorted[k++], pcs[i++]);
		else
			strcpy(sorted[k++], pcs[j++]);
		
	}
	
	if(i>mid) {
		for(l=j; l<=right; ++l)
			strcpy(sorted[k++], pcs[l]);
		
	}

	else {
		for(l=i; l<=mid; ++l)
			strcpy(sorted[k++], pcs[l]);
	}
}

bool cmpdbstr(char* a, char* b)
{
	if(a[0] < b[0])
		return true;
	else if(a[0]==b[0]){
		if(a[1] <= b[1])
			return true;
		else
			return false;
	}
	else
		return false;
}
