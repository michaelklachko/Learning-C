//this program takes text as input, and removes any blanks (spaces or tabs) at the end of each line. 
//It also removes empty lines.



#include<stdio.h>

#define MAXLINE 300

int getline1(char line[], int max);
void copy(char from[], char to[]);

main() {

	char line[MAXLINE];                           //current input line
	int len, i;                                   //length of the current input line

	while((len = getline1(line, MAXLINE)) > 0) {  //len = 1 when line is empty ('\n'), len = 0 when EOF

		for(i=len-2; line[i] == ' ' || line[i] == '\t' || line[i] == '\n'; i--) {

			line[i] = '\0';         //if the char before NULL is space or newline, replace it with NULL, decrement i
		}
		
		if(i > 0)

			printf("%s\n", line);
	}

}


int getline1(char line[], int lim) {

	char c;
	int i=0, k=0;

	while((c = getchar()) != EOF) {

		k++;                                   //count the length of the input line (might be longer than limit)
		if(i < lim-1) {

			line[i] = c;                   //if newline comes early, insert it, but don't increment i
			
			if(c == '\n') break;
			else i++;
		}
		
		else if(c == '\n') break;              //if newline comes at the last place or later, don't insert it. But insert NULL.
	}

	line[i] = '\0';
	return k;
}		
