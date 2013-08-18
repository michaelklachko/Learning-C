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

int main() {

	int k, s=0, l, t, position;

	printf("\nEnter the size of array: ");
	scanf("%i", &l);

	int input[l];

	printf("\nEnter value to find: ");
	scanf("%i", &t);

	for(k=0;k<l;k++)  input[k] = k*k*k-3*k*k-20;	//populate the array

	position = match(input, s, l, t);

	if(position == -1) printf("\n\n***Value %i NOT FOUND***\n\n", t);
	
	else printf("\nValue %i is found at position %i\n\n", t, position);

	main();

return 0;
}

int match(int input[], int s, int l, int t) {

	printf("\nBeginning function: s= %i, l= %i, (s+l)/2 = %i\n\n\n", s, l, (s+l)/2);
	
	if(t > input[l-1] || t < input[s]) {  //target not in array
	
		printf("Target is outside of the array\n");
		return -1;
	}

	while(1) {  //keep going until target found, or target is in between two conseq values

		printf("inside while, s= %i, l= %i, (s+l)/2= %i\n", s, l, (s+l)/2);
		printf("input[%i] = %i, t= %i\n\n", (s+l)/2, input[(s+l)/2], t);
		
		if(t > input[s] && t < input[s+1]) {  //check if target is in between two conseq values in the array
		
			printf("Target is in between two consequtive array elements\n");
			return -1;
		}
		
		if(input[(s+l)/2] == t) {   //check if target is at the edge of the segment
		
			printf("Target match\n");
			return (s+l)/2;
		}
		
		if(input[(s+l)/2] < t) {
			
			printf("Target in upper half\n");
			printf("s= %i, l= %i, (s+l)/2 = %i\n", s, l, (s+l)/2);
			printf("Setting start to be %i\n\n", (s+l)/2);
		
			s=(s+l)/2;   //if target is in the upper half of the segment, move the start up
		}
		else {
		
			printf("Target in lower half\n");
			printf("s= %i, l= %i, (s+l)/2 = %i\n", s, l, (s+l)/2);
			printf("Setting last to be %i\n\n", (s+l)/2);
			
			l=(s+l)/2;  //if target is in the lower half, move the last down
		}
	}
}
