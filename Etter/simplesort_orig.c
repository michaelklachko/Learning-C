//This program sorts elements by finding min value, then swapping it with the first element.
//
//Coded by Michael Klachko on Aug 11, 2013
//
//

#include<stdio.h>

void sort(int input[], int n);
int min(int input[], int n);


int main() {

	int k=0, j, n;
	int input[128];

	printf("\nEnter sequence of integers, separated by spaces. Type dot (.) when done: \n");

	while(scanf("%i", &input[k]) == 1) {   //keep accepting characters as long as they can be converted to integers
		
			k++;      //count them, so we know the length of the array
	}

	n=k;

	printf("\n\nSorting in ascending order:\n\n");

	for(j=0;j<n;j++) {       //find min value, swap it with the first element, and print it

		sort(input, n-j);
		printf("%i ", input[0]);  

		for(k=0;k<n-j-1;k++) {    //shift array values to the left (array shortens by one)

			input[k] = input[k+1];
		}

	}
	printf("\n\n");
	return 0;
}


void sort(int input[], int n) {  //swaps first element with the min value

	int temp, place;

	temp= input[0];
	place= min(input, n);  //using extra var 'place' so we don't have to call min() twice
	input[0]= input[place];
	input[place]= temp;

return;
}


int min(int input[], int n) { //returns the position of the min value in the array

	int k, min, place=0;
	min= input[0];

	for(k=1;k<n;k++) {

		if(input[k] < min) {

			min= input[k];
			place=k;
		}
	}
	return place;
}
