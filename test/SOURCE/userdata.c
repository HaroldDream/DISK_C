#include "common.h"
#include "data.h"

/********************************************
FUNCTION:input_data
DESCRIPTION: 建立用户信息
INPUT:username,phone,password
RETURN:无
********************************************/
void input_data(char* username, char* phone, char* password,int mode)
{
	FILE* fp;
	USER* u;
	char nu[3];
	if ((fp = fopen("Data\\UserData.dat", "rb+" )) == NULL)//建立数据库
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
	fseek(fp, 0, SEEK_END);//跳转至文件末尾
	fwrite(u, sizeof(USER), 1, fp);//把用户信息写入文件
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


