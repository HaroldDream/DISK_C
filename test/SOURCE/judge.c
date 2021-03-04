#include"judge.h"
#include"common.h"
#include "userdata.h"

/************************************************************************
FUNCTION:register_success
DESCRIPTION: �����ж�ע����Ϣ�Ƿ�������ȫ����ȷ
INPUT:*u,*c,*p,*cp
RETURN:�������ͳ���0��1��ע��ɹ�����1��ע��ʧ�ܷ���0
************************************************************************/
int register_success(char* u,char *c, char* p, char* cp)
{
    //?num: 1�û��� 2��ϵ��ʽ 3���� 4ȷ������
    int box1 = 0;    //*�ж��û����Ƿ�����淶
	int box2 = 0;    //*�ж���ϵ��ʽ�Ƿ�����淶
	int box3 = 0;    //*�ж������Ƿ�����淶
	int box4 = 0;    //*�ж��ٴ�ȷ�������Ƿ�����淶

    FILE *fp;

    while (1)
    {
        recover(1);
        recover(2);
        recover(3);
        recover(4);
        judgelength(u,&box1,1);
        judgelength(c,&box2,2);
        judgelength(p,&box3,3);
        judgelength(cp,&box4,4);
        
        if (box1*box2*box3*box4 == 0)
        {
            break;
        }
        else if (box1*box2*box3*box4 == 1)
        {
            if (judge_sameuser(u)== 1)
            {
                break;
            }
            else if (judge_sameuser(u)== 0)
            {
                if (strcmp(p, cp) != 0)
	            {
                    puthz(240+220+25,120+180+4,"�����벻һ��",24,30,RED);
		            break;
	            }
                if ((fp = fopen("data\\UserData.dat","rb+" )) == NULL) //??????????
					{
						closegraph();
						printf("register_success cannot open file fp");
						delay(3000);
						exit(1);
					}
                    input_data(u, c, p);
                    return 1;
            }
        }

    }
    return 0;
}

/*********************************************
FUNCTION:judgelength
DESCRIPTION���жϸ�������򳤶��Ƿ����Ҫ��
INPUT:*str,*box, num
RETURN:��
***********************************************/
void judgelength(char* str, int* box, int num)
{
	switch (num)
    {
    case 1:
        if (strlen(str) > 5 && strlen(str) < 13)
	    {
		    *box = 1 ;
	    }
     	else
      	{
    		*box = 0;
			puthz(240+220+25,120+4,"���Ȳ���",24,30,RED);
	    }
        break;
    case 2:
        if (strlen(str) == 11)
	    {
		    *box = 1 ;
	    }
     	else
      	{
    		*box = 0;
			puthz(240+220+25,120+60+4,"���Ȳ���",24,30,RED);
	    }
        break;
    case 3:
        if (strlen(str) > 7 && strlen(str) < 17)
	    {
		    *box = 1 ;
	    }
     	else
      	{
    		*box = 0;
			puthz(240+220+25,120+120+4,"���Ȳ���",24,30,RED);
	    }
        break;
    case 4:
        if (strlen(str) > 7 && strlen(str) < 17)
	    {
		    *box = 1 ;
	    }
     	else
      	{
    		*box = 0;
	    }
        break;
    
    default:
        break;
    }

}

/*********************************************
FUNCTION:recover
DESCRIPTION���ָ��������ʾ
INPUT: num
RETURN:��
***********************************************/
void recover (int num)
{   
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

	switch (num)
    {
    case 1:
        bar(240+220+20,120,640,120+40); 
        break;
    case 2:
        bar(240+220+20,120+60,640,120+60+40); 
        break;
    case 3:
        bar(240+220+20,120+120,640,120+120+40); 
        break;
    case 4:
        bar(240+220+20,120+180,640,120+180+40); 
        break;
    
    default:
        break;
    }

}

/************************************************************************
FUNCTION:judge_sameuser
DESCRIPTION: �ж��˻��Ƿ��������
INPUT:*new_user
RETURN:�������ͳ���0��1���û������ڷ���0���û��Ѵ��ڷ���1
************************************************************************/

int judge_sameuser(char* new_user)
{
	int len;											  //�û�����
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("data\\UserData.dat", "wb+")) == NULL)//�������ݿ�//??????????????
	{
		closegraph();
		printf("judge_sameuser cannot open file fp");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			closegraph();
			printf("judge_sameuser u malloc wrong");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(u->username, new_user) == 0)
		{
			puthz(240+220+25,120+4,"�û����ظ�",24,30,RED);
			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				closegraph();
				printf("judge_sameuser cannot close fp");
				delay(3000);
				exit(1);
			}
			return 1;
		}
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("judge_sameuser cannot close fp");
		delay(3000);
		exit(1);
	}
	return 0;
}


/************************************************************************
FUNCTION:judge_rightpassword
DESCRIPTION: �ж��û����������Ƿ�ƥ��
INPUT:*name ,*pass
RETURN:�������ͳ���0��1���û���������ƥ�䷵��1���û��������벻ƥ�䷵��0
************************************************************************/
int judge_rightpassword(char* name, char* pass)
{
	int len;												//�û�����
	int i;
	FILE* fp;
	USER* u;
	if ((fp = fopen("Data\\UserData.dat", "rb+")) == NULL)
	{
		closegraph();
		printf("judge_rightpassword cannot open file fp");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / sizeof(USER);
	for (i = 0; i < len; i++)
	{
		if ((u = (USER*)malloc(sizeof(USER))) == NULL)
		{
			closegraph();
			printf("judge_rightpassword u malloc wrong");
			delay(3000);
			exit(1);
		}
		fseek(fp, i * sizeof(USER), SEEK_SET);
		fread(u, sizeof(USER), 1, fp);
		if (strcmp(name, u->username) == 0)//�û���ƥ��
		{
			if (strcmp(pass, u->password) != 0)//���벻��
			{
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//����ƥ��
			{
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				if (fclose(fp) != 0)
				{
					closegraph();
					printf("judge_rightpassword cannot close fp");
					delay(3000);
					exit(1);
				}
				return 1;
				//�л�����
			}
		}
		if (u != NULL)
		{
			free(u);
			u = NULL;
		}
	}
	if (i == len)
	{
		puthz(460+10, 240+12, "�˻�δע��", 16, 17, BLUE);//�ߵ����һλ
	}

	if (u != NULL)
	{
		free(u);
		u = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("judge_rightpassword cannot close fp");
		delay(3000);
		exit(1);
	}
	return 0;
}
