#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 10
#include "contact.h"
void menu()
{
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t******    通讯录管理系统    ********\n");
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t*      1.添加联系人---ADD          *\n");
	printf("\t\t\t\t*      2.删除联系人---DEL          *\n");
	printf("\t\t\t\t*      3.查找联系人---SEARCH	   *\n");
	printf("\t\t\t\t*      4.修改联系人---MODIFY       *\n");
	printf("\t\t\t\t*      5.显示联系人---SHOW         *\n");
	printf("\t\t\t\t*      6.排序联系人---SORT         *\n");
	printf("\t\t\t\t*      0.退出通讯录---EXIT         *\n");
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t************************************\n");
}
enum
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//添加联系人信息
			break;
		case DEL:
			DelContact(&con);//删除联系人信息
			break;
		case SEARCH:
			SearchContact(&con);//查找联系人信息
			break;
		case MODIFY:
			ModifyContact(&con);//修改联系人信息
			break;
		case SHOW:
			ShowContact(&con);//显示联系人信息
			break;
		case SORT:
			SortContact(&con);//排序联系人信息
			break;
		case EXIT:
			SaveContact(&con);//保存信息
			DistroyContact(&con);//销毁通讯录信息
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}