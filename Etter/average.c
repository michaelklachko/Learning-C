//This program reads data from a file, which contains 8 rows, 7 values each, which represent average temp values for 8 weeks.
//The program then outputs a file with average weekly temp values. 
//
//Coded by Michael Klachko, Aug 19, 2013
//

#include<stdio.h>

int main() {

	int i, j, input[8][7];
	double sum=0, output[8];
	FILE *temp_daily;
	FILE *temp_weekly;

	temp_daily = fopen("temps_daily.txt", "r");
	temp_weekly = fopen("temps_weekly.txt", "w");

	if(temp_daily == 0) printf("Can't open temps_daily.txt for reading.\n\n");
	else {

		printf("here's the input array:\n\n");

		for(i=0;i<8;i++) {
			
			for(j=0;j<7;j++) {

				fscanf(temp_daily, "%i", &input[i][j]); 
				printf("%i ", input[i][j]);
				sum=sum+input[i][j];
			}
			output[i] = sum/7;
			sum=0;
			printf("\n");
		}

		printf("\n\nHere's averaged weekly temp values:\n\n");
		
		for(i=0;i<8;i++) {
		
			printf("%.2f ", output[i]);
			if(temp_weekly == 0) {

				printf("\n\nCan't create/write to temps_weekly.txt, exiting...\n\n");
				return 0;
			}
			else fprintf(temp_weekly, "%.2f, ", output[i]);
		}
		printf("\n\n");

	}

return 0;
}

