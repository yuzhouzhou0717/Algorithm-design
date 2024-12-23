#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 99999  
#define N 10  // ������

int path[N];   // ����·��

// �������·��
void shortestPath(int cost[N][N], int path[N]) {
    int minCost[N];  // ���·���Ĵ���
    int i, j;

    // ��ʼ��minCost���飬���Ĵ���Ϊ0������Ϊ�����
    for (i = 0; i < N; i++) {
        minCost[i] = INF;
    }
    minCost[0] = 0;

    // ���θ���ÿ����������·�����ۺ�·��
    for (j = 1; j < N; j++) { 
        for (i = 0; i < j; i++) {
            if (cost[i][j] != INF && minCost[i] + cost[i][j] < minCost[j]) {
                minCost[j] = minCost[i] + cost[i][j];
                path[j] = i;  // ��¼���� j ��ǰ������
            }
        }
    }

    // �������㵽�յ�����·������
    printf("���·������: %d\n", minCost[N-1]);

    // ������·�������Ķ���
    printf("·��: %d", N - 1);
    int v = N - 1;
    while (path[v] != -1) {
        printf(" <- %d", path[v]);
        v = path[v];
    }
    printf("\n");
}

int main() {
    // ��ʼ�����۾���Ϊ�����
    int cost[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = INF;
        }
    }
    //�ļ�����
    FILE* file;
    file = fopen("edges.txt", "r");
    // ���ļ��л�ȡ�ߵ�����
    int edges;
    fscanf(file, "%d", &edges);  
    printf("�ߵ�����: %d\n", edges);
    printf("����ı���Ϣ:\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        // ���ļ���ȡ��
        fscanf(file, "%d %d %d", &u, &v, &w);
        cost[u][v] = w;  
        printf("��: %d -> %d, ����: %d\n", u, v, w);
    }
    fclose(file);

    // ��¼·�������飬��ʼ��Ϊ -1
    for (int i = 0; i < N; i++) {
        path[i] = -1;
    }

    shortestPath(cost, path);

    return 0;
}
