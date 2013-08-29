//weird bug, when you feed this source code as input to the program, it will print the longest line, followed by the newline, and then 
//print a few random characters. Those characters won't be shown if the longest array is initialized, or if you add commented out code after printf statement. Bizarre...
//
//
//this program prints the longest line in the input text, and prints it.



#include<stdio.h>

#define MAXLINE 10

int getline1(char line[], int max);
void copy(char from[], char to[]);

main() {

	char line[MAXLINE]; // = {97};  //current input line
	char longest[MAXLINE]; // = {97}; //longest line entered

	int len;   //length of the current input line
	int max=0;    //length of longest line

	while((len = getline1(line, MAXLINE)) > 0) {

//		printf("\n\ngetline returned length = %i\n", len);

		if(len > max) {
//			printf("length k=%i is longer than max=%i, copying line into longest\n\n", len, max);
			max = len;
			copy(line, longest);
		}
	
	}
	
	if(max > 0)

		printf("\n\nLongest line = %i:\n\n%s\n\n", max, longest);

}


int getline1(char line[], int lim) {

	char c;
	int i=0, k=0;

	while((c = getchar()) != EOF) {

		k++;                       //count the length of the input line (might be longer than limit)
//		printf("\nGot %c character.\n", c);
		
		if(i < lim-1) {

		//	printf("inserting '%c' into line[%i]\n", c, i);
		
			line[i] = c;
			
//			printf("line is now: %s\n", line);
			
			if(c == '\n') {

		//		printf("it's a newline character, breaking the loop\n\n");
				break;
			}
			else
				i++;
		}
		
		else if(c == '\n') {

		//	printf("it's a newline character, breaking the loop\n\n");
			break;
		}

	}


	line[i] = '\0';

	//printf("\n\nOut of the while loop, inserting NULL at line[%i] = '%c' (%i), returning k=%i\n", i, line[i], line[i], k);		
	//printf("line is now: %s\n", line);
	
	return k;
}		
		

void copy(char from[], char to[]) {

	int i=0;
//	printf("\nStarting copy:\n Copying line (%s) into longest (%s)\n\n", from, to);
	
	while((to[i] = from[i]) != '\0') 

		i++;

	//printf("\nFinished copying line (%s) into longest (%s)\n\n", from, to);

}
