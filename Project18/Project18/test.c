#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define LEN 10000

int main()
{
    int fac[LEN] = { 0 };//��׳˵�����
    int sum[LEN] = { 0 };//���δ洢�׳�֮�͵�����
    int i, j, k;	//�����ı���
    int n;		//���һ���׳�

    scanf("%d", &n);
    if (n == 1) {		//�ȿ���1�Ľ׳ˣ���ʼ��1��ֵ
        printf("%d", 1);
        return 0;	//����һ������
    }
    int x = 0;	//xΪ��λ����
    fac[1] = 1;	//��ʼ��1�Ľ׳ˣ�����2�Ľ׳˵ĺͿ�ʼ
    for (i = 1;i <= n;i++) {	//����ѭ����֤����������׳˵�ֵ
        for (j = 1;j <= LEN;j++) {	//����ѭ�������ǰ���Ľ׳�
            fac[j] = fac[j] * i + x;	//��ǰ�������j-1�Ľ׳ˣ���ÿ��һλ�ϵ���ͬ��j
            x = fac[j] / 10;		//xΪint�ͣ������λ����
            fac[j] = fac[j] % 10;	//���µ�ǰ��
        }
        for (k = 1;k <= LEN;k++) {	//��ͣ�ÿ���һ���׳˼�һ��
            sum[k] = sum[k] + fac[k];
            if (sum[k] >= 10) {		//��λ
                sum[k + 1] += 1;
                sum[k] = sum[k] % 10;
            }
        }
    }
    for (i = LEN;i >= 1;i--) { 	//���Ӧ���������������λ��
        if (sum[i] != 0)
            break;
    }
    for (j = i;j >= 1;j--) {		//�������
        printf("%d", sum[j]);
    }
    return 0;
}
