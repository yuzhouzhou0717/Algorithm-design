#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>  // 引入 malloc 和 free 的头文件
//
//// --- 暴力匹配（BF算法） ---
//int BF(char* text, char* pattern) {
//    int n = strlen(text);      // 文本串长度
//    int m = strlen(pattern);   // 模式串长度
//
//    for (int i = 0; i <= n - m; i++) {  // 遍历文本串
//        int j = 0;
//        while (j < m && text[i + j] == pattern[j]) {
//            j++;
//        }
//        if (j == m) {  // 匹配成功
//            return i;  // 返回匹配的起始位置
//        }
//    }
//    return -1;  // 如果没有找到匹配
//}
//
//// --- KMP算法 ---
//void computeNext(char* pattern, int* next) {
//    int m = strlen(pattern);
//    next[0] = -1;  // 第一位置没有前缀
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
//    if (m == 0) {  // 如果模式串长度为0，直接返回-1
//        return -1;
//    }
//
//    // 使用动态内存分配来避免大小为0的数组
//    int* next = (int*)malloc(sizeof(int) * m);
//    if (next == NULL) {
//        printf("内存分配失败!\n");
//        return -1;
//    }
//
//    computeNext(pattern, next);  // 计算Next数组
//
//    int i = 0, j = 0;
//    while (i < n) {
//        if (text[i] == pattern[j]) {
//            i++;
//            j++;
//            if (j == m) {  // 找到匹配
//                free(next);  // 释放内存
//                return i - j;
//            }
//        }
//        else {
//            if (j > 0) {
//                j = next[j - 1];  // 根据Next数组跳转
//            }
//            else {
//                i++;
//            }
//        }
//    }
//
//    free(next);  // 释放内存
//    return -1;  // 如果没有找到匹配
//}
//
//int main() {
//    char text[] = "ababcabccabcacbab";  // 文本串
//    char pattern[] = "abcac";            // 模式串
//
//    // 使用BF算法进行匹配
//    int positionBF = BF(text, pattern);
//    if (positionBF != -1) {
//        printf("使用BF算法：模式串 '%s' 在文本串中首次出现的位置是: %d\n", pattern, positionBF);
//    }
//    else {
//        printf("使用BF算法：没有找到匹配的子串\n");
//    }
//
//    // 使用KMP算法进行匹配
//    int positionKMP = KMP(text, pattern);
//    if (positionKMP != -1) {
//        printf("使用KMP算法：模式串 '%s' 在文本串中首次出现的位置是: %d\n", pattern, positionKMP);
//    }
//    else {
//        printf("使用KMP算法：没有找到匹配的子串\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//void deleteValue(int r[], int* n, int x) {
//    int j = 0;  // j 用来记录新数组的有效元素个数
//
//    for (int i = 0; i < *n; i++) {
//        if (r[i] != x) {
//            r[j] = r[i];  // 将非 x 的元素移动到前面
//            j++;
//        }
//    }
//
//    // 更新数组的大小
//    *n = j;
//}
//
//int main() {
//    int r[] = { 1, 2, 3, 4, 2, 5, 2, 6 };  // 示例数组
//    int n = sizeof(r) / sizeof(r[0]);    // 数组的长度
//    int x = 2;  // 要删除的元素值
//
//    printf("原始数组：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    // 调用删除函数
//    deleteValue(r, &n, x);
//
//    // 打印删除后的数组
//    printf("删除值为 %d 后的数组：", x);
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
//// 删除重复元素
//void removeDuplicates(int r[], int* n) {
//    bool seen[1000] = { false };  // 假设数组元素值的范围是 [0, 999]，用来记录是否出现过
//    int j = 0;  // 用于记录新数组的有效元素位置
//
//    for (int i = 0; i < *n; i++) {
//        if (!seen[r[i]]) {  // 如果当前元素没有出现过
//            r[j] = r[i];    // 将其保存到新位置
//            seen[r[i]] = true;  // 标记该元素已出现
//            j++;
//        }
//    }
//
//    *n = j;  // 更新数组的有效长度
//}
//
//int main() {
//    int r[] = { 1, 2, 3, 2, 4, 5, 3, 6, 4 };  // 示例数组
//    int n = sizeof(r) / sizeof(r[0]);    // 数组的长度
//
//    printf("原始数组：");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", r[i]);
//    }
//    printf("\n");
//
//    // 删除重复元素
//    removeDuplicates(r, &n);
//
//    // 打印删除后的数组
//    printf("删除重复元素后的数组：");
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
//// 合并两个已排序的子数组并统计逆序对
//int mergeAndCount(int arr[], int temp[], int left, int right) {
//    if (left >= right) {
//        return 0;
//    }
//
//    int mid = (left + right) / 2;
//    int count = 0;
//
//    // 递归地统计左边和右边的逆序对
//    count += mergeAndCount(arr, temp, left, mid);
//    count += mergeAndCount(arr, temp, mid + 1, right);
//
//    // 合并两个子数组并统计跨越部分的逆序对
//    count += merge(arr, temp, left, mid, right);
//
//    return count;
//}
//
//// 合并两个已排序的子数组并计算逆序对
//int merge(int arr[], int temp[], int left, int mid, int right) {
//    int i = left;    // 左子数组的起始索引
//    int j = mid + 1; // 右子数组的起始索引
//    int k = left;    // 临时数组的索引
//    int count = 0;
//
//    // 合并两个子数组
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp[k++] = arr[i++];
//        }
//        else {
//            temp[k++] = arr[j++];
//            count += (mid - i + 1); // 右边的元素比左边的元素小，因此它与左边的所有元素形成逆序对
//        }
//    }
//
//    // 复制左边的剩余元素
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//
//    // 复制右边的剩余元素
//    while (j <= right) {
//        temp[k++] = arr[j++];
//    }
//
//    // 将临时数组中的数据复制回原数组
//    for (i = left; i <= right; i++) {
//        arr[i] = temp[i];
//    }
//
//    return count;
//}
//
//// 计算逆序对
//int countInversions(int arr[], int n) {
//    if (n == 0) {
//        return 0;  // 如果数组为空，直接返回0
//    }
//
//    // 动态分配临时数组
//    int* temp = (int*)malloc(sizeof(int) * n);
//    if (temp == NULL) {
//        printf("内存分配失败!\n");
//        return -1;
//    }
//
//    int result = mergeAndCount(arr, temp, 0, n - 1);
//    free(temp);  // 释放内存
//    return result;
//}
//
//int main() {
//    int arr[] = { 3, 1, 4, 5, 2 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("原始数组: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int result = countInversions(arr, n);
//    printf("数组中的逆序对数量为: %d\n", result);
//
//    return 0;
//}
//#include <stdio.h>
//
//// 分治法求最大元素
//int findMax(int arr[], int left, int right) {
//    // 基准情况：当数组只包含一个元素时，返回该元素
//    if (left == right) {
//        return arr[left];
//    }
//
//    // 计算中间索引
//    int mid = (left + right) / 2;
//
//    // 递归求解左半部分和右半部分的最大值
//    int maxLeft = findMax(arr, left, mid);
//    int maxRight = findMax(arr, mid + 1, right);
//
//    // 返回两个部分中较大的值
//    return (maxLeft > maxRight) ? maxLeft : maxRight;
//}
//
//int main() {
//    int arr[] = { 3, 1, 4, 5, 2, 7, 6 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    // 求数组中的最大元素
//    int maxElement = findMax(arr, 0, n - 1);
//
//    printf("数组中的最大元素是: %d\n", maxElement);
//    return 0;
//}
//#include <stdio.h>
//
//// 反转数组中从索引 left 到 right 的部分
//void reverse(int arr[], int left, int right) {
//    while (left < right) {
//        // 交换元素
//        int temp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = temp;
//
//        left++;
//        right--;
//    }
//}
//// 进行循环左移
//void leftRotate(int arr[], int n, int k) {
//    // 如果 k >= n, 进行 k % n 操作来避免不必要的旋转
//    k = k % n;
//    reverse(arr, 0, k - 1);
//    reverse(arr, k, n - 1);
//    reverse(arr, 0, n - 1);
//}
//
//int main() {
//    int arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
//    int n = sizeof(arr) / sizeof(arr[0]);  // 数组的长度
//    int k = 3;  // 要循环左移的位数
//
//    printf("原始数组：");
//    for (int i = 0; i < n; i++) {
//        printf("%c ", arr[i]);
//    }
//    printf("\n");
//
//    // 调用左移函数
//    leftRotate(arr, n, k);
//
//    // 打印左移后的数组
//    printf("循环左移 %d 位后的数组：", k);
//    for (int i = 0; i < n; i++) {
//        printf("%c ", arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//#include <stdio.h>
//
//// 交换两个元素的函数
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 打印数组的排列
//void printArray(int arr[], int n) {
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//// 递归生成排列
//void generatePermutations(int arr[], int start, int end) {
//    if (start == end) {  // 递归结束条件：所有元素已排列完成
//        printArray(arr, end + 1);  // 打印当前排列
//    }
//    else {
//        for (int i = start; i <= end; i++) {
//            // 交换元素，固定第start位置的元素
//            swap(&arr[start], &arr[i]);
//
//            // 递归生成从start+1到end的排列
//            generatePermutations(arr, start + 1, end);
//
//            // 回溯，恢复原数组状态
//            swap(&arr[start], &arr[i]);  } }}
//int main() {
//    int arr[] = { 1, 2, 3 }; 
//    int n = sizeof(arr) / sizeof(arr[0]);  // 数组的大小
//
//    printf("所有排列：\n");
//    generatePermutations(arr, 0, n - 1);  // 从第一个元素开始生成排列
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//
//// 结构体表示点的坐标
//typedef struct {
//    int x;  // 点的坐标
//} Point;
//
//// 比较函数，用于排序
//int compare(const void* a, const void* b) {
//    return ((Point*)a)->x - ((Point*)b)->x;
//}
//
//// 计算两个点之间的距离
//double distance(Point p1, Point p2) {
//    return (double)(p1.x - p2.x);
//}
//
//// 分治算法解决最近对问题
//double closestPair(Point points[], int left, int right) {
//    if (right - left <= 1) {
//        return FLT_MAX;  // 如果只有一个点，返回一个非常大的数
//    }
//
//    int mid = (left + right) / 2;
//    double leftMin = closestPair(points, left, mid);  // 递归求左半部分的最小距离
//    double rightMin = closestPair(points, mid, right); // 递归求右半部分的最小距离
//
//    // 合并阶段：找出跨越中间点的最小距离
//    double minDist = (leftMin < rightMin) ? leftMin : rightMin;  // 当前最小距离
//
//    // 创建一个临时数组来存储与中间线相近的点
//    Point temp[right - left];
//    int k = 0;
//    for (int i = left; i < right; i++) {
//        if ((points[mid].x - points[i].x) < minDist) {
//            temp[k++] = points[i];
//        }
//    }
//
//    // 检查这些点是否有更小的距离
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
//// 主函数，输入点集并调用分治算法
//int main() {
//    // 输入示例
//    Point points[] = { {1}, {3}, {5}, {9}, {11}, {12}, {14} };
//    int n = sizeof(points) / sizeof(points[0]);
//
//    // 对点集按坐标进行排序
//    qsort(points, n, sizeof(Point), compare);
//
//    // 调用分治算法求解最近对
//    double minDist = closestPair(points, 0, n);
//
//    printf("最小距离为: %.6f\n", minDist);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <float.h>
//
//// 结构体表示点的坐标
//typedef struct {
//    int x;  // 点的坐标
//} Point;
//
//// 比较函数，用于排序
//int compare(const void* a, const void* b) {
//    return ((Point*)a)->x - ((Point*)b)->x;
//}
//
//// 计算两个点之间的距离
//double distance(Point p1, Point p2) {
//    return (double)(p1.x - p2.x > 0 ? p1.x - p2.x : p2.x - p1.x);  // 计算绝对值
//}
//
//// 分治算法解决最近对问题
//double closestPair(Point* points, int left, int right, Point* temp) {
//    if (right - left <= 1) {
//        return FLT_MAX;  // 如果只有一个点，返回一个非常大的数
//    }
//
//    int mid = (left + right) / 2;
//    double leftMin = closestPair(points, left, mid, temp);  // 递归求左半部分的最小距离
//    double rightMin = closestPair(points, mid, right, temp); // 递归求右半部分的最小距离
//
//    // 合并阶段：找出跨越中间点的最小距离
//    double minDist = (leftMin < rightMin) ? leftMin : rightMin;  // 当前最小距离
//
//    // 创建一个临时数组来存储与中间线相近的点
//    int k = 0;
//    for (int i = left; i < right; i++) {
//        if ((points[mid].x - points[i].x) < minDist) {
//            temp[k++] = points[i];
//        }
//    }
//
//    // 检查这些点是否有更小的距离
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
//// 主函数，输入点集并调用分治算法
//int main() {
//    // 输入示例
//    int n = 7;
//    Point* points = (Point*)malloc(sizeof(Point) * n);  // 动态分配内存来存储点集
//    if (points == NULL) {
//        printf("内存分配失败!\n");
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
//    // 对点集按坐标进行排序
//    qsort(points, n, sizeof(Point), compare);
//
//    // 创建临时数组来存储点集的副本
//    Point* temp = (Point*)malloc(sizeof(Point) * n);
//    if (temp == NULL) {
//        free(points);
//        printf("内存分配失败!\n");
//        return -1;
//    }
//
//    // 调用分治算法求解最近对
//    double minDist = closestPair(points, 0, n, temp);
//
//    printf("最小距离为: %.6f\n", minDist);
//
//    // 释放动态分配的内存
//    free(points);
//    free(temp);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//// 哈希表
//#define MAX_SIZE 10000
//
//// 哈希表结构体
//typedef struct {
//    int key;    // 元素值
//    int count;  // 元素出现次数
//} HashNode;
//
//// 哈希表实现：插入元素并更新出现次数
//void insert(HashNode hashTable[], int key) {
//    int index = abs(key) % MAX_SIZE;
//    while (hashTable[index].count != 0 && hashTable[index].key != key) {
//        index = (index + 1) % MAX_SIZE; // 线性探测法解决冲突
//    }
//    hashTable[index].key = key;
//    hashTable[index].count++;
//}
//
//// 查找出现次数最多的元素（众数）
//int findMode(int arr[], int n) {
//    HashNode* hashTable = (HashNode*)malloc(MAX_SIZE * sizeof(HashNode));
//    if (hashTable == NULL) {
//        printf("内存分配失败!\n");
//        return -1;
//    }
//
//    // 初始化哈希表
//    for (int i = 0; i < MAX_SIZE; i++) {
//        hashTable[i].count = 0;
//    }
//
//    // 插入每个元素并更新出现次数
//    for (int i = 0; i < n; i++) {
//        insert(hashTable, arr[i]);
//    }
//
//    // 查找出现次数最多的元素
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
//    printf("众数是: %d\n", mode);
//
//    return 0;
//}
//#include <stdio.h>
//
//// 分治算法查找目标值
//int searchInMatrix(int M[][100], int n, int target) {
//    int row = 0;      // 从矩阵的第一行开始
//    int col = n - 1;  // 从矩阵的最后一列开始
//
//    // 在矩阵内进行查找
//    while (row < n && col >= 0) {
//        if (M[row][col] == target) {
//            return 1;  // 找到目标值，返回1
//        }
//        else if (M[row][col] > target) {
//            col--;  // 当前值大于目标值，排除当前列
//        }
//        else {
//            row++;  // 当前值小于目标值，排除当前行
//        }
//    }
//
//    return 0;  // 如果循环结束，说明没有找到目标值
//}
//
//int main() {
//    int n = 5;  // 矩阵的大小
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
//        printf("目标值 %d 在矩阵中存在。\n", target);
//    }
//    else {
//        printf("目标值 %d 不在矩阵中。\n", target);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// 合并两个已排序的子数组并统计逆序对
//int mergeAndCount(int arr[], int left, int right, int* temp) {
//    if (left >= right) {
//        return 0;
//    }
//
//    int mid = (left + right) / 2;
//    int count = 0;
//
//    // 递归地统计左边和右边的逆序对
//    count += mergeAndCount(arr, left, mid, temp);
//    count += mergeAndCount(arr, mid + 1, right, temp);
//
//    // 合并两个子数组并统计跨越部分的逆序对
//    count += merge(arr, left, mid, right, temp);
//
//    return count;
//}
//
//// 合并两个已排序的子数组并计算逆序对
//int merge(int arr[], int left, int mid, int right, int* temp) {
//    int i = left;    // 左子数组的起始索引
//    int j = mid + 1; // 右子数组的起始索引
//    int k = left;    // 临时数组的索引
//    int count = 0;
//
//    // 合并两个子数组
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp[k++] = arr[i++];
//        }
//        else {
//            temp[k++] = arr[j++];
//            count += (mid - i + 1); // 右边的元素比左边的元素小，因此它与左边的所有元素形成逆序对
//        }
//    }
//
//    // 复制左边的剩余元素
//    while (i <= mid) {
//        temp[k++] = arr[i++];
//    }
//
//    // 复制右边的剩余元素
//    while (j <= right) {
//        temp[k++] = arr[j++];
//    }
//
//    // 将临时数组中的数据复制回原数组
//    for (i = left; i <= right; i++) {
//        arr[i] = temp[i];
//    }
//
//    return count;
//}
//
//// 计算逆序对
//int countInversions(int arr[], int n) {
//    // 动态分配临时数组
//    int* temp = (int*)malloc(n * sizeof(int));
//    if (temp == NULL) {
//        printf("内存分配失败!\n");
//        return -1;
//    }
//
//    // 调用递归函数计算逆序对
//    int result = mergeAndCount(arr, 0, n - 1, temp);
//
//    // 释放临时数组
//    free(temp);
//
//    return result;
//}
//
//int main() {
//    int arr[] = { 2, 3, 1 };  //
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("原始数组: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//
//    int result = countInversions(arr, n);
//    if (result != -1) {
//        printf("数组中的逆序对数量为: %d\n", result);
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
//        // 找到目标值
//        if (A[mid] == target) {
//            result = mid;  // 记录目标值位置
//            high = mid - 1; // 向左继续查找，寻找第一个出现的位置
//        }
//        else if (A[mid] < target) {
//            low = mid + 1; // 目标值在右侧
//        }
//        else {
//            high = mid - 1; // 目标值在左侧
//        }
//    }
//
//    return result; // 如果没有找到，result 会是 -1
//}
//
//int main() {
//    int A[] = { 1, 3, 3, 5, 7, 7, 7, 7, 8, 14, 14 };  // 输入数组
//    int n = sizeof(A) / sizeof(A[0]);  // 数组长度
//    int target = 7;  // 目标值
//
//    int result = findFirstOccurrence(A, n, target);
//
//    if (result != -1) {
//        printf("目标值 %d 在数组中的第一个位置是: %d\n", target, result + 1);  // 返回的索引是从0开始的，题目要求从1开始
//    }
//    else {
//        printf("目标值 %d 在数组中没有找到\n", target);
//    }
//
//    return 0;
//}
//BiNode* SearchBSTIterative(BiNode* root, int k) {
//    while (root != NULL) {
//        if (root->data == k) {
//            return root;  // 找到目标值，返回当前节点
//        }
//        else if (k < root->data) {
//            root = root->lchild;  // 继续在左子树查找
//        }
//        else {
//            root = root->rchild;  // 继续在右子树查找
//        }
//    }
//    return NULL;  // 如果查找完树仍然没有找到，返回 NULL
//}
//BiNode* FindMin(BiNode* root) {
//    if (root == NULL) return NULL;  // 空树没有最小值
//
//    // 一直沿着左子树走，直到找到最左的叶子节点
//    while (root->lchild != NULL) {
//        root = root->lchild;
//    }
//
//    return root;  // 返回最左的节点（最小值）
//}
//BiNode* FindMax(BiNode* root) {
//    if (root == NULL) return NULL;  // 空树没有最大值
//
//    // 一直沿着右子树走，直到找到最右的叶子节点
//    while (root->rchild != NULL) {
//        root = root->rchild;
//    }
//
//    return root;  // 返回最右的节点（最大值）
//}
//BiNode* DeleteNode(BiNode* root, int key) {
//    if (root == NULL) return root;  // 空树，直接返回
//
//    if (key < root->data) {
//        // 在左子树查找
//        root->lchild = DeleteNode(root->lchild, key);
//    }
//    else if (key > root->data) {
//        // 在右子树查找
//        root->rchild = DeleteNode(root->rchild, key);
//    }
//    else {
//        // 找到要删除的节点
//        if (root->lchild == NULL) {
//            // 如果左子树为空，直接将右子树接到父节点上
//            BiNode* temp = root->rchild;
//            free(root);  // 释放当前节点
//            return temp;
//        }
//        else if (root->rchild == NULL) {
//            // 如果右子树为空，直接将左子树接到父节点上
//            BiNode* temp = root->lchild;
//            free(root);
//            return temp;
//        }
//
//        // 如果有两个子树，找到右子树中的最小值，替换当前节点的值
//        BiNode* temp = FindMin(root->rchild);  // 找到右子树中的最小节点
//        root->data = temp->data;  // 用右子树的最小节点替换当前节点的值
//        root->rchild = DeleteNode(root->rchild, temp->data);  // 删除右子树中的最小节点
//    }
//    return root;
//}
//#include <stdio.h>
//
//int binarySearch(int arr[], int left, int right, int target) {
//    // 基本情况：如果数组为空，返回 -1
//    if (left > right) {
//        return -1;  // 查找失败
//    }
//
//    // 计算中间索引
//    int mid = left + (right - left) / 2;
//
//    // 如果中间元素等于目标元素，返回其索引
//    if (arr[mid] == target) {
//        return mid;
//    }
//    // 如果目标元素小于中间元素，在左半部分查找
//    else if (arr[mid] > target) {
//        return binarySearch(arr, left, mid - 1, target);
//    }
//    // 如果目标元素大于中间元素，在右半部分查找
//    else {
//        return binarySearch(arr, mid + 1, right, target);
//    }
//}
//
//int main() {
//    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };  // 已排序数组
//    int n = sizeof(arr) / sizeof(arr[0]);  // 数组的大小
//    int target = 7;  // 要查找的目标值
//
//    int result = binarySearch(arr, 0, n - 1, target);  // 调用递归二分查找
//
//    if (result != -1) {
//        printf("目标值 %d 在数组中的位置是: %d\n", target, result);
//    }
//    else {
//        printf("目标值 %d 不在数组中。\n", target);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//
//// 寻找左边界，即第一个大于等于a的位置
//int findLeftBoundary(int arr[], int left, int right, int a) {
//    int res = -1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] >= a) {
//            res = mid;  // 记录当前位置，继续向左查找
//            right = mid - 1;
//        }
//        else {
//            left = mid + 1;
//        }
//    }
//    return res;
//}
//
//// 寻找右边界，即最后一个小于等于b的位置
//int findRightBoundary(int arr[], int left, int right, int b) {
//    int res = -1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] <= b) {
//            res = mid;  // 记录当前位置，继续向右查找
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return res;
//}
//
//// 执行范围查找
//void rangeSearch(int arr[], int n, int a, int b) {
//    // 找左边界和右边界
//    int leftIndex = findLeftBoundary(arr, 0, n - 1, a);
//    int rightIndex = findRightBoundary(arr, 0, n - 1, b);
//
//    // 检查是否找到有效范围
//    if (leftIndex == -1 || rightIndex == -1 || leftIndex > rightIndex) {
//        printf("没有找到在 [%d, %d] 范围内的元素。\n", a, b);
//    }
//    else {
//        // 打印范围内的所有元素
//        printf("在 [%d, %d] 范围内的元素为：", a, b);
//        for (int i = leftIndex; i <= rightIndex; i++) {
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
//    }
//}
//
//int main() {
//    int arr[] = { 1, 3, 3, 5, 7, 7, 7, 7, 8, 14, 14 };  // 已排序数组
//    int n = sizeof(arr) / sizeof(arr[0]);  // 数组大小
//    int a = 7, b = 7;  // 范围 [a, b]
//
//    rangeSearch(arr, n, a, b);  // 执行范围查找
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_SIZE 100
//
//// 大根堆结构
//typedef struct {
//    int data[MAX_SIZE];
//    int size;  // 堆的大小
//} MaxHeap;
//
//// 交换两个元素
//void swap(int* a, int* b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 下沉操作，保持大根堆的性质
//void heapifyDown(MaxHeap* heap, int index) {
//    int largest = index;
//    int left = 2 * index + 1;
//    int right = 2 * index + 2;
//
//    // 找出左右子节点中最大的元素
//    if (left < heap->size && heap->data[left] > heap->data[largest]) {
//        largest = left;
//    }
//    if (right < heap->size && heap->data[right] > heap->data[largest]) {
//        largest = right;
//    }
//
//    // 如果堆的元素不满足大根堆性质，交换并继续下沉
//    if (largest != index) {
//        swap(&heap->data[largest], &heap->data[index]);
//        heapifyDown(heap, largest);
//    }
//}
//
//// 上浮操作，保持大根堆的性质
//void heapifyUp(MaxHeap* heap, int index) {
//    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
//        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
//        index = (index - 1) / 2;
//    }
//}
//
//// 在大根堆中删除指定位置的元素
//void deleteElement(MaxHeap* heap, int index) {
//    if (index < 0 || index >= heap->size) {
//        printf("索引无效\n");
//        return;
//    }
//
//    // 将要删除的元素与堆的最后一个元素交换
//    swap(&heap->data[index], &heap->data[heap->size - 1]);
//    heap->size--;  // 删除堆顶元素（原来要删除的元素）
//
//    // 调整堆，使其恢复大根堆性质
//    heapifyDown(heap, index);  // 使用下沉调整堆
//
//    // 如果下沉之后堆不符合大根堆性质，可以尝试上浮操作（heapify-up）
//    // heapifyUp(heap, index); // 也可以尝试使用上浮调整
//}
//
//// 插入元素到堆中
//void insert(MaxHeap* heap, int val) {
//    if (heap->size == MAX_SIZE) {
//        printf("堆已满，无法插入新元素\n");
//        return;
//    }
//    heap->data[heap->size] = val;
//    heap->size++;
//    heapifyUp(heap, heap->size - 1);
//}
//
//// 打印堆
//void printHeap(MaxHeap* heap) {
//    for (int i = 0; i < heap->size; i++) {
//        printf("%d ", heap->data[i]);
//    }
//    printf("\n");
//}
//int main() {
//    MaxHeap heap = { {30, 20, 15, 10, 8, 5, 3}, 7 };  // 初始化一个堆
//    printf("原始堆: ");
//    printHeap(&heap);
//
//    // 删除堆中的一个元素
//    deleteElement(&heap, 2);
//    printf("删除元素后堆: ");
//    printHeap(&heap);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_N 1000
//
//// 第1部分：求最长递减子序列的长度
//int longest_decreasing_subsequence(int heights[], int n) {
//    int dp[MAX_N];
//    for (int i = 0; i < n; i++) {
//        dp[i] = 1;  // 初始化，每个元素自己构成一个长度为1的递减子序列
//    }
//
//    // 动态规划计算最长递减子序列
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (heights[i] < heights[j]) {
//                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
//            }
//        }
//    }
//
//    // 找到最长递减子序列的长度
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
//// 第2部分：求最少系统数
//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int min_systems_to_intercept(int heights[], int n) {
//    int systems[MAX_N];  // 用来存储每个系统的末尾元素
//    int systemCount = 0;
//
//    for (int i = 0; i < n; i++) {
//        int left = 0, right = systemCount - 1;
//        // 使用二分查找来找到合适的系统
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
//        // 如果找不到合适的系统，增加一个新的系统
//        if (left == systemCount) {
//            systems[systemCount++] = heights[i];
//        }
//        else {
//            systems[left] = heights[i];  // 否则替换该系统的末尾元素
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
//    // 1. 求最多能拦截的导弹数
//    int maxIntercepted = longest_decreasing_subsequence(heights, n);
//    printf("%d\n", maxIntercepted);  // 输出最多能拦截的导弹数
//
//    // 2. 求最少需要多少个系统
//    int minSystems = min_systems_to_intercept(heights, n);
//    printf("%d\n", minSystems);  // 输出最少需要的系统数
//
//    return 0;
////}
//#include <stdio.h>
//
//#define MAX_N 6  // 物品数量
//#define MAX_CAPACITY 6  // 背包容量
//
//// 0/1背包问题动态规划解法
//int knapsack(int weight[], int value[], int n, int capacity) {
//    int dp[n + 1][capacity + 1];  // dp[i][j]表示前i个物品，容量为j时的最大价值
//
//    // 初始化dp数组，dp[0][j] = 0表示没有物品时的最大价值为0
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= capacity; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // 动态规划填表
//    for (int i = 1; i <= n; i++) {  // 遍历物品
//        for (int j = 0; j <= capacity; j++) {  // 遍历容量
//            if (j >= weight[i - 1]) {  // 如果当前容量大于或等于当前物品的重量
//                dp[i][j] = (dp[i - 1][j] > dp[i - 1][j - weight[i - 1]] + value[i - 1])
//                    ? dp[i - 1][j]
//                    : dp[i - 1][j - weight[i - 1]] + value[i - 1];
//            }
//            else {
//                dp[i][j] = dp[i - 1][j];  // 不放入当前物品
//            }
//        }
//    }
//
//    // 返回最大价值
//    return dp[n][capacity];
//}
//
//int main() {
//    int weight[] = { 3, 2, 1, 4, 5 };  // 物品的重量
//    int value[] = { 25, 20, 15, 40, 50 };  // 物品的价值
//    int n = 5;  // 物品数量
//    int capacity = 6;  // 背包容量
//
//    // 求解0/1背包问题的最优解
//    int maxValue = knapsack(weight, value, n, capacity);
//    printf("最大价值为: %d\n", maxValue);
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_CAPACITY 6  // 背包容量
//#define MAX_N 5  // 物品数量
//
//// 0/1背包问题动态规划解法（使用动态数组）
//int knapsack(int weight[], int value[], int n, int capacity) {
//    // 动态数组 dp，用于存储当前背包容量下的最大价值
//    int* dp = (int*)malloc((capacity + 1) * sizeof(int));
//
//    // 初始化 dp 数组，dp[j] 表示容量为 j 时的最大价值
//    for (int j = 0; j <= capacity; j++) {
//        dp[j] = 0;
//    }
//
//    // 动态规划填表
//    for (int i = 0; i < n; i++) {  // 遍历物品
//        for (int j = capacity; j >= weight[i]; j--) {  // 从大到小遍历容量
//            dp[j] = (dp[j] > dp[j - weight[i]] + value[i]) ? dp[j] : dp[j - weight[i]] + value[i];
//        }
//    }
//
//    // 最大价值就是 dp[capacity]
//    int maxValue = dp[capacity];
//
//    // 释放动态数组
//    free(dp);
//
//    return maxValue;
//}
//
//int main() {
//    int weight[] = { 3, 2, 1, 4, 5 };  // 物品的重量
//    int value[] = { 25, 20, 15, 40, 50 };  // 物品的价值
//    int n = 5;  // 物品数量
//    int capacity = 6;  // 背包容量
//
//    // 求解0/1背包问题的最优解
//    int maxValue = knapsack(weight, value, n, capacity);
//    printf("最大价值为: %d\n", maxValue);
//
//    return 0;
////}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 动态规划计算最长公共子序列的长度
//int LCS(char* A, char* B) {
//    int m = strlen(A);  // 字符串A的长度
//    int n = strlen(B);  // 字符串B的长度
//
//    // 创建二维动态数组 dp，dp[i][j] 表示 A[0..i-1] 和 B[0..j-1] 的最长公共子序列长度
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // 初始化 dp 数组，dp[i][0] 和 dp[0][j] 都是0，因为当一个字符串为空时，LCS长度为0
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // 动态规划填表
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (A[i - 1] == B[j - 1]) {  // 如果当前字符相同
//                dp[i][j] = dp[i - 1][j - 1] + 1;  // LCS长度增加1
//            }
//            else {
//                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];  // 否则取较大值
//            }
//        }
//    }
//
//    // 释放动态分配的内存
//    int result = dp[m][n];
//
//    // 释放二维数组内存
//    for (int i = 0; i <= m; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    // 返回最长公共子序列的长度
//    return result;
//}
//
//// 反向打印出最长公共子序列的字符串
//void printLCS(char* A, char* B) {
//    int m = strlen(A);
//    int n = strlen(B);
//
//    // 创建二维动态数组 dp 存储中间结果
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // 初始化 dp 数组
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            dp[i][j] = 0;
//        }
//    }
//
//    // 动态规划填表
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
//    // 从 dp[m][n] 反向找回最长公共子序列
//    int index = dp[m][n];
//    char* lcs = (char*)malloc((index + 1) * sizeof(char));  // +1 是为了加上字符串结尾的 '\0'
//    lcs[index] = '\0';  // 最后加上字符串结束符
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
//    // 输出最长公共子序列
//    printf("最长公共子序列: %s\n", lcs);
//
//    // 释放动态分配的内存
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
//    // 计算并输出最长公共子序列的长度
//    int lcsLength = LCS(A, B);
//    printf("最长公共子序列的长度: %d\n", lcsLength);
//
//    // 输出最长公共子序列
//    printLCS(A, B);
//
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define INF 999999  // 一个很大的数，表示编辑距离
//
//// 动态规划法求解K-近似匹配
//int KApproximateMatch(char* pattern, char* text, int k) {
//    int m = strlen(pattern);  // 模式的长度
//    int n = strlen(text);     // 文本的长度
//
//    // 创建一个二维数组 dp，dp[i][j] 表示模式前 i 个字符与文本前 j 个字符的编辑距离
//    int** dp = (int**)malloc((m + 1) * sizeof(int*));
//    for (int i = 0; i <= m; i++) {
//        dp[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // 初始化 dp 数组
//    for (int i = 0; i <= m; i++) {
//        for (int j = 0; j <= n; j++) {
//            if (i == 0) {
//                dp[i][j] = j;  // 模式为空，文本插入 j 次
//            }
//            else if (j == 0) {
//                dp[i][j] = i;  // 文本为空，模式删除 i 次
//            }
//            else {
//                dp[i][j] = INF;  // 初始化为一个很大的数
//            }
//        }
//    }
//
//    // 动态规划填充 dp 数组
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (pattern[i - 1] == text[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];  // 如果字符相同，不需要操作
//            }
//            else {
//                // 替换、插入、删除的最小值
//                dp[i][j] = (dp[i - 1][j - 1] < dp[i][j - 1]) ? dp[i - 1][j - 1] : dp[i][j - 1];
//                dp[i][j] = (dp[i][j] < dp[i - 1][j]) ? dp[i][j] : dp[i - 1][j];
//                dp[i][j] += 1;
//            }
//        }
//    }
//
//    // 结果判断：如果 dp[m][n] <= k，则可以找到匹配
//    int result = dp[m][n];
//
//    // 释放动态分配的内存
//    for (int i = 0; i <= m; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result <= k;  // 如果编辑距离不超过 k，返回 1（表示匹配成功），否则返回 0
//}
//
//int main() {
//    char pattern[] = "grammer";
//    char text[] = "grameer";
//    int k = 2;  // 允许最多 2 次编辑
//
//    // 调用 K-近似匹配算法
//    if (KApproximateMatch(pattern, text, k)) {
//        printf("文本与模式匹配，编辑距离 <= %d\n", k);
//    }
//    else {
//        printf("文本与模式匹配失败，编辑距离 > %d\n", k);
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义一个结构体表示树节点
//typedef struct TreeNode {
//    int key;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//
//// 计算从 i 到 j 的权重和
//int sum(int* freq, int i, int j) {
//    int total = 0;
//    for (int k = i; k <= j; k++) {
//        total += freq[k];
//    }
//    return total;
//}
//
//// 构建最优二叉查找树
//TreeNode* buildOptimalBST(int** R, int* keys, int* freq, int i, int j) {
//    // 基本情况：i > j 时返回 NULL
//    if (i > j) return NULL;
//
//    // 取出 R[i][j] 的根节点
//    int r = R[i][j];
//
//    // 创建当前根节点
//    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
//    root->key = keys[r];
//    root->left = buildOptimalBST(R, keys, freq, i, r - 1);  // 递归构建左子树
//    root->right = buildOptimalBST(R, keys, freq, r + 1, j); // 递归构建右子树
//
//    return root;
//}
//
//// 打印树的中序遍历
//void inorder(TreeNode* root) {
//    if (root != NULL) {
//        inorder(root->left);
//        printf("%d ", root->key);
//        inorder(root->right);
//    }
//}
//
//// 最优二叉查找树动态规划算法
//void optimalBST(int* keys, int* freq, int n) {
//    int** C = (int**)malloc((n + 1) * sizeof(int*));
//    int** R = (int**)malloc((n + 1) * sizeof(int*));
//
//    // 初始化 C 和 R 表
//    for (int i = 0; i <= n; i++) {
//        C[i] = (int*)malloc((n + 1) * sizeof(int));
//        R[i] = (int*)malloc((n + 1) * sizeof(int));
//    }
//
//    // base case: C[i][i] 为该节点的频率
//    for (int i = 0; i < n; i++) {
//        C[i][i] = freq[i];
//        R[i][i] = i;
//    }
//
//    // 递推填充 C 和 R 表
//    for (int length = 2; length <= n; length++) {
//        for (int i = 0; i <= n - length; i++) {
//            int j = i + length - 1;
//            C[i][j] = INT_MAX;
//            int totalFreq = sum(freq, i, j);
//
//            // 计算 C[i][j] 的最小值
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
//    // 打印最优二叉查找树
//    TreeNode* root = buildOptimalBST(R, keys, freq, 0, n - 1);
//    printf("Inorder traversal of the optimal BST: ");
//    inorder(root);
//    printf("\n");
//
//    // 释放内存
//    for (int i = 0; i <= n; i++) {
//        free(C[i]);
//        free(R[i]);
//    }
//    free(C);
//    free(R);
//}
//
//int main() {
//    int keys[] = { 10, 12, 20 };  // 键
//    int freq[] = { 34, 8, 50 };   // 对应的频率
//    int n = sizeof(keys) / sizeof(keys[0]);
//
//    optimalBST(keys, freq, n);
//
//    return 0;
////}
//#include <stdio.h>
//#include <limits.h>
//
//#define MAX_Y 10000  // 最大目标金额
//#define MAX_N 100    // 最大货币种类数量
//
//// 动态规划解决最少货币问题
//int minCoins(int coins[], int n, int y) {
//    int dp[MAX_Y + 1];
//
//    // 初始化 dp 数组
//    for (int i = 0; i <= y; i++) {
//        dp[i] = INT_MAX;  // 设置初始值为一个很大的值
//    }
//    dp[0] = 0;  // 支付 0 元时，货币数为 0
//
//    // 动态规划填充 dp 数组
//    for (int i = 1; i <= y; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i >= coins[j]) {
//                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : (dp[i - coins[j]] + 1);
//            }
//        }
//    }
//
//    return dp[y] == INT_MAX ? -1 : dp[y];  // 如果没有解，返回 -1
//}
//
//int main() {
//    int coins[] = { 1, 3, 4 };  // 货币面值
//    int n = 3;  // 货币种类数
//    int y = 6;  // 目标金额
//
//    int result = minCoins(coins, n, y);
//    if (result != -1) {
//        printf("最少的货币张数为: %d\n", result);
//    }
//    else {
//        printf("无法支付该金额\n");
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//// 定义运算符
//#define ADD 1
//#define MUL 2
//
//// 动态数组实现的最大得分计算函数
//int maxScore(int* values, int n, int** ops) {
//    // 动态分配二维 dp 数组
//    int** dp = (int**)malloc(n * sizeof(int*));
//    for (int i = 0; i < n; i++) {
//        dp[i] = (int*)malloc(n * sizeof(int));
//    }
//
//    // 初始化 dp 数组，单个顶点的得分就是顶点值
//    for (int i = 0; i < n; i++) {
//        dp[i][i] = values[i];
//    }
//
//    // 填充 dp 数组，遍历所有子问题
//    for (int len = 2; len <= n; len++) {  // len是子多边形的长度
//        for (int i = 0; i <= n - len; i++) {
//            int j = i + len - 1;
//            dp[i][j] = INT_MIN;  // 初始化为最小值
//            // 尝试所有可能的中间顶点 k
//            for (int k = i; k < j; k++) {
//                int temp;
//                if (ops[k][k + 1] == ADD) {
//                    temp = dp[i][k] + dp[k + 1][j];
//                }
//                else { // ops[k][k+1] == MUL
//                    temp = dp[i][k] * dp[k + 1][j];
//                }
//                // 更新 dp[i][j]
//                dp[i][j] = (dp[i][j] > temp) ? dp[i][j] : temp;
//            }
//        }
//    }
//
//    // 获取最终得分并释放 dp 数组内存
//    int result = dp[0][n - 1];
//
//    // 释放动态分配的内存
//    for (int i = 0; i < n; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result;
//}
//
//int main() {
//    int n = 5;  // 顶点数
//    int values[] = { 1, 2, 3, 4, 5 };  // 顶点的值
//
//    // 动态分配 ops 数组，存储每条边的运算符
//    int** ops = (int**)malloc(n * sizeof(int*));
//    for (int i = 0; i < n; i++) {
//        ops[i] = (int*)malloc(n * sizeof(int));
//    }
//
//    // 设置 ops 数组，每条边的运算符：ADD为加法，MUL为乘法
//    ops[0][1] = ADD;
//    ops[1][2] = MUL;
//    ops[2][3] = ADD;
//    ops[3][4] = MUL;
//    ops[0][2] = MUL;
//    ops[1][3] = ADD;
//    ops[2][4] = ADD;
//
//    // 计算最高得分
//    int result = maxScore(values, n, ops);
//    printf("最高得分是: %d\n", result);
//
//    // 释放 ops 数组内存
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
//// 并查集的父节点数组
//int parent[MAX];
//
//// 初始化并查集
//void init() {
//    for (int i = 0; i < MAX; i++) {
//        parent[i] = i;  // 初始每个人都是自己的父节点
//    }
//}
//
//// 查找操作：路径压缩优化
//int find(int x) {
//    if (parent[x] != x) {
//        parent[x] = find(parent[x]);  // 路径压缩
//    }
//    return parent[x];
//}
//
//// 合并操作：按秩合并优化
//void union_sets(int x, int y) {
//    int rootX = find(x);
//    int rootY = find(y);
//
//    if (rootX != rootY) {
//        parent[rootX] = rootY;  // 将x的根节点指向y的根节点
//    }
//}
//
//int main() {
//    int n, m, p;
//
//    // 读入 n, m, p
//    scanf("%d %d %d", &n, &m, &p);
//
//    // 初始化并查集
//    init();
//
//    // 处理m条亲戚关系
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        scanf("%d %d", &a, &b);
//        union_sets(a, b);  // 将a和b合并到同一个集合中
//    }
//
//    // 处理p条查询
//    for (int i = 0; i < p; i++) {
//        int Pi, Pj;
//        scanf("%d %d", &Pi, &Pj);
//
//        // 如果Pi和Pj在同一个集合中，则输出YES，否则输出NO
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
//// 邻接矩阵表示图
//int graph[MAX_V][MAX_V];
//
//int main() {
//    int V, E, K, N;
//
//    // 输入顶点数V, 边数E, 颜色数K
//    scanf("%d %d %d", &V, &E, &K);
//
//    // 初始化邻接矩阵
//    for (int i = 0; i < V; i++) {
//        for (int j = 0; j < V; j++) {
//            graph[i][j] = 0;
//        }
//    }
//
//    // 输入E条边
//    for (int i = 0; i < E; i++) {
//        int u, v;
//        scanf("%d %d", &u, &v);
//        // 注意输入的顶点是从1开始的，需要调整为从0开始
//        u--; v--;
//        graph[u][v] = 1;
//        graph[v][u] = 1;  // 无向图
//    }
//
//    // 输入待检查的颜色分配方案的个数N
//    scanf("%d", &N);
//
//    // 对每个颜色分配方案进行检查
//    for (int i = 0; i < N; i++) {
//        int colors[MAX_V];
//
//        // 输入每个顶点的颜色
//        for (int j = 0; j < V; j++) {
//            scanf("%d", &colors[j]);
//        }
//
//        // 检查方案是否满足图着色的条件
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
//        // 输出结果
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
