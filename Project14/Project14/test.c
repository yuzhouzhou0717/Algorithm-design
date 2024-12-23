#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
typedef struct {
    double x, y;
} point;

// �������n����
void greatePoint(point arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].x = (rand() % 10000) + (rand() % 10000) / 10000.0;
        arr[i].y = (rand() % 10000) + (rand() % 10000) / 10000.0;
    }
}
// ����������֮��ľ���
double Distance(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// ������
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
// ���� ��X����
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
// ���η�
double Closest(point arr[], int left, int right) {
    if (right - left == 1)
        return Distance(arr[left], arr[right]);// ֻ��������

    if (right - left == 2) {
        double d1 = Distance(arr[left], arr[left + 1]);
        double d2 = Distance(arr[left + 1], arr[right]);
        double d3 = Distance(arr[left], arr[right]);
        return fmin(d1, fmin(d2, d3));   // �����������о��������
    }
    // ��������������
    int mid = (left + right) / 2;   // �ҳ��е㣬�ֱ������ߺ��ұߵ�����Ծ���
    double d1 = Closest(arr, left, mid);
    double d2 = Closest(arr, mid + 1, right);
    double d = fmin(d1, d2);  // ��Сֵ����d

    // ������������һ��һ�ҵ����
    // ����ָ����� d ��Χ�ڵĵ㴫������P
    point P[3000];
    int index = 0;
    for (int i = left; i <= right; i++) {
        if (fabs(arr[i].x - arr[mid].x) < d) {
            P[index++] = arr[i];
        }
    }

    // ������P ��x��������
    QuickSort(P, 0, index - 1);

    // ���������ߵ���С���
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
    printf("��ģ�ֱ�Ϊ��100, 1000, 3000\n\n");
    for (int i = 0; i < 3; i++) {
        int n = num[i];
        greatePoint(arr, n);// �������n����

        LARGE_INTEGER frequency;
        LARGE_INTEGER start, end;
        double sec;// ����ʱ��
        double MinD;// ����Ծ���
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);
        MinD = BF(arr, n); // ������
        QueryPerformanceCounter(&end);
        sec = (double)(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;
        printf("�������루����������%f\n����ʱ��: %.3f ΢��\n", MinD, sec);

        //���η� �Ȱ�x���������ҵ��м��

        QuickSort(arr, 0, n - 1); // �Ȱ�x��������
        LARGE_INTEGER frequency1;
        LARGE_INTEGER start1, end1;
        double sec1;// ���η�����ʱ��
        double FZMinD;// ���η�����Ծ���
        QueryPerformanceFrequency(&frequency1);
  
        QueryPerformanceCounter(&start1);
        FZMinD = Closest(arr, 0, n - 1);
        QueryPerformanceCounter(&end1);
        sec1 = (double)(end1.QuadPart - start1.QuadPart) * 1000000.0 / frequency1.QuadPart;
        printf("�������루���η�����%f\n����ʱ��: %.3f ΢��\n\n", FZMinD, sec1);
    }

    return 0;
}
