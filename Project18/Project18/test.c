#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LEN 10000

int main()
{
    int fac[LEN] = { 0 };//求阶乘的数组
    int sum[LEN] = { 0 };//依次存储阶乘之和的数组
    int i, j, k;	//计数的变量
    int n;		//最后一个阶乘

    scanf("%d", &n);
    if (n == 1) {		//先考虑1的阶乘，初始化1的值
        printf("%d", 1);
        return 0;	//设置一个出口
    }
    int x = 0;	//x为进位的数
    fac[1] = 1;	//初始化1的阶乘，并从2的阶乘的和开始
    for (i = 1;i <= n;i++) {	//外层的循环保证算出各个数阶乘的值
        for (j = 1;j <= LEN;j++) {	//里层的循环算出当前数的阶乘
            fac[j] = fac[j] * i + x;	//当前储存的是j-1的阶乘，令每个一位上的数同乘j
            x = fac[j] / 10;		//x为int型，求出进位的数
            fac[j] = fac[j] % 10;	//更新当前数
        }
        for (k = 1;k <= LEN;k++) {	//求和，每求出一个阶乘加一次
            sum[k] = sum[k] + fac[k];
            if (sum[k] >= 10) {		//进位
                sum[k + 1] += 1;
                sum[k] = sum[k] % 10;
            }
        }
    }
    for (i = LEN;i >= 1;i--) { 	//求出应当输出的数字所在位置
        if (sum[i] != 0)
            break;
    }
    for (j = i;j >= 1;j--) {		//倒序输出
        printf("%d", sum[j]);
    }
    return 0;
}
