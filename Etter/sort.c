//This program sorts elements by repeatedly finding min value, and swapping it with the elements at the beginning of the array.
//
//Coded by Michael Klachko on Aug 11, 2013
//

#include<stdio.h>
#include "functions.h"

int sort(int input[], int n) {

	int k;

	for(k=0;k<n;k++)  swap(input, k, n);

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
