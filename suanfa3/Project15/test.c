#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
//#define R_WH 7  // 真币重量
//#define F_WH 5   // 假币重量

int DoubleCoins(int coins[], int low, int high) {
    if (low == high) {
        return low;
    }
    // 大于1个
    int mid = (low + high) / 2;
    int LSum = 0, RSum = 0;

    for (int i = low; i <= mid; i++) {
        LSum += coins[i];
    }
    for (int i = mid + 1; i <= high; i++) {
        RSum += coins[i];
    }

    if (LSum <= RSum) {
        return DoubleCoins(coins, low, mid);  // 在左边
    }
    else {
        return DoubleCoins(coins, mid + 1, high);  // 在右边
    }
}
// 三分法查找假币
int ThreeCoins(int coins[], int low, int high) {
    if (low == high) {
        return low;
    }
    // 大于1个
    int third = (high - low + 1) / 3;  // 将硬币分成三组

    int mid1 = low + third;   // 第一组末位
    int mid2 = low + 2 * third;  // 第二组末位

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
        return ThreeCoins(coins, low, mid1 - 1);  // 在左边
    }else if (MSum < RSum) {
        return ThreeCoins(coins, mid1, mid2 - 1);  // 在中间
    }else { // 假币在右边
        return ThreeCoins(coins, mid2, high);  }}
int main() {
    srand(time(NULL));
    int n;
    printf("硬币的数量: ");
    scanf("%d", &n);
    int coins[MAX];
    int Floca = rand() % n;
    printf("假币的位置在%d\n", Floca + 1);
    for (int i = 0; i < n; i++) {
        if (i == Floca) {
            coins[i] = 0;
        }
        else {
            coins[i] = 1;
        }
    }
    printf("假币质量为0 真币质量为1\n");
    int result1 = DoubleCoins(coins, 0, n - 1);
    printf("二分法--假币位置: %d\n", result1 + 1);
    int result2 = ThreeCoins(coins, 0, n - 1);
    printf("三分法--假币位置: %d\n", result2 + 1);

    return 0;
}
