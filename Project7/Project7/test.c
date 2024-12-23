#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
//int Fun(int n) {
//	if (n == 5)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//int main() {
//
//	int ret = Fun(2);
//	printf("%d", ret);
//
//	return 0;
//}
// 

//×Ö·û´®ÄæÐò
//int main() {
//	char arr[] ="abcdef";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 2;
//	while (left<right) {
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s", arr);
//	return 0;
//}


//×Ö·û´®ÄæÐò º¯Êý
// 
//void reverse_str(char arr[]) {
//	int left = 0;
//	int right = strlen(arr) - 1;
//	while(left<right){
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main() {
//	char arr[] = "abcdef";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse_str(arr);
//	printf("%s", arr);
//	return 0;
//}
//
//int my_strlen(char* str) {
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//
////×Ö·û´®ÄæÐò º¯Êý µÝ¹é
//void reverse_str(char *str) {
//	char tmp = *str;
//	int len = my_strlen(str);
//	*str = *(str + len - 1);
//	*(str + len - 1) = '\0';
//	if(my_strlen(str+1)>=2)
//		reverse_str(str + 1);
//	*(str + len - 1) = tmp;
//
//}
//
//
//
//int main() {
//	char arr[] = "abcdefg";
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse_str(arr);
//	printf("%s", arr);
//	return 0;
//}


////¼ÆËãÃ¿Î»Ö®ºÍ µÝ¹é
//int DigSum(unsigned n) {
//	if (n > 9) 
//		return DigSum(n / 10) + n % 10;
//	else
//		return n;
//}
//int main() {
//	unsigned int n = 0;
//
//	scanf("%d", &n);
//	int sum = DigSum(n);
//	printf("%d", sum);
//	return 0;
//}

//ÇónµÄk´Î·½
//double Pow(int n, int k) {
//	int flag = 1;
//	for (int i = 0;i < k;i++) {
//		flag *= n;
//
//	}
//	return 1.0/flag;
//}

double Pow(int n, int k) {
	if (k > 0)
		return n * Pow(n, k - 1);
	if (k == 0)
		return 1;
	if (k < 0)
		return 1.0 / Pow(n, -k);
}
int main() {
	int n = 0;
	int k = 0;
	scanf_s("%d %d",&n, &k);
	double m = Pow(n, k);
	printf("%lf\n", m);

	return 0;
}