#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void initboard(char board[ROW][COL], int row, int col) {

	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++) {
		for (j = 0;j < col;j++) {
			board[i][j] =' ';
		}
	}
}
void displayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0;i < row;i++) {
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		for (int j = 0;j < col;j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0;j < col;j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
		    
	 }
}
//玩家下棋
void playerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	printf("请输入坐标:>");
	scanf("%d %d", &x, &y); 
	while (1) 
	{
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标已被占用，请选择其他位置\n");
				break;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			break;
		}

		}
	
}
//电脑下棋
void computerMove(char board[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));
	int x = 0;
	int y = 0;
	printf("电脑下棋:>\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}
//满返回1
int IsFull(char board[ROW][COL], int row, int col) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1; 
}


char IsWin(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1]&& board[i][1] ==board[i][2] && board[i][1] != ' ') 
		{
			return board[i][1];

		}
		
	}
	//列
	for (int j = 0;j < col;j++) 
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') 
		{
			return board[1][j];
		}


	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] ==board[2][2] && board[1][1] != ' ')
	{
			return board[1][1];
	}
	
	if (board[0][2] == board[1][1] && board[1][1] ==board[2][0] && board[1][1] != ' ')
	{
			return board[1][1];
	}
	if(IsFull(board,row,col))
	{
		return 'Q';
	}
	return 'C';
}

