#include <stdlib.h>
#include <stdio.h>
//#include <math.h>
//if using math.h compile like this:
// gcc -std=c11 --static -Ofast -Wall -pedantic -o prime prime.c -lm
//

int isPrime(int n)
{
    int factor;
    //double sq_root;

    //return 1 (True) if n is prime
    if(n<2) return 0;
    if(n % 2 == 0) return n == 2; //special case for even numbers, only '2' is prime (n==2 = True)
    //if(n % 3 == 0) return n == 3; //if divisible by 3 then not prime
    //if(n % 5 == 0) return n == 5;
    //if(n % 7 == 0) return n == 7;

    //no need to scan all the way till n, can only scan until sqrt(n), 
    //because one of two factors of n will surely be less than its sqrt
    //and if no such factor is found then n is prime

    //sq_root = sqrt(n);

    //for(factor = 3; factor < sq_root+1; factor += 2) {
    for(factor = 3; factor*factor < n; factor += 2) {
	//need only evaluate mod for non-multiples of known primes
	if(n % factor == 0) return 0;
    }
    return 1;
}

int countPrimes(int n)
{
    int count, i;
    
    count = 1;

    for(i = 3; i < n; i+=2) {
	//TODO: need only call isPrime for non-multiples of known primes
	if(isPrime(i)) {
	    count++;
	    //printf("%d, ", i);
	}
    }
    return count;
}

int main(int argc, char **argv)
{
    if(argc != 2) {
	fprintf(stderr, "Usage: %s\n", argv[0]);
	return 1;
    }
    
    int n = atoi(argv[1]);

    printf("\n\nThere are %d primes in the [0, %d] range\n\n", countPrimes(n), n);

    return 0;
}


