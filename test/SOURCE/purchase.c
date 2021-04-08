#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void purchase(int *fun)
{
    int page = 1;
    int func = 1;

    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(1,1);
    show_plist(1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//系统预测
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(1,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 0;
        }
        
        if(mouse_press(0,91,140,129) == 1)//采购目录
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,1);
            show_plist(1);
            page = 1;
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 1;
        }
        if ((mouse_press(510,445,560,480) == 1) && (func == 1) && (page > 1))
        {
            drawad(1,1);
            show_plist(page - 1);
            page -= 1;
        }
        if ((mouse_press(560,445,610,480) == 1) && (func == 1) && (page < show_plist(page)))
        {
            drawad(1,1);
            show_plist(page + 1);
            page += 1;
        }


        if(mouse_press(0,131,140,169) == 1)//采购单
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 2;
        }
        if(mouse_press(10,390,130,430) == 1)//todo条件筛选
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,3);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *fun = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//物流
        {
            *fun = 2;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *fun = 3;
            return;
        }
    }
}

int show_plist(int cp)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    char length[10];
    char tlength[10];
    int mon = 0, day = 0;

    time_t timep;
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    if (p->tm_mon < 10)
    {
        if (p->tm_mday < 10)
        {
            sprintf(stime,"0%d0%d",1+p->tm_mon,p->tm_mday-1);   
        }
        else 
        {
            sprintf(stime,"0%d%d",1+p->tm_mon,p->tm_mday-1);
        }
    }
    if (p->tm_mon >= 10)
    {
        if (p->tm_mday < 10)
        {
            sprintf(stime,"%d0%d",1+p->tm_mon,p->tm_mday-1);   
        }
        else 
        {
            sprintf(stime,"%d%d",1+p->tm_mon,p->tm_mday-1);
        }
    }


    if ((fdp = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,show_plist");
        delay(3000);
        exit(1);
    }

    if ((fp = fopen("c:\\test\\data\\plist.dat", "rb+" )) == NULL)
    {
        closegraph();
        printf("cannot open file plist.dat,show_plist");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(FD);//数据条数
    page = (len / 13) + 1;
    itoa(cp,length,10);
    itoa(page,tlength,10);   
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,444,338,480);
    bar(390,444,408,480);
    outtextxy(325,445,length);
    outtextxy(395,445,tlength);
    //itoa(len,length,10);
    //itoa(ftell(fp),tlength,10);    
    //outtextxy(500,180,tlength);
    //outtextxy(500,200,length);

    for(i = 0 + (cp -1) * 13, j = 0 ; (i < len) && (i < cp*13 - 1); i++, j++)
    {
        memset(fdp,'\0',sizeof(FD));
        fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
        fread(fdp, sizeof(FD),1,fp);

        setcolor(BLUE);
        puthz(150,88+j*30,fdp->name,16,18,BLUE);
        puthz(220,88+j*30,fdp->type,16,18,BLUE);
        puthz(290,88+j*30,fdp->s,16,18,BLUE);
        outtextxy(391,86+j*30,fdp->p);
        outtextxy(425,86+j*30,"/");
        puthz(431,88+j*30,fdp->unit,16,18,BLUE);
        outtextxy(453,86+j*30,fdp->num); 
        outtextxy(525,86+j*30,fdp->est);
        puthz(603,88+j*30,"采购",16,18,BLUE);
    }

    free(fdp);
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close plist.dat,show_p1");
        delay(3000);
        exit(1);
    }

    return page;
}

int show_order(int cp)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    char length[10];
    char tlength[10];

    if ((fdp = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,show_order");
        delay(3000);
        exit(1);
    }

    if ((fp = fopen("c:\\test\\data\\olist.dat", "rb+" )) == NULL)
    {
        closegraph();
        printf("cannot open file olist.dat,show_order");
        delay(3000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(FD);//数据条数
    page = (len / 13) + 1;
    itoa(cp,length,10);
    itoa(page,tlength,10);   
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,444,338,480);
    bar(390,444,408,480);
    outtextxy(325,445,length);
    outtextxy(395,445,tlength);
    //itoa(len,length,10);
    //itoa(ftell(fp),tlength,10);    
    //outtextxy(500,180,tlength);
    //outtextxy(500,200,length);

    for(i = 0 + (cp -1) * 13, j = 0 ; (i < len) && (i < cp*13 - 1); i++, j++)
    {
        memset(fdp,'\0',sizeof(FD));
        fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
        fread(fdp, sizeof(FD),1,fp);
        //fscanf(fp,"%s %s %s",fdp->name,fdp->type,fdp->s);
        //get_plist(i + 1, &fdp);

        setcolor(BLUE);
        puthz(150,88+j*30,fdp->name,16,18,BLUE);
        puthz(230,88+j*30,fdp->type,16,18,BLUE);
        puthz(300,88+j*30,fdp->s,16,18,BLUE);
        outtextxy(400,88+j*30,fdp->p);
        outtextxy(460,88+j*30,fdp->num); 
        outtextxy(528,88+j*30,fdp->est);
        puthz(605,88+j*30,"采购",16,18,BLUE);
    }

    free(fdp);
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close olist.dat,show_order");
        delay(3000);
        exit(1);
    }

    return page;

}

