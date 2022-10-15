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
}//初始化两层雷阵
void print_player()//打印玩家棋盘
{
	int i = 0;
	int j = 0;
	printf("0 ");
	for (i = 0; i < x - 1; i++)
	{
		printf("%d", i);//打印横坐标
	}
	printf("\n");
	for (i = 0; i < x - 2; i++)
	{
		printf("%d", i);//打印竖坐标
		for (j = 0; j < y - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//玩家棋盘数组
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < x - 1; i++)
	{
		printf("%c ", show_mine[10][j]);
	}
	printf("\n");
}
void print_mine()//打印设计者棋盘
{
	int i = 0;
	int j = 0;
	printf("0 ");
	for (i = 0; i < x - 1; i++)
	{
		printf("%d", i);//打印横坐标
	}
	printf("\n");
	for (i = 0; i < x - 2; i++)
	{
		printf("%d", i);//打印竖坐标
		for (j = 0; j < y - 1; j++)
		{
			printf("%c ", real_mine[i][j]);//玩家棋盘数组
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < x - 1; i++)
	{
		printf("%c ", real_mine[10][j]);
	}
	printf("\n");
}
void set_mine()//给设计者棋盘布雷
{
	int i = 0;
	int j = 0;
	int count = COUNT;//雷总数
	while (count)//雷布完后停住循环
	{
		int i = rand() % 10 + 1;
		int j = rand() % 10 + 1;//产生1-10的随机数，在数组下标为1到10的范围内布雷
		if (real_mine[i][j] == '0')//找到不是雷的地方布雷
		{
			real_mine[i][j] = '1';
			count--;
		}
	}
}
int count_mine(int m, int n)//检测周围八个区域雷的个数
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
	printf("输入坐标扫雷\n");
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
			printf("输入错误，请重新输入\n");
		}
	}
}
void open_mine(int m, int n)//坐标周围展开函数
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
int sweep_mine()//游戏点击进程
{
	int m = 0;
	int n = 0;
	int count = 0;
	printf("输入坐标扫雷\n");
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
				printf("玩家赢\n\n");
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
		printf("输入错误，请重新输入\n");
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
	printf("*******1开始游戏*******\n");
	printf("*******0结束游戏*******\n");
	printf("***********************\n");
}