#include<stdio.h>


main() {

	int nc, nw, nl, c, state;
	int IN = 1, OUT = 0;

	nc = nw = nl = 0;
	state = OUT;

	while( (c = getchar()) != EOF) {

		nc++;

		if(c == '\n') 

			nl++;

		if(c == ' ' || c == '\n' || c == '\t') 
				
			state = OUT;

		else if(state == OUT) {

			state = IN;
			nw++;
		}
	}

	printf("lines: %i, words: %i, characters: %i\n", nl, nw, nc);

}
