#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 10
#include "contact.h"
void menu()
{
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t******    ͨѶ¼����ϵͳ    ********\n");
	printf("\t\t\t\t************************************\n");
	printf("\t\t\t\t*      1.�����ϵ��---ADD          *\n");
	printf("\t\t\t\t*      2.ɾ����ϵ��---DEL          *\n");
	printf("\t\t\t\t*      3.������ϵ��---SEARCH	   *\n");
	printf("\t\t\t\t*      4.�޸���ϵ��---MODIFY       *\n");
	printf("\t\t\t\t*      5.��ʾ��ϵ��---SHOW         *\n");
	printf("\t\t\t\t*      6.������ϵ��---SORT         *\n");
	printf("\t\t\t\t*      0.�˳�ͨѶ¼---EXIT         *\n");
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
	InitContact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);//�����ϵ����Ϣ
			break;
		case DEL:
			DelContact(&con);//ɾ����ϵ����Ϣ
			break;
		case SEARCH:
			SearchContact(&con);//������ϵ����Ϣ
			break;
		case MODIFY:
			ModifyContact(&con);//�޸���ϵ����Ϣ
			break;
		case SHOW:
			ShowContact(&con);//��ʾ��ϵ����Ϣ
			break;
		case SORT:
			SortContact(&con);//������ϵ����Ϣ
			break;
		case EXIT:
			SaveContact(&con);//������Ϣ
			DistroyContact(&con);//����ͨѶ¼��Ϣ
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}