//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//// 欧几里得算法，计算最大公约数（GCD）
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = a % b;
//        a = b;
//        b = temp;
//    }
//    return a;
//}
//
//// 分式化简
//void simplifyFraction(int numerator, int denominator) {
//    if (denominator == 0) {
//        printf("分母不能为零\n");
//        return;
//    }
//    // 计算最大公约数
//    int gcdValue = gcd(numerator, denominator);
//
//    // 使用最大公约数化简分数
//    numerator /= gcdValue;
//    denominator /= gcdValue;
//
//    // 输出化简后的分数
//    printf("化简后的分数是: %d/%d\n", numerator, denominator);
//}
//
//int main() {
//    int numerator, denominator;
//
//    // 输入分子和分母
//    printf("请输入分子: ");
//    scanf("%d", &numerator);
//    printf("请输入分母: ");
//    scanf("%d", &denominator);
//
//    // 调用化简分数函数
//    simplifyFraction(numerator, denominator);
//
//    return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXN 10000
//
//// 活动结构体
//typedef struct {
//    int start;
//    int end;
//    int index; // 活动的索引
//} Activity;
//
//// 比较函数，用于排序活动（按开始时间排序）
//int compare(const void* a, const void* b) {
//    Activity* x = (Activity*)a;
//    Activity* y = (Activity*)b;
//
//    if (x->start != y->start) {
//        return x->start - y->start;
//    }
//    return x->end - y->end;
//}
//
//// 最小堆结构体，用于跟踪当前教室的结束时间
//typedef struct {
//    int endTime;
//    int roomIndex;  // 教室编号
//} HeapNode;
//
//HeapNode heap[MAXN];
//int heapSize = 0;
//
//// 堆操作：插入元素
//void pushHeap(HeapNode node) {
//    heap[heapSize++] = node;
//    int i = heapSize - 1;
//    while (i > 0 && heap[i].endTime < heap[(i - 1) / 2].endTime) {
//        HeapNode temp = heap[i];
//        heap[i] = heap[(i - 1) / 2];
//        heap[(i - 1) / 2] = temp;
//        i = (i - 1) / 2;
//    }
//}
//
//// 堆操作：弹出堆顶元素
//HeapNode popHeap() {
//    HeapNode root = heap[0];
//    heap[0] = heap[--heapSize];
//    int i = 0;
//    while (2 * i + 1 < heapSize) {
//        int j = 2 * i + 1;
//        if (j + 1 < heapSize && heap[j].endTime > heap[j + 1].endTime) {
//            j++;
//        }
//        if (heap[i].endTime <= heap[j].endTime) break;
//        HeapNode temp = heap[i];
//        heap[i] = heap[j];
//        heap[j] = temp;
//        i = j;
//    }
//    return root;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    Activity activities[MAXN];
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &activities[i].start, &activities[i].end);
//        activities[i].index = i + 1; // 记录活动编号
//    }
//
//    // 对活动按开始时间排序
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // 最小堆用于跟踪当前活动的结束时间
//    int roomCount = 0;
//    int rooms[MAXN][MAXN];  // 用于记录每个教室的活动安排
//    int roomEndTime[MAXN];   // 每个教室的结束时间
//
//    // 处理活动安排
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//
//        // 检查是否有空闲的教室
//        if (heapSize > 0 && heap[0].endTime <= start) {
//            HeapNode node = popHeap(); // 取出最早结束的教室
//            int roomIndex = node.roomIndex;
//            roomEndTime[roomIndex] = end;
//            rooms[roomIndex][0]++;
//
//            // 防止越界：活动个数应 <= MAXN
//            if (rooms[roomIndex][0] < MAXN) {
//                rooms[roomIndex][rooms[roomIndex][0]] = activities[i].index;
//            }
//            pushHeap((HeapNode) { end, roomIndex }); // 更新教室结束时间
//        }
//        else {
//            // 如果找不到合适的教室，开设一个新的教室
//            roomEndTime[roomCount] = end;
//            rooms[roomCount][0] = 1;
//            rooms[roomCount][1] = activities[i].index; // 记录活动编号
//            pushHeap((HeapNode) { end, roomCount });
//            roomCount++;
//        }
//    }
//
//    // 输出最少教室数
//    printf("%d\n", roomCount);
//
//    // 输出每个教室的安排方案
//    for (int i = 0; i < roomCount; i++) {
//        for (int j = 1; j <= rooms[i][0]; j++) {
//            if (j > 1) printf(" ");
//            printf("%d", rooms[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//void greedyChange(int target) {
//    // 货币面值数组
//    int denominations[] = { 100, 50, 20, 10, 5, 1 };
//    int n = sizeof(denominations) / sizeof(denominations[0]);
//
//    int count[6] = { 0 }; // 用来记录每个面值的数量
//
//    // 遍历每个面值，从大到小进行找零
//    for (int i = 0; i < n; i++) {
//        // 计算当前面值的个数
//        count[i] = target / denominations[i];
//        target %= denominations[i]; // 更新剩余需要找零的金额
//    }
//
//    // 输出找零方案
//    printf("找零方案:\n");
//    int totalCount = 0;  // 记录总张数
//    for (int i = 0; i < n; i++) {
//        if (count[i] > 0) {
//            printf("面值 %d: %d 张\n", denominations[i], count[i]);
//            totalCount += count[i];  // 累计总张数
//        }
//    }
//
//    printf("总共需要找零张数: %d\n", totalCount);
//}
//
//int main() {
//    int target;
//    printf("请输入需要找零的金额: ");
//    scanf("%d", &target);
//
//    greedyChange(target);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//#define MAX_V 100 // 最大结点数
//#define INF INT_MAX // 表示无穷大，无法到达的结点
//
//// 最小堆的结构
//typedef struct {
//    int vertex;  // 结点
//    int dist;    // 距离
//} MinHeapNode;
//
//typedef struct {
//    int size;
//    int capacity;
//    MinHeapNode* heap;
//} MinHeap;
//
//// 最小堆操作函数
//MinHeap* createMinHeap(int capacity) {
//    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
//    minHeap->capacity = capacity;
//    minHeap->size = 0;
//    minHeap->heap = (MinHeapNode*)malloc(capacity * sizeof(MinHeapNode));
//    return minHeap;
//}
//
//void swap(MinHeapNode* x, MinHeapNode* y) {
//    MinHeapNode temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//void minHeapify(MinHeap* minHeap, int idx) {
//    int smallest = idx;
//    int left = 2 * idx + 1;
//    int right = 2 * idx + 2;
//
//    if (left < minHeap->size && minHeap->heap[left].dist < minHeap->heap[smallest].dist) {
//        smallest = left;
//    }
//    if (right < minHeap->size && minHeap->heap[right].dist < minHeap->heap[smallest].dist) {
//        smallest = right;
//    }
//    if (smallest != idx) {
//        swap(&minHeap->heap[smallest], &minHeap->heap[idx]);
//        minHeapify(minHeap, smallest);
//    }
//}
//
//MinHeapNode extractMin(MinHeap* minHeap) {
//    if (minHeap->size == 0) {
//        MinHeapNode node = { -1, INF };
//        return node; // 表示队列为空
//    }
//
//    MinHeapNode root = minHeap->heap[0];
//    MinHeapNode lastNode = minHeap->heap[minHeap->size - 1];
//    minHeap->heap[0] = lastNode;
//    minHeap->size--;
//    minHeapify(minHeap, 0);
//
//    return root;
//}
//
//void decreaseKey(MinHeap* minHeap, int vertex, int dist) {
//    int i;
//    for (i = 0; i < minHeap->size; i++) {
//        if (minHeap->heap[i].vertex == vertex) {
//            minHeap->heap[i].dist = dist;
//            break;
//        }
//    }
//
//    // 从该结点开始向上调整
//    while (i > 0 && minHeap->heap[i].dist < minHeap->heap[(i - 1) / 2].dist) {
//        swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//// Dijkstra 算法的实现
//void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
//    int dist[MAX_V];  // dist[i] 存储从源结点 src 到 i 的最短路径
//    int sptSet[MAX_V]; // 用于标记已确定最短路径的结点
//
//    MinHeap* minHeap = createMinHeap(V);
//
//    // 初始化最短路径数组和优先队列
//    for (int i = 0; i < V; i++) {
//        dist[i] = INF;
//        sptSet[i] = 0;
//        minHeap->heap[i].vertex = i;
//        minHeap->heap[i].dist = INF;
//    }
//    dist[src] = 0;
//    minHeap->heap[src].dist = 0;
//    minHeap->size = V;
//
//    while (minHeap->size) {
//        MinHeapNode minNode = extractMin(minHeap);
//        int u = minNode.vertex;
//        sptSet[u] = 1;
//
//        // 遍历 u 的所有邻接点
//        for (int v = 0; v < V; v++) {
//            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
//                dist[v] = dist[u] + graph[u][v];
//                decreaseKey(minHeap, v, dist[v]);
//            }
//        }
//    }
//
//    // 输出结果
//    printf("Shortest distances from source %d:\n", src);
//    for (int i = 0; i < V; i++) {
//        if (dist[i] == INF) {
//            printf("Vertex %d is unreachable\n", i);
//        }
//        else {
//            printf("Distance to vertex %d: %d\n", i, dist[i]);
//        }
//    }
//}
//
//int main() {
//    int V, E, src;
//
//    // 输入图的结点数 V 和边数 E
//    printf("Enter number of vertices and edges:\n");
//    scanf("%d %d", &V, &E);
//
//    // 初始化图的邻接矩阵
//    int graph[MAX_V][MAX_V];
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++) {
//            graph[i][j] = INF;
//        }
//    }
//
//    // 输入边的权重
//    printf("Enter edges (start vertex, end vertex, weight):\n");
//    for (int i = 0; i < E; i++) {
//        int u, v, weight;
//        scanf("%d %d %d", &u, &v, &weight);
//        graph[u][v] = weight;
//    }
//
//    // 输入源结点
//    printf("Enter source vertex:\n");
//    scanf("%d", &src);
//
//    // 调用 Dijkstra 算法
//    dijkstra(graph, V, src);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//#define MAXN 200
//#define MAXM 1000
//#define INF INT_MAX
//
//// 最小堆节点结构体
//typedef struct {
//    int node;
//    int dist;
//} Node;
//
//Node heap[MAXN];
//int heapSize = 0;
//
//void swap(Node* a, Node* b) {
//    Node temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 上浮操作
//void heapifyUp(int idx) {
//    while (idx > 1 && heap[idx].dist < heap[idx / 2].dist) {
//        swap(&heap[idx], &heap[idx / 2]);
//        idx /= 2;
//    }
//}
//
//// 下沉操作
//void heapifyDown(int idx) {
//    int minIdx = idx;
//    int left = idx * 2;
//    int right = idx * 2 + 1;
//
//    if (left <= heapSize && heap[left].dist < heap[minIdx].dist)
//        minIdx = left;
//    if (right <= heapSize && heap[right].dist < heap[minIdx].dist)
//        minIdx = right;
//
//    if (minIdx != idx) {
//        swap(&heap[idx], &heap[minIdx]);
//        heapifyDown(minIdx);
//    }
//}
//
//// 插入操作
//void push(Node node) {
//    heap[++heapSize] = node;
//    heapifyUp(heapSize);
//}
//
//// 删除并返回堆顶元素
//Node pop() {
//    Node result = heap[1];
//    heap[1] = heap[heapSize--];
//    heapifyDown(1);
//    return result;
//}
//
//// Dijkstra 算法计算最短路径
//void dijkstra(int graph[MAXN][MAXN], int n, int start, int end) {
//    int dist[MAXN];
//    int visited[MAXN] = { 0 };
//    for (int i = 0; i < n; i++) {
//        dist[i] = INF;
//    }
//    dist[start] = 0;
//
//    push((Node) { start, 0 });
//
//    while (heapSize > 0) {
//        Node current = pop();
//        int u = current.node;
//
//        if (visited[u]) continue;
//        visited[u] = 1;
//
//        for (int v = 0; v < n; v++) {
//            if (graph[u][v] != INF && !visited[v]) {
//                if (dist[u] + graph[u][v] < dist[v]) {
//                    dist[v] = dist[u] + graph[u][v];
//                    push((Node) { v, dist[v] });
//                }
//            }
//        }
//    }
//
//    // 输出结果
//    if (dist[end] == INF) {
//        printf("-1\n");
//    }
//    else {
//        printf("%d\n", dist[end]);
//    }
//}
//
//int main() {
//    int n, m;
//    scanf("%d %d", &n, &m);
//
//    // 初始化图，INF 表示没有直接连接的城市
//    int graph[MAXN][MAXN];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            graph[i][j] = INF;
//        }
//    }
//
//    // 读取道路信息
//    for (int i = 0; i < m; i++) {
//        int a, b, x;
//        scanf("%d %d %d", &a, &b, &x);
//        graph[a][b] = x;
//        graph[b][a] = x;  // 双向道路
//    }
//
//    int start, end;
//    scanf("%d %d", &start, &end);
//
//    dijkstra(graph, n, start, end);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    int weight;
//    int value;
//    double ratio;  // 单位重量的价值
//} Item;
//
//// 比较函数，用于按单位重量价值从大到小排序
//int compare(const void* a, const void* b) {
//    Item* itemA = (Item*)a;
//    Item* itemB = (Item*)b;
//
//    if (itemA->ratio < itemB->ratio) {
//        return 1;
//    }
//    else if (itemA->ratio > itemB->ratio) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    int n, W;
//
//    // 动态输入物品数量和背包容量
//    printf("请输入物品数量和背包容量: ");
//    scanf("%d %d", &n, &W);
//
//    // 动态分配物品数组
//    Item* items = (Item*)malloc(n * sizeof(Item));
//
//    printf("请输入物品的重量和价值:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &items[i].weight, &items[i].value);
//        items[i].ratio = (double)items[i].value / items[i].weight;  // 计算单位重量的价值
//    }
//
//    // 按单位价值从大到小排序
//    qsort(items, n, sizeof(Item), compare);
//
//    int totalValue = 0;  // 背包中的总价值
//    int currentWeight = 0;  // 当前背包的重量
//
//    // 贪心选择物品
//    for (int i = 0; i < n; i++) {
//        if (currentWeight + items[i].weight <= W) {
//            // 如果放入当前物品不会超过背包容量
//            totalValue += items[i].value;
//            currentWeight += items[i].weight;
//        }
//    }
//
//    // 输出结果
//    printf("背包能装入的最大价值是: %d\n", totalValue);
//
//    // 释放动态分配的内存
//    free(items);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//
//// 比较函数，用于排序顾客服务时间（升序排列）
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int main() {
//    int n;
//    printf("请输入顾客数量: ");
//    scanf("%d", &n);
//
//    int* serviceTimes = (int*)malloc(n * sizeof(int));
//
//    printf("请输入每个顾客的服务时间:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &serviceTimes[i]);
//    }
//
//    // 按照服务时间升序排序
//    qsort(serviceTimes, n, sizeof(int), compare);
//
//    // 计算总的等待时间
//    int totalWaitTime = 0;
//    int currentWaitTime = 0;  // 当前等待时间
//
//    for (int i = 0; i < n; i++) {
//        totalWaitTime += currentWaitTime;  // 加上当前顾客的等待时间
//        currentWaitTime += serviceTimes[i];  // 更新当前等待时间
//    }
//
//    printf("最小总等待时间是: %d\n", totalWaitTime);
//
//    // 释放内存
//    free(serviceTimes);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXN 10000
//
//// 活动结构体
//typedef struct {
//    int start;
//    int end;
//    int id;  // 活动的编号
//} Activity;
//
//// 比较函数，用于按开始时间排序
//int compare(const void* a, const void* b) {
//    Activity* x = (Activity*)a;
//    Activity* y = (Activity*)b;
//    return x->start - y->start;
//}
//
//typedef struct {
//    int time;
//    int room_id;  // 当前教室的编号
//} EndTime;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    Activity activities[MAXN];
//
//    // 输入活动的开始时间和结束时间
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &activities[i].start, &activities[i].end);
//        activities[i].id = i + 1;  // 记录活动的编号
//    }
//
//    // 按开始时间升序排序活动
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // 使用最小堆来管理结束时间
//    EndTime rooms[MAXN];
//    int room_count = 0;  // 当前使用的教室数量
//    int room_assignments[MAXN][MAXN];  // 存储每个教室的活动安排
//    int room_sizes[MAXN] = { 0 };  // 每个教室的活动数目
//
//    // 遍历所有活动，安排最少的教室
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//        int assigned = 0;
//
//        // 查找一个可以容纳当前活动的教室
//        for (int j = 0; j < room_count; j++) {
//            if (rooms[j].time <= start) {
//                // 如果当前教室的结束时间小于或等于当前活动的开始时间
//                rooms[j].time = end;
//                room_assignments[j][room_sizes[j]++] = activities[i].id;  // 安排活动到该教室
//                assigned = 1;
//                break;
//            }
//        }
//
//        // 如果没有找到合适的教室，创建一个新教室
//        if (!assigned) {
//            rooms[room_count].time = end;
//            rooms[room_count].room_id = room_count + 1;
//            room_assignments[room_count][0] = activities[i].id;  // 第一个活动放入新教室
//            room_sizes[room_count] = 1;
//            room_count++;
//        }
//    }
//
//    // 输出最少教室的数量
//    printf("%d\n", room_count);
//
//    // 输出每个教室的活动安排
//    for (int i = 0; i < room_count; i++) {
//        for (int j = 0; j < room_sizes[i]; j++) {
//            if (j > 0) printf(" ");
//            printf("%d", room_assignments[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXN 10000
//
//// 活动结构体
//typedef struct {
//    int start;
//    int end;
//    int id;  // 活动的编号
//} Activity;
//
//// 比较函数，用于按开始时间排序
//int compare(const void* a, const void* b) {
//    Activity* x = (Activity*)a;
//    Activity* y = (Activity*)b;
//    return x->start - y->start;
//}
//
//typedef struct {
//    int time;
//    int room_id;  // 当前教室的编号
//} EndTime;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    Activity* activities = (Activity*)malloc(n * sizeof(Activity));  // 动态分配内存
//
//    // 输入活动的开始时间和结束时间
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &activities[i].start, &activities[i].end);
//        activities[i].id = i + 1;  // 记录活动的编号
//    }
//
//    // 按开始时间升序排序活动
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // 使用最小堆来管理结束时间
//    EndTime* rooms = (EndTime*)malloc(n * sizeof(EndTime));  // 动态分配内存
//    int* room_sizes = (int*)malloc(n * sizeof(int));  // 用来记录每个教室的活动数目
//    int** room_assignments = (int**)malloc(n * sizeof(int*));  // 动态分配内存给每个教室的活动安排
//
//    int room_count = 0;  // 当前使用的教室数量
//
//    // 遍历所有活动，安排最少的教室
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//        int assigned = 0;
//
//        // 查找一个可以容纳当前活动的教室
//        for (int j = 0; j < room_count; j++) {
//            if (rooms[j].time <= start) {
//                // 如果当前教室的结束时间小于或等于当前活动的开始时间
//                rooms[j].time = end;
//                room_assignments[j] = (int*)realloc(room_assignments[j], (room_sizes[j] + 1) * sizeof(int)); // 动态扩展
//                room_assignments[j][room_sizes[j]++] = activities[i].id;  // 安排活动到该教室
//                assigned = 1;
//                break;
//            }
//        }
//
//        // 如果没有找到合适的教室，创建一个新教室
//        if (!assigned) {
//            rooms[room_count].time = end;
//            rooms[room_count].room_id = room_count + 1;
//            room_assignments[room_count] = (int*)malloc(sizeof(int));  // 新建一个教室，分配内存
//            room_assignments[room_count][0] = activities[i].id;  // 第一个活动放入新教室
//            room_sizes[room_count] = 1;
//            room_count++;
//        }
//    }
//
//    // 输出最少教室的数量
//    printf("%d\n", room_count);
//
//    // 输出每个教室的活动安排
//    for (int i = 0; i < room_count; i++) {
//        for (int j = 0; j < room_sizes[i]; j++) {
//            if (j > 0) printf(" ");
//            printf("%d", room_assignments[i][j]);
//        }
//        printf("\n");
//    }
//
//    // 释放动态分配的内存
//    free(activities);
//    free(rooms);
//    free(room_sizes);
//    for (int i = 0; i < room_count; i++) {
//        free(room_assignments[i]);
//    }
//    free(room_assignments);
////
////    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//#define MAXN 150
//
//int n;  // 骑士数量
//bool adj[MAXN][MAXN];  // 邻接矩阵，表示骑士之间是否不和
//
//int seat[MAXN];  // 用于记录每个骑士的座位（颜色）
//
//// 判断当前座位安排是否合法
//bool is_valid(int knight, int position) {
//    // 检查当前骑士与已安排的相邻骑士是否有冲突
//    if (adj[knight][seat[position - 1]] || adj[knight][seat[position + 1]]) {
//        return false;
//    }
//    return true;
//}
//
//// 回溯算法，尝试给每个骑士安排座位
//bool backtrack(int position) {
//    // 如果所有骑士都已安排座位，返回true
//    if (position == n) {
//        return true;
//    }
//
//    // 尝试所有可能的座位
//    for (int i = 1; i <= n; i++) {
//        if (is_valid(position, i)) {
//            seat[position] = i;
//            if (backtrack(position + 1)) {
//                return true;
//            }
//            // 回溯
//            seat[position] = -1;
//        }
//    }
//
//    // 如果所有可能都无法安排座位，返回false
//    return false;
//}
//
//int main() {
//    int m;
//    scanf("%d %d", &n, &m);
//
//    // 初始化邻接矩阵
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        adj[a][b] = adj[b][a] = true;  // 标记a和b之间不和
//    }
//
//    // 初始化座位安排（-1表示尚未安排）
//    for (int i = 0; i < n; i++) {
//        seat[i] = -1;
//    }
//
//    // 回溯算法从第0个位置开始安排
//    if (backtrack(0)) {
//        printf("Solution found: ");
//        for (int i = 0; i < n; i++) {
//            printf("%d ", seat[i]);
//        }
//        printf("\n");
//    }
//    else {
//        printf("No solution\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <limits.h>
//
//#define MAXN 20  // 最大城市数
//#define INF INT_MAX
//
//int n;                        // 城市数
//int cost[MAXN][MAXN];         // 票价矩阵
//int visited[MAXN];            // 访问标记数组
//int bestCost = INF;           // 当前最优解
//int currentCost = 0;          // 当前路径的票价
//int path[MAXN];               // 当前路径
//int bestPath[MAXN];           // 最优路径
//
//// 回溯函数：level 表示当前已访问城市的数量
//void TSP(int level, int city) {
//    if (level == n) { // 所有城市已访问完，回到起点
//        if (cost[city][0] > 0 && currentCost + cost[city][0] < bestCost) {
//            bestCost = currentCost + cost[city][0];
//            for (int i = 0; i < n; i++) bestPath[i] = path[i]; // 保存最优路径
//        }
//        return;
//    }
//
//    // 遍历所有城市
//    for (int nextCity = 0; nextCity < n; nextCity++) {
//        if (!visited[nextCity] && cost[city][nextCity] > 0) {
//            visited[nextCity] = 1; // 标记当前城市已访问
//            currentCost += cost[city][nextCity];
//            path[level] = nextCity; // 记录路径
//
//            // 剪枝：如果当前票价已经超过最优解，则停止继续搜索
//            if (currentCost < bestCost) {
//                TSP(level + 1, nextCity);
//            }
//
//            // 回溯：撤销当前选择
//            visited[nextCity] = 0;
//            currentCost -= cost[city][nextCity];
//        }
//    }
//}
//
//int main() {
//    // 输入城市数
//    printf("请输入城市数量: ");
//    scanf("%d", &n);
//
//    // 输入票价矩阵
//    printf("请输入票价矩阵:\n");
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf("%d", &cost[i][j]);
//        }
//    }
//
//    // 初始化
//    for (int i = 0; i < n; i++) visited[i] = 0;
//
//    // 从城市1（编号0）出发
//    visited[0] = 1;
//    path[0] = 0;
//
//    TSP(1, 0);
//
//    // 输出最优解
//    printf("最小票价为: %d\n", bestCost);
//    printf("最优路径为: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d -> ", bestPath[i] + 1); // 城市编号从1开始
//    }
//    printf("1\n");
//
//    return 0;
//}
//#include <stdio.h>
//
//#define N 6             // 物品个数
//#define W 20            // 背包容量
//
//int weight[N] = { 5, 3, 2, 10, 4, 2 };  // 物品重量
//int value[N] = { 11, 8, 15, 18, 12, 6 }; // 物品价值
//
//int currentWeight = 0;  // 当前背包中的重量
//int currentValue = 0;   // 当前背包中的价值
//int bestValue = 0;      // 最优价值
//
//// 回溯函数
//void knapsack(int i) {
//    if (i == N) {  // 递归边界：所有物品都考虑过
//        if (currentValue > bestValue) {
//            bestValue = currentValue;  // 更新最优解
//        }
//        return;
//    }
//
//    // 选择当前物品：如果加入不会超出背包容量
//    if (currentWeight + weight[i] <= W) {
//        currentWeight += weight[i];  // 更新重量
//        currentValue += value[i];    // 更新价值
//        knapsack(i + 1);             // 递归到下一个物品
//        currentWeight -= weight[i];  // 回溯：恢复重量
//        currentValue -= value[i];    // 回溯：恢复价值
//    }
//
//    // 不选择当前物品
//    knapsack(i + 1);
//}
//
//int main() {
//    knapsack(0);  // 从第0个物品开始回溯
//    printf("背包中能装的最大价值为: %d\n", bestValue);
//    return 0;
//}
//#include <stdio.h>
//
//#define N 4  // 集合元素个数
//
//int X[N] = { 11, 13, 24, 7 };  // 给定集合
//int M = 31;                  // 目标和
//
//int subset[N];  // 记录当前子集
//int sum = 0;    // 当前子集的和
//int found = 0;  // 记录是否找到解
//
//// 回溯函数：i 表示当前考虑的元素
//void subsetSum(int i) {
//    if (sum == M) {  // 如果当前子集的和等于目标和
//        printf("找到满足条件的子集: ");
//        for (int j = 0; j < i; j++) {
//            if (subset[j]) {
//                printf("%d ", X[j]);  // 输出当前子集
//            }
//        }
//        printf("\n");
//        found = 1;
//        return;  // 找到解后返回，不继续递归
//    }
//
//    if (i >= N || sum > M) {  // 递归边界：所有元素考虑完或和超出目标
//        return;
//    }
//
//    // 选择当前元素 X[i]
//    subset[i] = 1;
//    sum += X[i];
//    subsetSum(i + 1);  // 递归到下一个元素
//
//    // 不选择当前元素 X[i]，回溯
//    subset[i] = 0;
//    sum -= X[i];
//    subsetSum(i + 1);
//}
//
//int main() {
//    printf("寻找子集，使得子集的和等于 %d:\n", M);
//    subsetSum(0);
//    if (!found) {
//        printf("没有找到满足条件的子集\n");
//    }
//    return 0;
//}
#include <stdio.h>

