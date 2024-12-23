#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 999
int D[MAX][MAX];
int Qmin(int a, int b,int c) {
	return a < b ? a < c ? a : c : b < c ? b : c;
}
int ASM(char p[], int m, char T[], int n) {
	int i, j;
	for (j = 1;j <= n;j++) {
		D[0][j] = j; //行
	}
	for (i = 0;i <= m;i++) {
		D[i][0] = i;  //列
	}
	for (j = 1;j <= n;j++) {
		for (i = 1;i <= m;i++) {
			if (p[i - 1] == T[j - 1])
				/*D[i][j] = Qmin(D[i - 1][j - 1], D[i - 1][j] + 1, D[i][j - 1] + 1);*/
				D[i][j] = D[i - 1][j - 1];
			else
			    D[i][j] = Qmin(D[i - 1][j - 1] + 1, D[i - 1][j] + 1, D[i][j - 1] + 1);
		}
	}
	return D[m][n];
}
int main() {
	char P[MAX], T[MAX];
	printf("请输入样本字符串：");
	scanf("%s", P);
	printf("请输入文本字符串：");
	scanf("%s", T);
	int m = strlen(P);
	int n = strlen(T);
	int result = ASM(P, m, T, n);
	//for (int i = 0;i <= m;i++) {
	//	for (int j = 0;j <= n;j++) {
	//		printf("%d",D[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("最小差别数为：%d", result);

	return 0;
}