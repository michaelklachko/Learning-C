#include<stdio.h>

void switch2(int *a, int *b);

main() {

	
	int x = 3, y=7;
	
	int *px, *py;

	px = &x;
	py = &y;

	printf("x= %i, y= %i\n\n", x, y);
	
		switch2(px, py);

	printf("x= %i, y= %i\n\n", x, y);

/*
int a[] = {1,2,3,4,5};

int sum=0;
int i;

int* ptr = NULL;

ptr = &a[0];

for(i=0; i<5; i++) {

	sum = sum + *(a+i);

}

printf("sum = %i\n\n", sum);

//printf("a is: %i, address of a is: %u, pointer to a is: %u, b is: %i, address of the pointer pa is: %u\n\n", a, &a, pa, b, &pa);

*/
}


void switch2(int *a, int *b) {

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

return;
}
