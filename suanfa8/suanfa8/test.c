#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 100

void prim(int n, int edges[MAX][MAX]) {
    int minCost = 0;  // 最小总长度
    int visited[MAX] = { 0 };  // 标记已访问的村庄
    int parent[MAX];        // 记录最小生成树的边
    int minEdge[MAX];       // 记录当前每个节点的最小边值


    visited[0] = 1;               // 从村庄1开始
    for (int i = 0; i < n; i++) {
        minEdge[i] = edges[0][i];
        parent[i] = 0;           // 初始化所有节点的父节点为起点
    }

    // 构建最小生成树
    for (int count = 1; count < n; count++) {
        int min = MAX;
        int u;

        // 找到未访问节点中，距离最近的节点
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minEdge[i] < min) {
                min = minEdge[i];
                u = i;
            }
        }

        visited[u] = 1;      // 标记节点 u 为已访问

        minCost += min;      // 更新总长度
        printf("%d-%d\n", parent[u] + 1, u + 1);  

        // 更新最短边
        for (int v = 0; v < n; v++) {
            if (!visited[v] && edges[u][v] < minEdge[v]) {
                minEdge[v] = edges[u][v];
                parent[v] = u;  // 更新父节点
            }
        }
    }

    printf("最小总长度: %d\n", minCost);
}

int main() {
    int n;
    int edges[MAX][MAX];
    FILE* file = fopen("input.txt", "r");
    fscanf(file, "%d", &n);
    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edges[i][j] = MAX;
        }
    }
    // 读取距离
    int u, v, cost;
    while (fscanf(file, "%d %d %d", &u, &v, &cost) != EOF) {
        edges[u - 1][v - 1] = cost;
        edges[v - 1][u - 1] = cost;  
    }

    prim(n, edges);

    return 0;
}
