#ifndef _JUDGE_H_
#define _JUDGE_H_

int register_success(char* u,char *c, char* p, char* cp,int m); //*�����ж�ע����Ϣ�Ƿ�������ȫ����ȷ
void judgelength(char* str, int* box, int num); //*�жϸ�������򳤶��Ƿ����Ҫ��
void recover (int num); //*�ָ��������ʾ
int judge_sameuser(char* new_user); //*�ж��˻��Ƿ��������
int judge_rightpassword(char* name, char* pass, int mode);//*�ж��û����������Ƿ�ƥ��


#endif