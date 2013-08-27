/*This program calculates molecular weights of aminoacids. 
 * Aminoacids consist of several chemical elements: H, N, C, O, or S.
 * A user can enter several aminoacids separated by spaces.
 * A single array is used to store input, and then individual acids are extracted, calculated, and printed. 
 *
 * Coded by Michael Klachko on Aug 10 2013
 *
*/



#include<stdio.h>
#include<ctype.h>

#define ELEMENTS "HCNOS"
#define WEIGHTS {1, 12, 14, 16, 32}        

int weight(int input, int num);
void formula(char input[], int k, int count);

int main()
{
	int k=0, n, count=0;
	char input[128];

	printf("\nEnter aminoacids, separated by spaces, enter dot (.) when done: \n");


	while((input[k] = getchar()) != '.')   //input array is populated with n character string
	
		k++;
		
	n=k+1;                       //n is k+1 because the last character is always set to space.
	input[k] = ' ';   //last ch is set to space because space triggers calculation when mult acids are entered

	for(k=0; k<n; k++) {

		input[k] = toupper(input[k]);
		
		if(input[k] != ' ' && input[k] != '\n')  //user should separate acids by space, however, newline ch is also accepted as a separator (however an error will be printed at the end complaining about a non valid element. Can be fixed, but not important.
		{
//			printf("non-space character: %c, counting...\n", input[k]);
			count++;     //we need to know how many characters are in each acid (if more than one entered)
		}
		else 
		{
//			printf("space character: \"%c\", calling formula\n\n", input[k]);
			formula(input, k, count);   //space ch in input tells us an acid has been detected in the input string
			count=0;     //therefore, weight calc function is called, and count is reset for the possible next acid in the string
		}
	}
return 0;
}

			
void formula(char input[], int n, int count)
{

	int k, num=0, temp=0, total = 0;
	
/*	printf("n= %i, count= %i, amino array passed from main contains:\n\n", n, count);

	for(k=n-count; k<n; k++) 

		printf("%c", input[k]);
	
	printf("\n\nhere's the same array printed as a string: %s\n\n", input);
*/
	
	if(isalpha(input[n-count]) == 0) {  //the acid starts [count] characters back, and is [count] characters long.

		printf("first character is not a valid element\n\n");   //the first character must be a letter.
		return;
	}
	else {
		
//		printf("first character is a letter. FOR REFERENCE: '0' = %i\n", '0');

		for(k=n-count; k<n; k++) {

//			printf("iteration %i:\n", k);
//			printf("input[%i] = '%c' (%i)\n", k, input[k], input[k]);
//			printf("value of function isalpha[%c] = %i\n", input[k], isalpha(input[k]));

			if(isalpha(input[k])) {  //if letter, find out the number that follows it (1 if no number)

//				printf("%ith character is a letter: '%c'\n", k, input[k]);
		
				if(isdigit(input[k+1])) {

//					printf("%ith character is a digit: '%c'\n", k+1, input[k+1]);

					if(isdigit(input[k+2])) {  //it could be 2-digit number

//						printf("%ith character is a digit: '%c'\n", k+2, input[k+2]);

						if(isdigit(input[k+3])) {  //but 3-digit numbers are not accepted.

//							printf("%ith character is a digit: '%c'\n", k+3, input[k+3]);
							printf("too many digits in a row\n\n");
							return;
						}

						else 	{
						
							num = (input[k+1]-'0')*10 + (input[k+2]-'0');  //calculate the 2-digit number, to convert character digit into an integer digit we substract '0' (decimal 48).
//							printf("num (two digits) = %i\n", num);
						}
					}

					else    {
						
						num = input[k+1]-'0';  //calculate 1-digit number
//						printf("num (one digit) = %i\n", num);
					}
				}

				else   { 
				
					num = 1;  //if no numbers follow the element letter, set number to 1
//					printf("num = 1\n");
				}

				temp = weight(input[k], num);  //calculate the weight of the element in the acid
//				printf("temp = %i\n", temp);

				if(temp == 0) { //weight function returns zero if it does not recognize the element

					printf("not a valid element detected in formula\n\n");
					return;
				}

				total = total + temp;  //otherwise, total is updated for the acid
//				printf("total = %i\n", total);
			}
		}

		printf("Molecular weight of ");
		
		for(k=n-count; k<n; k++)

			printf("%c", input[k]);

		printf(" is %i\n\n", total);

	}

}


int weight(int element, int num)
{
	int k;
	char elements[] = ELEMENTS;  //see #DEFINE statements at the top, there's 1-to-1 correspondence of elements and their weights`
	int weights[] = WEIGHTS;

	for(k=0; k<5; k++) {   

	//	printf("%c", elements[k]);

		if(element == elements[k])

			return num*weights[k];

	}
	return 0;
}
