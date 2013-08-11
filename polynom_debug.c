#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define precision 1.0e-5
//#define segments 100

double f(double x);

double find_root(double a, double step);

int c1, c2, c3, segments;

int main()
{
	int k, count=0;
	double a,b, step;

	printf("\nEnter coef c1*x^2+c2*x+c3 ");
	scanf("%i %i %i", &c1, &c2, &c3);
	
	printf("\nEnter range a b: ");
	scanf("%lf %lf", &a, &b);
	
	printf("\nEnter number of segments to search: ");
	scanf("%i", &segments);

	step= (b-a)/segments;

	for(k=0; k<segments; k++) {

		//printf("SEGMENT %i:\n\n", k);
		//printf("a: %f\n", a+k*step);
		//printf("step: %f\n", step);
		//printf("f(%f)*f(%f) = %f * %f = %.10f\n\n", a+k*step, a+(k+1)*step, f((a+k*step)), f((a+(k+1)*step)), f((a+k*step))*f((a+(k+1)*step))); 

		if(fabs(f(a+k*step)) < precision) {

			count++;
	
			printf("ROOT AT THE START OF SEGMENT: \n\n");
			printf("***ROOT%i = %.4f\n\n", count, a+k*step);

			continue;
		
		}

		if(fabs(f(a+(k+1)*step)) < precision) {
		
			count++;
			printf("ROOT AT THE END OF SEGMENT:\n\n");
			printf("***ROOT%i = %.4f\n\n", count, a+(k+1)*step);
		
			k++;
			continue;
	
		}

		if( f((a+k*step))*f((a+(k+1)*step)) > precision*precision)  {	

			if(k==segments-1 && count==0) {

				printf("No real roots found.\n\n");
				return 0;
			}

			//else    printf("No roots in segment %i:\n\n", k);
			
		}	
		
		else {

			count++;

			//printf("Segment %i has roots. Searching subsegments...\n\n", k);
			printf("***ROOT%i = %.4f\n\n", count, find_root((a+k*step), step/segments));

		}

	}

return 0;

}

double find_root(double a, double step)

{
	int i;

	while(step>precision) {

		for(i=0; i<segments; i++) {

			//printf("subsegment %i: \n", i);
			//printf("a: %f\n", a);
			//printf("step: %f\n", step);
			//printf("f(%f)*f(%f) = %f * %f = %.10f\n\n", a+i*step, a+(i+1)*step, f((a+i*step)), f((a+(i+1)*step)), f((a+i*step))*f((a+(i+1)*step))); 

			if( fabs(f(a+i*step)) < precision) {

				printf("Root at the start of subsegment:\n\n\n");

				return a+i*step;

			}

			if( fabs(f(a+(i+1)*step)) < precision) {

				printf("Root at the end of subsegment:\n\n\n");

				return a+(i+1)*step;

			}


			if( f((a+i*step))*f((a+(i+1)*step)) <= precision*precision) {	

				//printf("Subsegment %i has roots, breaking into subsegments... \n\n", i);

				return find_root((a+i*step), step/segments);
				
			}
		
			else if(i==segments-1) {

				printf("INFINITE LOOP...\n\n");

				return 0;

			}

			else {

				//printf("Subsegment %i has NO roots, moving on... \n\n", i);

			}

		}

	}

	return a+step/2;

}




double f(double x)
{
 
	return c1*pow(x,2) + c2*x + c3;
}
