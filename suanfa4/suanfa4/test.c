#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 99999  
#define N 10  // 顶点数

int path[N];   // 保存路径

// 计算最短路径
void shortestPath(int cost[N][N], int path[N]) {
    int minCost[N];  // 最短路径的代价
    int i, j;

    // 初始化minCost数组，起点的代价为0，其余为无穷大
    for (i = 0; i < N; i++) {
        minCost[i] = INF;
    }
    minCost[0] = 0;

    // 依次更新每个顶点的最短路径代价和路径
    for (j = 1; j < N; j++) { 
        for (i = 0; i < j; i++) {
            if (cost[i][j] != INF && minCost[i] + cost[i][j] < minCost[j]) {
                minCost[j] = minCost[i] + cost[i][j];
                path[j] = i;  // 记录顶点 j 的前驱顶点
            }
        }
    }

    // 输出从起点到终点的最短路径长度
    printf("最短路径长度: %d\n", minCost[N-1]);

    // 输出最短路径经过的顶点
    printf("路径: %d", N - 1);
    int v = N - 1;
    while (path[v] != -1) {
        printf(" <- %d", path[v]);
        v = path[v];
    }
    printf("\n");
}

int main() {
    // 初始化代价矩阵为无穷大
    int cost[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = INF;
        }
    }
    //文件输入
    FILE* file;
    file = fopen("edges.txt", "r");
    // 从文件中获取边的数量
    int edges;
    fscanf(file, "%d", &edges);  
    printf("边的数量: %d\n", edges);
    printf("输入的边信息:\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        // 从文件获取边
        fscanf(file, "%d %d %d", &u, &v, &w);
        cost[u][v] = w;  
        printf("边: %d -> %d, 代价: %d\n", u, v, w);
    }
    fclose(file);

    // 记录路径的数组，初始化为 -1
    for (int i = 0; i < N; i++) {
        path[i] = -1;
    }

    shortestPath(cost, path);

    return 0;
}
