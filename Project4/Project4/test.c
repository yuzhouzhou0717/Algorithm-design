#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main() {
//	int n;
//	scanf("%d", &n);
//	int flag = 1;
//	for (int i = 1;i <= n;i++)
//		flag *= i;
//	printf("%d", flag);
//	return 0;
//}
//int main() {
//	int flag = 1;
//	int sum = 0;
//	for (int i = 1;i <= 10;i++) {
//		for (int j = 1;j <= i;j++) {
//			flag *= j;
//		}sum += flag;
//		flag = 1;
//
//	}printf("%d", sum);
//	
//
////}
//int main(){
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 11;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0;i < sz;i++) {
//		if (arr[i] == k) {
//			printf("找到了,下标为%d", i);
//			break;
//		}
//	}
//	if (i == sz) {
//		printf("找不到");
//	}
//	return 0;
//}
int main() { /////折半查找

    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	int left = 0;
	int right = sz-1;
	

	int k = 0;
	scanf("%d", &k);
	while (left <= right) {
		int mid = (left + right) / 2;
		if (k > arr[mid]) {
			left = mid + 1;
		}
		else if (k < arr[mid]) {
			right = mid - 1;
		}
		else {
			printf("找到了，下标为%d", mid); //left=right
			break;
		}
	}
	if (left > right) {
		printf("找不到");
	}

	return 0;
}