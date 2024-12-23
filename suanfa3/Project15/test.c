#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
//#define R_WH 7  // �������
//#define F_WH 5   // �ٱ�����

int DoubleCoins(int coins[], int low, int high) {
    if (low == high) {
        return low;
    }
    // ����1��
    int mid = (low + high) / 2;
    int LSum = 0, RSum = 0;

    for (int i = low; i <= mid; i++) {
        LSum += coins[i];
    }
    for (int i = mid + 1; i <= high; i++) {
        RSum += coins[i];
    }

    if (LSum <= RSum) {
        return DoubleCoins(coins, low, mid);  // �����
    }
    else {
        return DoubleCoins(coins, mid + 1, high);  // ���ұ�
    }
}
// ���ַ����Ҽٱ�
int ThreeCoins(int coins[], int low, int high) {
    if (low == high) {
        return low;
    }
    // ����1��
    int third = (high - low + 1) / 3;  // ��Ӳ�ҷֳ�����

    int mid1 = low + third;   // ��һ��ĩλ
    int mid2 = low + 2 * third;  // �ڶ���ĩλ

    int LSum = 0, MSum = 0, RSum = 0;

    for (int i = low; i < mid1; i++) {
        LSum += coins[i];
    }
    for (int i = mid1; i < mid2; i++) {
        MSum += coins[i];
    }
    for (int i = mid2; i <= high; i++) {
        RSum += coins[i];
    }if (LSum < MSum) {
        return ThreeCoins(coins, low, mid1 - 1);  // �����
    }else if (MSum < RSum) {
        return ThreeCoins(coins, mid1, mid2 - 1);  // ���м�
    }else { // �ٱ����ұ�
        return ThreeCoins(coins, mid2, high);  }}
int main() {
    srand(time(NULL));
    int n;
    printf("Ӳ�ҵ�����: ");
    scanf("%d", &n);
    int coins[MAX];
    int Floca = rand() % n;
    printf("�ٱҵ�λ����%d\n", Floca + 1);
    for (int i = 0; i < n; i++) {
        if (i == Floca) {
            coins[i] = 0;
        }
        else {
            coins[i] = 1;
        }
    }
    printf("�ٱ�����Ϊ0 �������Ϊ1\n");
    int result1 = DoubleCoins(coins, 0, n - 1);
    printf("���ַ�--�ٱ�λ��: %d\n", result1 + 1);
    int result2 = ThreeCoins(coins, 0, n - 1);
    printf("���ַ�--�ٱ�λ��: %d\n", result2 + 1);

    return 0;
}
