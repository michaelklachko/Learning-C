//weird bug, when you feed this source code as input to the program, it will print the longest line, followed by the newline, and then 
//print a few random characters. Those characters won't be shown if the longest array is initialized, or if you add commented out code after printf statement. Bizarre...
//
//
//Figured it out:
//
//print %s command will print the array until it encounters NULL character. It will go outside of array if necessary. 
//
//
//this program prints the longest line in the input text, and prints it.



#include<stdio.h>

#define MAXLINE 300

int getline1(char line[], int max);
void copy(char from[], char to[]);

main() {

	char line[MAXLINE];                           //current input line
	char longest[MAXLINE];                        //longest line entered

	int len;                                      //length of the current input line
	int max=0;                                    //length of longest line

	while((len = getline1(line, MAXLINE)) > 0) {

		if(len > max) {
			
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
		

void copy(char from[], char to[]) {

	int i=0;
	
	while((to[i] = from[i]) != '\0')               //don't forget to copy NULL

		i++;
}
