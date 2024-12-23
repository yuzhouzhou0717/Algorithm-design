#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_N 20// �ж�һ�����Ƿ�������
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;  } }
    return true;}// �����ǰ�Ļ�����
void printSolution(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }// ��黷�����һ��͵�һ���Ƿ�������������
    if (isPrime(arr[n - 1] + arr[0])) {
        printf("%d\n", arr[0]);   }
    else { printf("\n");   }}// ���ݷ�������������
void findPrimeRing(int arr[], bool visited[], int n, int step) {// ��������������������������Ƿ���������
    if (step == n) {  // ������һ�������һ�����Ƿ��Ϊ����
        if (isPrime(arr[n - 1] + arr[0])) {
            printSolution(arr, n);}  return; }// ����ÿ������
    for (int i = 1; i <= n; i++) {// ��������Ѿ�ʹ�ù����߲���������������
        if (visited[i]) continue;// ����ǵ�һ�����֣�ֱ�ӷ���
        if (step == 0 || isPrime(arr[step - 1] + i)) {
            arr[step] = i;  // ��������
            visited[i] = true;  // ���Ϊ��ʹ��
            findPrimeRing(arr, visited, n, step + 1);  // �ݹ�
            visited[i] = false;   }  }}
int main() {
    int n;
    printf("������n��1<n <= 20����");
    scanf("%d", &n);
    int arr[MAX_N];  // �洢��ǰ�Ļ�����
    bool visited[MAX_N + 1] = { false };  // ��������Ƿ���ʹ��// ������1��ʼ
    arr[0] = 1;
    visited[1] = true;
    printf("���з���Ҫ�����������\n");
    findPrimeRing(arr, visited, n, 1);
    return 0;
}
