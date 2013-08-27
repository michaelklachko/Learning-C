#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{

int i, dummy, x, sum, count=0;
float avg;

	FILE *stat;
	stat=fopen("stat.text", "w");
	if(stat==NULL) printf("can't open file\n");

	else 
		for(i=1;i<101;i++)  
		
			fprintf(stat, "%i  %i\n", i, rand()%101);
		
	fclose(stat);

	stat=fopen("stat.text", "r");
	if(stat==NULL) printf("can't open file\n");
	
	else 
		 while ((fscanf(stat, "%i   %i", &dummy, &x)) == 2) {	

			sum=sum+x;
			count++;
		}	
	
  
printf("count = %i, sum = %i, dummy = %i, x = %i\n", count, sum, dummy, x);

	avg=(float)sum/count;

	printf("sum/count = avg = %f\n", avg);	
	fclose(stat);

	count=0;
	stat=fopen("stat.text", "r");
	
	if(stat==NULL) printf("can't open file\n");

	else 

		while((fscanf(stat, "%i %i", &dummy, &x)) == 2) 

			if(x>avg) count++;

	printf("\n%i values are above average (%f)\n", count, avg);

return 0;
}
	

