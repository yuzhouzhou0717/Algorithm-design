//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//// �жϴ������Ƿ��ܱ�11����
//int isDivisibleBy11(char* num) {
//    int len = strlen(num);
//    int sum = 0;
//
//    // ���Ҷ˿�ʼÿ��λһ��
//    for (int i = len - 1; i >= 0; i -= 2) {
//        // ȡ��ǰһ��ĸ�λ���֣�������������֣�
//        int part = num[i] - '0';  // �����λ����
//
//        if (i - 1 >= 0) {  // ���������λ����ȡ���ڶ�λ
//            part = (num[i - 1] - '0') * 10 + part;
//        }
//
//        // ���뵽�ܺ�
//        sum += part;
//    }
//
//    // �ж��ܺ��Ƿ��ܱ�11����
//    return sum % 11 == 0;
//}
//
//int main() {
//    char num[101];  // ����Ĵ���������󳤶�Ϊ100
//
//    // ���������
//    printf("������һ��������: ");
//    scanf("%s", num);
//
//    // �ж��Ƿ��ܱ�11����
//    if (isDivisibleBy11(num)) {
//        printf("�����ܱ�11����\n");
//    }
//    else {
//        printf("�������ܱ�11����\n");
//    }
//
//    return 0;
//}
