//create 2D array from a file with rows of random numbers. 
//find local peaks: highlight those numbers that are larger than their
//immediate neighbours, so that (m,n) > {(m-1, n); (m+1, n); (m, n-1); (m, n+1)}
//for edges of the array (top/bottom rows, and left/rightmost columns), adjustments are made 
//to position indexes, so that no index is outside of array
//array is then printed, and the peaks are shown as values in brackets

#include<stdio.h>

#define R 20
#define C 20


void find_peaks(int terra[R][C]);

main() {

	int r, c;
	int terra[R][C];

	//generate a text file with data:
	FILE *terrain;
	terrain = fopen("terrain.txt", "w");

	for(r=0; r<R; r++) {

		for(c=0; c<C; c++) 

			fprintf(terrain, "%2i ", rand()%100);

		fprintf(terrain, "%c", '\n');
	}

	fclose(terrain);

	//read the data from text file to an array
	terrain = fopen("terrain.txt", "r");

	if(terrain == NULL)

		printf("Can't open terrain.txt\n\n");

	else

		for(r=0; r<R; r++)

			for(c=0; c<C; c++)

				fscanf(terrain, "%i", &terra[r][c]); 
				
	
	//show the peaks
	find_peaks(terra);

}


void find_peaks(int terra[R][C]) {

	int r,c,a,b,d,f;	
	
	for(r=0; r<R; r++) {
	
		for(c=0; c<C; c++) {

			if(r==0)	 {d=-2; f=0;}
			if(r==R-1)	 {d=0; f=-2;}
			if(c==0) 	{a=-2; b=0;}
			if(c==C-1) 	{a=0; b=-2;}
			
			else if(r != 0 && r != R-1 && c != 0 && c != C-1)     
			
				{a=0; b=0; d=0; f=0;}


			if(terra[r][c] > terra[r][c-1+a] && 
			   terra[r][c] > terra[r][c+1+b] && 
			   terra[r][c] > terra[r-1+d][c] && 
			   terra[r][c] > terra[r+1+f][c])

				printf(" (%i)", terra[r][c]);

			else

				printf("%4i ", terra[r][c]);
		}
		printf("\n\n");
	}

}
