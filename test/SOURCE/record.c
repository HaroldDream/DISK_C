#include <common.h>
#include "database.h"
#include "record.h"

/************************************************************************
FUNCTION:kucunrd
DESCRIPTION: ��ȡ�����Ϣ
INPUT:recent,*all��type����
RETURN:��
************************************************************************/
void kucunrd(int recent,int *all,int type)
{
    FILE* fp;
	CKFD* ckfood;
	int len = 0,i,k,j,namemax,l;
	int t = 0,m;//tΪ��ǰ��ȡ����-1;
	int ln[10];//��¼ÿ�������ļ�����
	int dqwj,dqt;
	char n[5];
	char rt[5];
    char ap[5];
	char usee[40]="\0";
	char nowtype[2]; //������ת���ɵ��ַ�
	char nowname[2];
    
	switch (type)
	{
	case 1:
		namemax = 9;
		break;
	case 2:
		namemax = 6;
		break;
	case 3:
		namemax = 5;
		break;
	case 4:
		namemax = 5;
		break;
	case 5:
		namemax = 6;
		break;
	case 6:
		namemax = 4;
		break;
	default:
		break;
	}

	for(m=1;m < namemax+1;m++)
	{
		itoa(type,nowtype,10);
		itoa(m,nowname,10);
		sprintf(usee,"data\\storg\\%stype\\%sname.dat",nowtype,nowname);
		if ((fp = fopen(usee,"rt" )) == NULL)
		{
			closegraph();
			printf("cannot open file %s,kucunrd",usee);
			delay(3000);
			exit(1);
		}
		if ((ckfood = (CKFD*)malloc(sizeof(CKFD))) == NULL)
		{
			closegraph();
			printf("something wrong in CKFD* ckfood,kucunrd");
			delay(3000);
			exit(1);
		}
		fseek(fp, 0, SEEK_END);
		ln[m-1] = ftell(fp) / sizeof(CKFD);
		len = ftell(fp) / sizeof(CKFD)+len;
		if (ckfood != NULL)
		{
			free(ckfood);
			ckfood = NULL;
		}
		if (fclose(fp) != 0)
		{
			closegraph();
			printf("\n cannot close file %s,kucunrd",usee);
			delay(3000);
			exit(1);
		}
	}
	j = (recent-1)*12;
	if (recent*12 <= len)
	{
		k = 12;
	}
	else
	{
		k = len-j;
	}
	dqt = j;
	for(dqwj = 1;dqwj < namemax+1;dqwj++)
	{
		if(dqt >= ln[dqwj -1])
		{
			dqt = dqt-ln[dqwj -1];
		}
		else if(dqt < ln[dqwj -1])
		{
			break;
		}
	}
    for(m=dqwj;m < namemax+1;m++)
	{ 
		itoa(type,nowtype,10);
		itoa(m,nowname,10);
		sprintf(usee,"data\\storg\\%stype\\%sname.dat",nowtype,nowname);
		if ((fp = fopen(usee,"rt" )) == NULL)
		{
			closegraph();
			printf("cannot open file %s,kucunrd",usee);
			delay(3000);
			exit(1);
		}
		if ((ckfood = (CKFD*)malloc(sizeof(CKFD))) == NULL)
		{
			closegraph();
			printf("something wrong in CKFD* ckfood,kucunrd");
			delay(3000);
			exit(1);
		}
		fseek(fp, 0, SEEK_END);
		l = ftell(fp) / sizeof(CKFD);
		memset(ckfood,'\0',sizeof(CKFD));
		fseek(fp,dqt* sizeof(CKFD),SEEK_SET);
		for(i=t;i<k && dqt<l;i++)
		{
			fread(ckfood, sizeof(CKFD), 1, fp);
			setcolor(BLUE);
			outtextxy(156,58+30*(i+1),ckfood->cknum);
			puthz(272,58+30*(i+1),ckfood->name,16,20,BLUE);
			puthz(350,58+30*(i+1),ckfood->unit,16,20,BLUE);
			outtextxy(407,58+30*(i+1),ckfood->num);
			puthz(535,58+30*(i+1),ckfood->r1,16,18,BLUE);
			dqt = dqt+1;
			memset(ckfood,'\0',sizeof(CKFD));
			fseek(fp,dqt* sizeof(CKFD),SEEK_SET);
		}
		if (ckfood != NULL)
		{
			free(ckfood);
			ckfood = NULL;
		}
		if (fclose(fp) != 0)
		{
			closegraph();
			printf("\n cannot close file %s,kucunrd",usee);
			delay(3000);
			exit(1);
		}
		t = i;
		if(t == k)
		{
			break;
		}
		else
		{
			dqt = 0;
		}
		
	}
	if(len%12==0)
	{
		*all=len/12;
	}
	else if(len%12!=0)
	{
		*all=len/12+1;
	}
	itoa(recent,rt,10);
	itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
	outtextxy(390,450,ap);
}
/************************************************************************
FUNCTION:storagerd
DESCRIPTION: ��ȡ�����Ϣ
INPUT:recent,*all
RETURN:��
************************************************************************/
void storagerd(int recent,int *all)
{
    FILE* fp;
	FD* food;
	int len = 0,k,i,j,statenow;
	char n[5];
	char rt[5];
    char ap[5];
   

	if ((fp = fopen("Data\\PLIST.dat", "rt" )) == NULL)
	{
		closegraph();
		printf("cannot open file PLIST.dat,storagerd");
		delay(3000);
		exit(1);
	}
	if ((food = (FD*)malloc(sizeof(FD))) == NULL)
	{
		closegraph();
		printf("something wrong in FD* food,storagerd");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FD)+1);
    j = (recent-1)*12;
	if (recent*12 <= len)
	{
		k = 12;
	}
	else
	{
		k = len-j;
	}
	
	for(i=0;i<k;i++)
	{
	    memset(food,'\0',sizeof(FD));
	    fseek(fp,(j+i) * (sizeof(FD)+1),SEEK_SET);
	    fread(food, sizeof(FD), 1, fp);
	    itoa(j+i+1,n,10);
	    outtextxy(155,58+30*(i+1),n);
	    puthz(223,58+30*(i+1),food->name,16,18,BLUE);
		setcolor(BLUE);
	    outtextxy(318,58+30*(i+1),food->num);
		statenow=atoi(food -> state);
		if(statenow == 2)
		{
			puthz(440,58+30*(i+1),"δ���",16,18,RED);
		}
		else if(statenow == 3)
		{
			puthz(440,58+30*(i+1),"�����",16,18,BLUE);
			//!!!!!!!!!!!!!!!!
		}
	}
	if (food != NULL)
	{
		free(food);
		food = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close PLIST.dat,storagerd");
		delay(3000);
		exit(1);
	}
	if(len%12==0)
    {
        *all=len/12;
    }
    else if(len%12!=0)
    {
        *all=len/12+1;
    }
	itoa(recent,rt,10);
    itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
    outtextxy(390,450,ap);
}

