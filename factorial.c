//This program calculates factorial recursively
//
//Coded by Michael Klachko on Aug 3rd, 2013
//
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fact(int n);  //this function could be defined as macro

int main()
{

int n; 

	printf("\nEnter integer: \n");
	scanf("%i", &n);

	printf("\n%i! = %.0f\n", n, fact(n));

return 0;

}

double fact(int n)
{
	if(n==1) return 1;
	else return n*fact(n-1);
}
