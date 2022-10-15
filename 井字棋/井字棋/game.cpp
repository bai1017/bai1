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
	printf("���A�غ�");
	int i = 0;
	int j = 0;
	while(1){
		printf("�����A����->");
		scanf("%d %d",&i,&j);
		if (i >= 1 && i <= x && j >= 1 && j <= y) {
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
		    }
			else {
				printf("��λ����������\n");
				continue;
			}
		}
		else {
			printf("�������������1-3֮���ֵ\n");
			continue;
		}
	}
}
void gamerB_board(char board[X][Y], int x, int y) {
	printf("���B�غ�");
	int i = 0;
	int j = 0;
	while (1) {
		printf("�����B����->");
		scanf("%d %d", &i, &j);
		if (i >= 1 && i <= x && j >= 1 && j <= y) {
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '#';
				break;
			}
			else {
				printf("��λ����������\n");
				continue;
			}
		}
		else {
			printf("�������������1-3֮���ֵ\n");
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
	//�Զ���һ������
	init_board(board, X, Y);
	//��ӡ����
	display_board(board, X, Y);
	//��һ�������
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
		//�ж���Ϸ��Ӯ
	}
	if (ret == '*')
		printf("���A��ʤ\n");
	else if (ret == '#')
		printf("���B��ʤ\n");
	else
		printf("ƽ��\n");
}
