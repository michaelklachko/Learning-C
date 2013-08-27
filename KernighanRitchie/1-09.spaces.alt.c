#include<stdio.h>

main()
{

	int c;
	int pc = EOF;

	while((c = getchar()) != EOF) {

		if(c != ' ') {
			
			putchar(c);
		}
		else

			if(pc != c) {
				
				pc = c;
				putchar(c);
			}
	}
}
