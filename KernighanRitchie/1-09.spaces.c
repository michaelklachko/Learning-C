#include<stdio.h>

main()
{

	int c;
	int dontPrint = 0;

	while((c = getchar()) != EOF) {

		if(c != ' ') {
			
			putchar(c);
			dontPrint = 0;
		}
		else

			if(dontPrint == 0) {

				putchar(c);
				dontPrint = 1;
			}
	}
}
