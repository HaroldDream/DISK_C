#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //ʳ���û�
{
    char username[15];
    char password[15];
}UESR;

typedef struct admininfo //���ڹ���Ա�û�
{
    char username[15];
    char password[15];
}ADMIN;

typedef struct foodinfo //ʳ��  
{
    char name[15];  //����
    char type[10];  //���࣬���߲ˡ�����
    int weight;     //����
    TIME time; 
}FD;

typedef struct supplierinfo //��Ӧ��
{
    char name[15];  //����
    char phone[12]; //�绰
    FD food[20];    //���۵�ʳ��
}SPL;

typedef struct timeinfo //ʱ����Ϣ
{
    char dlv1[11]; //��Ӧ�̷���ʱ��
    char rcv1[11]; //���ڲֿ��ջ�ʱ��
    char dlv2[11]; //���ڲֿⷢ��ʱ��
    char rcv2[11]; //ʳ���ջ�ʱ��
}TIME; 

typedef struct menuinfo //����˵���Ϣ
{
    char name[15]; //����
    char type[15]; //���࣬��������ˡ��زġ���ɫ��
    FD food;
}MN;

typedef struct canteeninfo //ʳ����Ϣ
{
    char name[15];   //ʳ������
    FD food[20];     //ʳ�Ŀ��
    MN menu[20];     //����˵�
}CTN;

typedef struct warehouse //�ֿ���Ϣ
{
    FD food[20];
}
