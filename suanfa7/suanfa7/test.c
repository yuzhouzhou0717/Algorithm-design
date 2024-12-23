#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define n 5  // 5������

// ����ڵ����
int TSP1(int c[n][n], int w) {
    int edgeCount = 0, TSPLength = 0;
    int min, u, v;
    int flag[n] = { 0 };  // ������飬0��ʾδ���ʣ�1��ʾ�ѷ���
    u = w;          
    flag[w] = 1;        // ���

    while (edgeCount < n - 1) { 
        min = 100; 
        for (int j = 0; j < n; j++) {  
            // ������С����
            if ((flag[j] == 0) && (c[u][j] != 0) && (c[u][j] < min)) {
                v = j;
                min = c[u][j];  
            }
        }

        TSPLength += c[u][v];  

        flag[v] = 1;  // ���
        edgeCount++; 
        printf("�� %d �� %d��·������: %d\n", u + 1, v + 1, c[u][v]);
        u = v;  // �ٴ�v��ʼ��������
    }

    // ���ı�
    TSPLength += c[u][w];
    printf("�� %d �ص���� %d��·������: %d\n", u + 1, w + 1, c[u][w]);
    return TSPLength; 
}

int main() {
    int C[n][n] = { 0 };  // �ڽӾ���C

    FILE* file = fopen("data.txt", "r");
    int x, y, cost;
    while (fscanf(file, "%d %d %d", &x, &y, &cost) != EOF) {
        C[x - 1][y - 1] = cost;  
        C[y - 1][x - 1] = cost;  // ����ͼ��ֵ����������
    }

    int start = 0; // �ӵ�һ�������
    int totalCost = TSP1(C, start);

    printf("��̹��ܶٻ�·�ĳ���: %d\n", totalCost);
    return 0;
}
