#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int a[1000];
//int fun(int l, int r)
//{
//	int min =99999;
//	for (int i = l;i <= r;i++)
//	{
//		if (a[i] <= min)
//		{
//			min = a[i];
//		}
//	}
//	return min;
//}
//int main()
//{
//	int n, q;
//	int l, r;
//	scanf("%d %d", &n, &q);
//	for (int i = 0;i < n;i++)
//		scanf("%d", &a[i]);
//	for (int i = 0;i < q;i++)
//	{
//		scanf("%d %d", &l, &r);
//		printf("%d\n", fun(l, r));
//	}
//	return 0;
//}

//void func(int n) {
//	if (n % 4 == 0 && n % 100 != 0) {
//		printf("yes");
//	}	
//	else if(n % 400 == 0){
//		printf("yes");
//	}
//	else
//	    printf("no");
//}
//
//int main() {
//	int y = 0;
//	scanf("%d", &y);
//	func(y);
//	return 0;
//}


//void fun(int *s) {
//	int len = strlen(s);
//	int flag = 0;
//	for (int i = 0;i <=99;i++) {
//		if (s[i] != s[len - i - 1]) {
//			int tmp = s[i];
//			s[i] = s[len - i];
//			s[len - i] = tmp;
//		}
//		else {
//            flag++;
//		    continue;
//		}
//		printf("%d", flag);
//	}
//	printf("Impossible");
//}
//
//int main() {
//
//	int n;
//	char s;
//	scanf("%d\n%s", &n, &s);
//	fun(s);
//	return 0;
//}
//#include <math.h>
//
//#define pai acos(-1)
//int main() {
//	double r = 0.0;
//	scanf("%lf", &r);
//	printf("%.7lf", pai * r * r);
//
//	return 0;
//}

//int fun(int a, int arr[],int n){
//	for (int i = 0;i <n;i++) {
//		if (a == arr[i]) {
//			return i+1;
//			break;
//		}
//		continue;
//	
//	}
//	return -1;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	int arr[1000];
//	for(int i=0;i<n;i++){
//		scanf("%d", &arr[i]);
//	}
//	int a;
//	scanf("%d", &a);
//	int ret = fun(a, arr,n);
//	printf("%d", ret);
//	return 0;
//}
//#define M 10007
//long long Fib(long long num)
//{
//	long long first = 0;
//	long long second = 1;
//	long long third = 0;
//	for (int i = 2; i <= num; i++)
//	{
//		third = first + second;
//		first = second;
//		second = third;
//	}
//	return third%M;
//}
//
//int main() {
//	long long n;
//	scanf("%lld", &n);
//	long long ret = Fib(n);
//	printf("%lld", ret);
//	return 0;
////}
//#include<stdio.h>
//#define M 10007
//int main()
//{
//	int a1, a2;
//	a1 = a2 = 1;
//	int sum = 0, temp;//sum是保存余数的变量 ，temp是为了方便交换数据 
//	long n;//因为n>=1 and n<=1000000 
//	long i;
//	scanf("%ld", &n);
//
//	for (i = 1;i <= n;i++)
//	{
//		sum = a1 % M;
//		temp = a2;
//		a2 = (a1 + a2) % M;
//		a1 = temp;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i, j;
//	int a[n][n];
//	for (i = 0;i < n;i++)
//	{
//		for (j = 0;j < i + 1;j++)
//		{
//			a[i][0] = 1;
//			a[i][j] = 1;
//
//			if (i > 1 && j > 0 && i != j)
//			{
//				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//			}
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
//#include <ctype.h>
//#include <string.h>
//int main() {
//	char s1[10], s2[10];
//	int i = 0;
//	do {
//		scanf("%s", &s1[i]);
//		i++;
//	} while (s1[i] == '\n');
//	do {
//		scanf("%s", &s2[i]);
//		i++;
//	} while (s2[i] == '\n');
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	char S1[10];
//	char S2[10];
//	for (int i = 0;i < len1;i++) {
//		S1[i] = toupper(s1[i]);
//	}
//	for (int i = 0;i < len2;i++) {
//		S2[i] = toupper(s2[i]);
//	}
//
//	if (len1 != len2)
//		printf("1"); //长度不等
//	else if (len1 == len2 && strcmp(s1, s2) == 0)
//		printf("2"); //完全相等
//	else if (len1 == len2 && strcmp(S1,S2) == 0) //区分大小写 不相等
//		printf("3");
//	else
//		printf("4");
//
//	return 0;
//}