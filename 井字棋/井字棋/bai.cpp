#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
int main() {
	int input = 0;
	int number = 0;
	printf("***********************\n");
	printf("*******1��ʼ��Ϸ*******\n");
	printf("*******0������Ϸ*******\n");
	printf("***********************\n");
	do{
		printf("������->");
		scanf("%d", &input);
	switch (input)
	{
	case 1:
		printf("ѡ������->");
		scanf("%d", &number);
		game();
		break;
	case 0:
		printf("������Ϸ\n");
		break;
	default:
		printf("������������� 1 or 0 \n");
		break;
	}
	} while (input);
	return 0;
}