#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "drawuser.h"
#include "infof.h"
#include "info.h"

int show_ddcx(int cp, int day)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    int md, mm;
    float tp; //total price
    float sum = 0.0;
    char length[10], tlength[10];
    char floc[50], stime2[20];
    char temp[20];
    

    time_t timep;//文件时间
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);

    if ((p->tm_mday+day) <= 0)
    {
        md = 30 + day + 1;
        mm = p->tm_mon - 1;
    }
    else 
    {
        md = p->tm_mday+day;
        mm = p->tm_mon;
    }
    if (mm < 10)
    {
        if (md < 10)
        {
            sprintf(stime,"0%d0%d",1+mm,md);  
        }
        else 
        {
            sprintf(stime,"0%d%d",1+mm,md);
        }
    }
    else 
    {
        if (md < 10)
        {
            sprintf(stime,"%d0%d",1+mm,md);   
        }
        else 
        {
            sprintf(stime,"%d%d",1+mm,md);
        }
    }

    if ((fdp = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,show_order");
        delay(3000);
        exit(1);
    }
    sprintf(floc,"c:\\test\\data\\order\\%so.dat",stime);
    if ((fp = fopen(floc, "rb+" )) == NULL)
    {
        closegraph();
        printf("cannot open file orderlist,show_order");
        delay(3000);
        exit(1);
    }

    setcolor(WHITE);
    
    sprintf(stime2,"%d.%d",1+mm,md);
    outtextxy(330,58,stime2);
    setfillstyle(SOLID_FILL,DARKGRAY);
    if (day == -6)
        bar(160,80,270,110);
    else if (day == 0)
        bar(280,80,400,110);

    setcolor(BLUE);
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FD)+1);//数据条数
    page = (len / 10) + 1;
    itoa(cp,length,10);
    itoa(page,tlength,10);   
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,444,338,480);
    bar(390,444,408,480);
    outtextxy(325,452,length);
    outtextxy(395,452,tlength);

    for(i = 0 + (cp -1) * 10, j = 0 ; (i < len) && (i < cp*10); i++, j++)
    {
        memset(fdp,'\0',sizeof(FD));
        fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
        fread(fdp, sizeof(FD),1,fp);
        
        setcolor(BLUE);
        puthz(150,148+j*30,fdp->name,16,18,BLUE);
        puthz(230,148+j*30,fdp->type,16,18,BLUE);
        puthz(300,148+j*30,fdp->s,16,18,BLUE);
        outtextxy(400,148+j*30,fdp->p);
        puthz(460,148+j*30,fdp->unit,16,18,BLUE);
        outtextxy(510,148+j*30,fdp->num);
        tp = atof(fdp->num)*atof(fdp->p); //total price
        sum += tp;
        sprintf(temp,"%f",tp);
        outtextxy(570,148+j*30,temp);
        setfillstyle(SOLID_FILL,WHITE);
        if (tp < 10000.0)
            bar(624,142+i*30,640,168+i*30);
        else 
            bar(634,142+i*30,640,168+i*30);
    }
    
    setfillstyle(SOLID_FILL,DARKGRAY);
    setcolor(WHITE);
    sprintf(temp,"%f",sum);
    outtextxy(545,70,temp);
    if (sum < 10.0)
        bar(570,60,640,100);
    else if (sum < 100.0)
        bar(580,60,640,100);
    else if (sum < 1000.0)
        bar(590,60,640,100);
    else if (sum < 10000.0)
        bar(600,60,640,100);
    else if (sum < 100000.0)
        bar(610,60,640,100);

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