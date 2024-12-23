#include <stdio.h>

int main()
{
	int a = 10;
	int b = a++;
	int c = ++a;
	printf("%d", b);
	printf("%d", a);
	printf("%d", c);

	return 0;
}