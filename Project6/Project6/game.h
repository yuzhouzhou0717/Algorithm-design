#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//初始化
void initboard(char board[ROW][COL], int row, int col);


//打印
void displayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void playerMove(char board[ROW][COL], int row,int col);

//电脑下棋
void computerMove(char board[ROW][COL], int row, int col);

//输赢

char IsWin(char board[ROW][COL],int row,int col);