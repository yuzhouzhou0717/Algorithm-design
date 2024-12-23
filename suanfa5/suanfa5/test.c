#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100
int L[MAX][MAX]; // �洢LCS�ĳ���
int S[MAX][MAX]; // �洢״̬
char z[MAX];     // �洢�����������

int CommonOrder(char x[], int m, char y[], int n) {
    // ��ʼ��L��S
    for (int j = 0; j <= n; j++) {
        L[0][j] = 0; 
    }
    for (int i = 0; i <= m; i++) {
        L[i][0] = 0; 
    }
    // ��̬�滮����
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {   //1 2
                L[i][j] = L[i - 1][j - 1] + 1; // ƥ��ʱ��1
                S[i][j] = 1; // ״̬1 ���
            }
            else {
                if (L[i - 1][j] > L[i][j - 1]) {  //��0 2   ��1 1
                    L[i][j] = L[i - 1][j]; // ������ȡֵ
                    S[i][j] = 2; // ״̬2 
                }
                else {
                    L[i][j] = L[i][j - 1]; // �����ȡֵ
                    S[i][j] = 3; // ״̬3
                }
            }
        }
    }

    // ���������д浽z
    int i = m, j = n, k = L[m][n];
    while (i > 0 && j > 0) {
        if (S[i][j] == 1) {
            z[k - 1] = x[i - 1]; // ״̬Ϊ1 ����
            k--;
            i--;
            j--;
        }
        else if (S[i][j] == 2) {
            i--; // ״̬2
        }
        else {
            j--; 
        }
    }

    return L[m][n]; // ���ع��������еĳ���
}

int main() {
    char x[MAX], y[MAX];
    printf("�������һ���ַ���: ");
    scanf("%s", x);
    printf("������ڶ����ַ���: ");
    scanf("%s", y);

    int m = strlen(x);
    int n = strlen(y);

    int length = CommonOrder(x, m, y, n);

    printf("����������еĳ���: %d\n", length);
    printf("�����������: ");
    for (int k = 0; k < length; k++) {
        printf("%c", z[k]);
    }
    printf("\n");

    return 0;
}