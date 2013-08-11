//This program finds real roots of a quadratic equation using incremental search algorithm:
//
//1. User enters range to search for roots.
//2. Range is divided into segments.
//3. For each segment its start and end points are checked, if close to zero, they are returned as roots.
//4. If start/end points are not close to zero, product of functions at start/end points are evaluated.
//5. If the product is negative or zero, the segment is divided into smaller segments, and each is then searched.
//6. Division happens until roots found, or subsegments become smaller than 'precision' value.  
//
//
//_______________________WARNING:___________________________________________
//
// THE PROGRAM FAILS IF THERE IS MORE THAN ONE ROOT IN A SINGLE SEGMENT.
// WHERE SUCH CASES ARE A CONCERN, "segments" PARAMETER SHOULD BE INCREASED
// _________________________________________________________________________
//
//
//Coded by Michael Klachko, August 4, 2013
//
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (c1*(x)*(x) + c2*(x) + c3)

#define precision 1.0e-5  
#define segments 100

double find_root(double a, double step);
int c1, c2, c3;


int main()
{
	int k, count=0;
	double a,b, step;

	printf("\nEnter coefficients c1 c2 c3 for quadratic equation c1*x*x+c2*x+c3: ");
	scanf("%i %i %i", &c1, &c2, &c3);
	
	printf("\nEnter range a b: ");
	scanf("%lf %lf", &a, &b);
	
	step= (b-a)/segments;

	for(k=0; k<segments; k++) {   //range is broken into initial segments

		if(fabs(f(a+k*step)) < precision) {  //is starting point close to zero?

			count++;  //number of roots found so far
			printf("\nROOT%i = %.4f\n\n", count, a+k*step);  //if segment start is root, goto to next segment
			continue;
		
		}

		if(fabs(f(a+(k+1)*step)) < precision) {  //is end of segment close to zero?
		
			count++;
			printf("\nROOT%i = %.4f\n\n", count, a+(k+1)*step);
			k++;  //skip not only current segment, but also the next segment
			continue;
	
		}

		if( f(a+k*step)*f(a+(k+1)*step) > precision*precision)  {	//check if function has opposite signs at start/end of segment. We are looking for cases where the product is less or equal than zero (or very small number in this case)

			if(k==segments-1 && count==0) {  //if no roots are found after checking the last segment, exit.

				printf("No real roots found.\n\n");
				return 0;
			}

		}	
		
		else {  //if segment has roots, divide it into subsegments, and search for roots

			count++;
			printf("\nROOT%i = %.4f\n\n", count, find_root((a+k*step), step/segments));

		}

	}

return 0;

}


double find_root(double a, double step)  //note that step here has been decreased, and a is the start of the segment

{
	int i;

	while(step>precision) {

		for(i=0; i<segments; i++) {  //check start/end of subsegments

			if(fabs(f(a+i*step)) < precision) {

				return a+i*step;

			}

			if(fabs(f(a+(i+1)*step)) < precision) {

				return a+(i+1)*step;

			}


			if(f(a+i*step)*f(a+(i+1)*step) <= precision*precision) {	

				return find_root((a+i*step), step/segments);   //keep dividing until subsegments are smaller than precision seeked

				
			}
		
			else if(i==segments-1) {  //safeguard, just in case...

				printf("PROGRAM TERMINATED DUE TO INFINITE LOOP...\n\n");
				return 0;

			}

		}

	}

	return a+step/2;  //when precision reached, return midpoint of subsegment as root

}
