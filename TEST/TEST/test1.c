//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//// ŷ������㷨���������Լ����GCD��
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = a % b;
//        a = b;
//        b = temp;
//    }
//    return a;
//}
//
//// ��ʽ����
//void simplifyFraction(int numerator, int denominator) {
//    if (denominator == 0) {
//        printf("��ĸ����Ϊ��\n");
//        return;
//    }
//    // �������Լ��
//    int gcdValue = gcd(numerator, denominator);
//
//    // ʹ�����Լ���������
//    numerator /= gcdValue;
//    denominator /= gcdValue;
//
//    // ��������ķ���
//    printf("�����ķ�����: %d/%d\n", numerator, denominator);
//}
//
//int main() {
//    int numerator, denominator;
//
//    // ������Ӻͷ�ĸ
//    printf("���������: ");
//    scanf("%d", &numerator);
//    printf("�������ĸ: ");
//    scanf("%d", &denominator);
//
//    // ���û����������
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
//// ��ṹ��
//typedef struct {
//    int start;
//    int end;
//    int index; // �������
//} Activity;
//
//// �ȽϺ�������������������ʼʱ������
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
//// ��С�ѽṹ�壬���ڸ��ٵ�ǰ���ҵĽ���ʱ��
//typedef struct {
//    int endTime;
//    int roomIndex;  // ���ұ��
//} HeapNode;
//
//HeapNode heap[MAXN];
//int heapSize = 0;
//
//// �Ѳ���������Ԫ��
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
//// �Ѳ����������Ѷ�Ԫ��
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
//        activities[i].index = i + 1; // ��¼����
//    }
//
//    // �Ի����ʼʱ������
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // ��С�����ڸ��ٵ�ǰ��Ľ���ʱ��
//    int roomCount = 0;
//    int rooms[MAXN][MAXN];  // ���ڼ�¼ÿ�����ҵĻ����
//    int roomEndTime[MAXN];   // ÿ�����ҵĽ���ʱ��
//
//    // ��������
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//
//        // ����Ƿ��п��еĽ���
//        if (heapSize > 0 && heap[0].endTime <= start) {
//            HeapNode node = popHeap(); // ȡ����������Ľ���
//            int roomIndex = node.roomIndex;
//            roomEndTime[roomIndex] = end;
//            rooms[roomIndex][0]++;
//
//            // ��ֹԽ�磺�����Ӧ <= MAXN
//            if (rooms[roomIndex][0] < MAXN) {
//                rooms[roomIndex][rooms[roomIndex][0]] = activities[i].index;
//            }
//            pushHeap((HeapNode) { end, roomIndex }); // ���½��ҽ���ʱ��
//        }
//        else {
//            // ����Ҳ������ʵĽ��ң�����һ���µĽ���
//            roomEndTime[roomCount] = end;
//            rooms[roomCount][0] = 1;
//            rooms[roomCount][1] = activities[i].index; // ��¼����
//            pushHeap((HeapNode) { end, roomCount });
//            roomCount++;
//        }
//    }
//
//    // ������ٽ�����
//    printf("%d\n", roomCount);
//
//    // ���ÿ�����ҵİ��ŷ���
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
//    // ������ֵ����
//    int denominations[] = { 100, 50, 20, 10, 5, 1 };
//    int n = sizeof(denominations) / sizeof(denominations[0]);
//
//    int count[6] = { 0 }; // ������¼ÿ����ֵ������
//
//    // ����ÿ����ֵ���Ӵ�С��������
//    for (int i = 0; i < n; i++) {
//        // ���㵱ǰ��ֵ�ĸ���
//        count[i] = target / denominations[i];
//        target %= denominations[i]; // ����ʣ����Ҫ����Ľ��
//    }
//
//    // ������㷽��
//    printf("���㷽��:\n");
//    int totalCount = 0;  // ��¼������
//    for (int i = 0; i < n; i++) {
//        if (count[i] > 0) {
//            printf("��ֵ %d: %d ��\n", denominations[i], count[i]);
//            totalCount += count[i];  // �ۼ�������
//        }
//    }
//
//    printf("�ܹ���Ҫ��������: %d\n", totalCount);
//}
//
//int main() {
//    int target;
//    printf("��������Ҫ����Ľ��: ");
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
//#define MAX_V 100 // �������
//#define INF INT_MAX // ��ʾ������޷�����Ľ��
//
//// ��С�ѵĽṹ
//typedef struct {
//    int vertex;  // ���
//    int dist;    // ����
//} MinHeapNode;
//
//typedef struct {
//    int size;
//    int capacity;
//    MinHeapNode* heap;
//} MinHeap;
//
//// ��С�Ѳ�������
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
//        return node; // ��ʾ����Ϊ��
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
//    // �Ӹý�㿪ʼ���ϵ���
//    while (i > 0 && minHeap->heap[i].dist < minHeap->heap[(i - 1) / 2].dist) {
//        swap(&minHeap->heap[i], &minHeap->heap[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//// Dijkstra �㷨��ʵ��
//void dijkstra(int graph[MAX_V][MAX_V], int V, int src) {
//    int dist[MAX_V];  // dist[i] �洢��Դ��� src �� i �����·��
//    int sptSet[MAX_V]; // ���ڱ����ȷ�����·���Ľ��
//
//    MinHeap* minHeap = createMinHeap(V);
//
//    // ��ʼ�����·����������ȶ���
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
//        // ���� u �������ڽӵ�
//        for (int v = 0; v < V; v++) {
//            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
//                dist[v] = dist[u] + graph[u][v];
//                decreaseKey(minHeap, v, dist[v]);
//            }
//        }
//    }
//
//    // ������
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
//    // ����ͼ�Ľ���� V �ͱ��� E
//    printf("Enter number of vertices and edges:\n");
//    scanf("%d %d", &V, &E);
//
//    // ��ʼ��ͼ���ڽӾ���
//    int graph[MAX_V][MAX_V];
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++) {
//            graph[i][j] = INF;
//        }
//    }
//
//    // ����ߵ�Ȩ��
//    printf("Enter edges (start vertex, end vertex, weight):\n");
//    for (int i = 0; i < E; i++) {
//        int u, v, weight;
//        scanf("%d %d %d", &u, &v, &weight);
//        graph[u][v] = weight;
//    }
//
//    // ����Դ���
//    printf("Enter source vertex:\n");
//    scanf("%d", &src);
//
//    // ���� Dijkstra �㷨
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
//// ��С�ѽڵ�ṹ��
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
//// �ϸ�����
//void heapifyUp(int idx) {
//    while (idx > 1 && heap[idx].dist < heap[idx / 2].dist) {
//        swap(&heap[idx], &heap[idx / 2]);
//        idx /= 2;
//    }
//}
//
//// �³�����
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
//// �������
//void push(Node node) {
//    heap[++heapSize] = node;
//    heapifyUp(heapSize);
//}
//
//// ɾ�������ضѶ�Ԫ��
//Node pop() {
//    Node result = heap[1];
//    heap[1] = heap[heapSize--];
//    heapifyDown(1);
//    return result;
//}
//
//// Dijkstra �㷨�������·��
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
//    // ������
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
//    // ��ʼ��ͼ��INF ��ʾû��ֱ�����ӵĳ���
//    int graph[MAXN][MAXN];
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            graph[i][j] = INF;
//        }
//    }
//
//    // ��ȡ��·��Ϣ
//    for (int i = 0; i < m; i++) {
//        int a, b, x;
//        scanf("%d %d %d", &a, &b, &x);
//        graph[a][b] = x;
//        graph[b][a] = x;  // ˫���·
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
//    double ratio;  // ��λ�����ļ�ֵ
//} Item;
//
//// �ȽϺ��������ڰ���λ������ֵ�Ӵ�С����
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
//    // ��̬������Ʒ�����ͱ�������
//    printf("��������Ʒ�����ͱ�������: ");
//    scanf("%d %d", &n, &W);
//
//    // ��̬������Ʒ����
//    Item* items = (Item*)malloc(n * sizeof(Item));
//
//    printf("��������Ʒ�������ͼ�ֵ:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &items[i].weight, &items[i].value);
//        items[i].ratio = (double)items[i].value / items[i].weight;  // ���㵥λ�����ļ�ֵ
//    }
//
//    // ����λ��ֵ�Ӵ�С����
//    qsort(items, n, sizeof(Item), compare);
//
//    int totalValue = 0;  // �����е��ܼ�ֵ
//    int currentWeight = 0;  // ��ǰ����������
//
//    // ̰��ѡ����Ʒ
//    for (int i = 0; i < n; i++) {
//        if (currentWeight + items[i].weight <= W) {
//            // ������뵱ǰ��Ʒ���ᳬ����������
//            totalValue += items[i].value;
//            currentWeight += items[i].weight;
//        }
//    }
//
//    // ������
//    printf("������װ�������ֵ��: %d\n", totalValue);
//
//    // �ͷŶ�̬������ڴ�
//    free(items);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//
//// �ȽϺ�������������˿ͷ���ʱ�䣨�������У�
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int main() {
//    int n;
//    printf("������˿�����: ");
//    scanf("%d", &n);
//
//    int* serviceTimes = (int*)malloc(n * sizeof(int));
//
//    printf("������ÿ���˿͵ķ���ʱ��:\n");
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &serviceTimes[i]);
//    }
//
//    // ���շ���ʱ����������
//    qsort(serviceTimes, n, sizeof(int), compare);
//
//    // �����ܵĵȴ�ʱ��
//    int totalWaitTime = 0;
//    int currentWaitTime = 0;  // ��ǰ�ȴ�ʱ��
//
//    for (int i = 0; i < n; i++) {
//        totalWaitTime += currentWaitTime;  // ���ϵ�ǰ�˿͵ĵȴ�ʱ��
//        currentWaitTime += serviceTimes[i];  // ���µ�ǰ�ȴ�ʱ��
//    }
//
//    printf("��С�ܵȴ�ʱ����: %d\n", totalWaitTime);
//
//    // �ͷ��ڴ�
//    free(serviceTimes);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXN 10000
//
//// ��ṹ��
//typedef struct {
//    int start;
//    int end;
//    int id;  // ��ı��
//} Activity;
//
//// �ȽϺ��������ڰ���ʼʱ������
//int compare(const void* a, const void* b) {
//    Activity* x = (Activity*)a;
//    Activity* y = (Activity*)b;
//    return x->start - y->start;
//}
//
//typedef struct {
//    int time;
//    int room_id;  // ��ǰ���ҵı��
//} EndTime;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    Activity activities[MAXN];
//
//    // �����Ŀ�ʼʱ��ͽ���ʱ��
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &activities[i].start, &activities[i].end);
//        activities[i].id = i + 1;  // ��¼��ı��
//    }
//
//    // ����ʼʱ����������
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // ʹ����С�����������ʱ��
//    EndTime rooms[MAXN];
//    int room_count = 0;  // ��ǰʹ�õĽ�������
//    int room_assignments[MAXN][MAXN];  // �洢ÿ�����ҵĻ����
//    int room_sizes[MAXN] = { 0 };  // ÿ�����ҵĻ��Ŀ
//
//    // �������л���������ٵĽ���
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//        int assigned = 0;
//
//        // ����һ���������ɵ�ǰ��Ľ���
//        for (int j = 0; j < room_count; j++) {
//            if (rooms[j].time <= start) {
//                // �����ǰ���ҵĽ���ʱ��С�ڻ���ڵ�ǰ��Ŀ�ʼʱ��
//                rooms[j].time = end;
//                room_assignments[j][room_sizes[j]++] = activities[i].id;  // ���Ż���ý���
//                assigned = 1;
//                break;
//            }
//        }
//
//        // ���û���ҵ����ʵĽ��ң�����һ���½���
//        if (!assigned) {
//            rooms[room_count].time = end;
//            rooms[room_count].room_id = room_count + 1;
//            room_assignments[room_count][0] = activities[i].id;  // ��һ��������½���
//            room_sizes[room_count] = 1;
//            room_count++;
//        }
//    }
//
//    // ������ٽ��ҵ�����
//    printf("%d\n", room_count);
//
//    // ���ÿ�����ҵĻ����
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
//// ��ṹ��
//typedef struct {
//    int start;
//    int end;
//    int id;  // ��ı��
//} Activity;
//
//// �ȽϺ��������ڰ���ʼʱ������
//int compare(const void* a, const void* b) {
//    Activity* x = (Activity*)a;
//    Activity* y = (Activity*)b;
//    return x->start - y->start;
//}
//
//typedef struct {
//    int time;
//    int room_id;  // ��ǰ���ҵı��
//} EndTime;
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    Activity* activities = (Activity*)malloc(n * sizeof(Activity));  // ��̬�����ڴ�
//
//    // �����Ŀ�ʼʱ��ͽ���ʱ��
//    for (int i = 0; i < n; i++) {
//        scanf("%d %d", &activities[i].start, &activities[i].end);
//        activities[i].id = i + 1;  // ��¼��ı��
//    }
//
//    // ����ʼʱ����������
//    qsort(activities, n, sizeof(Activity), compare);
//
//    // ʹ����С�����������ʱ��
//    EndTime* rooms = (EndTime*)malloc(n * sizeof(EndTime));  // ��̬�����ڴ�
//    int* room_sizes = (int*)malloc(n * sizeof(int));  // ������¼ÿ�����ҵĻ��Ŀ
//    int** room_assignments = (int**)malloc(n * sizeof(int*));  // ��̬�����ڴ��ÿ�����ҵĻ����
//
//    int room_count = 0;  // ��ǰʹ�õĽ�������
//
//    // �������л���������ٵĽ���
//    for (int i = 0; i < n; i++) {
//        int start = activities[i].start;
//        int end = activities[i].end;
//        int assigned = 0;
//
//        // ����һ���������ɵ�ǰ��Ľ���
//        for (int j = 0; j < room_count; j++) {
//            if (rooms[j].time <= start) {
//                // �����ǰ���ҵĽ���ʱ��С�ڻ���ڵ�ǰ��Ŀ�ʼʱ��
//                rooms[j].time = end;
//                room_assignments[j] = (int*)realloc(room_assignments[j], (room_sizes[j] + 1) * sizeof(int)); // ��̬��չ
//                room_assignments[j][room_sizes[j]++] = activities[i].id;  // ���Ż���ý���
//                assigned = 1;
//                break;
//            }
//        }
//
//        // ���û���ҵ����ʵĽ��ң�����һ���½���
//        if (!assigned) {
//            rooms[room_count].time = end;
//            rooms[room_count].room_id = room_count + 1;
//            room_assignments[room_count] = (int*)malloc(sizeof(int));  // �½�һ�����ң������ڴ�
//            room_assignments[room_count][0] = activities[i].id;  // ��һ��������½���
//            room_sizes[room_count] = 1;
//            room_count++;
//        }
//    }
//
//    // ������ٽ��ҵ�����
//    printf("%d\n", room_count);
//
//    // ���ÿ�����ҵĻ����
//    for (int i = 0; i < room_count; i++) {
//        for (int j = 0; j < room_sizes[i]; j++) {
//            if (j > 0) printf(" ");
//            printf("%d", room_assignments[i][j]);
//        }
//        printf("\n");
//    }
//
//    // �ͷŶ�̬������ڴ�
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
//int n;  // ��ʿ����
//bool adj[MAXN][MAXN];  // �ڽӾ��󣬱�ʾ��ʿ֮���Ƿ񲻺�
//
//int seat[MAXN];  // ���ڼ�¼ÿ����ʿ����λ����ɫ��
//
//// �жϵ�ǰ��λ�����Ƿ�Ϸ�
//bool is_valid(int knight, int position) {
//    // ��鵱ǰ��ʿ���Ѱ��ŵ�������ʿ�Ƿ��г�ͻ
//    if (adj[knight][seat[position - 1]] || adj[knight][seat[position + 1]]) {
//        return false;
//    }
//    return true;
//}
//
//// �����㷨�����Ը�ÿ����ʿ������λ
//bool backtrack(int position) {
//    // ���������ʿ���Ѱ�����λ������true
//    if (position == n) {
//        return true;
//    }
//
//    // �������п��ܵ���λ
//    for (int i = 1; i <= n; i++) {
//        if (is_valid(position, i)) {
//            seat[position] = i;
//            if (backtrack(position + 1)) {
//                return true;
//            }
//            // ����
//            seat[position] = -1;
//        }
//    }
//
//    // ������п��ܶ��޷�������λ������false
//    return false;
//}
//
//int main() {
//    int m;
//    scanf("%d %d", &n, &m);
//
//    // ��ʼ���ڽӾ���
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        adj[a][b] = adj[b][a] = true;  // ���a��b֮�䲻��
//    }
//
//    // ��ʼ����λ���ţ�-1��ʾ��δ���ţ�
//    for (int i = 0; i < n; i++) {
//        seat[i] = -1;
//    }
//
//    // �����㷨�ӵ�0��λ�ÿ�ʼ����
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
//#define MAXN 20  // ��������
//#define INF INT_MAX
//
//int n;                        // ������
//int cost[MAXN][MAXN];         // Ʊ�۾���
//int visited[MAXN];            // ���ʱ������
//int bestCost = INF;           // ��ǰ���Ž�
//int currentCost = 0;          // ��ǰ·����Ʊ��
//int path[MAXN];               // ��ǰ·��
//int bestPath[MAXN];           // ����·��
//
//// ���ݺ�����level ��ʾ��ǰ�ѷ��ʳ��е�����
//void TSP(int level, int city) {
//    if (level == n) { // ���г����ѷ����꣬�ص����
//        if (cost[city][0] > 0 && currentCost + cost[city][0] < bestCost) {
//            bestCost = currentCost + cost[city][0];
//            for (int i = 0; i < n; i++) bestPath[i] = path[i]; // ��������·��
//        }
//        return;
//    }
//
//    // �������г���
//    for (int nextCity = 0; nextCity < n; nextCity++) {
//        if (!visited[nextCity] && cost[city][nextCity] > 0) {
//            visited[nextCity] = 1; // ��ǵ�ǰ�����ѷ���
//            currentCost += cost[city][nextCity];
//            path[level] = nextCity; // ��¼·��
//
//            // ��֦�������ǰƱ���Ѿ��������Ž⣬��ֹͣ��������
//            if (currentCost < bestCost) {
//                TSP(level + 1, nextCity);
//            }
//
//            // ���ݣ�������ǰѡ��
//            visited[nextCity] = 0;
//            currentCost -= cost[city][nextCity];
//        }
//    }
//}
//
//int main() {
//    // ���������
//    printf("�������������: ");
//    scanf("%d", &n);
//
//    // ����Ʊ�۾���
//    printf("������Ʊ�۾���:\n");
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            scanf("%d", &cost[i][j]);
//        }
//    }
//
//    // ��ʼ��
//    for (int i = 0; i < n; i++) visited[i] = 0;
//
//    // �ӳ���1�����0������
//    visited[0] = 1;
//    path[0] = 0;
//
//    TSP(1, 0);
//
//    // ������Ž�
//    printf("��СƱ��Ϊ: %d\n", bestCost);
//    printf("����·��Ϊ: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d -> ", bestPath[i] + 1); // ���б�Ŵ�1��ʼ
//    }
//    printf("1\n");
//
//    return 0;
//}
//#include <stdio.h>
//
//#define N 6             // ��Ʒ����
//#define W 20            // ��������
//
//int weight[N] = { 5, 3, 2, 10, 4, 2 };  // ��Ʒ����
//int value[N] = { 11, 8, 15, 18, 12, 6 }; // ��Ʒ��ֵ
//
//int currentWeight = 0;  // ��ǰ�����е�����
//int currentValue = 0;   // ��ǰ�����еļ�ֵ
//int bestValue = 0;      // ���ż�ֵ
//
//// ���ݺ���
//void knapsack(int i) {
//    if (i == N) {  // �ݹ�߽磺������Ʒ�����ǹ�
//        if (currentValue > bestValue) {
//            bestValue = currentValue;  // �������Ž�
//        }
//        return;
//    }
//
//    // ѡ��ǰ��Ʒ��������벻�ᳬ����������
//    if (currentWeight + weight[i] <= W) {
//        currentWeight += weight[i];  // ��������
//        currentValue += value[i];    // ���¼�ֵ
//        knapsack(i + 1);             // �ݹ鵽��һ����Ʒ
//        currentWeight -= weight[i];  // ���ݣ��ָ�����
//        currentValue -= value[i];    // ���ݣ��ָ���ֵ
//    }
//
//    // ��ѡ��ǰ��Ʒ
//    knapsack(i + 1);
//}
//
//int main() {
//    knapsack(0);  // �ӵ�0����Ʒ��ʼ����
//    printf("��������װ������ֵΪ: %d\n", bestValue);
//    return 0;
//}
//#include <stdio.h>
//
//#define N 4  // ����Ԫ�ظ���
//
//int X[N] = { 11, 13, 24, 7 };  // ��������
//int M = 31;                  // Ŀ���
//
//int subset[N];  // ��¼��ǰ�Ӽ�
//int sum = 0;    // ��ǰ�Ӽ��ĺ�
//int found = 0;  // ��¼�Ƿ��ҵ���
//
//// ���ݺ�����i ��ʾ��ǰ���ǵ�Ԫ��
//void subsetSum(int i) {
//    if (sum == M) {  // �����ǰ�Ӽ��ĺ͵���Ŀ���
//        printf("�ҵ������������Ӽ�: ");
//        for (int j = 0; j < i; j++) {
//            if (subset[j]) {
//                printf("%d ", X[j]);  // �����ǰ�Ӽ�
//            }
//        }
//        printf("\n");
//        found = 1;
//        return;  // �ҵ���󷵻أ��������ݹ�
//    }
//
//    if (i >= N || sum > M) {  // �ݹ�߽磺����Ԫ�ؿ������ͳ���Ŀ��
//        return;
//    }
//
//    // ѡ��ǰԪ�� X[i]
//    subset[i] = 1;
//    sum += X[i];
//    subsetSum(i + 1);  // �ݹ鵽��һ��Ԫ��
//
//    // ��ѡ��ǰԪ�� X[i]������
//    subset[i] = 0;
//    sum -= X[i];
//    subsetSum(i + 1);
//}
//
//int main() {
//    printf("Ѱ���Ӽ���ʹ���Ӽ��ĺ͵��� %d:\n", M);
//    subsetSum(0);
//    if (!found) {
//        printf("û���ҵ������������Ӽ�\n");
//    }
//    return 0;
//}
#include <stdio.h>

