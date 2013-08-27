#include<stdio.h>

#define N 32

main() {

	int c, k, count=0, i; 
	int words[N] = {0};

	while((c = getchar()) != EOF) {

		count++;
		if(c == ' ' || c == '\n' || c == '\t') {

			words[count-1]++;
			count = 0;
		}
	}

	printf("\n\nHistogram of word length occurances:\n\n");

	for(i=1; i<N; i++) 

	{//	if(words[i] != 0) {
		
			printf("%3i-char words: ", i);
			for(k=0; k<words[i]; k++)

				printf("|");

			printf(" (%i)\n", words[i]);
		}

}
