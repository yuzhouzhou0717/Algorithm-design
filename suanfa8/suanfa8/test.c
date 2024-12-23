#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

void prim(int n, int edges[MAX][MAX]) {
    int minCost = 0;  // ��С�ܳ���
    int visited[MAX] = { 0 };  // ����ѷ��ʵĴ�ׯ
    int parent[MAX];        // ��¼��С�������ı�
    int minEdge[MAX];       // ��¼��ǰÿ���ڵ����С��ֵ


    visited[0] = 1;               // �Ӵ�ׯ1��ʼ
    for (int i = 0; i < n; i++) {
        minEdge[i] = edges[0][i];
        parent[i] = 0;           // ��ʼ�����нڵ�ĸ��ڵ�Ϊ���
    }

    // ������С������
    for (int count = 1; count < n; count++) {
        int min = MAX;
        int u;

        // �ҵ�δ���ʽڵ��У���������Ľڵ�
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minEdge[i] < min) {
                min = minEdge[i];
                u = i;
            }
        }

        visited[u] = 1;      // ��ǽڵ� u Ϊ�ѷ���

        minCost += min;      // �����ܳ���
        printf("%d-%d\n", parent[u] + 1, u + 1);  

        // ������̱�
        for (int v = 0; v < n; v++) {
            if (!visited[v] && edges[u][v] < minEdge[v]) {
                minEdge[v] = edges[u][v];
                parent[v] = u;  // ���¸��ڵ�
            }
        }
    }

    printf("��С�ܳ���: %d\n", minCost);
}

int main() {
    int n;
    int edges[MAX][MAX];
    FILE* file = fopen("input.txt", "r");
    fscanf(file, "%d", &n);
    // ��ʼ���ڽӾ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = MAX;
        }
    }
    // ��ȡ����
    int u, v, cost;
    while (fscanf(file, "%d %d %d", &u, &v, &cost) != EOF) {
        edges[u - 1][v - 1] = cost;
        edges[v - 1][u - 1] = cost;  
    }

    prim(n, edges);

    return 0;
}
