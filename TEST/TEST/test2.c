//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//// 判断大整数是否能被11整除
//int isDivisibleBy11(char* num) {
//    int len = strlen(num);
//    int sum = 0;
//
//    // 从右端开始每两位一组
//    for (int i = len - 1; i >= 0; i -= 2) {
//        // 取当前一组的个位数字（如果有两个数字）
//        int part = num[i] - '0';  // 处理个位数字
//
//        if (i - 1 >= 0) {  // 如果存在两位数，取出第二位
//            part = (num[i - 1] - '0') * 10 + part;
//        }
//
//        // 加入到总和
//        sum += part;
//    }
//
//    // 判断总和是否能被11整除
//    return sum % 11 == 0;
//}
//
//int main() {
//    char num[101];  // 输入的大整数，最大长度为100
//
//    // 输入大整数
//    printf("请输入一个大整数: ");
//    scanf("%s", num);
//
//    // 判断是否能被11整除
//    if (isDivisibleBy11(num)) {
//        printf("该数能被11整除\n");
//    }
//    else {
//        printf("该数不能被11整除\n");
//    }
//
//    return 0;
//}
