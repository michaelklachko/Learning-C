//This program sorts elements by repeatedly finding min value, and swapping it with the elements at the beginning of the array.
//
//Coded by Michael Klachko on Aug 11, 2013
//
//

#include<stdio.h>

void swap(int input[], int k, int n);
int min(int input[], int k, int n);


int main() {

	int k=0, n;
	int input[128];

	printf("\nEnter sequence of integers, separated by spaces. Type dot (.) when done: \n");

	while(scanf("%i", &input[k]) == 1)    //keep accepting characters as long as they can be converted to integers
		
		k++;      //count them, so we know the length of the array

	n=k;

	printf("\n\nSorting in ascending order:\n\n");

	for(k=0;k<n;k++) {       //find min value, swap it with kth element, and print it

		swap(input, k, n);
		printf("%i ", input[k]);  

	}
	printf("\n\n");
	return 0;
}


void swap(int input[], int k, int n) {  //swaps kth element with the min value

	int temp, place;

	temp= input[k];
	place= min(input, k, n);  //using extra var 'place' so we don't have to call min() twice
	input[k]= input[place];
	input[place]= temp;

	return;
}


int min(int input[], int k, int n) { //returns the position of the min value in the array

	int i, min, place=k;
	min= input[k];

	for(i=k+1;i<n;i++) 

		if(input[i] < min) {

			min= input[i];
			place=i;
		}
	
	return place;
}
