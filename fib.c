//This program calculates nth number in a Fibonacci sequence. 
//Here we use non-recursive approach.
//
//
//Coded by Michael Klachko on August 3rd, 2013
//


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

	int n,i, a=1, b=1;   // first two elements in F sequence are 1.

	printf("\nEnter position in Fibonacci sequence: \n");
	scanf("%i", &n);
	
	for(i=1;i < n-1;i=i+2) {   //we process elements in pairs, treating element 1 as the first element (not element 0)

		printf("%i: %i\n%i: %i\n", i, a, i+1, b);
		a=a+b;     //each next element is a sum of the two previous ones
		b=b+a;     
	}

	printf("%i: %i\n%i: %i\n", i, a, i+1, b);

	if(n%2==0) printf("\n%ith element is %i\n", n, b);
	else printf("\n%ith element is %i\n", n, a);

return 0;
}

	
