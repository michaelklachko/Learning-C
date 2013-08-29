//weird bug, when you feed this source code as input to the program, it will print the longest line, followed by the newline, and then 
//print a few random characters. Those characters won't be shown if the longest array is initialized, or if you add commented out code after printf statement. Bizarre...
//
//
//this program prints the longest line in the input text, and prints it.



#include<stdio.h>

#define MAXLINE 1000

int getline1(char line[], int max);
void copy(char line[], char longest[]);

main() {

	char line[MAXLINE];  //current input line
	char longest[MAXLINE];// = {65}; //longest line entered

	int len;   //length of the current input line
	int max=0;    //length of longest line

	while((len = getline1(line, MAXLINE)) > 0) {

		if(len > max) {

			max = len;
			copy(line, longest);
		}
	
	}
	
	if(max > 0)

		printf("\n\n%s", longest);

/*	int i;
	for(i=0; i<max; i++) 

		printf("%c", longest[i]);

	printf("\n");

	*/
}


int getline1(char line[], int lim) {

	char c;
	int i;

	for(i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; i++) 

		line[i] = c;

	if(c == '\n') {

		line[i] = c;
		i++;
	}
	line[i] = '\0';
	
	return i;
}

		

void copy(char from[], char to[]) {

	int i=0;

	while(from[i] != '\0') {

		to[i] = from[i];
		i++;

	}

}
