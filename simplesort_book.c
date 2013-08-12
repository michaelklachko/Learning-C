//Sorting algorithm as implemented in the textbook. Repeatedly finds the min value, and moves it up.
//
//Coded (after looking at the code in the textbook) by Michael Klachko on Aug 12, 2013
//
//

#include<stdio.h>


void main() {

	int k=0, n, m, j, temp;
	int input[128];

	printf("\nEnter a sequence of integers, separated with spaces, type dot (.) when done:\n\n");

	while(scanf("%i", &input[k]) == 1) 

		k++;

	n=k;

	printf("\nSorting in ascending order: \n\n");

	for(k=0;k<n-1;k++) {

		m=k;

		for(j=k+1;j<n;j++) {

			if(input[j] < input[m]) {

				m=j;
			}

		}
	
		temp = input[k];
		input[k] = input[m];
		input[m] = temp;
		
		printf("%i ", input[k]);
	}
	
	printf("%i\n", input[n-1]);

	return;
}

		

				
			