/************************************************************************
FUNCTION:storage_in
DESCRIPTION: �������
INPUT:*f
RETURN:��
************************************************************************/
void storage_in(FD *f)
{
	FILE *fp;
	CKFD *ckf;
	FF *foodc;
	char code[5];
	char usee[40]="\0";
	char bhao[9]="\0";
	int tpnum,nmnum,len;
	long bianhao;

	time_t timep;//�ļ�ʱ��
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    sprintf(stime,"%d.%d %d:%d",1+p->tm_mon,p->tm_mday,p->tm_hour-4,p->tm_min);
	
	if ((ckf = (CKFD*)malloc(sizeof(CKFD))) == NULL)
	{
		closegraph();
		printf("something wrong in CKFD* ckf,storage_in");
		delay(3000);
		exit(1);
	}
	memset(ckf,'\0',sizeof(CKFD));
	strcpy(ckf->name,f->name);
	strcpy(ckf->type,f->type);
	strcpy(ckf->s,f->s);
	strcpy(ckf->num,f->num);
	strcpy(ckf->unit,f->unit);
	strcpy(ckf->state,f->state);
	strcpy(ckf->r1,stime);

    searchtype(f,ckf,foodc,0);
	tpnum = atoi(ckf->typenum);
	nmnum = atoi(ckf->namenum);
	sprintf(usee,"data\\storg\\%stype\\%sname.dat",ckf->typenum,ckf->namenum);
    if ((fp = fopen(usee,"rt+" )) == NULL)
    {
        closegraph();
        printf("cannot open file storage,storage_in");
        delay(3000);
        exit(1);
    }
	fseek(fp,0,SEEK_END);
	len = ftell(fp) / sizeof(CKFD);
	sprintf(bhao,"%d0%d",tpnum,nmnum);
	bianhao = atoi(bhao)*100+len;
	itoa(bianhao,bhao,10);
	strcpy(ckf->cknum,bhao);
	fwrite(ckf, sizeof(CKFD), 1, fp);
	if (ckf!= NULL)
	{
		free(ckf);
		ckf = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close storage,storage_in");
		delay(3000);
		exit(1);
	}

}

