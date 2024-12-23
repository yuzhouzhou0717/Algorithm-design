#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>  // ���� malloc �� free ��ͷ�ļ�
//
//// --- ����ƥ�䣨BF�㷨�� ---
//int BF(char* text, char* pattern) {
//    int n = strlen(text);      // �ı�������
//    int m = strlen(pattern);   // ģʽ������
//
//    for (int i = 0; i <= n - m; i++) {  // �����ı���
//        int j = 0;
//        while (j < m && text[i + j] == pattern[j]) {
//            j++;
//        }
//        if (j == m) {  // ƥ��ɹ�
//            return i;  // ����ƥ�����ʼλ��
//        }
//    }
//    return -1;  // ���û���ҵ�ƥ��
//}
//
//// --- KMP�㷨 ---
//void computeNext(char* pattern, int* next) {
//    int m = strlen(pattern);
//    next[0] = -1;  // ��һλ��û��ǰ׺
//    int j = 0;
//
//    for (int i = 1; i < m; i++) {
//        while (j >= 0 && pattern[j] != pattern[i]) {
//            j = next[j];
//        }
//        j++;
//        next[i] = j;
//    }
//}
//
//int KMP(char* text, char* pattern) {
//    int n = strlen(text);
//    int m = strlen(pattern);
//
//    if (m == 0) {  // ���ģʽ������Ϊ0��ֱ�ӷ���-1
//        return -1;
//    }
//
//    // ʹ�ö�̬�ڴ�����������СΪ0������
//    int* next = (int*)malloc(sizeof(int) * m);
//    if (next == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    computeNext(pattern, next);  // ����Next����
//
//    int i = 0, j = 0;
//    while (i < n) {
//        if (text[i] == pattern[j]) {
//            i++;
//            j++;
//            if (j == m) {  // �ҵ�ƥ��
//                free(next);  // �ͷ��ڴ�
//                return i - j;
//            }
//        }
//        else {
//            if (j > 0) {
//                j = next[j - 1];  // ����Next������ת
//            }
//            else {
//                i++;
//            }
//        }
//    }
//
//    free(next);  // �ͷ��ڴ�
//    return -1;  // ���û���ҵ�ƥ��
//}
//
//int main() {
//    char text[] = "ababcabccabcacbab";  // �ı���
//    char pattern[] = "abcac";            // ģʽ��
//
//    // ʹ��BF�㷨����ƥ��
//    int positionBF = BF(text, pattern);
//    if (positionBF != -1) {
//        printf("ʹ��BF�㷨��ģʽ�� '%s' ���ı������״γ��ֵ�λ����: %d\n", pattern, positionBF);
//    }
//    else {
//        printf("ʹ��BF�㷨��û���ҵ�ƥ����Ӵ�\n");
//    }
//
//    // ʹ��KMP�㷨����ƥ��
//    int positionKMP = KMP(text, pattern);
//    if (positionKMP != -1) {
//        printf("ʹ��KMP�㷨��ģʽ�� '%s' ���ı������״γ��ֵ�λ����: %d\n", pattern, positionKMP);
//    }
//    else {
//        printf("ʹ��KMP�㷨��û���ҵ�ƥ����Ӵ�\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//void deleteValue(int r[], int* n, int x) {
//    int j = 0;  // j ������¼���������ЧԪ�ظ���
//
//    for (int i = 0; i < *n; i++) {
//        if (r[i] != x) {
//            r[j] = r[i];  // ���� x ��Ԫ���ƶ���ǰ��
//            j++;
//        }
//    }
//
//    // ��������Ĵ�С
//    *n = j;
//}
//
//int main() {
//    int r[] = { 1, 2, 3, 4, 2, 5, 2, 6 };  // ʾ������
//    int n = sizeof(r) / sizeof(r[0]);    // ����ĳ���
//    int x = 2;  // Ҫɾ����Ԫ��ֵ
//
//    printf("ԭʼ���飺");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    // ����ɾ������
//    deleteValue(r, &n, x);
//
//    // ��ӡɾ���������
//    printf("ɾ��ֵΪ %d ������飺", x);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdbool.h>
//
//// ɾ���ظ�Ԫ��
//void removeDuplicates(int r[], int* n) {
//    bool seen[1000] = { false };  // ��������Ԫ��ֵ�ķ�Χ�� [0, 999]��������¼�Ƿ���ֹ�
//    int j = 0;  // ���ڼ�¼���������ЧԪ��λ��
//
//    for (int i = 0; i < *n; i++) {
//        if (!seen[r[i]]) {  // �����ǰԪ��û�г��ֹ�
//            r[j] = r[i];    // ���䱣�浽��λ��
//            seen[r[i]] = true;  // ��Ǹ�Ԫ���ѳ���
//            j++;
//        }
//    }
//
//    *n = j;  // �����������Ч����
//}
//
//int main() {
//    int r[] = { 1, 2, 3, 2, 4, 5, 3, 6, 4 };  // ʾ������
//    int n = sizeof(r) / sizeof(r[0]);    // ����ĳ���
//
//    printf("ԭʼ���飺");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    // ɾ���ظ�Ԫ��
//    removeDuplicates(r, &n);
//
//    // ��ӡɾ���������
//    printf("ɾ���ظ�Ԫ�غ�����飺");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// �ϲ�����������������鲢ͳ�������
//int mergeAndCount(int arr[], int temp[], int left, int right) {
//    if (left >= right) {
//        return 0;
//    }
//
//    int mid = (left + right) / 2;
//    int count = 0;
//
//    // �ݹ��ͳ����ߺ��ұߵ������
//    count += mergeAndCount(arr, temp, left, mid);
//    count += mergeAndCount(arr, temp, mid + 1, right);
//
//    // �ϲ����������鲢ͳ�ƿ�Խ���ֵ������
//    count += merge(arr, temp, left, mid, right);
//
//    return count;
//}
//
//// �ϲ�����������������鲢���������
//int merge(int arr[], int temp[], int left, int mid, int right) {
//    int i = left;    // �����������ʼ����
//    int j = mid + 1; // �����������ʼ����
//    int k = left;    // ��ʱ���������
//    int count = 0;
//
//    // �ϲ�����������
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp[k++] = arr[i++];
//        }
//        else {
//            temp[k++] = arr[j++];
//            count += (mid - i + 1); // �ұߵ�Ԫ�ر���ߵ�Ԫ��С�����������ߵ�����Ԫ���γ������
//        }
//    }
//
//    // ������ߵ�ʣ��Ԫ��
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//
//    // �����ұߵ�ʣ��Ԫ��
//    while (j <= right) {
//        temp[k++] = arr[j++];
//    }
//
//    // ����ʱ�����е����ݸ��ƻ�ԭ����
//    for (i = left; i <= right; i++) {
//        arr[i] = temp[i];
//    }
//
//    return count;
//}
//
//// ���������
//int countInversions(int arr[], int n) {
//    if (n == 0) {
//        return 0;  // �������Ϊ�գ�ֱ�ӷ���0
//    }
//
//    // ��̬������ʱ����
//    int* temp = (int*)malloc(sizeof(int) * n);
//    if (temp == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    int result = mergeAndCount(arr, temp, 0, n - 1);
//    free(temp);  // �ͷ��ڴ�
//    return result;
//}
//
//int main() {
//    int arr[] = { 3, 1, 4, 5, 2 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("ԭʼ����: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int result = countInversions(arr, n);
//    printf("�����е����������Ϊ: %d\n", result);
//
//    return 0;
//}
//#include <stdio.h>
//
//// ���η������Ԫ��
//int findMax(int arr[], int left, int right) {
//    // ��׼�����������ֻ����һ��Ԫ��ʱ�����ظ�Ԫ��
//    if (left == right) {
//        return arr[left];
//    }
//
//    // �����м�����
//    int mid = (left + right) / 2;
//
//    // �ݹ������벿�ֺ��Ұ벿�ֵ����ֵ
//    int maxLeft = findMax(arr, left, mid);
//    int maxRight = findMax(arr, mid + 1, right);
//
//    // �������������нϴ��ֵ
//    return (maxLeft > maxRight) ? maxLeft : maxRight;
//}
//
//int main() {
//    int arr[] = { 3, 1, 4, 5, 2, 7, 6 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // �������е����Ԫ��
//    int maxElement = findMax(arr, 0, n - 1);
//
//    printf("�����е����Ԫ����: %d\n", maxElement);
//    return 0;
//}
//#include <stdio.h>
//
//// ��ת�����д����� left �� right �Ĳ���
//void reverse(int arr[], int left, int right) {
//    while (left < right) {
//        // ����Ԫ��
//        int temp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = temp;
//
//        left++;
//        right--;
//    }
//}
//// ����ѭ������
//void leftRotate(int arr[], int n, int k) {
//    // ��� k >= n, ���� k % n ���������ⲻ��Ҫ����ת
//    k = k % n;
//    reverse(arr, 0, k - 1);
//    reverse(arr, k, n - 1);
//    reverse(arr, 0, n - 1);
//}
//
//int main() {
//    int arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
//    int n = sizeof(arr) / sizeof(arr[0]);  // ����ĳ���
//    int k = 3;  // Ҫѭ�����Ƶ�λ��
//
//    printf("ԭʼ���飺");
//    for (int i = 0; i < n; i++) {
//        printf("%c ", arr[i]);
//    }
//    printf("\n");
//
//    // �������ƺ���
//    leftRotate(arr, n, k);
//
//    // ��ӡ���ƺ������
//    printf("ѭ������ %d λ������飺", k);
//    for (int i = 0; i < n; i++) {
//        printf("%c ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//#include <stdio.h>
//
//// ��������Ԫ�صĺ���
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// ��ӡ���������
//void printArray(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//// �ݹ���������
//void generatePermutations(int arr[], int start, int end) {
//    if (start == end) {  // �ݹ��������������Ԫ�����������
//        printArray(arr, end + 1);  // ��ӡ��ǰ����
//    }
//    else {
//        for (int i = start; i <= end; i++) {
//            // ����Ԫ�أ��̶���startλ�õ�Ԫ��
//            swap(&arr[start], &arr[i]);
//
//            // �ݹ����ɴ�start+1��end������
//            generatePermutations(arr, start + 1, end);
//
//            // ���ݣ��ָ�ԭ����״̬
//            swap(&arr[start], &arr[i]);  } }}
//int main() {
//    int arr[] = { 1, 2, 3 }; 
//    int n = sizeof(arr) / sizeof(arr[0]);  // ����Ĵ�С
//
//    printf("�������У�\n");
//    generatePermutations(arr, 0, n - 1);  // �ӵ�һ��Ԫ�ؿ�ʼ��������
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//
//// �ṹ���ʾ�������
//typedef struct {
//    int x;  // �������
//} Point;
//
//// �ȽϺ�������������
//int compare(const void* a, const void* b) {
//    return ((Point*)a)->x - ((Point*)b)->x;
//}
//
//// ����������֮��ľ���
//double distance(Point p1, Point p2) {
//    return (double)(p1.x - p2.x);
//}
//
//// �����㷨������������
//double closestPair(Point points[], int left, int right) {
//    if (right - left <= 1) {
//        return FLT_MAX;  // ���ֻ��һ���㣬����һ���ǳ������
//    }
//
//    int mid = (left + right) / 2;
//    double leftMin = closestPair(points, left, mid);  // �ݹ�����벿�ֵ���С����
//    double rightMin = closestPair(points, mid, right); // �ݹ����Ұ벿�ֵ���С����
//
//    // �ϲ��׶Σ��ҳ���Խ�м�����С����
//    double minDist = (leftMin < rightMin) ? leftMin : rightMin;  // ��ǰ��С����
//
//    // ����һ����ʱ�������洢���м�������ĵ�
//    Point temp[right - left];
//    int k = 0;
//    for (int i = left; i < right; i++) {
//        if ((points[mid].x - points[i].x) < minDist) {
//            temp[k++] = points[i];
//        }
//    }
//
//    // �����Щ���Ƿ��и�С�ľ���
//    for (int i = 0; i < k; i++) {
//        for (int j = i + 1; j < k && (temp[j].x - temp[i].x) < minDist; j++) {
//            double d = distance(temp[i], temp[j]);
//            if (d < minDist) {
//                minDist = d;
//            }
//        }
//    }
//
//    return minDist;
//}
//
//// ������������㼯�����÷����㷨
//int main() {
//    // ����ʾ��
//    Point points[] = { {1}, {3}, {5}, {9}, {11}, {12}, {14} };
//    int n = sizeof(points) / sizeof(points[0]);
//
//    // �Ե㼯�������������
//    qsort(points, n, sizeof(Point), compare);
//
//    // ���÷����㷨��������
//    double minDist = closestPair(points, 0, n);
//
//    printf("��С����Ϊ: %.6f\n", minDist);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//
//// �ṹ���ʾ�������
//typedef struct {
//    int x;  // �������
//} Point;
//
//// �ȽϺ�������������
//int compare(const void* a, const void* b) {
//    return ((Point*)a)->x - ((Point*)b)->x;
//}
//
//// ����������֮��ľ���
//double distance(Point p1, Point p2) {
//    return (double)(p1.x - p2.x > 0 ? p1.x - p2.x : p2.x - p1.x);  // �������ֵ
//}
//
//// �����㷨������������
//double closestPair(Point* points, int left, int right, Point* temp) {
//    if (right - left <= 1) {
//        return FLT_MAX;  // ���ֻ��һ���㣬����һ���ǳ������
//    }
//
//    int mid = (left + right) / 2;
//    double leftMin = closestPair(points, left, mid, temp);  // �ݹ�����벿�ֵ���С����
//    double rightMin = closestPair(points, mid, right, temp); // �ݹ����Ұ벿�ֵ���С����
//
//    // �ϲ��׶Σ��ҳ���Խ�м�����С����
//    double minDist = (leftMin < rightMin) ? leftMin : rightMin;  // ��ǰ��С����
//
//    // ����һ����ʱ�������洢���м�������ĵ�
//    int k = 0;
//    for (int i = left; i < right; i++) {
//        if ((points[mid].x - points[i].x) < minDist) {
//            temp[k++] = points[i];
//        }
//    }
//
//    // �����Щ���Ƿ��и�С�ľ���
//    for (int i = 0; i < k; i++) {
//        for (int j = i + 1; j < k && (temp[j].x - temp[i].x) < minDist; j++) {
//            double d = distance(temp[i], temp[j]);
//            if (d < minDist) {
//                minDist = d;
//            }
//        }
//    }
//
//    return minDist;
//}
//
//// ������������㼯�����÷����㷨
//int main() {
//    // ����ʾ��
//    int n = 7;
//    Point* points = (Point*)malloc(sizeof(Point) * n);  // ��̬�����ڴ����洢�㼯
//    if (points == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    points[0].x = 1;
//    points[1].x = 3;
//    points[2].x = 5;
//    points[3].x = 9;
//    points[4].x = 11;
//    points[5].x = 12;
//    points[6].x = 14;
//
//    // �Ե㼯�������������
//    qsort(points, n, sizeof(Point), compare);
//
//    // ������ʱ�������洢�㼯�ĸ���
//    Point* temp = (Point*)malloc(sizeof(Point) * n);
//    if (temp == NULL) {
//        free(points);
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    // ���÷����㷨��������
//    double minDist = closestPair(points, 0, n, temp);
//
//    printf("��С����Ϊ: %.6f\n", minDist);
//
//    // �ͷŶ�̬������ڴ�
//    free(points);
//    free(temp);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//// ��ϣ��
//#define MAX_SIZE 10000
//
//// ��ϣ��ṹ��
//typedef struct {
//    int key;    // Ԫ��ֵ
//    int count;  // Ԫ�س��ִ���
//} HashNode;
//
//// ��ϣ��ʵ�֣�����Ԫ�ز����³��ִ���
//void insert(HashNode hashTable[], int key) {
//    int index = abs(key) % MAX_SIZE;
//    while (hashTable[index].count != 0 && hashTable[index].key != key) {
//        index = (index + 1) % MAX_SIZE; // ����̽�ⷨ�����ͻ
//    }
//    hashTable[index].key = key;
//    hashTable[index].count++;
//}
//
//// ���ҳ��ִ�������Ԫ�أ�������
//int findMode(int arr[], int n) {
//    HashNode* hashTable = (HashNode*)malloc(MAX_SIZE * sizeof(HashNode));
//    if (hashTable == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    // ��ʼ����ϣ��
//    for (int i = 0; i < MAX_SIZE; i++) {
//        hashTable[i].count = 0;
//    }
//
//    // ����ÿ��Ԫ�ز����³��ִ���
//    for (int i = 0; i < n; i++) {
//        insert(hashTable, arr[i]);
//    }
//
//    // ���ҳ��ִ�������Ԫ��
//    int mode = arr[0];
//    int maxCount = 0;
//
//    for (int i = 0; i < MAX_SIZE; i++) {
//        if (hashTable[i].count > maxCount) {
//            maxCount = hashTable[i].count;
//            mode = hashTable[i].key;
//        }
//    }
//
//    free(hashTable);
//    return mode;
//}
//
//int main() {
//    int arr[] = { 4, 5, 6, 5, 4, 4, 6, 4, 5 };  
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    int mode = findMode(arr, n);
//    printf("������: %d\n", mode);
//
//    return 0;
//}
//#include <stdio.h>
//
//// �����㷨����Ŀ��ֵ
//int searchInMatrix(int M[][100], int n, int target) {
//    int row = 0;      // �Ӿ���ĵ�һ�п�ʼ
//    int col = n - 1;  // �Ӿ�������һ�п�ʼ
//
//    // �ھ����ڽ��в���
//    while (row < n && col >= 0) {
//        if (M[row][col] == target) {
//            return 1;  // �ҵ�Ŀ��ֵ������1
//        }
//        else if (M[row][col] > target) {
//            col--;  // ��ǰֵ����Ŀ��ֵ���ų���ǰ��
//        }
//        else {
//            row++;  // ��ǰֵС��Ŀ��ֵ���ų���ǰ��
//        }
//    }
//
//    return 0;  // ���ѭ��������˵��û���ҵ�Ŀ��ֵ
//}
//
//int main() {
//    int n = 5;  // ����Ĵ�С
//    int M[5][5] = {
//        {1, 2, 8, 9, 10},
//        {2, 4, 9, 10, 11},
//        {3, 6, 10, 11, 12},
//        {4, 7, 11, 12, 13},
//        {5, 8, 12, 13, 14}
//    };
//
//    int target = 10;
//
//    int result = searchInMatrix(M, n, target);
//    if (result) {
//        printf("Ŀ��ֵ %d �ھ����д��ڡ�\n", target);
//    }
//    else {
//        printf("Ŀ��ֵ %d ���ھ����С�\n", target);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// �ϲ�����������������鲢ͳ�������
//int mergeAndCount(int arr[], int left, int right, int* temp) {
//    if (left >= right) {
//        return 0;
//    }
//
//    int mid = (left + right) / 2;
//    int count = 0;
//
//    // �ݹ��ͳ����ߺ��ұߵ������
//    count += mergeAndCount(arr, left, mid, temp);
//    count += mergeAndCount(arr, mid + 1, right, temp);
//
//    // �ϲ����������鲢ͳ�ƿ�Խ���ֵ������
//    count += merge(arr, left, mid, right, temp);
//
//    return count;
//}
//
//// �ϲ�����������������鲢���������
//int merge(int arr[], int left, int mid, int right, int* temp) {
//    int i = left;    // �����������ʼ����
//    int j = mid + 1; // �����������ʼ����
//    int k = left;    // ��ʱ���������
//    int count = 0;
//
//    // �ϲ�����������
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp[k++] = arr[i++];
//        }
//        else {
//            temp[k++] = arr[j++];
//            count += (mid - i + 1); // �ұߵ�Ԫ�ر���ߵ�Ԫ��С�����������ߵ�����Ԫ���γ������
//        }
//    }
//
//    // ������ߵ�ʣ��Ԫ��
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//
//    // �����ұߵ�ʣ��Ԫ��
//    while (j <= right) {
//        temp[k++] = arr[j++];
//    }
//
//    // ����ʱ�����е����ݸ��ƻ�ԭ����
//    for (i = left; i <= right; i++) {
//        arr[i] = temp[i];
//    }
//
//    return count;
//}
//
//// ���������
//int countInversions(int arr[], int n) {
//    // ��̬������ʱ����
//    int* temp = (int*)malloc(n * sizeof(int));
//    if (temp == NULL) {
//        printf("�ڴ����ʧ��!\n");
//        return -1;
//    }
//
//    // ���õݹ麯�����������
//    int result = mergeAndCount(arr, 0, n - 1, temp);
//
//    // �ͷ���ʱ����
//    free(temp);
//
//    return result;
//}
//
//int main() {
//    int arr[] = { 2, 3, 1 };  //
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("ԭʼ����: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int result = countInversions(arr, n);
//    if (result != -1) {
//        printf("�����е����������Ϊ: %d\n", result);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//int findFirstOccurrence(int A[], int n, int target) {
//    int low = 0, high = n - 1;
//    int result = -1;
//
//    while (low <= high) {
//        int mid = (low + high) / 2;
//
//        // �ҵ�Ŀ��ֵ
//        if (A[mid] == target) {
//            result = mid;  // ��¼Ŀ��ֵλ��
//            high = mid - 1; // ����������ң�Ѱ�ҵ�һ�����ֵ�λ��
//        }
//        else if (A[mid] < target) {
//            low = mid + 1; // Ŀ��ֵ���Ҳ�
//        }
//        else {
//            high = mid - 1; // Ŀ��ֵ�����
//        }
//    }
//
//    return result; // ���û���ҵ���result ���� -1
//}
//
//int main() {
//    int A[] = { 1, 3, 3, 5, 7, 7, 7, 7, 8, 14, 14 };  // ��������
//    int n = sizeof(A) / sizeof(A[0]);  // ���鳤��
//    int target = 7;  // Ŀ��ֵ
//
//    int result = findFirstOccurrence(A, n, target);
//
//    if (result != -1) {
//        printf("Ŀ��ֵ %d �������еĵ�һ��λ����: %d\n", target, result + 1);  // ���ص������Ǵ�0��ʼ�ģ���ĿҪ���1��ʼ
//    }
//    else {
//        printf("Ŀ��ֵ %d ��������û���ҵ�\n", target);
//    }
//
//    return 0;
//}
//BiNode* SearchBSTIterative(BiNode* root, int k) {
//    while (root != NULL) {
//        if (root->data == k) {
//            return root;  // �ҵ�Ŀ��ֵ�����ص�ǰ�ڵ�
//        }
//        else if (k < root->data) {
//            root = root->lchild;  // ����������������
//        }
//        else {
//            root = root->rchild;  // ����������������
//        }
//    }
//    return NULL;  // �������������Ȼû���ҵ������� NULL
//}
//BiNode* FindMin(BiNode* root) {
//    if (root == NULL) return NULL;  // ����û����Сֵ
//
//    // һֱ�����������ߣ�ֱ���ҵ������Ҷ�ӽڵ�
//    while (root->lchild != NULL) {
//        root = root->lchild;
//    }
//
//    return root;  // ��������Ľڵ㣨��Сֵ��
//}
//BiNode* FindMax(BiNode* root) {
//    if (root == NULL) return NULL;  // ����û�����ֵ
//
//    // һֱ�����������ߣ�ֱ���ҵ����ҵ�Ҷ�ӽڵ�
//    while (root->rchild != NULL) {
//        root = root->rchild;
//    }
//
//    return root;  // �������ҵĽڵ㣨���ֵ��
//}
//BiNode* DeleteNode(BiNode* root, int key) {
//    if (root == NULL) return root;  // ������ֱ�ӷ���
//
//    if (key < root->data) {
//        // ������������
//        root->lchild = DeleteNode(root->lchild, key);
//    }
//    else if (key > root->data) {
//        // ������������
//        root->rchild = DeleteNode(root->rchild, key);
//    }
//    else {
//        // �ҵ�Ҫɾ���Ľڵ�
//        if (root->lchild == NULL) {
//            // ���������Ϊ�գ�ֱ�ӽ��������ӵ����ڵ���
//            BiNode* temp = root->rchild;
//            free(root);  // �ͷŵ�ǰ�ڵ�
//            return temp;
//        }
//        else if (root->rchild == NULL) {
//            // ���������Ϊ�գ�ֱ�ӽ��������ӵ����ڵ���
//            BiNode* temp = root->lchild;
//            free(root);
//            return temp;
//        }
//
//        // ����������������ҵ��������е���Сֵ���滻��ǰ�ڵ��ֵ
//        BiNode* temp = FindMin(root->rchild);  // �ҵ��������е���С�ڵ�
//        root->data = temp->data;  // ������������С�ڵ��滻��ǰ�ڵ��ֵ
//        root->rchild = DeleteNode(root->rchild, temp->data);  // ɾ���������е���С�ڵ�
//    }
//    return root;
//}
//#include <stdio.h>
//
//int binarySearch(int arr[], int left, int right, int target) {
//    // ����������������Ϊ�գ����� -1
//    if (left > right) {
//        return -1;  // ����ʧ��
//    }
//
//    // �����м�����
//    int mid = left + (right - left) / 2;
//
//    // ����м�Ԫ�ص���Ŀ��Ԫ�أ�����������
//    if (arr[mid] == target) {
//        return mid;
//    }
//    // ���Ŀ��Ԫ��С���м�Ԫ�أ�����벿�ֲ���
//    else if (arr[mid] > target) {
//        return binarySearch(arr, left, mid - 1, target);
//    }
//    // ���Ŀ��Ԫ�ش����м�Ԫ�أ����Ұ벿�ֲ���
//    else {
//        return binarySearch(arr, mid + 1, right, target);
//    }
//}
//
//int main() {
//    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };  // ����������
//    int n = sizeof(arr) / sizeof(arr[0]);  // ����Ĵ�С
//    int target = 7;  // Ҫ���ҵ�Ŀ��ֵ
//
//    int result = binarySearch(arr, 0, n - 1, target);  // ���õݹ���ֲ���
//
//    if (result != -1) {
//        printf("Ŀ��ֵ %d �������е�λ����: %d\n", target, result);
//    }
//    else {
//        printf("Ŀ��ֵ %d ���������С�\n", target);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//// Ѱ����߽磬����һ�����ڵ���a��λ��
//int findLeftBoundary(int arr[], int left, int right, int a) {
//    int res = -1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] >= a) {
//            res = mid;  // ��¼��ǰλ�ã������������
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return res;
//}
//
//// Ѱ���ұ߽磬�����һ��С�ڵ���b��λ��
//int findRightBoundary(int arr[], int left, int right, int b) {
//    int res = -1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] <= b) {
//            res = mid;  // ��¼��ǰλ�ã��������Ҳ���
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return res;
//}
//
//// ִ�з�Χ����
//void rangeSearch(int arr[], int n, int a, int b) {
//    // ����߽���ұ߽�
//    int leftIndex = findLeftBoundary(arr, 0, n - 1, a);
//    int rightIndex = findRightBoundary(arr, 0, n - 1, b);
//
//    // ����Ƿ��ҵ���Ч��Χ
//    if (leftIndex == -1 || rightIndex == -1 || leftIndex > rightIndex) {
//        printf("û���ҵ��� [%d, %d] ��Χ�ڵ�Ԫ�ء�\n", a, b);
//    }
//    else {
//        // ��ӡ��Χ�ڵ�����Ԫ��
//        printf("�� [%d, %d] ��Χ�ڵ�Ԫ��Ϊ��", a, b);
//        for (int i = leftIndex; i <= rightIndex; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int arr[] = { 1, 3, 3, 5, 7, 7, 7, 7, 8, 14, 14 };  // ����������
//    int n = sizeof(arr) / sizeof(arr[0]);  // �����С
//    int a = 7, b = 7;  // ��Χ [a, b]
//
//    rangeSearch(arr, n, a, b);  // ִ�з�Χ����
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100
//
//// ����ѽṹ
//typedef struct {
//    int data[MAX_SIZE];
//    int size;  // �ѵĴ�С
//} MaxHeap;
//
//// ��������Ԫ��
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// �³����������ִ���ѵ�����
//void heapifyDown(MaxHeap* heap, int index) {
//    int largest = index;
//    int left = 2 * index + 1;
//    int right = 2 * index + 2;
//
//    // �ҳ������ӽڵ�������Ԫ��
//    if (left < heap->size && heap->data[left] > heap->data[largest]) {
//        largest = left;
//    }
//    if (right < heap->size && heap->data[right] > heap->data[largest]) {
//        largest = right;
//    }
//
//    // ����ѵ�Ԫ�ز������������ʣ������������³�
//    if (largest != index) {
//        swap(&heap->data[largest], &heap->data[index]);
//        heapifyDown(heap, largest);
//    }
//}
//
//// �ϸ����������ִ���ѵ�����
//void heapifyUp(MaxHeap* heap, int index) {
//    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
//        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
//        index = (index - 1) / 2;
//    }
//}
//
//// �ڴ������ɾ��ָ��λ�õ�Ԫ��
//void deleteElement(MaxHeap* heap, int index) {
//    if (index < 0 || index >= heap->size) {
//        printf("������Ч\n");
//        return;
//    }
//
//    // ��Ҫɾ����Ԫ����ѵ����һ��Ԫ�ؽ���
//    swap(&heap->data[index], &heap->data[heap->size - 1]);
//    heap->size--;  // ɾ���Ѷ�Ԫ�أ�ԭ��Ҫɾ����Ԫ�أ�
//
//    // �����ѣ�ʹ��ָ����������
//    heapifyDown(heap, index);  // ʹ���³�������
//
//    // ����³�֮��Ѳ����ϴ�������ʣ����Գ����ϸ�������heapify-up��
//    // heapifyUp(heap, index); // Ҳ���Գ���ʹ���ϸ�����
//}
//
//// ����Ԫ�ص�����
//void insert(MaxHeap* heap, int val) {
//    if (heap->size == MAX_SIZE) {
//        printf("���������޷�������Ԫ��\n");
//        return;
//    }
//    heap->data[heap->size] = val;
//    heap->size++;
//    heapifyUp(heap, heap->size - 1);
//}
//
//// ��ӡ��
//void printHeap(MaxHeap* heap) {
//    for (int i = 0; i < heap->size; i++) {
//        printf("%d ", heap->data[i]);
//    }
//    printf("\n");
//}
//int main() {
//    MaxHeap heap = { {30, 20, 15, 10, 8, 5, 3}, 7 };  // ��ʼ��һ����
//    printf("ԭʼ��: ");
//    printHeap(&heap);
//
//    // ɾ�����е�һ��Ԫ��
//    deleteElement(&heap, 2);
//    printf("ɾ��Ԫ�غ��: ");
//    printHeap(&heap);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_N 1000
//
//// ��1���֣�����ݼ������еĳ���
//int longest_decreasing_subsequence(int heights[], int n) {
//    int dp[MAX_N];
//    for (int i = 0; i < n; i++) {
//        dp[i] = 1;  // ��ʼ����ÿ��Ԫ���Լ�����һ������Ϊ1�ĵݼ�������
//    }
//
//    // ��̬�滮������ݼ�������
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (heights[i] < heights[j]) {
//                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
//            }
//        }
//    }
//
//    // �ҵ���ݼ������еĳ���
//    int maxLDS = 0;
//    for (int i = 0; i < n; i++) {
//        if (dp[i] > maxLDS) {
//            maxLDS = dp[i];
//        }
//    }
//
//    return maxLDS;
//}
//
//// ��2���֣�������ϵͳ��
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int min_systems_to_intercept(int heights[], int n) {
//    int systems[MAX_N];  // �����洢ÿ��ϵͳ��ĩβԪ��
//    int systemCount = 0;
//
//    for (int i = 0; i < n; i++) {
//        int left = 0, right = systemCount - 1;
//        // ʹ�ö��ֲ������ҵ����ʵ�ϵͳ
//        while (left <= right) {
//            int mid = (left + right) / 2;
//            if (systems[mid] >= heights[i]) {
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//
//        // ����Ҳ������ʵ�ϵͳ������һ���µ�ϵͳ
//        if (left == systemCount) {
//            systems[systemCount++] = heights[i];
//        }
//        else {
//            systems[left] = heights[i];  // �����滻��ϵͳ��ĩβԪ��
//        }
//    }
//
//    return systemCount;
//}
//
//int main() {
//    int heights[] = { 389, 207, 155, 300, 299, 170, 158, 65 };
//    int n = sizeof(heights) / sizeof(heights[0]);
//
//    // 1. ����������صĵ�����
//    int maxIntercepted = longest_decreasing_subsequence(heights, n);
//    printf("%d\n", maxIntercepted);  // �����������صĵ�����
//
//    // 2. ��������Ҫ���ٸ�ϵͳ
//    int minSystems = min_systems_to_intercept(heights, n);
//    printf("%d\n", minSystems);  // ���������Ҫ��ϵͳ��
//
//    return 0;
////}
//#include <stdio.h>
//
//#define MAX_N 6  // ��Ʒ����
//#define MAX_CAPACITY 6  // ��������
//
//// 0/1�������⶯̬�滮�ⷨ
//int knapsack(int weight[], int value[], int n, int capacity) {
//    int dp[n + 1][capacity + 1];  // dp[i][j]��ʾǰi����Ʒ������Ϊjʱ������ֵ
//
//    // ��ʼ��dp���飬dp[0][j] = 0��ʾû����Ʒʱ������ֵΪ0
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= capacity; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // ��̬�滮���
//    for (int i = 1; i <= n; i++) {  // ������Ʒ
//        for (int j = 0; j <= capacity; j++) {  // ��������
//            if (j >= weight[i - 1]) {  // �����ǰ�������ڻ���ڵ�ǰ��Ʒ������
//                dp[i][j] = (dp[i - 1][j] > dp[i - 1][j - weight[i - 1]] + value[i - 1])
//                    ? dp[i - 1][j]
//                    : dp[i - 1][j - weight[i - 1]] + value[i - 1];
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];  // �����뵱ǰ��Ʒ
//            }
//        }
//    }
//
//    // ��������ֵ
//    return dp[n][capacity];
//}
//
//int main() {
//    int weight[] = { 3, 2, 1, 4, 5 };  // ��Ʒ������
//    int value[] = { 25, 20, 15, 40, 50 };  // ��Ʒ�ļ�ֵ
//    int n = 5;  // ��Ʒ����
//    int capacity = 6;  // ��������
//
//    // ���0/1������������Ž�
//    int maxValue = knapsack(weight, value, n, capacity);
//    printf("����ֵΪ: %d\n", maxValue);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_CAPACITY 6  // ��������
//#define MAX_N 5  // ��Ʒ����
//
//// 0/1�������⶯̬�滮�ⷨ��ʹ�ö�̬���飩
//int knapsack(int weight[], int value[], int n, int capacity) {
//    // ��̬���� dp�����ڴ洢��ǰ���������µ�����ֵ
//    int* dp = (int*)malloc((capacity + 1) * sizeof(int));
//
//    // ��ʼ�� dp ���飬dp[j] ��ʾ����Ϊ j ʱ������ֵ
//    for (int j = 0; j <= capacity; j++) {
//        dp[j] = 0;
//    }
//
//    // ��̬�滮���
//    for (int i = 0; i < n; i++) {  // ������Ʒ
//        for (int j = capacity; j >= weight[i]; j--) {  // �Ӵ�С��������
//            dp[j] = (dp[j] > dp[j - weight[i]] + value[i]) ? dp[j] : dp[j - weight[i]] + value[i];
//        }
//    }
//
//    // ����ֵ���� dp[capacity]
//    int maxValue = dp[capacity];
//
//    // �ͷŶ�̬����
//    free(dp);
//
//    return maxValue;
//}
//
//int main() {
//    int weight[] = { 3, 2, 1, 4, 5 };  // ��Ʒ������
//    int value[] = { 25, 20, 15, 40, 50 };  // ��Ʒ�ļ�ֵ
//    int n = 5;  // ��Ʒ����
//    int capacity = 6;  // ��������
//
//    // ���0/1������������Ž�
//    int maxValue = knapsack(weight, value, n, capacity);
//    printf("����ֵΪ: %d\n", maxValue);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// ��̬�滮��������������еĳ���
//int LCS(char* A, char* B) {
//    int m = strlen(A);  // �ַ���A�ĳ���
//    int n = strlen(B);  // �ַ���B�ĳ���
//
//    // ������ά��̬���� dp��dp[i][j] ��ʾ A[0..i-1] �� B[0..j-1] ������������г���
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // ��ʼ�� dp ���飬dp[i][0] �� dp[0][j] ����0����Ϊ��һ���ַ���Ϊ��ʱ��LCS����Ϊ0
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // ��̬�滮���
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (A[i - 1] == B[j - 1]) {  // �����ǰ�ַ���ͬ
//                dp[i][j] = dp[i - 1][j - 1] + 1;  // LCS��������1
//            }
//            else {
//                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // ����ȡ�ϴ�ֵ
//            }
//        }
//    }
//
//    // �ͷŶ�̬������ڴ�
//    int result = dp[m][n];
//
//    // �ͷŶ�ά�����ڴ�
//    for (int i = 0; i <= m; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    // ��������������еĳ���
//    return result;
//}
//
//// �����ӡ������������е��ַ���
//void printLCS(char* A, char* B) {
//    int m = strlen(A);
//    int n = strlen(B);
//
//    // ������ά��̬���� dp �洢�м���
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // ��ʼ�� dp ����
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // ��̬�滮���
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (A[i - 1] == B[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            }
//            else {
//                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
//            }
//        }
//    }
//
//    // �� dp[m][n] �����һ������������
//    int index = dp[m][n];
//    char* lcs = (char*)malloc((index + 1) * sizeof(char));  // +1 ��Ϊ�˼����ַ�����β�� '\0'
//    lcs[index] = '\0';  // �������ַ���������
//
//    int i = m, j = n;
//    while (i > 0 && j > 0) {
//        if (A[i - 1] == B[j - 1]) {
//            lcs[index - 1] = A[i - 1];
//            i--;
//            j--;
//            index--;
//        }
//        else if (dp[i - 1][j] > dp[i][j - 1]) {
//            i--;
//        }
//        else {
//            j--;
//        }
//    }
//
//    // ��������������
//    printf("�����������: %s\n", lcs);
//
//    // �ͷŶ�̬������ڴ�
//    free(lcs);
//    for (int i = 0; i <= m; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//}
//
//int main() {
//    char A[] = "xzyzzyz";
//    char B[] = "zxyyzxz";
//
//    // ���㲢�������������еĳ���
//    int lcsLength = LCS(A, B);
//    printf("����������еĳ���: %d\n", lcsLength);
//
//    // ��������������
//    printLCS(A, B);
//
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define INF 999999  // һ���ܴ��������ʾ�༭����
//
//// ��̬�滮�����K-����ƥ��
//int KApproximateMatch(char* pattern, char* text, int k) {
//    int m = strlen(pattern);  // ģʽ�ĳ���
//    int n = strlen(text);     // �ı��ĳ���
//
//    // ����һ����ά���� dp��dp[i][j] ��ʾģʽǰ i ���ַ����ı�ǰ j ���ַ��ı༭����
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // ��ʼ�� dp ����
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            if (i == 0) {
//                dp[i][j] = j;  // ģʽΪ�գ��ı����� j ��
//            }
//            else if (j == 0) {
//                dp[i][j] = i;  // �ı�Ϊ�գ�ģʽɾ�� i ��
//            }
//            else {
//                dp[i][j] = INF;  // ��ʼ��Ϊһ���ܴ����
//            }
//        }
//    }
//
//    // ��̬�滮��� dp ����
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (pattern[i - 1] == text[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];  // ����ַ���ͬ������Ҫ����
//            }
//            else {
//                // �滻�����롢ɾ������Сֵ
//                dp[i][j] = (dp[i - 1][j - 1] < dp[i][j - 1]) ? dp[i - 1][j - 1] : dp[i][j - 1];
//                dp[i][j] = (dp[i][j] < dp[i - 1][j]) ? dp[i][j] : dp[i - 1][j];
//                dp[i][j] += 1;
//            }
//        }
//    }
//
//    // ����жϣ���� dp[m][n] <= k��������ҵ�ƥ��
//    int result = dp[m][n];
//
//    // �ͷŶ�̬������ڴ�
//    for (int i = 0; i <= m; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result <= k;  // ����༭���벻���� k������ 1����ʾƥ��ɹ��������򷵻� 0
//}
//
//int main() {
//    char pattern[] = "grammer";
//    char text[] = "grameer";
//    int k = 2;  // ������� 2 �α༭
//
//    // ���� K-����ƥ���㷨
//    if (KApproximateMatch(pattern, text, k)) {
//        printf("�ı���ģʽƥ�䣬�༭���� <= %d\n", k);
//    }
//    else {
//        printf("�ı���ģʽƥ��ʧ�ܣ��༭���� > %d\n", k);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// ����һ���ṹ���ʾ���ڵ�
//typedef struct TreeNode {
//    int key;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//// ����� i �� j ��Ȩ�غ�
//int sum(int* freq, int i, int j) {
//    int total = 0;
//    for (int k = i; k <= j; k++) {
//        total += freq[k];
//    }
//    return total;
//}
//
//// �������Ŷ��������
//TreeNode* buildOptimalBST(int** R, int* keys, int* freq, int i, int j) {
//    // ���������i > j ʱ���� NULL
//    if (i > j) return NULL;
//
//    // ȡ�� R[i][j] �ĸ��ڵ�
//    int r = R[i][j];
//
//    // ������ǰ���ڵ�
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//    root->key = keys[r];
//    root->left = buildOptimalBST(R, keys, freq, i, r - 1);  // �ݹ鹹��������
//    root->right = buildOptimalBST(R, keys, freq, r + 1, j); // �ݹ鹹��������
//
//    return root;
//}
//
//// ��ӡ�����������
//void inorder(TreeNode* root) {
//    if (root != NULL) {
//        inorder(root->left);
//        printf("%d ", root->key);
//        inorder(root->right);
//    }
//}
//
//// ���Ŷ����������̬�滮�㷨
//void optimalBST(int* keys, int* freq, int n) {
//    int** C = (int**)malloc((n + 1) * sizeof(int*));
//    int** R = (int**)malloc((n + 1) * sizeof(int*));
//
//    // ��ʼ�� C �� R ��
//    for (int i = 0; i <= n; i++) {
//        C[i] = (int*)malloc((n + 1) * sizeof(int));
//        R[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // base case: C[i][i] Ϊ�ýڵ��Ƶ��
//    for (int i = 0; i < n; i++) {
//        C[i][i] = freq[i];
//        R[i][i] = i;
//    }
//
//    // ������� C �� R ��
//    for (int length = 2; length <= n; length++) {
//        for (int i = 0; i <= n - length; i++) {
//            int j = i + length - 1;
//            C[i][j] = INT_MAX;
//            int totalFreq = sum(freq, i, j);
//
//            // ���� C[i][j] ����Сֵ
//            for (int r = i; r <= j; r++) {
//                int cost = (r > i ? C[i][r - 1] : 0) + (r < j ? C[r + 1][j] : 0) + totalFreq;
//                if (cost < C[i][j]) {
//                    C[i][j] = cost;
//                    R[i][j] = r;
//                }
//            }
//        }
//    }
//
//    // ��ӡ���Ŷ��������
//    TreeNode* root = buildOptimalBST(R, keys, freq, 0, n - 1);
//    printf("Inorder traversal of the optimal BST: ");
//    inorder(root);
//    printf("\n");
//
//    // �ͷ��ڴ�
//    for (int i = 0; i <= n; i++) {
//        free(C[i]);
//        free(R[i]);
//    }
//    free(C);
//    free(R);
//}
//
//int main() {
//    int keys[] = { 10, 12, 20 };  // ��
//    int freq[] = { 34, 8, 50 };   // ��Ӧ��Ƶ��
//    int n = sizeof(keys) / sizeof(keys[0]);
//
//    optimalBST(keys, freq, n);
//
//    return 0;
////}
//#include <stdio.h>
//#include <limits.h>
//
//#define MAX_Y 10000  // ���Ŀ����
//#define MAX_N 100    // ��������������
//
//// ��̬�滮������ٻ�������
//int minCoins(int coins[], int n, int y) {
//    int dp[MAX_Y + 1];
//
//    // ��ʼ�� dp ����
//    for (int i = 0; i <= y; i++) {
//        dp[i] = INT_MAX;  // ���ó�ʼֵΪһ���ܴ��ֵ
//    }
//    dp[0] = 0;  // ֧�� 0 Ԫʱ��������Ϊ 0
//
//    // ��̬�滮��� dp ����
//    for (int i = 1; i <= y; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i >= coins[j]) {
//                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : (dp[i - coins[j]] + 1);
//            }
//        }
//    }
//
//    return dp[y] == INT_MAX ? -1 : dp[y];  // ���û�н⣬���� -1
//}
//
//int main() {
//    int coins[] = { 1, 3, 4 };  // ������ֵ
//    int n = 3;  // ����������
//    int y = 6;  // Ŀ����
//
//    int result = minCoins(coins, n, y);
//    if (result != -1) {
//        printf("���ٵĻ�������Ϊ: %d\n", result);
//    }
//    else {
//        printf("�޷�֧���ý��\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//// ���������
//#define ADD 1
//#define MUL 2
//
//// ��̬����ʵ�ֵ����÷ּ��㺯��
//int maxScore(int* values, int n, int** ops) {
//    // ��̬�����ά dp ����
//    int** dp = (int**)malloc(n * sizeof(int*));
//    for (int i = 0; i < n; i++) {
//        dp[i] = (int*)malloc(n * sizeof(int));
//    }
//
//    // ��ʼ�� dp ���飬��������ĵ÷־��Ƕ���ֵ
//    for (int i = 0; i < n; i++) {
//        dp[i][i] = values[i];
//    }
//
//    // ��� dp ���飬��������������
//    for (int len = 2; len <= n; len++) {  // len���Ӷ���εĳ���
//        for (int i = 0; i <= n - len; i++) {
//            int j = i + len - 1;
//            dp[i][j] = INT_MIN;  // ��ʼ��Ϊ��Сֵ
//            // �������п��ܵ��м䶥�� k
//            for (int k = i; k < j; k++) {
//                int temp;
//                if (ops[k][k + 1] == ADD) {
//                    temp = dp[i][k] + dp[k + 1][j];
//                }
//                else { // ops[k][k+1] == MUL
//                    temp = dp[i][k] * dp[k + 1][j];
//                }
//                // ���� dp[i][j]
//                dp[i][j] = (dp[i][j] > temp) ? dp[i][j] : temp;
//            }
//        }
//    }
//
//    // ��ȡ���յ÷ֲ��ͷ� dp �����ڴ�
//    int result = dp[0][n - 1];
//
//    // �ͷŶ�̬������ڴ�
//    for (int i = 0; i < n; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result;
//}
//
//int main() {
//    int n = 5;  // ������
//    int values[] = { 1, 2, 3, 4, 5 };  // �����ֵ
//
//    // ��̬���� ops ���飬�洢ÿ���ߵ������
//    int** ops = (int**)malloc(n * sizeof(int*));
//    for (int i = 0; i < n; i++) {
//        ops[i] = (int*)malloc(n * sizeof(int));
//    }
//
//    // ���� ops ���飬ÿ���ߵ��������ADDΪ�ӷ���MULΪ�˷�
//    ops[0][1] = ADD;
//    ops[1][2] = MUL;
//    ops[2][3] = ADD;
//    ops[3][4] = MUL;
//    ops[0][2] = MUL;
//    ops[1][3] = ADD;
//    ops[2][4] = ADD;
//
//    // ������ߵ÷�
//    int result = maxScore(values, n, ops);
//    printf("��ߵ÷���: %d\n", result);
//
//    // �ͷ� ops �����ڴ�
//    for (int i = 0; i < n; i++) {
//        free(ops[i]);
//    }
//    free(ops);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 5000
//
//// ���鼯�ĸ��ڵ�����
//int parent[MAX];
//
//// ��ʼ�����鼯
//void init() {
//    for (int i = 0; i < MAX; i++) {
//        parent[i] = i;  // ��ʼÿ���˶����Լ��ĸ��ڵ�
//    }
//}
//
//// ���Ҳ�����·��ѹ���Ż�
//int find(int x) {
//    if (parent[x] != x) {
//        parent[x] = find(parent[x]);  // ·��ѹ��
//    }
//    return parent[x];
//}
//
//// �ϲ����������Ⱥϲ��Ż�
//void union_sets(int x, int y) {
//    int rootX = find(x);
//    int rootY = find(y);
//
//    if (rootX != rootY) {
//        parent[rootX] = rootY;  // ��x�ĸ��ڵ�ָ��y�ĸ��ڵ�
//    }
//}
//
//int main() {
//    int n, m, p;
//
//    // ���� n, m, p
//    scanf("%d %d %d", &n, &m, &p);
//
//    // ��ʼ�����鼯
//    init();
//
//    // ����m�����ݹ�ϵ
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        union_sets(a, b);  // ��a��b�ϲ���ͬһ��������
//    }
//
//    // ����p����ѯ
//    for (int i = 0; i < p; i++) {
//        int Pi, Pj;
//        scanf("%d %d", &Pi, &Pj);
//
//        // ���Pi��Pj��ͬһ�������У������YES���������NO
//        if (find(Pi) == find(Pj)) {
//            printf("YES\n");
//        }
//        else {
//            printf("NO\n");
//        }
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//#define MAX_V 500
//
//// �ڽӾ����ʾͼ
//int graph[MAX_V][MAX_V];
//
//int main() {
//    int V, E, K, N;
//
//    // ���붥����V, ����E, ��ɫ��K
//    scanf("%d %d %d", &V, &E, &K);
//
//    // ��ʼ���ڽӾ���
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++) {
//            graph[i][j] = 0;
//        }
//    }
//
//    // ����E����
//    for (int i = 0; i < E; i++) {
//        int u, v;
//        scanf("%d %d", &u, &v);
//        // ע������Ķ����Ǵ�1��ʼ�ģ���Ҫ����Ϊ��0��ʼ
//        u--; v--;
//        graph[u][v] = 1;
//        graph[v][u] = 1;  // ����ͼ
//    }
//
//    // �����������ɫ���䷽���ĸ���N
//    scanf("%d", &N);
//
//    // ��ÿ����ɫ���䷽�����м��
//    for (int i = 0; i < N; i++) {
//        int colors[MAX_V];
//
//        // ����ÿ���������ɫ
//        for (int j = 0; j < V; j++) {
//            scanf("%d", &colors[j]);
//        }
//
//        // ��鷽���Ƿ�����ͼ��ɫ������
//        int valid = 1;
//        for (int u = 0; u < V; u++) {
//            for (int v = u + 1; v < V; v++) {
//                if (graph[u][v] == 1 && colors[u] == colors[v]) {
//                    valid = 0;
//                    break;
//                }
//            }
//            if (!valid) break;
//        }
//
//        // ������
//        if (valid) {
//            printf("Yes\n");
//        }
//        else {
//            printf("No\n");
//        }
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
