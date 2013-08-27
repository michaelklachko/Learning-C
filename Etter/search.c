//This program takes any integers from users into an array, sorts the array, 
//then it asks the user to enter a value to search for in the array.:wq
//
//The program uses header file "functions.h" which contains declarations for sort-related functions (sort, swap, and min)
//
//To compile this program, you need to include (link) sort.c program, for example, like this: "gcc search.c sort.c -o search.exe"
//where the search.c is this program, and sort.c contains the functions declared in the header "functions.h". 
//
//Binary search algorithm for ordered lists. Returns position if found, or -1 if not.
//
//Assuming ascending order:
//
//1. compare target with middle of the list value
//2. if target is greater than the value, compare target with the middle value in the second half, 
//if not, compare with the first half middle value.
//3. keep comparing target until match is found, or until the segment of the list collapses into one element
//4. if match is found return the position 
//5. if no match is found, return -1
//

#include<stdio.h>
#include "functions.h"

int match(int input[], int s, int l, int t);

int main() {

	int k=0, s=0, l, t=5, position;
	int input[20];
	char linedelim;
	
	printf("\nEnter array elements separated by spaces, type dot (.) when done: ");
	while(scanf("%i", &input[k]) == 1) k++;
	
	scanf("%c", &linedelim);  //this is necessary because the next scan below would grab the last value entered in the first scan 
	    			  //(the dot) from the stdin buffer (and it would skip the second input from user)

//	printf("\n***linedelim = %c (%i)\n\n", linedelim);

	l=k;

	printf("\nHere's what you entered:\n\n");
	for(k=0;k<l;k++)  printf("%i ", input[k]);
	
	sort(input, l);

	printf("\n\nHere's array after sort:\n\n");
	for(k=0;k<l;k++)  printf("%i ", input[k]);
	
	printf("\n\nEnter value to find:\n");
	scanf("%i", &t);

	position = match(input, s, l, t);

	if(position == -1) printf("\n\n***Value %i NOT FOUND***\n\n", t);
	
	else printf("\nValue %i is found at position %i\n\n", t, position);

return 0;
}

int match(int input[], int s, int l, int t) {

	int mid;
	
	while(l>=s) {  //if element is not found, s will first become equal to, and then greater than l

		mid=(s+l)/2;

		if(input[mid] == t) return mid;  //check for target match in the middle
		
		if(input[mid] < t) 	s=mid+1;   //if target is in the upper half of the segment, move the start above the middle
		
		else  l=mid-1;  //if target is in the lower half, move the last below the middle
	}
	return -1;
}
