#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
char show_mine[x][y]={0};
char real_mine[x][y]={0};
void init_mine() 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			show_mine[i][j] = '*';
			real_mine[i][j] = '0';
		}
	}
}//��ʼ����������
void print_player()//��ӡ�������
{
	int i = 0;
	int j = 0;
	printf("0 ");
	for (i = 0; i < x - 1; i++)
	{
		printf("%d", i);//��ӡ������
	}
	printf("\n");
	for (i = 0; i < x - 2; i++)
	{
		printf("%d", i);//��ӡ������
		for (j = 0; j < y - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//�����������
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < x - 1; i++)
	{
		printf("%c ", show_mine[10][j]);
	}
	printf("\n");
}
void print_mine()//��ӡ���������
{
	int i = 0;
	int j = 0;
	printf("0 ");
	for (i = 0; i < x - 1; i++)
	{
		printf("%d", i);//��ӡ������
	}
	printf("\n");
	for (i = 0; i < x - 2; i++)
	{
		printf("%d", i);//��ӡ������
		for (j = 0; j < y - 1; j++)
		{
			printf("%c ", real_mine[i][j]);//�����������
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < x - 1; i++)
	{
		printf("%c ", real_mine[10][j]);
	}
	printf("\n");
}
void set_mine()//����������̲���
{
	int i = 0;
	int j = 0;
	int count = COUNT;//������
	while (count)//�ײ����ͣסѭ��
	{
		int i = rand() % 10 + 1;
		int j = rand() % 10 + 1;//����1-10����������������±�Ϊ1��10�ķ�Χ�ڲ���
		if (real_mine[i][j] == '0')//�ҵ������׵ĵط�����
		{
			real_mine[i][j] = '1';
			count--;
		}
	}
}
int count_mine(int m, int n)//�����Χ�˸������׵ĸ���
{
	int count = 0;
	if (real_mine[m - 1][n - 1] == '1')
		count++;
	if (real_mine[m - 1][n] == '1')
		count++;
	if (real_mine[m - 1][n + 1] == '1')
		count++;
	if (real_mine[m][n - 1] == '1')
		count++;
	if (real_mine[m][n] == '1')
		count++;
	if (real_mine[m+1][n + 1] == '1')
		count++;
	if (real_mine[m - 1][n ] == '1')
		count++;
	if (real_mine[m - 1][n - 1] == '1')
		count++;
	return count;
}
void safe_mine() {
	int m = 0;
	int n = 0;
	char ch = 0;
	int count = 0;
	int ret = 1;
	printf("��������ɨ��\n");
	while (1) {
		scanf("%d%d", &m, &n);
		if ((m >= 1 && m <= x - 2) && (n >= 1 && n <= y - 2))
		{
			if (real_mine[m][n] == '1')
			{
				real_mine[m][n] == '0';
				char ch = count_mine(m, n);
				show_mine[m][n] = ch + '0';
				open_mine(m, n);
				while (ret)
				{
					int m = rand() % 10 + 1;
					int n = rand() % 10 + 1;
					if (real_mine[m][n] == '0')
					{
						real_mine[m][n] == '1';
						ret--;
						break;
					}
				}break;
			}
			if (real_mine[m][n] == '0')
			{
				char ch = count_mine(m, n);
				show_mine[m][n] = ch + '0';
				open_mine(m, n);
				break;
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
}
void open_mine(int m, int n)//������Χչ������
{
	if (real_mine[m - 1][n - 1] == '0')
	{
		show_mine[m - 1][n - 1] = count_mine(m - 1, n - 1) + '0';
	}
	if (real_mine[m - 1][n] == '0')
	{
		show_mine[m - 1][n] = count_mine(m - 1, n ) + '0';
	}
	if (real_mine[m - 1][n + 1] == '0')
	{
		show_mine[m - 1][n + 1] = count_mine(m - 1, n + 1) + '0';
	}
	if (real_mine[m ][n - 1] == '0')
	{
		show_mine[m][n - 1] = count_mine(m , n - 1) + '0';
	}
	if (real_mine[m ][n + 1] == '0')
	{
		show_mine[m ][n + 1] = count_mine(m , n + 1) + '0';
	}
	if (real_mine[m + 1][n - 1] == '0')
	{
		show_mine[m + 1][n - 1] = count_mine(m + 1, n - 1) + '0';
	}
	if (real_mine[m + 1][n ] == '0')
	{
		show_mine[m + 1][n ] = count_mine(m + 1, n ) + '0';
	}
	if (real_mine[m + 1][n + 1] == '0')
	{
		show_mine[m + 1][n + 1] = count_mine(m + 1, n + 1) + '0';
	}
}
int sweep_mine()//��Ϸ�������
{
	int m = 0;
	int n = 0;
	int count = 0;
	printf("��������ɨ��\n");
	scanf("%d%d", &m, &n);
	if ((m >= 1 && m <=x-2) && (n >= 1 && n <= y-2))
	{
		if (real_mine[m][n] == '0')
		{
			char ch = count_mine(m, n);
			show_mine[m][n] = ch + '0';
			open_mine(m, n);
			if (count_show_mine() == COUNT)
			{
				print_mine();
				printf("���Ӯ\n\n");
				return 0;
			}
		}
		else if (real_mine[m][n] == '1')
		{
			return 1;
		}
	}
	else
	{
		printf("�����������������\n");
	}
	return 0;
}
int count_show_mine()
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i <= x - 2; i++)
	{
		for (j = 0; j <= y - 2; j++)
		{
			if (show_mine[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
void muen()
{
	printf("***********************\n");
	printf("*******1��ʼ��Ϸ*******\n");
	printf("*******0������Ϸ*******\n");
	printf("***********************\n");
}