/************************************************************************
FUNCTION:ruku
DESCRIPTION: �������
INPUT:i,recent
RETURN:��
************************************************************************/
void ruku(int i,int recent)
{
	FILE* fp;
	FD* food;
	int j;

	time_t timep;//�ļ�ʱ��
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    sprintf(stime,"%d.%d %d:%d",1+p->tm_mon,p->tm_mday,p->tm_hour-4,p->tm_min);

	if ((fp = fopen("Data\\PLIST.dat", "rt+" )) == NULL)
	{
		closegraph();
		printf("cannot open file PLIST.dat,ruku");
		delay(3000);
		exit(1);
	}
	if ((food = (FD*)malloc(sizeof(FD))) == NULL)
	{
		closegraph();
		printf("something wrong in FD* food,ruku");
		delay(3000);
		exit(1);
	}
	memset(food,'\0',sizeof(FD));
	j = (recent-1)*12+i-1;
	fseek(fp, j*(sizeof(FD)+1), SEEK_SET);
	fread(food, sizeof(FD), 1, fp);
	if(!strcmp(food -> state,"2"))
	{
		strcpy(food -> state ,"3");
		fseek(fp, j*(sizeof(FD)+1), SEEK_SET);
	    fwrite(food, sizeof(FD), 1, fp);
        storage_in(food);
		setfillstyle(SOLID_FILL,WHITE);
        bar(457,58+30*i,457+60,58+30*i+18);
		puthz(457,58+30*i,"�����",16,18,BLUE);
		setcolor(BLUE);
	    outtextxy(547,58+30*i,stime);
	}
	if (food != NULL)
	{
		free(food);
		food = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close PLIST.dat,ruku");
		delay(3000);
		exit(1);
	}
}

/************************************************************************
FUNCTION:logisticsrd
DESCRIPTION: ��ȡ����״̬��Ϣ
INPUT:recent,*all��codeģʽ��type����
RETURN:��
************************************************************************/
void logisticsrd(int recent,int *all,int code,int type,int i)
{
	char nowcode[2]; //nowcode��1ΪУ������0ΪУ������
	char nowtype[2]; //������ת���ɵ��ַ�
	FILE* fp;
	int len = 0,j,p;
	int k;
	char gys[11];//��Ӧ��
	char wlzt[36];//����״̬
	char n[5];//���
	char rt[5];//��ǰҳ
    char ap[5];//����ҳ
	char usee[40]="\0";
	itoa(code,nowcode,10);
	itoa(type,nowtype,10);
	if(code == 0)
	{
		strcpy(nowcode,"0");
	}
	sprintf(usee,"data\\logis\\%szt\\%slg.dat",nowcode,nowtype);
	if ((fp = fopen(usee,"rt+" )) == NULL)
	{
		closegraph();
		printf("cannot open file data\\logis,logisticsrd");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(gys)+sizeof(wlzt)+1);
	if(i>len) 
	{
		i = len;
	}
    j = (recent-1)*11;
	if (recent*11 <= len)
	{
		k = 11;
	}
	else
	{
		k = len-j;
	}

	for(p=0 ; p < k && p <=(i-j); p++)
	{
		fseek(fp,(j+p) * (sizeof(gys)+sizeof(wlzt)+1),SEEK_SET);
		fread(gys, sizeof(gys), 1, fp);
		fread(wlzt, sizeof(wlzt), 1, fp);
		itoa(j+p+1,n,10);
		outtextxy(160,88+30*(p+1),n);//������
		puthz(200,88+30*(p+1),gys,16,18,BLUE);
		puthz(320,88+30*(p+1),wlzt,16,18,BLUE);
	}
	
	
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close file data\\logis,logisticsrd");
		delay(3000);
		exit(1);
	}
	if(len%11==0)
    {
        *all=len/11;
    }
    else if(len%11!=0)
    {
        *all=len/11+1;
    }
	itoa(recent,rt,10);
    itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
    outtextxy(390,450,ap);
            
}

