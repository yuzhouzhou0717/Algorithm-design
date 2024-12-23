#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100
int L[MAX][MAX]; // 存储LCS的长度
int S[MAX][MAX]; // 存储状态
char z[MAX];     // 存储最长公共子序列

int CommonOrder(char x[], int m, char y[], int n) {
    // 初始化L和S
    for (int j = 0; j <= n; j++) {
        L[0][j] = 0; 
    }
    for (int i = 0; i <= m; i++) {
        L[i][0] = 0; 
    }
    // 动态规划计算
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {   //1 2
                L[i][j] = L[i - 1][j - 1] + 1; // 匹配时加1
                S[i][j] = 1; // 状态1 相等
            }
            else {
                if (L[i - 1][j] > L[i][j - 1]) {  //上0 2   左1 1
                    L[i][j] = L[i - 1][j]; // 从上面取值
                    S[i][j] = 2; // 状态2 
                }
                else {
                    L[i][j] = L[i][j - 1]; // 从左边取值
                    S[i][j] = 3; // 状态3
                }
            }
        }
    }

    // 公共子序列存到z
    int i = m, j = n, k = L[m][n];
    while (i > 0 && j > 0) {
        if (S[i][j] == 1) {
            z[k - 1] = x[i - 1]; // 状态为1 保存
            k--;
            i--;
            j--;
        }
        else if (S[i][j] == 2) {
            i--; // 状态2
        }
        else {
            j--; 
        }
    }

    return L[m][n]; // 返回公共子序列的长度
}

int main() {
    char x[MAX], y[MAX];
    printf("请输入第一个字符串: ");
    scanf("%s", x);
    printf("请输入第二个字符串: ");
    scanf("%s", y);

    int m = strlen(x);
    int n = strlen(y);

    int length = CommonOrder(x, m, y, n);

    printf("最长公共子序列的长度: %d\n", length);
    printf("最长公共子序列: ");
    for (int k = 0; k < length; k++) {
        printf("%c", z[k]);
    }
    printf("\n");

    return 0;
}