#include <stdio.h>
#include <stdlib.h>

#define GIVENDOTS 3
#define rint register int

typedef struct rect{
	int x;
	int y;
} rect;

rect dots[GIVENDOTS];

void printdot();

int main()
{
	int cases, x, y;
	scanf("%d", &cases);

	while(cases--){
		for(rint i=0; i<GIVENDOTS; ++i){
			scanf("%d %d", &x, &y);
			dots[i].x = x;
			dots[i].y = y;
		}

		printdot();
	}

	return EXIT_SUCCESS;
}

void printdot()
{
	printf("%d %d\n", (dots[0].x^dots[1].x^dots[2].x), (dots[0].y^dots[1].y^dots[2].y));
}
