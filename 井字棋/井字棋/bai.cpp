#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main() {
	int input = 0;
	int number = 0;
	printf("***********************\n");
	printf("*******1开始游戏*******\n");
	printf("*******0结束游戏*******\n");
	printf("***********************\n");
	do{
		printf("请输入->");
		scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("选择类型->");
		scanf("%d", &number);
		game();
		break;
	case 0:
		printf("结束游戏\n");
		break;
	default:
		printf("输入错误，请输入 1 or 0 \n");
		break;
	}
	} while (input);
	return 0;
}