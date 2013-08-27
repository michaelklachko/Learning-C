#include<stdlib.h>
#include<stdio.h>

int main()
{
	unsigned int seed;
	int k, a, b;
	int rand_int(int a, int b);

	printf("Enter positive integer (seed)\n");
	scanf("%u", &seed);
	srand(seed);
	
	printf("Enter two integers (range):\n");
	scanf("%i %i", &a, &b);
//	printf("%i, %i\n", a, b);
	for (k=0; k<10; k++) {
		printf("%i ", rand_int(a, b));
		}
	printf("\n");
	return 0;
	
}
int rand_int(int a, int b)
{
//	printf("this is inside rand_int function: %i , %i\n", a, b);

	return rand()%(b-a+1) + a;
}

	             	       
