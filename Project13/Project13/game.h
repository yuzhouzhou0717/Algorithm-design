#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10
 
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FineMine(char mine[ROW][COL], char show[ROW][COL], int row, int col);
int get_mine_count(char mine[ROWS][COLS], int x, int y);