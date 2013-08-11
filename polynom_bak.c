#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(int c1,int c2,int c3, double x);

double find_root(double a, double step);


int main()
{
	int k,i,c1,c2,c3, count=0;
	double a,b,x, step;
	double find_root(double a, double step);

	printf("enter coef c1*x^2+c2*x+c3 ");
	scanf("%i %i %i", &c1, &c2, &c3);
	
	printf("enter range a b: ");
	scanf("%lf %lf", &a, &b);

	step= (double)(b-a)/10;

	for(k=0; k<10; k++) {

		a = a+k*step;

		if( f(c1,c2,c3,a)*f(c1,c2,c3, (a+step)) >= 1.0e-30) {	

			if(k==9 && count==0) {

				printf("No real roots found.\n\n");
				return 0;
			}

			else continue;

		}	
		
		else {

			count++;

			printf("root%i) = %f\n", count, find_root(a, step);

			a_temp=a;

			step_temp=step;

			printf("Segment %i has roots. Searching subsegments...\n\n", k);
	
			while(step_temp>0.0000001) {

				for(i=0; i<10; i++) {
				
//					printf("Subsegment %i has roots, breaking into subsegments... \n\n", i);
//					printf("a: %f\n", a);
//					printf("step: %f\n", step);
//					printf("ZZZZ= %f\n\n", f(c1,c2,c3, (a+i*step))*f(c1,c2,c3, (a+(i+1)*step))); 

					if( f(c1,c2,c3, (a_temp+i*step_temp))*f(c1,c2,c3, (a_temp+(i+1)*step_temp)) <= 1.0e-30) {	

						printf("Subsegment %i has roots, breaking into subsegments... \n\n", i);
						printf("a: %f\n", a_temp);
						printf("step: %f\n", step_temp);
						printf("ZZZZ= %f\n\n", f(c1,c2,c3, (a_temp+i*step_temp))*f(c1,c2,c3, (a_temp+(i+1)*step_temp))); 

					//	printf("the product is negative, decreasing step and breaking loop: \n");
					//	printf("i: %i\n", i);
					//	printf("a: %f\n", a);
					//	printf("step: %f\n", step);i

						a_temp=a_temp+i*step_temp;
						step_temp= step_temp/10;
						break;

				

return 0;

}

double find_root(double a, double step)

{

	printf("Segment %i has roots. Searching subsegments...\n\n", k);

	while(step_temp>0.0000001) {

		for(i=0; i<10; i++) {
		
//					printf("Subsegment %i has roots, breaking into subsegments... \n\n", i);
//					printf("a: %f\n", a);
//					printf("step: %f\n", step);
//					printf("ZZZZ= %f\n\n", f(c1,c2,c3, (a+i*step))*f(c1,c2,c3, (a+(i+1)*step))); 

			if( f(c1,c2,c3, (a_temp+i*step_temp))*f(c1,c2,c3, (a_temp+(i+1)*step_temp)) <= 1.0e-30) {	

				printf("Subsegment %i has roots, breaking into subsegments... \n\n", i);
				printf("a: %f\n", a_temp);
				printf("step: %f\n", step_temp);
				printf("ZZZZ= %f\n\n", f(c1,c2,c3, (a_temp+i*step_temp))*f(c1,c2,c3, (a_temp+(i+1)*step_temp))); 

			//	printf("the product is negative, decreasing step and breaking loop: \n");
			//	printf("i: %i\n", i);
			//	printf("a: %f\n", a);
			//	printf("step: %f\n", step);i

				a_temp=a_temp+i*step_temp;
				step_temp= step_temp/10;
				break;






double f(int c1,int c2,int c3,double x)
{
//	printf("x= %f, function = %f\n", x, c1*pow(x,2) + c2*x + c3);
 
	return c1*pow(x,2) + c2*x + c3;
}
