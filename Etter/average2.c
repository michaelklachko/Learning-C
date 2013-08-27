//Same as average.c but outputs a file with average temp values for each day of the week during the 8 week period. 
//
//Coded by Michael Klachko, Aug 20, 2013
//

#include<stdio.h>

int main() {

	int i, j, input[8][7];
	double sum=0, output[8];
	FILE *temp_daily;
	FILE *temp_weekly;
	char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

	temp_daily = fopen("temps_daily.txt", "r");
	temp_weekly = fopen("temps_avg.txt", "w");

	if(temp_daily == 0) printf("Can't open temps_daily.txt for reading.\n\n");
	else {

		printf("here's the input array:\n\n");

		for(i=0;i<8;i++) {
			
			for(j=0;j<7;j++) {

				fscanf(temp_daily, "%i", &input[i][j]); 
				printf("%i ", input[i][j]);
			}
			printf("\n");
		}
		
		for(i=0;i<8;i++) {
			
			for(j=0;j<7;j++) {

				sum=sum+input[j][i];  //add column values
			}
			output[i] = sum/8;
			sum=0;
		}

		printf("\n\nAveraged temp values for each day of the week for 8 week period:\n\n");
		
		for(i=0;i<7;i++) {
		
			printf("%s: %.2f\n", days[i], output[i]);
			if(temp_weekly == 0) {

				printf("\n\nCan't create/write to temps_weekly.txt, exiting...\n\n");
				return 0;
			}
			else { 
			
				fprintf(temp_weekly, "%s: %.2f ", days[i], output[i]);
				fprintf(temp_weekly, "\n");
			}
		}
		printf("\n\n");

	}

return 0;
}
