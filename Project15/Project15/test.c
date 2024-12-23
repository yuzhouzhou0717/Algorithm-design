#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int DoubleCoin(int coins[], int left, int right) {
	// ֻ��һ��
	if (left == right)
		return left;
	// �ֿ�
	int mid = (left + right) / 2;
	int Lwh = 0, Rwh = 0;
	// ���
	for (int i = left;i <= mid;i++) {
		Lwh += coins[i];
	}
	// �ұ�
	for (int i = mid + 1;i <= right;i++) {
		Rwh += coins[i];
	}
	// �Ƚ�
	if (Lwh < Rwh) {
		return DoubleCoin(coins, left, mid - 1);
	}
	else
		return DoubleCoin(coins, mid + 1, right);
}
int ThreeCoin(int coins, int left, int right) {
	return 0;
}

int main() {
	int n; //Ӳ����
	int t;
	scanf_s("%d", &n);
	int coins[] = { 0 };
	srand((unsigned)time(&t));
	int TcoinWh = rand() % 50 + 50;  // 50-100
	int FcoinWh = rand() % 50 + 1;   // 1-50
	int Fcoin = rand() % n;
	for (int i = 0; i < n; i++) {
		coins[i] = TcoinWh;          // �������
	}
	coins[Fcoin] = FcoinWh;          // �ٱ������һ��
	int index = DoubleCoin(coins, 0, n - 1);
	print("%d", Fcoin);
	printf("���ַ�--�ٱ�λ���ڣ� % d", index + 1);
	//printf("���ַ�--�ٱ�λ���ڣ� % d" , ThreeCoin(coins, 0, n - 1)+1);

	return 0;
}