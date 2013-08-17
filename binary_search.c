//Binary search algorithm for ordered lists. Returns position if found, or -1 if not.
//
//Assuming ascending order:
//
//1. compare target with middle of the list value
//2. if target is greater than the value, compare target with the middle value in the second half, 
//if not, compare with the first half middle value.
//3. keep comparing target until match is found, or until the segment of the list is less than two elements
//4. if match is found return the position 
//5. if no match is found, return -1
//

#include<stdio.h>

int main() {

	int k,d,e,f,z, s=0, l, t, position;

	printf("\nEnter the size of array: ");
	scanf("%i", &l);
	d=1;
	int input[l];
	e=2;
	printf("\nEnter value to find: ");
	scanf("%i", &t);
	f=3;
	for(k=0;k<l;k++)  input[k] = k;	
	z=4;
/*	printf("mem location of input[%i] = %u, mem location of t = %u\n\n", l, &input[l], &t);
	printf("input[%i] = %i\n", l, input[l]);
	printf("input[l-1] = %i\n", input[l-1]);
	printf("input[l+1] = %i\n", input[l+1]);
	printf("input[l+2] = %i\n", input[l+2]);
	printf("input[l+3] = %i\n", input[l+3]);
*/	
	
	position = match(input, s, l, t);

	if(position == -1 || position > l-1) printf("\n\n***Value %i NOT FOUND***\n\n", t);

	else printf("\nValue %i is found at position %i\n\n", t, position);

	main();

return 0;
}

int match(int input[], int s, int l, int t) {

//	printf("\nBeginning function: s= %i, l= %i, s+l = %i, N+1 = %i\n\n", s, l, s+l, N+1);
//	printf("input[l] = %i\n", input[l]);
	
	if(t==0 && input[0] == 0) return 0;
	if(t==input[l-1]) return l-1;

	while(l>1) {

	//	printf("inside while, s= %i, l= %i, now halving l:\n", s, l);

		l=l/2;

	//	printf("input[s+l] = input[%i+%i] = %i, t= %i\n", s, l, input[s+l], t);
		if(input[s+l] == t) { 
			
	//		printf("Target match! returning %i\n", s+l);
			return s+l;
		}

		if(input[s+l] < t) {
			
	//		printf("s= %i, l= %i, s+l = %i\n", s, l, s+l);
	//		printf("now s will be s+l and l will be l+1:\n\n");
			s=s+l;
			l=l+1;	
		}
	}
	return -1;
}