/************************************************************************
FUNCTION:pop
DESCRIPTION: 采购弹窗：n=1，数量填写；n=2时，采购成功
INPUT:num
RETURN:0：未更改，返回；a： 0：未更改，返回；返回采购数量
************************************************************************/
int pop(int n)
{
	int a = 0;//数量
    /*void *buffer;
	unsigned s;
    clrmous(MouseX, MouseY);
	s=imagesize(200,180,440,300);
	buffer=malloc(s);
	getimage(200,180,440,300,buffer);
	delay(10);*/

    setlinestyle(SOLID_LINE,0,1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(200,180,440,300);
    rectangle(200,180,440,300);

    switch(n)
    {
        case 1:
            rectangle(240,220,400,250);
            puthz(247,227,"采购数量：",16,18,BLUE);	
            rectangle(340,265,380,285);
            rectangle(260,265,300,285);
            puthz(345,267,"返回",16,20,BLUE);
            puthz(265,267,"确定",16,20,BLUE);
            break;
        case 2:
            puthz(260,230,"采购成功",16,20,BLUE);
            delay(1000);
            return a;
    }

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
        if ((mouse_press(240,220,400,250) == 1)
        {
            clrmous(MouseX,MouseY);
        }

		if (mouse_press(260,265,300,285) == 1)//确定框点击
		{
			clrmous(MouseX, MouseY);
			delay(10);
            //putimage(200,180,buffer,COPY_PUT);
            // free(buffer);
				tanchuang(11);
				d = atoi(U);
				return d;
			return 1;
		}
        
		if (mouse_press(340,265,380,285) == 1)//返回框点击
		{
			clrmous(MouseX, MouseY);
			delay(10);
            putimage(200,180,buffer,COPY_PUT);
            free(buffer);
			return 0;
		}
    }

}


/*int get_plist(int line, FD *fdp)
{
	FILE *fp;
	int row=1, len = 0;//row行数, length文件总字节数,数据行数
	char ch, *n;
    char length[10], tlength[10];
	int i, j;
	
	//打开文件
    if ((fp = fopen("c:\\test\\data\\plist.txt", "rt+" )) == NULL)
    {
        closegraph();
        printf("cannot open file plist.txt,show_p1");
        delay(3000);
        exit(1);
    }
	
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(FD);//数据条数
    itoa(len,length,10);
    itoa(ftell(fp),tlength,10);    
    outtextxy(500,180,tlength);
    outtextxy(500,200,length);
	
    //获取名称
    fseek(fp, line * sizeof(FD), SEEK_SET);
    //fread(fdp, sizeof(char), 4, fp);
    
    //获取名称2
    for(j = 0; ch != ' '; j++)
    {
        fseek(fp, (line+j)*sizeof(char), SEEK_SET);
        fread(&ch, sizeof(char), 1, fp);
        fdp->name[j] = ch;
    }
    
    
    for(j = 0; ch != '\t'; j++)
    {
        fseek(fp, j*sizeof(char), SEEK_CUR);
        fread(&ch, sizeof(char), 1, fp);
        fdp->type[j] = ch;
    }
    
    for(j = 0; ch != '\t'; j++)
    {
        fseek(fp, j*sizeof(char), SEEK_CUR);
        fread(&ch, sizeof(char), 1, fp);
        fdp->type[j] = ch;
    }
    //解决多字问题
    n = strstr(fdp->name, " ");
    stpcpy(n, "\0");

	
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close plist.dat,show_p1");
        delay(3000);
        exit(1);
    }
	
	return 1;
}*/