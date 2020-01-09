#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KG_TO_LB 2.2046
#define LB_TO_KG 0.4536
#define L_TO_G 0.2642
#define G_TO_L 3.7854

char inp[3];

int main()
{
    int cases, count=1;
    double inpn;

    scanf("%d", &cases);
    while(cases--){
        scanf(" %lf %s", &inpn, inp);
        printf("%d ", count++);
        if(!strcmp(inp, "kg"))
            printf("%.4lf %s", inpn*KG_TO_LB, "lb\n");
        else if(!strcmp(inp, "lb"))
            printf("%.4lf %s", inpn*LB_TO_KG, "kg\n");
        else if(!strcmp(inp, "l"))
            printf("%.4lf %s", inpn*L_TO_G, "g\n");
        else if(!strcmp(inp, "g"))
            printf("%.4lf %s", inpn*G_TO_L, "l\n");
        memset(inp, '\0', sizeof(inp));
    }
    return EXIT_SUCCESS;
}