/************************************************************************
FUNCTION:countline
DESCRIPTION: �����������״̬����
INPUT:type(������)
RETURN:����
************************************************************************/
int countline(int type)
{
	char nowtype[2]; //������ת���ɵ��ַ�
	FILE* fp;
	int len = 0;
	char usee[40]="\0";
	char gys[11];//��Ӧ��
	char wlzt[36];//����״̬
	itoa(type,nowtype,10);
	sprintf(usee,"data\\logis\\1zt\\%slg.dat",nowtype);
	if ((fp = fopen(usee,"rt" )) == NULL)
	{
		closegraph();
		printf("cannot open file %s,countline",usee);
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(gys)+sizeof(wlzt)+1);
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close file %s,countline",usee);
		delay(3000);
		exit(1);
	}
	return len;
}

/************************************************************************
FUNCTION:shouhuo
DESCRIPTION: �ջ����ݱ�д
INPUT: t��¼���������������������
RETURN:none
************************************************************************/
void shouhuo(int *t)
{
	FILE*fp,*fp2;
	FD* food;
	FF *foodc;
	CKFD* ckfood;
	//SH *shxx;
	int len,i,j,type,mode,opt;  //type:������,mode:��ʾ��״̬,opt:�Ƿ��ظ�
	char atype[3];
	char gys[10][11];
	int ak[6] = {0,0,0,0,0,0};//akΪ����������
	//char n[5];�������

	if ((fp = fopen("Data\\PLIST.dat", "rt+" )) == NULL)
	{
		closegraph();
		printf("cannot open file Data\\PLIST.dat,shouhuo ");
		delay(3000);
		exit(1);
	}
	if ((fp2 = fopen("Data\\tdshou.dat", "wt+" )) == NULL)
	{
		closegraph();
		printf("cannot open file Data\\todayshou.dat,shouhuo ");
		delay(3000);
		exit(1);
	}
	if ((food = (FD*)malloc(sizeof(FD))) == NULL)
	{
		closegraph();
		printf("something wrong in FD* food,shouhuo");
		delay(3000);
		exit(1);
	}
	if ((ckfood = (CKFD*)malloc(sizeof(CKFD))) == NULL)
	{
		closegraph();
		printf("something wrong in CKFD* food,shouhuo");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp) / (sizeof(FD)+1);
	for(type = 1;type < 7;type++)
    {
        ak[type-1] = countline(type);

        if(*(t+type-1)+1 >= ak[type-1]) //�ж����������Ƿ����
        {
            mode = 2;
        }
        else
        {
            mode = 1;
        }
		memset(gys,'\0',sizeof(gys)); //��Ÿ������ȡ���Ĺ�Ӧ��
		for(i=0;i<len;i++)
		{
			opt = 1;
			memset(food,'\0',sizeof(FD));
			memset(ckfood,'\0',sizeof(CKFD));
			//memset(shxx,'\0',sizeof(SH));
			fseek(fp,i * (sizeof(FD)+1),SEEK_SET);
			fread(food, sizeof(FD), 1, fp);
			searchtype(food,ckfood,foodc,0);
			itoa(type,atype,10);

			if(!strcmp(ckfood ->typenum,atype))
			{			
				if(mode == 2)
				{
					strcpy(food -> state ,"2"); //�ı�״̬��2Ϊ�ѵ���δ���
					fseek(fp,i * (sizeof(FD)+1),SEEK_SET);
					fwrite(food, sizeof(FD), 1, fp);
				}
				for(j=0;j<10 && strcmp(gys[j],"\0");j++)
				{
					if(!strcmp(gys[j],food->s))
					{
						opt = 0;
					}
				}
				
				if(opt)
				{
					strcpy(gys[j],food -> s);
					// strcpy(shxx->type,food -> type);
					// strcpy(shxx->s,food -> s);
					// strcpy(shxx->state,food -> state);
					fseek(fp2,0,SEEK_END);
					//fwrite(shxx, sizeof(SH), 1, fp2);
					fwrite(food->type, sizeof(food->type), 1, fp2);
					fseek(fp2,0,SEEK_END);
					fwrite(food->s, sizeof(food->s), 1, fp2);
					fseek(fp2,0,SEEK_END);
					fwrite(food->state, sizeof(food->state), 1, fp2);
					// fseek(fp2,0,SEEK_END);
					// fputc('\n',fp2);
				}
			}
		}   
    }
	
	if (food != NULL)
	{
		free(food);
		food = NULL;
	}
	if (ckfood != NULL)
	{
		free(ckfood);
		ckfood = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close file Data\\PLIST.dat,shouhuo");
		delay(3000);
		exit(1);
	}
	if (fclose(fp2) != 0)
	{
		closegraph();
		printf("\n cannot close file Data\\todayshou.dat,shouhuo");
		delay(3000);
		exit(1);
	}
}

