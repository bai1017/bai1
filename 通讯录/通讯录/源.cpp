#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_PHONE 12
#define MAX_ADDRESS 30
//ö�٣�ѡ����
enum Choose
{
    EXIT,  //0�˳�
    ADD,   //1������ϵ��
    DEL,   //2ɾ����ϵ��
    SEARCH,//3������ϵ��
    MODIFY,//4�޸���ϵ��
    SHOW,  //5չʾ��ϵ��
    SORT   //6��˳������
};
//�ṹ�壺ͨѶ¼��ÿ����Ա����Ϣ
typedef struct PeoInform
{
    char name[MAX_NAME];//����
    int age;//����
    char sex[MAX_SEX];//�Ա�
    char phone[MAX_PHONE];//�绰
    char address[MAX_ADDRESS];//��ַ
}PeoInform;
//ͨѶ¼����
struct Contact
{
    struct PeoInform data[MAX];//���1000����Ϣ
    int size;//��¼��ǰ�ṹ�����Ѿ��е�Ԫ�ظ���
};
//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* ps)
{
    memset(ps->data, 0, sizeof(ps->data));//��ʼ����������ĳһ���ڴ������ȫ����ʼ��
    ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}
//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps)
{
    if (ps->size == MAX)
    {
        printf("ͨѶ¼�������޷�����\n");
    }
    else
    {
        printf("����������:>");
        scanf("%s", ps->data[ps->size].name);
        printf("����������:>");
        scanf("%d", &(ps->data[ps->size].age));
        printf("�������Ա�:>");
        scanf("%s", ps->data[ps->size].sex);
        printf("������绰:>");
        scanf("%s", ps->data[ps->size].phone);
        printf("�������ͥ��ַ:>");
        scanf("%s", ps->data[ps->size].address);
        ps->size++;
        printf("��ӳɹ�\n");
    }
}
//���β��Һ����������Һ���������ʹ�ã���ֹ���ݶ�ʧ��������ҵ����ݳ���
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1;//�Ҳ��������
}
//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("������Ҫɾ���˵�����:>");
    scanf("%s", name);
    //1.����Ҫɾ��������ʲôλ��
    //�ҵ��˷�����������Ԫ�ص��±�
    //�Ҳ������� -1
    int pos = FindByName(ps, name);
    //2.ɾ��
    //��ѯ������ϵ��
    if (pos == -1)
    {
        printf("��ѯ����Ҫɾ������ϵ�ˣ�������\n");
    }
    else
    {
        //ɾ������
        int j = 0;
        for (j = pos; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
            //����ɾ����������ݣ����Ժ�������ݻᶥ������
        }
        ps->size--;
        printf("ɾ���ɹ�\n");
    }
}
//����ָ�����˵���Ϣ
void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("������Ҫ�����˵�����:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("Ҫ���ҵ��˲�����,������\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
            ps->data[pos].name,
            ps->data[pos].age,
            ps->data[pos].sex,
            ps->data[pos].phone,
            ps->data[pos].address);//��ȡ�׵�ַ�����������
    }
}
//�޸�ָ����ϵ�˵���Ϣ
void MoidfyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("������Ҫ�޸���ϵ�˵�����:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
        printf("Ҫ�޸���ϵ�˵���Ϣ�����ڣ�������\n");
    }
    else
    {
        printf("����������:>");
        scanf("%s", ps->data[pos].name);
        printf("����������:>");
        scanf("%d", &(ps->data[pos].age));
        printf("�������Ա�:>");
        scanf("%s", ps->data[pos].sex);
        printf("������绰:>");
        scanf("%s", ps->data[pos].phone);
        printf("�������ͥ��ַ:>");
        scanf("%s", ps->data[pos].address);

        printf("�޸����\n");
    }
}
//չʾͨѶ¼�е���Ϣ
void ShowContact(const struct Contact* ps)
{
    if (ps->size == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    else
    {
        int i = 0;
        //����
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        //����
        for (i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                ps->data[i].name,
                ps->data[i].age,
                ps->data[i].sex,
                ps->data[i].phone,
                ps->data[i].address);
        }
    }
}
//����������ͨѶ¼����
void SortContact(struct Contact* ps)
{
    if (ps->size <= 0) {
        printf("ͨѶ¼��û����ϵ�ˣ������!\n");
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < ps->size - 1; i++)
    {
        for (j = 0; j < ps->size - i - 1; j++)
        {
            if (strcmp(ps->data[j].name, (ps->data[j + 1]).name) > 0)
            {
                PeoInform tmp;
                tmp = ps->data[j];
                ps->data[j] = ps->data[j + 1];
                ps->data[j + 1] = tmp;
            }
        }
        printf("����ɹ���\n");
    }
}
void menu()
{
    printf("*********************************\n");
    printf("**      1. �����ϵ��          **\n");
    printf("**      2. ɾ����ϵ��          **\n");
    printf("**      3. ������ϵ��          **\n");
    printf("**      4. �޸���ϵ��          **\n");
    printf("**      5. ��ʾ������ϵ��      **\n");
    printf("**      6. ������������ϵ��    **\n");
    printf("**      0. exit                **\n");
    printf("*********************************\n");
}
int main()
{
    int input = 0;
    //����ͨѶ¼
    struct Contact con;//con����ͨѶ¼�����������1000��Ԫ�ص�����size
    //��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            MoidfyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            printf("�˳�ͨѶ¼\n");
            break;
        default:
            printf("ѡ�����\n");
            break;
        }
    } while (input);
    return 0;
}