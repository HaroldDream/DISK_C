#include <common.h>
#include "data.h"
#include "record.h"
/************************************************************************
FUNCTION:storagerd
DESCRIPTION: 读取入库信息
INPUT:recent,*all
RETURN:无
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
			puthz(440,58+30*(i+1),"未入库",16,18,RED);
		}
		else if(statenow == 3)
		{
			puthz(440,58+30*(i+1),"已入库",16,18,BLUE);
			//!!!!!!!!puthz(557,58+30*(i+1),food->r1,16,18,BLUE);
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
DESCRIPTION: 数据入库
INPUT:*f
RETURN:无
************************************************************************/
void storage_in(FD *f)
{
	FILE *fp;
	CKFD *ckf;
	char code[5];
	char usee[40]="\0";
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
	//!!!!!!!!!!!入库时间
    searchtype(f,ckf);
	sprintf(usee,"data\\storage\\%stype\\%sname.dat",ckf->typenum,ckf->namenum);
    if ((fp = fopen(usee,"wt+" )) == NULL)
    {
        closegraph();
        printf("cannot open file storage,storage_in");
        delay(3000);
        exit(1);
    }
	fseek(fp,0,SEEK_END);
	fwrite(ckf, sizeof(CKFD), 1, fp);
	fseek(fp,0,SEEK_END);
	fputc('\n',fp);
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
DESCRIPTION: 单击入库
INPUT:i,recent
RETURN:无
************************************************************************/
void ruku(int i,int recent)
{
	FILE* fp;
	FD* food;
	int j;
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
	j = (recent-1)*12+i;
	fseek(fp, j, SEEK_SET);
	fread(food, sizeof(FD), 1, fp);
	if(!strcmp(food -> state,"2"))
	{
		strcpy(food -> state ,"3");
		fseek(fp, j, SEEK_SET);
	    fwrite(food, sizeof(FD), 1, fp);
        storage_in(food);
		setfillstyle(SOLID_FILL,WHITE);
        bar(457,58+30*(i+1),457+60,58+30*(i+1)+18);
		puthz(457,58+30*(i+1),"已入库",16,18,BLUE);
		//!!!!!!puthz(557,58+30*(i+1),food->r1,16,18,BLUE);
	}
	fclose(fp);
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
DESCRIPTION: 读取物流状态信息
INPUT:recent,*all
RETURN:无
************************************************************************/
void logisticsrd(int recent,int *all,int code,int type,int i)
{
	char nowcode[2]; //nowcode中1为校外物流0为校内物流
	char nowtype[2]; //种类编号转化成的字符
	FILE* fp;
	int len = 0,j,p;
	//int k;
	char gys[11];//供应商
	char wlzt[36];//物流状态
	char n[5];//序号
	char rt[5];//当前页
    char ap[5];//所有页
	char usee[40]="\0";
	itoa(code,nowcode,10);
	itoa(type,nowtype,10);
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
	if(i>len-1)
	{
		i = len - 1;
	}
    j = (recent-1)*11;
	// if (recent*11 <= len)
	// {
	// 	k = 11;
	// }
	// else
	// {
	// 	k = len-j;
	// }

	for(p=0 ; p<i+1 && i < len; p++)//由于物流信息不到11条，暂时可以
	{
		fseek(fp,(j+p) * (sizeof(gys)+sizeof(wlzt)+1),SEEK_SET);
		fread(gys, sizeof(gys), 1, fp);
		fread(wlzt, sizeof(wlzt), 1, fp);
		itoa(j+p+1,n,10);
		outtextxy(160,88+30*(p+1),n);//输出序号
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
DESCRIPTION: 计算该类物流状态总数
INPUT:type(种类编号)
RETURN:数量
************************************************************************/
int countline(int type)
{
	char nowtype[2]; //种类编号转化成的字符
	FILE* fp;
	int len = 0;
	char usee[40]="\0";
	char gys[11];//供应商
	char wlzt[36];//物流状态
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
DESCRIPTION: 收货数据编写
INPUT: t记录物流输出数据条数的数组
RETURN:none
************************************************************************/
void shouhuo(int *t)
{
	FILE*fp,*fp2;
	FD* food;
	CKFD* ckfood;
	int len,i,j,type,mode,opt;  //type:种类编号,mode:显示的状态,opt:是否重复
	char atype[3];
	char gys[10][11];
	int ak[6] = {0,0,0,0,0,0};//ak为总数据条数
	//char n[5];订单编号
	// closegraph();
    // printf("%d\n%d",*(t),*(t+1));
    // delay(3000);

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

        if(*(t+type-1)+1 >= ak[type-1]) //判断所有数据是否读完
        {
            mode = 2;
        }
        else
        {
            mode = 1;
        }
		memset(gys,'\0',sizeof(gys)); //存放该种类读取过的供应商
		for(i=0;i<len;i++)
		{
			memset(food,'\0',sizeof(FD));
			memset(ckfood,'\0',sizeof(CKFD));
			fseek(fp,i * (sizeof(FD)+1),SEEK_SET);
			fread(food, sizeof(FD), 1, fp);
			searchtype(food,ckfood);
			itoa(type,atype,10);

			if(!strcmp(ckfood ->typenum,atype))
			{			
				if(mode == 2)
				{
					strcpy(food -> state ,"2"); //改变状态，2为已到货未入库
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
					fseek(fp2,0,SEEK_END);
					fwrite(food->type, sizeof(food->type), 1, fp);
					fseek(fp2,0,SEEK_END);
					fwrite(food->s, sizeof(food->s), 1, fp);
					fseek(fp2,0,SEEK_END);
					fwrite(food->state, sizeof(food->state), 1, fp);
					fseek(fp2,0,SEEK_END);
					//fputc('\n',fp2);
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
DESCRIPTION: 查询种类编号
INPUT:f,ckf
RETURN:无
************************************************************************/
void searchtype(FD *f,CKFD *ckf)
{
	if(!strcmp(f ->type,"蔬菜"))
	{
		strcpy(ckf->typenum,"1");
		if(!strcmp(f ->name,"白菜"))
		{
			strcpy(ckf->namenum,"1");			
		}
		if(!strcmp(f ->name,"青菜"))
		{
			strcpy(ckf->namenum,"2");		
		}
		if(!strcmp(f ->name,"韭菜"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"西兰花"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"胡萝卜"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"土豆"))
		{
			strcpy(ckf->namenum,"6");			
		}
		if(!strcmp(f ->name,"番茄"))
		{
			strcpy(ckf->namenum,"7");			
		}
		if(!strcmp(f ->name,"包菜"))
		{
			strcpy(ckf->namenum,"8");		
		}
		if(!strcmp(f ->name,"生姜"))
		{
			strcpy(ckf->namenum,"9");		
		}
	}
	if(!strcmp(f ->type,"肉类"))
	{
		strcpy(ckf->typenum,"2");
		if(!strcmp(f ->name,"猪里脊"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"猪五花"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"鸡胸肉"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"牛腩"))
		{
			strcpy(ckf->namenum,"4");		
		}
		if(!strcmp(f ->name,"鸡翅中"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"鸡腿"))
		{
			strcpy(ckf->namenum,"6");		
		}
	}
	if(!strcmp(f ->type,"水产"))
	{
		strcpy(ckf->typenum,"3");
		if(!strcmp(f ->name,"大黄鱼"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"鲫鱼"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"带鱼"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"草鱼"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"对虾"))
		{
			strcpy(ckf->namenum,"5");			
		}
	}
	if(!strcmp(f ->type,"其他"))
	{
		strcpy(ckf->typenum,"4");
		if(!strcmp(f ->name,"豆腐"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"香干"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"鸡蛋"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"皮蛋"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"纯牛奶"))
		{
			strcpy(ckf->namenum,"5");		
		}
	}
	if(!strcmp(f ->type,"调料"))
	{
		strcpy(ckf->typenum,"5");
		if(!strcmp(f ->name,"酱油"))
		{
			strcpy(ckf->namenum,"1");			
		}
		if(!strcmp(f ->name,"料酒"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"醋"))
		{
			strcpy(ckf->namenum,"3");			
		}
		if(!strcmp(f ->name,"食盐"))
		{
			strcpy(ckf->namenum,"4");			
		}
		if(!strcmp(f ->name,"白糖"))
		{
			strcpy(ckf->namenum,"5");		
		}
		if(!strcmp(f ->name,"辣椒"))
		{
			strcpy(ckf->namenum,"6");		
		}
	}
	if(!strcmp(f ->type,"粮油面"))
	{
		strcpy(ckf->typenum,"6");
		if(!strcmp(f ->name,"大米"))
		{
			strcpy(ckf->namenum,"1");		
		}
		if(!strcmp(f ->name,"面粉"))
		{
			strcpy(ckf->namenum,"2");			
		}
		if(!strcmp(f ->name,"酵母粉"))
		{
			strcpy(ckf->namenum,"3");		
		}
		if(!strcmp(f ->name,"食用油"))
		{
			strcpy(ckf->namenum,"4");		
		}
	}
	
}

/************************************************************************
FUNCTION:shourd
DESCRIPTION: 读取收货信息
INPUT:recent,*all
RETURN:无
************************************************************************/
void shourd(int recent,int *all)
{
    FILE* fp;
	int len = 0,k,i,j,statenow;
	int xdw;//xsw为每条数据占用大小
	char tp[7];  //种类，如蔬菜、肉类
    char gys[11];  //供应商
	char zt[2];
	char rt[5];
    char ap[5];
	if ((fp = fopen("Data\\tdshou.dat", "rt" )) == NULL)
	{
		closegraph();
		printf("cannot open file PLIST.dat,shourd");
		delay(3000);
		exit(1);
	}
	xdw = sizeof(tp[7])+sizeof(gys[11])+sizeof(zt[2]);
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / xdw;
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
	    fseek(fp,(j+i) * xdw,SEEK_SET);
	    fread(tp, sizeof(tp), 1, fp);
		fread(gys, sizeof(gys), 1, fp);
		fread(zt, sizeof(zt), 1, fp);
		puthz(275,58+30*(i+1),tp,16,18,BLUE);
	    puthz(370,58+30*(i+1),gys,16,18,BLUE);
		setcolor(BLUE);
		statenow=atoi(zt);
		if(statenow == 2)
		{
			puthz(459,58+30*(i+1),"已签收",16,18,BLUE);
		}
		else if (statenow == 1)
		{
			puthz(459,58+30*(i+1),"未签收",16,18,RED);
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
