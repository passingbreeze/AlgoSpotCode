#include <stdio.h>
#include <stdlib.h>

typedef struct bytes{
	char digit1;
	char digit2;
	char digit3;
	char digit4;
} bytes;

int main()
{
	int cases;
	unsigned int inpn, outn;
	bytes *inp, *out;

	scanf("%u", &cases);
	while(cases--){
		scanf("%u", &inpn);
		inp = (bytes*)&inpn;
		out = (bytes*)&outn;

		out->digit4 = inp->digit1;
		out->digit3 = inp->digit2;
		out->digit2 = inp->digit3;
		out->digit1 = inp->digit4;

		printf("%u\n", outn);

	}

	return EXIT_SUCCESS;
}
