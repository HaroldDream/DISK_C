#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //ʳ���û�
{
    char username[15];
    char password[15];
    char phone[20];
    int mode;
}USER;

typedef struct supplier //��Ӧ��
{
    char name[15];  //����
    char phone[12]; //�绰
}SPL;

typedef struct foodinfo //ʳ��  
{
    char name[7];  //����
    char type[7];  //���࣬���߲ˡ�����
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


#endif