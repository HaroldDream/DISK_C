#include"judge.h"
#include"common.h"
#include "userdata.h"

/************************************************************************
FUNCTION:register_success
DESCRIPTION: 用来判断注册信息是否输入完全和正确
INPUT:*u,*c,*p,*cp
RETURN:返回整型常数0或1，注册成功返回1，注册失败返回0
************************************************************************/
int register_success(char* u,char *c, char* p, char* cp)
{
    //?num: 1用户名 2联系方式 3密码 4确认密码
    int box1 = 0;    //*判断用户名是否输入规范
	int box2 = 0;    //*判断联系方式是否输入规范
	int box3 = 0;    //*判断密码是否输入规范
	int box4 = 0;    //*判断再次确认密码是否输入规范

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
                    puthz(240+220+25,120+180+4,"与密码不一致",24,30,RED);
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
DESCRIPTION：判断各个输入框长度是否符合要求
INPUT:*str,*box, num
RETURN:无
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
			puthz(240+220+25,120+4,"长度不符",24,30,RED);
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
			puthz(240+220+25,120+60+4,"长度不符",24,30,RED);
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
			puthz(240+220+25,120+120+4,"长度不符",24,30,RED);
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
DESCRIPTION：恢复输入框提示
INPUT: num
RETURN:无
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
DESCRIPTION: 判断账户是否出现重名
INPUT:*new_user
RETURN:返回整型常数0或1，用户不存在返回0，用户已存在返回1
************************************************************************/

int judge_sameuser(char* new_user)
{
	int len;											  //用户个数
	int i;
	FILE* fp;
	USER* u = NULL;
	if ((fp = fopen("data\\UserData.dat", "wb+")) == NULL)//建立数据库//??????????????
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
			puthz(240+220+25,120+4,"用户名重复",24,30,RED);
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
DESCRIPTION: 判断用户名和密码是否匹配
INPUT:*name ,*pass
RETURN:返回整型常数0或1，用户名和密码匹配返回1，用户名和密码不匹配返回0
************************************************************************/
int judge_rightpassword(char* name, char* pass)
{
	int len;												//用户个数
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
		if (strcmp(name, u->username) == 0)//用户名匹配
		{
			if (strcmp(pass, u->password) != 0)//密码不配
			{
				if (u != NULL)
				{
					free(u);
					u = NULL;
				}
				break;
			}
			else if (strcmp(pass, u->password) == 0)//密码匹配
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
				//切换界面
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
		puthz(460+10, 240+12, "账户未注册", 16, 17, BLUE);//走到最后一位
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
