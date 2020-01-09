#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define divfor(i, n) for((i)=2; (i)*(i)<=n; ++(i))

void printArr(int*, int);
int numcmp(const void*, const void*);
bool chkNotAbundant(int, int);
bool isSemiperfect(const int*, int, int);

int main()
{
    int cases, num, sumOvernum, idx;
    register int i;

    scanf("%d", &cases);
    while(cases--){
        int divs[1000] = {0,};
        divs[0] = 1;
        sumOvernum = idx = 1;
        scanf("%d", &num);
        divfor(i, num){
            if(!(num%i)){
                sumOvernum += i;
                divs[idx++] = i;
                if((num/i != i)){
                    sumOvernum += (num/i);
                    divs[idx++] = (num/i);
                }
            }
        }
//        printArr(divs, idx);
        if(chkNotAbundant(sumOvernum, num))
            printf("not weird\n");
        else{
            qsort(divs, idx, sizeof(int), numcmp);
            if(isSemiperfect(divs, idx, num))
                printf("not weird\n");
            else
                printf("weird\n");
        }
    }
    return EXIT_SUCCESS;
}

bool chkNotAbundant(int sum, int num)
{
    return sum <= num;
}

bool isSemiperfect(const int *d, int len, int n)
{
    bool subset[n+1];
    subset[0] = true;

    for(register int i=1; i<=n; ++i)
        subset[i] = false;

    for(register int i=0; i<len; ++i){
        for(register int j=n-1; j>=0; --j){
            if(subset[j]!=0){
                if(j+d[i]<=n){
                    subset[j+d[i]]=true;
                }
            }
        }
    } // memoization

    return subset[n];
}

void printArr(int* arr, int len)
{
    for(register int i=0; i<len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int numcmp(const void* a, const void* b)
{
    int na = *(const int*)a, nb = *(const int*)b;
    return (na > nb) - (na < nb);
}

