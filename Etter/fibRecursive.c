//This program calculates nth number in a Fibonacci sequence. 
//Here we use recursive approach.
//
//
//Coded by Michael Klachko on August 3rd, 2013
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fib(int n);

int main()
{

	int n;

	printf("\nEnter position in Fibonacci sequence: \n");
	scanf("%i", &n);
	
	printf("\n%ith element is %i\n", n, fib(n));

return 0;
}

int fib(int n)
{

	if(n==1 || n==2) return 1;
	else return fib(n-1)+fib(n-2);
}
