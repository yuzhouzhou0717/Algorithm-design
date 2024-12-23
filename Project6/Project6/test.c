#define _CRT_SECURE_NO_WARNINGS


//冒泡排序
//void bubble_sort(int* arr,int sz) {
//	for (int i = 0;i < sz - 1;i++) {
//		for (int j = 0;j < sz - 1 - i;j++) {
//			if (arr[j] > arr[j + 1]) {
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//			  
//		}
//	}
//}
//
//
//int main() {
//
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,sz);
//	for (int i = 0;i <= sz - 1;i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}

//三子棋（数组）

#include "game.h"

void menu() {
	printf("**********************\n");
	printf("****1.play  0.exit****\n");
	printf("**********************\n");
}

void game() {
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board,ROW,COL);
	displayBoard(board,ROW,COL);
	//下棋
	while (1) {
		playerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		displayBoard(board, ROW, COL);
		
		computerMove(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		displayBoard(board, ROW, COL);
		
	}
	if (ret == '*')
	{
		printf("玩家赢\n");

	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	displayBoard(board, ROW, COL);
}
int main() {
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			goto exit;
		default:
			printf("选择错误");
			break;
		}

	} while (1);


exit:
	return 0;

}