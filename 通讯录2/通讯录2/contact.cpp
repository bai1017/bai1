#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//��������
void CheckContact(struct Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
			exit(1);
		}
	}
}



//������Ч��Ϣ��ͨѶ¼��
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


//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc)
{
	pc->sz = 0;
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);//������Ч��Ϣ��ͨѶ¼��
}

//�����ϵ����Ϣ
void AddContact(struct Contact* pc)
{
	CheckContact(pc);
	printf("��������ϵ�˵�����:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("��������ϵ�˵�����:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("��������ϵ�˵��Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��������ϵ�˵ĵ绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("��������ϵ�˵�סַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("��ӳɹ�\n");
	pc->sz++;
}

//����ͨѶ¼
void DistroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


//��ʾ��ϵ����Ϣ
void ShowContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ���ʾʧ�ܣ�����\n");
		return;
	}
	int i = 0;
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t\t--------------------------------------------------------------------------\n");
	printf("\t%15s\t%15s\t%15s\t%15s\t%15s\n\n",
		"����", "����", "�Ա�", "�绰", "סַ");
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


//ɾ����ϵ����Ϣ
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
		printf("��ϵ��Ϊ�գ�����ʧ��\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("���ҵ���ϵ�˲����ڣ�����\n");
	}
	else
	{
		for (int i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}


//������ϵ����Ϣ
void SearchContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ʧ�ܣ�����\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	else
	{
		printf("\t%15s\t%15s\t%15s\t%15s\t%15s\n\n",
			"����", "����", "�Ա�", "�绰", "סַ");
		printf("\t%15s\t%15d\t%15s\t%15s\t%15s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}


//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ʧ�ܣ�����\n");
		return;
	}
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", name);
	int pos = FindContactByName(pc, name);
	if (pos == -1)
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	else
	{
		printf("�������µ���ϵ������:>");
		scanf("%s", pc->data[pos].name);
		printf("�������µ���ϵ������:>");
		scanf("%d", &pc->data[pos].age);
		printf("�������µ���ϵ���Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("�������µ���ϵ�˵绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������µ���ϵ��סַ:>");
		scanf("%s", pc->data[pos].addr);
	}
	printf("�޸ĳɹ�\n");
}

//������ϵ����Ϣ
void SortContact(struct Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷����򣡣���\n");
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
	printf("����ɹ�\n");
}


//������Ϣ
void SaveContact(struct Contact* pc)
{
	//1.���ļ�
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveContact:fopen");
		return;
	}
	//2.д����
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(&(pc->data[i]), sizeof(struct PeoInfo), 1, pf);
	}
	//3.�ر��ļ�
	fclose(pf);
	pf = NULL;
}