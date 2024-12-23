#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
void menu() {
	printf("1.play");
	printf("0.exit\n");
}
void game() {
	//给出数组
	char mine[ROWS][COLS] = {0}; //存放布置的雷的信息
	char show[ROWS][COLS] = {0};   //存放排查出的雷的信息
	//初始化数组的内容为指定的内容
	//mine数组在没有布置雷的时候，都是 0
	InitBoard(mine, ROW, COL,'0');
	//show数组在没有排查雷的时候，都是 *
	InitBoard(show, ROW, COL,'*');
	//设置雷
	SetMine(mine,ROW,COL);
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
	FineMine(mine,show,ROW,COL);
	
}
int main() {
	int input = 0;
	//设置随机数生成起点
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
		}while (input);
		
	return 0;
}