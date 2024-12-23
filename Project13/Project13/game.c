#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++) {
		for (j = 0;j < COLS;j++) {
			board[i][j] = set;
		}
	}


}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	for (j = 0;j <= col;j++) {
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1;i <= row;i++) {
		printf("%d ", i);
		for (j = 1;j <= col;j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷游戏------\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}
//int get_mine_count(char board[ROWS][COLS], int x, int y) {
//	return (board[x - 1][y] +
//		board[x - 1][y - 1] +
//		board[x][y - 1] +
//		board[x + 1][y - 1] +
//		board[x + 1][y] +
//		board[x + 1][y + 1] +
//		board[x][y + 1] +
//		board[x - 1][y - 1] - 8 * '0');
//}
int get_mine_count(char board[ROWS][COLS], int x, int y) {
	int result = 0;
	for(int i=-1;i<=1;i++){
		for (int j = -1;j <= 1;j++) {
			 result += (board[x + i][y + j]-'0');
			 //printf("%d", result);
		}

	}
	return result;
}
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;

	while (win<row*col-EASY_COUNT) {
		printf("请输入要排查的坐标");

		scanf("%d %d", &x, &y);
		if (show[x][y] != '*') {
			printf("已经查过了，重新输入\n");
		}
		else if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				
				printf("是炸弹\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//不是炸弹  统计周围的雷
			{
				win++;
				//统计mine数组中x，y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				printf("%d",count);
				show[x][y] = count + '0';  //转化为数字字符
				DisplayBoard(show, ROW, COL);
			}
		}
		else {
			printf("坐标违法，重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("获得胜利\n");
		DisplayBoard(mine, ROW, COL);
	}

}