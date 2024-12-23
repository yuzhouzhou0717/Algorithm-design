#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void temp(int a,int b,int c) {
	if (a < b && b < c) {
		printf("stair\n");
	}

	else if (a<b && b>c) {
		printf("Peak\n");
	}
	else {
		printf("None\n");
	}
}
int main() {
	int a, b, c;
	
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		temp(a,b,c);
	}
	
	return 0;
}