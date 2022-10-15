#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void init_board(char board[X][Y], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			board[i][j] = ' ';
		}
	}
}
void display_board(char board[X][Y], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			printf(" %c ", board[i][j]);
			if (j < y - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < y; j++) {
			if (i < x - 1) {
				printf("---");
				if (j < y - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void gamerA_board(char board[X][Y], int x, int y) {
	printf("玩家A回合");
	int i = 0;
	int j = 0;
	while(1){
		printf("请玩家A输入->");
		scanf("%d %d",&i,&j);
		if (i >= 1 && i <= x && j >= 1 && j <= y) {
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
		    }
			else {
				printf("该位置有人用了\n");
				continue;
			}
		}
		else {
			printf("输入错误，请输入1-3之间的值\n");
			continue;
		}
	}
}
void gamerB_board(char board[X][Y], int x, int y) {
	printf("玩家B回合");
	int i = 0;
	int j = 0;
	while (1) {
		printf("请玩家B输入->");
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= x && j >= 1 && j <= y) {
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '#';
				break;
			}
			else {
				printf("该位置有人用了\n");
				continue;
			}
		}
		else {
			printf("输入错误，请输入1-3之间的值\n");
			continue;
		}
	}
}
int if_board(char board[X][Y], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (board[i][j] == ' ');
			return 0;
		}
	}
	return 1;
}
char win_board(char board[X][Y], int x, int y) {
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++) {
		for (j =1 ; j < y; j++) {
			if (board[i][j - 1] == board[i][j] && board[i][j] == board[i][j + 1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	for (j = 0; j < y; j++) {
		for (i = 1; i < x-1; i++) {
			if (board[i-1][j] == board[i][j] && board[i][j] == board[i+1][j] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	for (i = 1; i < x-1; i++) {
		for (j = 1; j < y-1; j++) {
			if (board[i-1][j - 1] == board[i][j] && board[i][j] == board[i+1][j + 1] && board[i][j] != ' ')
				return board[i][j];
			if (board[i-1][j + 1] == board[i][j] && board[i][j] == board[i+1][j - 1] && board[i][j] != ' ')
				return board[i][j];
		}
	}
	if (1 == if_board(board, x, y))
		return'D';
	else
		return'C';
}		
void game()
{
	char board[X][Y] = { 0 };
	//自定义一个棋盘
	init_board(board, X, Y);
	//打印棋盘
	display_board(board, X, Y);
	//玩家互相下棋
	char ret = 0;
	while (1) {
		gamerA_board(board, X, Y);
		display_board(board, X, Y);
		ret = win_board(board, X, Y);
		if (ret != 'C')
			break;
		gamerB_board(board, X, Y);
		display_board(board, X, Y);
		ret = win_board(board, X, Y);
		if (ret != 'C')
			break;
		//判断游戏输赢
	}
	if (ret == '*')
		printf("玩家A获胜\n");
	else if (ret == '#')
		printf("玩家B获胜\n");
	else
		printf("平局\n");
}
