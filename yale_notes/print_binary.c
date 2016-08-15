#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
   /* print an integer in binary */

   if(argc != 2) 
   {
       printf("\nUsage: %s INTEGER\n", argv[0]);
       return 1;
   }
    
   int i,x,b;
   int starting_zero = 1;
   
   x = atoi(argv[1]);

   printf("\n\n%d: ", x);

   if(x == 0)
   {
       printf("0\n\n");
       return 0;
   }


   for(i=31; i>=0; i--)
   {
        b = (x & (1 << i)) >> i;  //b == 1 if x has '1' in ith position, otherwise b == 0

	if(starting_zero)   //do not print leading zeros of x
	    if(b == 0) {} 
	    else
	    {
		printf("1");
		starting_zero = 0;
	    }
	else printf("%d", b);  
   }

   printf("\n\n");

   return 0;
}
