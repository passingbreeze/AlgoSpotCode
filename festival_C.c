//
// Created by hongjeongmin on 19. 10. 2..
//

#include <stdio.h>

#define FOR(i, b, e) for(i=b; i<e; ++i)
#define INCFOR(i, b, e) for(i=b; i<=e; ++i)
#define RMAX 1001

int cv[RMAX];
double res[RMAX];

int main()
{
    int tcase = 0, rent = 0, team = 0, sum, i, j, cnt, k;
    double avgmin, temp;
    scanf("%d", &tcase);
    if(tcase > 100)
        return 1;

    FOR(i,0,tcase){
        avgmin = 1000.0, temp = 0.0;
        scanf("%d%d", &rent, &team);
        if((rent<1 || rent > 1000) || (team > rent))
            return 1;

        FOR(j, 0, rent)
            scanf("%d", cv+j);

        // 어려웠던 부분 시작...
        INCFOR(j, team, rent){
            for(cnt=0; j+cnt<=rent; ++cnt){
                sum = 0;
                FOR(k, cnt, cnt+j)
                    sum+=cv[k];
                temp = ((double)sum)/j;
                if(temp < avgmin)
                    avgmin = temp;
            }
        }
        res[i] = avgmin;
        /*
         * 처음 설계할때 시간 복잡도에만 너무 집중하였다..
         * 변수명을 처음에 직관적으로 만들지 못했기 때문에 푸는데 어려움이 있었다.
         *
         * */
        //끝
    }
    FOR(i,0,tcase)
        printf("%.12f\n", res[i]);
    return 0;
}