#define N 8

// 迷宫：0表示通路，1表示障碍
int maze[N][N] = {
    {0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0}
};

// 用于标记走过的路径
int path[N][N] = { 0 };

// 8个方向：上、下、左、右、左上、右上、左下、右下
int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},   // 上、下、左、右
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  // 左上、右上、左下、右下
};

// 打印路径函数
void printPath() {
    printf("找到一条路径:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    printf("\n按回车键查看下一条路径...\n");
    getch(); // 等待用户按回车继续
}

// 回溯搜索函数：查找所有路径
void solveMazeAllPaths(int x, int y) {
    // 如果到达出口位置，打印当前路径
    if (x == N - 1 && y == N - 1) {
        path[x][y] = 1;  // 标记终点
        printPath();     // 输出当前路径
        path[x][y] = 0;  // 回溯清除终点标记
        return;
    }

    // 尝试当前位置
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && path[x][y] == 0) {
        path[x][y] = 1;  // 标记当前路径

        // 遍历8个方向
        for (int i = 0; i < 8; i++) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];

            // 递归前进
            solveMazeAllPaths(nextX, nextY);
        }

        // 回溯：取消当前位置标记
        path[x][y] = 0;
    }
}

int main() {
    printf("迷宫所有路径求解：\n");
    solveMazeAllPaths(0, 0);
    printf("所有路径已输出完毕！\n");
    return 0;
}