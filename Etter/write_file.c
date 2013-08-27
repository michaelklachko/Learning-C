#include <stdio.h>

#define FILENAME "sensor.txt"


int main()
{

	int time=0;	
	int i;

	FILE *sensor;
	sensor = fopen(FILENAME, "w");

	for (i=0; i<150; i++) {
		fprintf(sensor, "%c %i\n", time, i);
		time++;
	}
	fclose(sensor);

	return 0;
}
		
