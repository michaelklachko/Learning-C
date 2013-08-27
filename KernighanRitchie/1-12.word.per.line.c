//this program prints its input one word per line.
//

#include<stdio.h>

main() {

	int c;
	int pc = ' ';

	while( (c = getchar()) != EOF) {

		if((c == '\n' || c == '\t' || c == ' ') && (pc != c)) {
				
			putchar('\n');
			pc = c;
		}
		else if((c != '\n') && (c != '\t') && (c != ' '))  {

			putchar(c);
			pc = c;
		}
	}
}    