#define N 8

// �Թ���0��ʾͨ·��1��ʾ�ϰ�
int maze[N][N] = {
    {0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 1, 0}
};

// ���ڱ���߹���·��
int path[N][N] = { 0 };

// 8�������ϡ��¡����ҡ����ϡ����ϡ����¡�����
int directions[8][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},   // �ϡ��¡�����
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  // ���ϡ����ϡ����¡�����
};

// ��ӡ·������
void printPath() {
    printf("�ҵ�һ��·��:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
    printf("\n���س����鿴��һ��·��...\n");
    getch(); // �ȴ��û����س�����
}

// ����������������������·��
void solveMazeAllPaths(int x, int y) {
    // ����������λ�ã���ӡ��ǰ·��
    if (x == N - 1 && y == N - 1) {
        path[x][y] = 1;  // ����յ�
        printPath();     // �����ǰ·��
        path[x][y] = 0;  // ��������յ���
        return;
    }

    // ���Ե�ǰλ��
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && path[x][y] == 0) {
        path[x][y] = 1;  // ��ǵ�ǰ·��

        // ����8������
        for (int i = 0; i < 8; i++) {
            int nextX = x + directions[i][0];
            int nextY = y + directions[i][1];

            // �ݹ�ǰ��
            solveMazeAllPaths(nextX, nextY);
        }

        // ���ݣ�ȡ����ǰλ�ñ��
        path[x][y] = 0;
    }
}

int main() {
    printf("�Թ�����·����⣺\n");
    solveMazeAllPaths(0, 0);
    printf("����·���������ϣ�\n");
    return 0;
}