/************************************************************************
FUNCTION:searchtype
DESCRIPTION: ��ѯ������
INPUT:f,ckf,fc,i(0Ϊ�ɹ����ֿ�1Ϊ����)
RETURN:��
************************************************************************/
void searchtype(FD *f,CKFD *ckf,FF* fc,int i)
{
	if (i)
	{
		strcpy(f ->name,fc->name);
		strcpy(f ->type,fc->type);
	}
	if(!strcmp(f ->type,"�߲�"))
	{
		strcpy(ckf->typenum,"1");
		if(!strcmp(f ->name,"�ײ�"))
		{
			strcpy(ckf->namenum,"1");			
		}
		if(!strcmp(f ->name,"���"))
		{
			strcpy(ckf->namenum,"2");		
		}
		if(!strcmp(f ->name,"�²�"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"������"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"���ܲ�"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"6");			
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"7");			
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"8");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"9");		
		}
	}
	if(!strcmp(f ->type,"����"))
	{
		strcpy(ckf->typenum,"2");
		if(!strcmp(f ->name,"���Ｙ"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"���廨"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"������"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"ţ��"))
		{
			strcpy(ckf->namenum,"4");		
		}
		if(!strcmp(f ->name,"������"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"6");		
		}
	}
	if(!strcmp(f ->type,"ˮ��"))
	{
		strcpy(ckf->typenum,"3");
		if(!strcmp(f ->name,"�����"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"��Ϻ"))
		{
			strcpy(ckf->namenum,"5");			
		}
	}
	if(!strcmp(f ->type,"����"))
	{
		strcpy(ckf->typenum,"4");
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"���"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"Ƥ��"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"��ţ��"))
		{
			strcpy(ckf->namenum,"5");		
		}
	}
	if(!strcmp(f ->type,"����"))
	{
		strcpy(ckf->typenum,"5");
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"1");			
		}
		if(!strcmp(f ->name,"�Ͼ�"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"��"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"ʳ��"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"6");		
		}
	}
	if(!strcmp(f ->type,"������"))
	{
		strcpy(ckf->typenum,"6");
		if(!strcmp(f ->name,"����"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"���"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"��ĸ��"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"ʳ����"))
		{
			strcpy(ckf->namenum,"4");		
		}
	}
	
}

/************************************************************************
FUNCTION:shourd
DESCRIPTION: ��ȡ�ջ���Ϣ
INPUT:recent,*all
RETURN:��
************************************************************************/
void shourd(int recent,int *all)
{
    FILE* fp;
	SH *shxx;
	int len = 0,k,i,j,statenow;
	// int xdw;//xswΪÿ������ռ�ô�С
	// char tp[7];  //���࣬���߲ˡ�����
    // char gys[11];  //��Ӧ��
	// char zt[2];
	char rt[5];
    char ap[5];
	if ((fp = fopen("Data\\tdshou.dat", "rt" )) == NULL)
	{
		closegraph();
		printf("cannot open file PLIST.dat,shourd");
		delay(3000);
		exit(1);
	}
	if ((shxx = (SH*)malloc(sizeof(SH))) == NULL)
	{
		closegraph();
		printf("something wrong in SH *shxx,shrd");
		delay(3000);
		exit(1);
	}
	//xdw = sizeof(tp)+sizeof(gys)+sizeof(zt)+1;
	fseek(fp, 0, SEEK_END);
    //len = ftell(fp) / xdw;
	len = ftell(fp) / sizeof(SH);
    j = (recent-1)*12;
	if (recent*12 <= len)
	{
		k = 12;
	}
	else
	{
		k = len-j;
	}
	
	for(i=0;i<k;i++)
	{
		memset(shxx,'\0',sizeof(SH));
	    fseek(fp,(j+i) * sizeof(SH),SEEK_SET);
	    fread(shxx, sizeof(SH), 1, fp);
	    // fread(tp, sizeof(tp), 1, fp);
		// fread(gys, sizeof(gys), 1, fp);
		// fread(zt, sizeof(zt), 1, fp);
		// puthz(275,58+30*(i+1),tp,16,18,BLUE);
	    // puthz(370,58+30*(i+1),gys,16,18,BLUE);
		puthz(270,58+30*(i+1),shxx->type,16,18,BLUE);
	    puthz(358,58+30*(i+1),shxx->s,16,18,BLUE);
		setcolor(BLUE);
		statenow=atoi(shxx->state);
		if(statenow == 2 ||statenow == 3)
		{
			puthz(470,58+30*(i+1),"��ǩ��",16,18,BLUE);
		}
		else if (statenow == 1)
		{
			puthz(470,58+30*(i+1),"δǩ��",16,18,RED);
		}
	}

	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close todayshou.dat,shourd");
		delay(3000);
		exit(1);
	}
	if(len%12==0)
    {
        *all=len/12;
    }
    else if(len%12!=0)
    {
        *all=len/12+1;
    }
	itoa(recent,rt,10);
    itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
    outtextxy(390,450,ap);
}

