#include<stdio.h>
#include<stdlib.h>

#define UNIT 1024*1024
main() {

	int i=1, input, *ptr;
	size_t SIZE_MAX;

	while((ptr = (int *)calloc(i*UNIT,sizeof(int))) != NULL) {

		i++;
//		free(ptr);
	}

	printf("max contigious memory is %iMB\n, SIZE_MAX = %u", (i-1)*sizeof(int), SIZE_MAX);

	scanf("%i\n", &input);
}

