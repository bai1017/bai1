#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 20
#define SEX_MAX 20
#define TELE_MAX 20
#define ADDR_MAX 20
#define DEFAULT_SZ 3

struct PeoInfo
{
	char name[NAME_MAX];//����
	int age;			//����
	char sex[SEX_MAX];  //�Ա�
	char tele[TELE_MAX];//�绰
	char addr[ADDR_MAX];//סַ
};

struct Contact
{
	struct PeoInfo* data;//�ܹ���̬�洢��ϵ�˵���Ϣ
	int sz;				 //��¼��ǰ��ϵ�˵ĸ���
	int capacity;		 //��¼��ǰͨѶ¼������
};


//��ʼ��ͨѶ¼
void InitContact(struct Contact* pc);

//�����ϵ����Ϣ
void AddContact(struct Contact* pc);

//����ͨѶ¼��Ϣ
void DistroyContact(struct Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(struct Contact* pc);

//ɾ����ϵ����Ϣ
void DelContact(struct Contact* pc);

//������ϵ����Ϣ
void SearchContact(struct Contact* pc);

//�޸���ϵ����Ϣ
void ModifyContact(struct Contact* pc);

//������ϵ����Ϣ
void SortContact(struct Contact* pc);

//������Ч��Ϣ��ͨѶ¼��
void LoadContact(struct Contact* pc);

//������Ϣ
void SaveContact(struct Contact* pc);
