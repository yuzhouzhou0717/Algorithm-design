#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
typedef struct {
    double x, y;
} point;

// 生成随机n个点
void greatePoint(point arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].x = (rand() % 10000) + (rand() % 10000) / 10000.0;
        arr[i].y = (rand() % 10000) + (rand() % 10000) / 10000.0;
    }
}
// 计算两个点之间的距离
double Distance(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// 蛮力法
double BF(point arr[], int n) {
    double MinD = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double D = Distance(arr[i], arr[j]);
            if (D < MinD) {
                MinD = D;
            }
        }
    }
    return MinD;
}
// 快排 按X坐标
void QuickSort(point arr[], int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    point pivot = arr[left];
    while (i < j) {
        while (i < j && arr[j].x >= pivot.x) j--;
        arr[i] = arr[j];
        while (i < j && arr[i].x <= pivot.x) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    QuickSort(arr, left, i - 1);
    QuickSort(arr, i + 1, right);
}
// 分治法
double Closest(point arr[], int left, int right) {
    if (right - left == 1)
        return Distance(arr[left], arr[right]);// 只有两个点

    if (right - left == 2) {
        double d1 = Distance(arr[left], arr[left + 1]);
        double d2 = Distance(arr[left + 1], arr[right]);
        double d3 = Distance(arr[left], arr[right]);
        return fmin(d1, fmin(d2, d3));   // 返回三个点中距离最近的
    }
    // 多余三个点的情况
    int mid = (left + right) / 2;   // 找出中点，分别计算左边和右边的最近对距离
    double d1 = Closest(arr, left, mid);
    double d2 = Closest(arr, mid + 1, right);
    double d = fmin(d1, d2);  // 最小值赋给d

    // 处理两个点在一左一右的情况
    // 距离分割线在 d 范围内的点传入数组P
    point P[3000];
    int index = 0;
    for (int i = left; i <= right; i++) {
        if (fabs(arr[i].x - arr[mid].x) < d) {
            P[index++] = arr[i];
        }
    }

    // 对数组P 按x坐标排序
    QuickSort(P, 0, index - 1);

    // 检查距离中线的最小点对
    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index && (P[j].x - P[i].x < d); j++) {
            double d3 = Distance(P[i], P[j]);
            if (d3 < d) 
                d = d3;
        }
    }
    return d;
}

int main() {
    point arr[3000];
    int num[] = { 100, 1000, 3000 };
    printf("规模分别为：100, 1000, 3000\n\n");
    for (int i = 0; i < 3; i++) {
        int n = num[i];
        greatePoint(arr, n);// 随机生成n个点

        LARGE_INTEGER frequency;
        LARGE_INTEGER start, end;
        double sec;// 计算时间
        double MinD;// 最近对距离
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);
        MinD = BF(arr, n); // 蛮力法
        QueryPerformanceCounter(&end);
        sec = (double)(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
        printf("最近点距离（蛮力法）：%f\n运行时间: %.3f 微秒\n", MinD, sec);

        //分治法 先按x坐标排序，找到中间点

        QuickSort(arr, 0, n - 1); // 先按x坐标排序
        LARGE_INTEGER frequency1;
        LARGE_INTEGER start1, end1;
        double sec1;// 分治法计算时间
        double FZMinD;// 分治法最近对距离
        QueryPerformanceFrequency(&frequency1);
  
        QueryPerformanceCounter(&start1);
        FZMinD = Closest(arr, 0, n - 1);
        QueryPerformanceCounter(&end1);
        sec1 = (double)(end1.QuadPart - start1.QuadPart) * 1000000.0 / frequency1.QuadPart;
        printf("最近点距离（分治法）：%f\n运行时间: %.3f 微秒\n\n", FZMinD, sec1);
    }

    return 0;
}
