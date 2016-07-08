#include <stdio.h>

int main()
{
    char a[2];

    a[0] = 'a';

    a[1] = '\0';

    printf("char array a: %s\n", a);
    for(int i=0; i<2; i++) {
	printf("%d, %c\n", i, a[i]);
    }

    printf(strcmp(a, 'a'));

    return 0;
}