/************************************************************************
FUNCTION:chukurd
DESCRIPTION: ��ȡ������Ϣ
INPUT:recent,*all,ctn(�������)
RETURN:��
************************************************************************/
void chukurd(int recent,int *all,int ctn)
{
    FILE* fp;
	FF* foodc;
	int len = 0,k,i,j,statenow;
	char rt[5];
    char ap[5];
	char usee[40]="\0";

	/*
	 time_t timep;//�ļ�ʱ��
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    if (p->tm_mon < 10)
    {
        if (p->tm_mday < 10)
        {
            sprintf(stime,"0%d0%d",1+p->tm_mon,p->tm_mday);   
        }
        else 
        {
            sprintf(stime,"0%d%d",1+p->tm_mon,p->tm_mday);
        }
    }
    else
    {
        if (p->tm_mday < 10)
        {
            sprintf(stime,"%d0%d",1+p->tm_mon,p->tm_mday);   
        }
        else 
        {
            sprintf(stime,"%d%d",1+p->tm_mon,p->tm_mday);
        }
    }
    */
	switch (ctn)
	{
	case 1:
		puthz(253,88,"�پ�԰",16,20,BLUE);
		break;
	case 2:
		puthz(253,88,"��԰ʳ��",16,20,BLUE);
		break;
	case 3:
		puthz(253,88,"��Էʳ��",16,20,BLUE);
		break;
	case 4:
		puthz(253,88,"ѧ��ʳ��",16,20,BLUE);
		break;
	default:
		break;
	}
	//sprintf(usee,"data\\canteen\\ct%d\\%sp.dat",ctn,stime);
	sprintf(usee,"data\\canteen\\ct%d\\FLIST.dat",ctn);
	if ((fp = fopen(usee, "rt" )) == NULL)
	{
		closegraph();
		printf("cannot open file %s,chukurd",usee);
		delay(3000);
		exit(1);
	}
	if ((foodc = (FF*)malloc(sizeof(FF))) == NULL)
	{
		closegraph();
		printf("something wrong in FF* foodc,chukurd");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FF)+1);
    j = (recent-1)*9;
	if (recent*9 <= len)
	{
		k = 9;
	}
	else
	{
		k = len-j;
	}
	
	for(i=0;i<k;i++)
	{
	    memset(foodc,'\0',sizeof(FF));
	    fseek(fp,(j+i) * (sizeof(FF)+1),SEEK_SET);
	    fread(foodc, sizeof(FF), 1, fp);
		puthz(200,118+30*(i+1),foodc->type,16,20,BLUE);
        puthz(312,118+30*(i+1),foodc->name,16,20,BLUE);
        puthz(403,118+30*(i+1),foodc->unit,16,20,BLUE);
		setcolor(BLUE);
	    outtextxy(510,118+30*(i+1),foodc->dis);
	}
	if (foodc != NULL)
	{
		free(foodc);
		foodc = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close file %s,chukurd",usee);
		delay(3000);
		exit(1);
	}
	if(len%9==0)
    {
        *all=len/9;
    }
    else if(len%9!=0)
    {
        *all=len/9+1;
    }
	itoa(recent,rt,10);
    itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
    outtextxy(390,450,ap);
}
/************************************************************************
FUNCTION:chuku
DESCRIPTION: ���ݳ���
INPUT:ctn(�������)
RETURN:��
************************************************************************/
void chuku(int ctn)
{
    FILE* fp;
	FILE* fp2;
	FF* foodc;
	FD *f;
	CKFD *ckf;
	int len = 0,len2,i,j;
	int cksy,chusy;//��ǰ��¼�ֿ�ʣ��������������ʣ��
	char usee1[40]="\0";
	char usee2[40]="\0";
	sprintf(usee1,"data\\canteen\\ct%d\\FLIST.dat",ctn);
	if ((fp = fopen(usee1, "rt+" )) == NULL)
	{
		closegraph();
		printf("cannot open file %s,chuku",usee1);
		delay(3000);
		exit(1);
	}
	if ((foodc = (FF*)malloc(sizeof(FF))) == NULL)
	{
		closegraph();
		printf("something wrong in FF* foodc,chuku");
		delay(3000);
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FF)+1);
	
	for(i=0;i<len;i++)
	{
	    memset(foodc,'\0',sizeof(FF));
	    fseek(fp,i* (sizeof(FF)+1),SEEK_SET);
	    fread(foodc, sizeof(FF), 1, fp);
		chusy = atoi(foodc->dis);
		searchtype(f,ckf,foodc,1);
		sprintf(usee2,"data\\storg\\%stype\\%sname.dat",ckf->typenum,ckf->namenum);
		if ((fp2 = fopen(usee2, "rt+" )) == NULL)
		{
			closegraph();
			printf("cannot open file %s,chuku",usee2);
			delay(3000);
			exit(1);
		}
		fseek(fp2, 0, SEEK_END);
    	len2 = ftell(fp2) / sizeof(CKFD);
		for(j=0;j<len2 && chusy!=0;j++)
		{
			fseek(fp2,j* sizeof(CKFD),SEEK_SET);
	    	fread(ckf, sizeof(CKFD), 1, fp2);
			cksy = atoi(ckf->num);
			if(cksy >= chusy)
			{
				cksy = cksy-chusy;
				chusy = 0;
			}
			else
			{
				chusy = chusy-cksy;
				cksy = 0;
			}
			itoa(cksy,ckf->num,10);
			fseek(fp2,j* sizeof(CKFD),SEEK_SET);
	    	fwrite(ckf, sizeof(CKFD), 1, fp2);
		}
		//!!!!!!!!��治�㵯��
		if (fclose(fp2) != 0)
		{
			closegraph();
			printf("\n cannot close file %s,chuku",usee2);
			delay(3000);
			exit(1);
		}
		strcpy(foodc->state,"4");
		fseek(fp,i* (sizeof(FF)+1),SEEK_SET);
	    fwrite(foodc, sizeof(FF), 1, fp);
	}
	if (f != NULL)
	{
		free(f);
		f = NULL;
	}
	if (ckf != NULL)
	{
		free(ckf);
		ckf = NULL;
	}
	if (foodc != NULL)
	{
		free(foodc);
		foodc = NULL;
	}
	if (fclose(fp) != 0)
	{
		closegraph();
		printf("\n cannot close file %s,chuku",usee1);
		delay(3000);
		exit(1);
	}	
}
/************************************************************************
FUNCTION:ckmanage
DESCRIPTION: ������
INPUT:��¼ȱ�����࣬��¼ȱ������
RETURN:��
************************************************************************/
void ckmanage(char *type,char* name)
{
    FILE* fp;
	FILE* fp2;
	CKFD* ckfood;
	int len = 0,namemax,m,i,j;
	int cksy,sum;//��ǰ��¼�ֿ�ʣ����������
	char usee[40]="\0";
	char useenew[40]="\0";
	int typenum;

    for(typenum = 1;typenum < 7;typenum++)
	{
		switch (typenum)
		{
		case 1:
			namemax = 9;
			break;
		case 2:
			namemax = 6;
			break;
		case 3:
			namemax = 5;
			break;
		case 4:
			namemax = 5;
			break;
		case 5:
			namemax = 6;
			break;
		case 6:
			namemax = 4;
			break;
		default:
			break;
		}
		for(m=1;m < namemax+1;m++)
		{
			sprintf(usee,"data\\storg\\%dtype\\%dname.dat",typenum,m);
			if ((fp = fopen(usee,"rt+" )) == NULL)
			{
				closegraph();
				printf("cannot open file %s,kcmanage",usee);
				delay(3000);
				exit(1);
			}
			if ((ckfood = (CKFD*)malloc(sizeof(CKFD))) == NULL)
			{
				closegraph();
				printf("something wrong in CKFD* ckfood,kcmanage");
				delay(3000);
				exit(1);
			}
			fseek(fp, 0, SEEK_END);
			len = ftell(fp) / sizeof(CKFD);
			sum = 0;
			for(i=0;i<len;i++)
			{
				memset(ckfood,'\0',sizeof(CKFD));
				fseek(fp,i* sizeof(CKFD),SEEK_SET);
				fread(ckfood, sizeof(CKFD), 1, fp);
				cksy = atoi(ckfood->num);
				sum = sum + cksy;
				if(cksy == 0)
				{
					m = m-1; //������˸��ļ�
					break;
				}			
			}
			if(cksy == 0)//ɾ��������¼���½��ļ�д����˸�����Ϣ���������ݣ�ɾ��ԭ�ļ������������ļ�
			{
				sprintf(useenew,"data\\storg\\%dtype\\zancun.dat",typenum);
				if ((fp2 = fopen(useenew,"wt+" )) == NULL)
				{
					closegraph();
					printf("cannot open file %s,kcmanage",useenew);
					delay(3000);
					exit(1);
				}
				for(j=0;j<i;j++)
				{
					memset(ckfood,'\0',sizeof(CKFD));
					fseek(fp,j* sizeof(CKFD),SEEK_SET);
					fread(ckfood, sizeof(CKFD), 1, fp);
					fseek(fp2, 0, SEEK_END);
					fwrite(ckfood, sizeof(CKFD), 1, fp2);			
				}
				for(j=i+1;j<len;j++)
				{
					memset(ckfood,'\0',sizeof(CKFD));
					fseek(fp,j* sizeof(CKFD),SEEK_SET);
					fread(ckfood, sizeof(CKFD), 1, fp);
					fseek(fp2, 0, SEEK_END);
					fwrite(ckfood, sizeof(CKFD), 1, fp2);			
				}
				if (fclose(fp2) != 0)
				{
					closegraph();
					printf("\n cannot close file %s,kcmanage",useenew);
					delay(3000);
					exit(1);
				}
				if(remove(usee) != 0)//ɾ��ԭ�ļ�
				{
					perror("remove");
				}
				if(rename(useenew,usee) != 0)//���������ļ�
				{
					perror("rename");
				}
				
			}
			if (ckfood != NULL)
			{
				free(ckfood);
				ckfood = NULL;
			}
			if (fclose(fp) != 0)
			{
				closegraph();
				printf("\n cannot close file %s,kcmanage",usee);
				delay(3000);
				exit(1);
			}
			if(i==len && sum < 5000)
			{
				*(type+typenum-1) = 1;//�ض������Ų������Ϊ1��
				*(name+m-1) = 1;
			}
		}
	}
	
}


