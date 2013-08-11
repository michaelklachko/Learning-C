#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])

{
       // int N[];
       // int N;
	//int N[] = 0;
	int i = 0;

	int N = atoi(argv[1]);

	if (argc != 2) {
		printf ("Usage: fizzbuzz NUM\n");
		return 1;
	}
	if (N < 1) {
		printf ("NUM is too small");
		return 1;
	}

	for (i=1; i<=N; i++) {

		if (i%3 == 0 && i%5 == 0)
			printf ("fizzbuzz\n");
		else if (i%3 ==0)
			printf ("fizz\n");
		else if (i%5 == 0)
			printf ("buzz\n");
		else
			printf ("%d\n", i);
	}

//	system("pause");
	return 0;
}

