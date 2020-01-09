#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define divfor(i, n) for(i=1; i*i<=n; ++i)
#define SOLVSET 10000

int numcmp(const void*, const void*);
bool chkSumSameNum(const int*, int, int);
int divs[SOLVSET];

int main()
{
    int cases, num, sum, idx;
    register int i;

    scanf("%d", &cases);
    while(cases--){
        sum = idx = 0;
        scanf("%d", &num);
        divfor(i, num){
            if(!(num%i)){
                sum += i;
                divs[idx++] = i;
                if(num/i != i){
                    sum += (num / i);
                    divs[idx++] = (num/i);
                }
            }
        }
        if(sum <= num)
            printf("not weird\n");
        else{
            qsort(divs, idx-1, sizeof(int), numcmp);
            if(chkSumSameNum(divs, sum, num))
                printf("weird\n");
            else
                printf("not weird\n");
        }
        for (register int i = 0; i <= idx; ++i)
            divs[i] = 0;
    }
    return EXIT_SUCCESS;
}

bool chkSumSameNum(const int *set, int sum, int num)
{
  bool subset[sum + 1][num + 1];

  for(register int i=1; i <= sum; ++i)
      subset[i][0] = false;

  for(register int i=0; i<=num; ++i)
      subset[0][i] = true;

  for(register int i=1; i <= sum; ++i){
      for(register int j=1; j<=num; ++j){
          if(j<set[i-1])
              subset[i][j] = subset[i-1][j];
          else
              subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
      }
  }
  if(!subset[sum][num])
      return false;
  else
      return true;
}

int numcmp(const void *a, const void *b)
{
    int na = *(const int*)a;
    int nb = *(const int*)b;
    return ((na > nb) - (na < nb));
}