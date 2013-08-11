#include<stdio.h>
#include<stdlib.h>

int main()
{
	double p=0;  //reliability of a single component
	int N=0;  //total number of trials
	double rand_float(); //generates a floating point random number from 0 to 1
	double rand1, rand2, rand3; //outcomes for each componenent at each trial
	int pass=0;  //total number of successful trials
	int i;
	double Ps; //success rate for 3 in series nodes

	printf("Enter reliability of a single component, and number of trials: ");
	scanf("%lf %i", &p, &N);
	
	for(i=1; i<=N; i++) 
	{
		rand1=rand_float();
		rand2=rand_float();
		rand3=rand_float();

		if(rand1<(1-p) || rand2<(1-p) || rand3<(1-p)) continue;  //if any of the components fail, don't increment pass counter
		else pass++;  //if all 3 components are good, incr # of successful trials
	}

	Ps = (double)pass/N; //success rate for 3 in series nodes after N trials

	printf("pass = %i\n", pass);
	printf("\n");


	printf("predicted success rate for 3 in series nodes (Ps=p^3): %f\n", p*p*p);
	printf("observed success rate for 3 in series nodes after %i trials: %f\n", N, Ps);

	main();

return 0;
		
}


double rand_float()
{
	double x;
	
	x= (double)rand()/RAND_MAX;

return x;

}
