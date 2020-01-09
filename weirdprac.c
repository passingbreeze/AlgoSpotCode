#include <stdio.h>
#include <stdlib.h>

int x[500001];
int chk(int *arr, int l, int n)
{
    int i, j;
    for (i = 0; i < n + 1; i++)
        x[i] = 0;
    x[0] = 1;
    for (i = 0; i < l; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (x[j] != 0) {
                if (j + arr[i] <= n) {
                    x[j + arr[i]] = 1;
                }
            }
        }
    }
    return x[n];
}

int cache[500000];
int arr[500000];

int func(int n)
{
    // int arr[n];
    int t = 0;
    int i;
    int s = 0;
    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            arr[t++] = i;
            s += i;
        }
    }
    if (s < n)
        return 1;
    return chk(arr, t, n);
}

int main()
{
    int c;
    scanf("%d", &c);
    while (c-->0) {
        int n;
        scanf("%d", &n);
        printf("%s\n", func(n) ? "not weird" : "weird");
    }
    return 0;
}