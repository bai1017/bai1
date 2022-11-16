#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//扩充容量
void CheckContact(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("扩容成功\n");
		}
		else
		{
			printf("扩容失败\n");
			exit(1);
		}
	}
}



//加载有效信息到通讯录中
void LoadContact(struct Contact* pc)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("contact:fopen");
		return;
	}
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pf))
	{
		CheckContact(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pf);
	pf = NULL;
}


//初始化通讯录
void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);//加载有效信息到通讯录中
}

//添加联系人信息
void AddContact(struct Contact* pc)
{
	CheckContact(pc);
	printf("请输入联系人的姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入联系人的年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入联系人的性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入联系人的电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入联系人的住址:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("添加成功\n");
	pc->sz++;
}

//销毁通讯录
void DistroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


//显示联系人信息
void ShowContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，显示失败！！！\n");
		return;
	}
	int i = 0;
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t%15s\t%15s\t%15s\t%15s\t%15s\n\n",
		"姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("\t%15s\t%15d\t%15s\t%15s\t%15s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t--------------------------------------------------------------------------\n");
}


//删除联系人信息
int FindContactByName(const struct Contact* pc, char* name)
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("联系人为空，操作失败\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人姓名:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("查找的联系人不存在！！！\n");
	}
	else
	{
		for (int i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}


//查找联系人信息
void SearchContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，查找失败！！！\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的联系人的名字:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在！！！\n");
		return;
	}
	else
	{
		printf("\t%15s\t%15s\t%15s\t%15s\t%15s\n\n",
			"姓名", "年龄", "性别", "电话", "住址");
		printf("\t%15s\t%15d\t%15s\t%15s\t%15s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}


//修改联系人信息
void ModifyContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，查找失败！！！\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的联系人姓名:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在！！！\n");
		return;
	}
	else
	{
		printf("请输入新的联系人姓名:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的联系人年龄:>");
		scanf("%d", &pc->data[pos].age);
		printf("请输入新的联系人性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的联系人电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的联系人住址:>");
		scanf("%s", pc->data[pos].addr);
	}
	printf("修改成功\n");
}

//排序联系人信息
void SortContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法排序！！！\n");
		return;
	}
	int i = 0;
	int j = 0;
	struct PeoInfo tmp;
	for (i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < pc->sz - i - 1; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) < 0)
			{
				tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			return;
		}
	}
	printf("排序成功\n");
}


//保存信息
void SaveContact(struct Contact* pc)
{
	//1.打开文件
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact:fopen");
		return;
	}
	//2.写数据
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&(pc->data[i]), sizeof(struct PeoInfo), 1, pf);
	}
	//3.关闭文件
	fclose(pf);
	pf = NULL;
}