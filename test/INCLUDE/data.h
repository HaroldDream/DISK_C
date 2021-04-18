#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //ʳ���û�
{
    char username[15];
    char password[15];
    char phone[20];
    int mode;
}USER;

typedef struct foodinfo //ʳ��  
{
    char name[7];  //����
    char type[7];  //����
    char s[11];  //��Ӧ��
    char p[5];    //�۸�
    char num[8];    //����
    char est[8];   //Ԥ������
    char unit[3];  //��λ
    char state[2]; //״̬:0δ�ɹ�,1�Ѳɹ�,2�������,3���ڷ���,4ʳ�����
    char d1[7]; //��Ӧ�̷���ʱ�䣨�ɹ�ʱ�䣩
    //char r1[7]; //���ڲֿ��ջ�ʱ��
    //char d2[7]; //���ڲֿⷢ��ʱ��
    //char r2[7]; //ʳ���ջ�ʱ��

}FD;

typedef struct logisticinfo //������Ϣ
{
    char location[15]; //��ǰλ��
    char state[15]; //��ǰ״̬
}LGTC;

typedef struct foodfc //ʳ�ģ�Ԥ�⣩  
{
    char name[7];  //����
    char type[7];  //����
    char unit[3];  //��λ
    char state[2]; //״̬

    char num[7]; //�ϱ�
    char d8[7]; //Ԥ��
    char dis[7]; //����

    char d1[7];//ǰ��������
    char d2[7];
    char d3[7];
    char d4[7];
    char d5[7];
    char d6[7];
    char d7[7];
}FF;

typedef struct CKfoodinfo //�ֿ�ʳ��  
{
    char cknum[9]; //�����
    char name[7];  //����
    char type[7];  //���࣬���߲ˡ�����
    char typenum[2]; //�����Ӧ���
    char namenum[3]; //���ƶ�Ӧ���
    char s[11];  //��Ӧ��
    char num[8];    //����
    char unit[3];  //��λ
    char state[2]; //״̬:0δ�ɹ�,1�Ѳɹ�,2���ﵫδ���,3�������,4���ڷ���,5ʳ�����

    char r1[12]; //���ڲֿ��ջ�ʱ��
    char d2[12]; //���ڲֿⷢ��ʱ��
    char r2[12]; //ʳ���ջ�ʱ��

}CKFD;

typedef struct supplierinfo //��Ӧ��gys
{
    char name[15];  //����
    char phone[12]; //�绰
    FD food[20];    //���۵�ʳ��
}SPL;

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

#endif