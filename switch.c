#include<stdio.h>

void main()
{
	int rank;
	printf("Please enter your rank: \n");
	scanf("%d", &rank);

	switch (rank)
	{
	case 1: case 2:
		printf("You are a freshman!\n");
		break;

	case 3:
		printf("You are a sophomore!\n");
		break;

	case 4:
			printf("You are a junior!\n");
			break;

	case 7:
		printf("You are a junior!\n");
		break;

	case 5:
			printf("You are a senior!\n");
			break;

	case 6:
		printf("You are a grad student!\n");
		break;

	default:
		printf("invalid rank!\n");
	}
	main();

}
