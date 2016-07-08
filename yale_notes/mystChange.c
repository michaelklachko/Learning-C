#include <stdio.h>
#include <assert.h>

int main()
{
    int x;
    int a[10];
    int i;

    x = 5;

    //printf("%d\n%d\n", a[-1], a[10]);
    for(i=-1; i<11; i++) {
	a[i] = 37;
    }
    assert(x == 5);
    return 0;
}
