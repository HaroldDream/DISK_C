#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //ʳ���û�
{
    char username[15];
    char password[15];
}USER;

typedef struct admininfo //���ڹ���Ա�û�
{
    char username[15];
    char password[15];
}ADMIN;

typedef struct foodinfo //ʳ��  
{
    char name[15];  //����
    char type[10];  //���࣬���߲ˡ�����
    int weight;   //����
}FOOD;

typedef struct supplierinfo //��Ӧ��
{
    char name[15];  //����
    char phone[12]; //�绰
}