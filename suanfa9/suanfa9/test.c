#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_N 20// 判断一个数是否是素数
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;  } }
    return true;}// 输出当前的环排列
void printSolution(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }// 检查环的最后一项和第一项是否满足素数条件
    if (isPrime(arr[n - 1] + arr[0])) {
        printf("%d\n", arr[0]);   }
    else { printf("\n");   }}// 回溯法生成所有排列
void findPrimeRing(int arr[], bool visited[], int n, int step) {// 如果排列完整，检查最后两个数是否满足条件
    if (step == n) {  // 检查最后一个数与第一个数是否和为素数
        if (isPrime(arr[n - 1] + arr[0])) {
            printSolution(arr, n);}  return; }// 尝试每个数字
    for (int i = 1; i <= n; i++) {// 如果数字已经使用过或者不满足条件，跳过
        if (visited[i]) continue;// 如果是第一个数字，直接放入
        if (step == 0 || isPrime(arr[step - 1] + i)) {
            arr[step] = i;  // 放置数字
            visited[i] = true;  // 标记为已使用
            findPrimeRing(arr, visited, n, step + 1);  // 递归
            visited[i] = false;   }  }}
int main() {
    int n;
    printf("请输入n（1<n <= 20）：");
    scanf("%d", &n);
    int arr[MAX_N];  // 存储当前的环排列
    bool visited[MAX_N + 1] = { false };  // 标记数字是否已使用// 从数字1开始
    arr[0] = 1;
    visited[1] = true;
    printf("所有符合要求的素数环：\n");
    findPrimeRing(arr, visited, n, 1);
    return 0;
}
