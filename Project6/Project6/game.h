#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//��ʼ��
void initboard(char board[ROW][COL], int row, int col);


//��ӡ
void displayBoard(char board[ROW][COL], int row, int col);

//�������
void playerMove(char board[ROW][COL], int row,int col);

//��������
void computerMove(char board[ROW][COL], int row, int col);

//��Ӯ

char IsWin(char board[ROW][COL],int row,int col);