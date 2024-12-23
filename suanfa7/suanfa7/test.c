#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define n 5  // 5个城市

// 最近邻点策略
int TSP1(int c[n][n], int w) {
    int edgeCount = 0, TSPLength = 0;
    int min, u, v;
    int flag[n] = { 0 };  // 标记数组，0表示未访问，1表示已访问
    u = w;          
    flag[w] = 1;        // 标记

    while (edgeCount < n - 1) { 
        min = 100; 
        for (int j = 0; j < n; j++) {  
            // 查找最小代价
            if ((flag[j] == 0) && (c[u][j] != 0) && (c[u][j] < min)) {
                v = j;
                min = c[u][j];  
            }
        }

        TSPLength += c[u][v];  

        flag[v] = 1;  // 标记
        edgeCount++; 
        printf("从 %d 到 %d，路径长度: %d\n", u + 1, v + 1, c[u][v]);
        u = v;  // 再从v开始继续查找
    }

    // 最后的边
    TSPLength += c[u][w];
    printf("从 %d 回到起点 %d，路径长度: %d\n", u + 1, w + 1, c[u][w]);
    return TSPLength; 
}

int main() {
    int C[n][n] = { 0 };  // 邻接矩阵C

    FILE* file = fopen("data.txt", "r");
    int x, y, cost;
    while (fscanf(file, "%d %d %d", &x, &y, &cost) != EOF) {
        C[x - 1][y - 1] = cost;  
        C[y - 1][x - 1] = cost;  // 无向图，值给两个方向
    }

    int start = 0; // 从第一个点出发
    int totalCost = TSP1(C, start);

    printf("最短哈密顿回路的长度: %d\n", totalCost);
    return 0;
}
