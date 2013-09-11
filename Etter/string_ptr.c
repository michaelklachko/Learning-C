//this program counts number of occurances of string t in string s



#include<stdio.h>
#include<string.h>

main() {

	char s[] = "saldobarmalifubarque";
	char t[] = "bar";
	char *ps;

	int count = 0;

	ps = s;

	while((ps = strstr(ps, t)) != NULL) {   //point ps to the start of t in ps (ps is s initially, then moves towards the end of s)

		printf("beginning while loop\nps = %s\n\n", ps);
		
		ps = ps + strlen(t);      //move ps to the first position in s after t
		count++;
	
		printf("Ending while loop\n ps = %s\n\n", ps);
	}

	printf("string '%s' is present in string \"%s\" %i times\n\n", t, s, count);
}
