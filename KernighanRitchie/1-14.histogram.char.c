#include<stdio.h>

#define N 128

main() {

	int c, k=0;
	int chars[N] = {0};

	while((c = getchar()) != EOF) 

		chars[c]++;

	for(k=0; k<N; k++) 

		if(chars[k] > 0) 
			
			printf("'%c': %i\n", k, chars[k]);

}



