//This program takes text as input, and reverses character order in each line


#include<stdio.h>

#define MAXLINE 1000

void reverse(char line[]);

main() {

	char c='a';
	char line[MAXLINE];
	int i;

	while(c != EOF) { 
 		
		//note the double check for EOF, because to get out of while loop we first need to get out of for loop
		
		for(i=0; (c = getchar()) != EOF && c != '\n'; i++)   

			line[i] = c;
		
		line[i] = '\0';   //replace newline with NULL
			
		reverse(line);

		printf("%s\n", line);
	}

}


void reverse(char line[]) {

	char temp;
	int i, j;
	
	for(j=0; line[j] != '\0'; j++);   //count the length of the line (not allowed to pass as argument)
	
	j--;  //don't count the NULL at the end
	
	for(i=0; i<j; i++, j--) {   //reversing could be done with a second array, but wouldn't be as memory efficient

		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}
