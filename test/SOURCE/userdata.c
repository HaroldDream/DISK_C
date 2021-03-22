#include "common.h"
#include "data.h"

/********************************************
FUNCTION:input_data
DESCRIPTION: �����û���Ϣ
INPUT:username,phone,password
RETURN:��
********************************************/
void input_data(char* username, char* phone, char* password,int mode)
{
	FILE* fp;
	USER* u;
	char nu[3];
	if ((fp = fopen("Data\\UserData.dat", "rb+" )) == NULL)//�������ݿ�
	{
		closegraph();
		printf("cannot open file UserData.dat,input_data");
		delay(3000);
		exit(1);
	}
	if ((u = (USER*)malloc(sizeof(USER))) == NULL)
	{
		closegraph();
		printf("something wrong in USER*u,input_data");
		delay(3000);
		exit(1);
	}
	memset(u,'\0',sizeof(USER));
	strcpy(u->username, username);
	strcpy(u->phone, phone);
	strcpy(u->password, password);
	u->mode = mode;
	fseek(fp, 0, SEEK_END);//��ת���ļ�ĩβ
	fwrite(u, sizeof(USER), 1, fp);//���û���Ϣд���ļ�
	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close UserData.dat,input_data");
		delay(3000);
		exit(1);
	}
} 


