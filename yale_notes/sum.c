#include <stdio.h>
#include <stdlib.h>

int sumRange(int start, int end)
{
    int sum;
    int i;

    sum = 0;

    printf("\nIntermediate sums: ");
    for (i=start; i<end; i++)
    {
	sum += i;
	printf("%d, ", sum);
    }

    //printf("\nFinal sum is: %d\n\n", sum);
    return sum;
}

int main(int argc, char **argv)
{
    //printf("\nNumber of supplied arguments: %d\n", argc-1);
    if(argc != 3) 
    {
	printf("\nargc != 3\n");
	printf("USAGE: %s start_integer end_integer\n\n", argv[0]);
	return 1;
    }
    
    //printf("\nafter the argc check\n");

    int start;
    int end;

    start = atoi(argv[1]);
    end = atoi(argv[2]);

    printf("\n\n\nsize of int variable: %d bytes!\n\n\n\n", sizeof(double));
    printf("\nFinal Sum of numbers between %d and %d is: %d\n\n", start, end, sumRange(start, end));

    return 0;
    
}


