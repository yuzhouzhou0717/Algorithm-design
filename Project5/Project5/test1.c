#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//my_strlen(char *str) {
//	int count = 0;
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main() {
//
//	char arr[] = "abcd";
//
//	int len = my_strlen(arr);
//
//	printf("%d", len);
//
//	return 0;
//}
//my_strlen(char* str) {
//	if (*str != '\0')
//		return 1 + my_strlen(str + 1);
//	else
//		return 0;
//}
//
//int main() {
//
//	char arr[] = "abcd";
//
//	int len = my_strlen(arr);
//
//	printf("%d", len);
//
//	return 0;
//}
//int fib(int n) {
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib  (n - 2);
//}

//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//}

//int main() {
//
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int min = a;
//	if (min > b) {
//		a = min;
//	}
//	for (int i = min;i > 0;i--) {
//		if (a % i == 0 && b % i == 0) {
//			printf("最大公约数为%d", i);
//			break;
//		}
//	}
//	return 0;
//}
//int main() {
//
//	int a, b, c;
//	scanf("%d %d", &a, &b);
//	while(c =a % b){
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//	return 0;
//}
int main() {
	for (int i = 1;i <= 9;i++) {
		for (int j = 1;j <= i;j++) {
			printf("%d*%d=%-2d  ", i,j,i*j);
		}
		printf("\n");
	}
	return 0;
}