/************************************************************************
FUNCTION:fahuord
DESCRIPTION: ��ȡ������Ϣ
INPUT:recent,*all
RETURN:��
************************************************************************/
void fahuord(int recent,int *all)
{
    FILE* fp;
	FF *foodc;
	int ctn,i,k = 0;
	char usee[40]="\0";
	char rt[5];
    char ap[5];

	for(ctn = 1;ctn < 5;ctn++)
	{
		sprintf(usee,"data\\canteen\\ct%d\\FLIST.dat",ctn);
		if ((fp = fopen(usee, "rt" )) == NULL)
		{
			closegraph();
			printf("cannot open file %s,chukurd",usee);
			delay(3000);
			exit(1);
		}
		if ((foodc = (FF*)malloc(sizeof(FF))) == NULL)
		{
			closegraph();
			printf("something wrong in FF* foodc,fahuord");
			delay(3000);
			exit(1);
		}
	    memset(foodc,'\0',sizeof(FF));
	    fseek(fp,0,SEEK_SET);
	    fread(foodc, sizeof(FF), 1, fp);
		if (!strcmp(foodc->state,"4"))
		{
			k = 1;
		}
		if (fclose(fp) != 0)
		{
			closegraph();
			printf("\n cannot close file %s,chukurd",usee);
			delay(3000);
			exit(1);
		}
	}
	
	for(i=0;i<6;i++)
	{		
		setcolor(BLUE);
		if(k)
		{
			puthz(470,58+30*(i+1),"δ����",16,18,BLUE);
		}
	}
	itoa(recent,rt,10);
    itoa(*all,ap,10);
	setcolor(BLUE);
	outtextxy(320,450,rt);
    outtextxy(390,450,ap);
}