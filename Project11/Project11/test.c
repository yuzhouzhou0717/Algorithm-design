#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main() {
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int temp;
//	int len = sizeof(arr1) / sizeof(arr1[0]);
//	for (int i = 0;i < len;i++) {
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//		}
//	for (int i = 0;i < len;i++) {
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0;i < len;i++) {
//		printf("%d", arr2[i]);
//	}
// return 0;
// }

void init(char arr[], int sz) {
	for (int i = 0;i < sz;i++) {
		arr[i] = 0;
	}
}
void print(char arr[], int sz) {
	for (int i = 0;i < sz;i++) {
		printf("%c", arr[i]);
	}
}
void reverse(char arr[], int sz) {
	for (int i = 0;i < sz/2;i++) {
		int tmp = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = tmp;
	}
}
int main() {
	char arr[] = "abcdefgh";
	int sz = sizeof(arr) / sizeof(arr[0]);
	//init(arr, sz);
	//print(arr, sz);
	reverse(arr, sz); 
	print(arr, sz);
	return 0;
}

