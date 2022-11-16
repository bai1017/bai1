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
	char name[NAME_MAX];//姓名
	int age;			//年龄
	char sex[SEX_MAX];  //性别
	char tele[TELE_MAX];//电话
	char addr[ADDR_MAX];//住址
};

struct Contact
{
	struct PeoInfo* data;//能够动态存储联系人的信息
	int sz;				 //记录当前联系人的个数
	int capacity;		 //记录当前通讯录的容量
};


//初始化通讯录
void InitContact(struct Contact* pc);

//添加联系人信息
void AddContact(struct Contact* pc);

//销毁通讯录信息
void DistroyContact(struct Contact* pc);

//显示联系人信息
void ShowContact(struct Contact* pc);

//删除联系人信息
void DelContact(struct Contact* pc);

//查找联系人信息
void SearchContact(struct Contact* pc);

//修改联系人信息
void ModifyContact(struct Contact* pc);

//排序联系人信息
void SortContact(struct Contact* pc);

//加载有效信息到通讯录中
void LoadContact(struct Contact* pc);

//保存信息
void SaveContact(struct Contact* pc);
