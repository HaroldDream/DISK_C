#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "purchase.h"
#include "pfile.h"
#include "pfunc.h"

/************************************************************************
FUNCTION:show_plist
DESCRIPTION: 显示采购目录
INPUT:cp：当前页码，type：种类
RETURN:总页数
************************************************************************/
int show_plist(int cp, int type)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0, n = 0;
    int len = 1, page = 0;
    int errNum;
    char length[4], tlength[4];
    char ctype[8];
    char floc[40];


    time_t timep;//文件时间
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
    

    if ((fdp = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,show_plist");
        delay(3000);
        exit(1);
    }

    sprintf(floc,"c:\\test\\data\\plist\\%sp.dat",stime);
    if ((fp = fopen(floc, "rb+" )) == NULL) //plist
    {
        errNum = errno;
        closegraph();
        printf("cannot open file plist.dat,show_plist\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FD)+1);//数据条数
    if (type == 0)
    {
        page = (len / 12) + 1;
        itoa(cp,length,10);
        itoa(page,tlength,10);   
        setfillstyle(SOLID_FILL,WHITE);
        bar(320,444,338,480);
        bar(390,444,408,480);
        setcolor(BLUE);
        outtextxy(325,452,length);
        outtextxy(395,452,tlength);    

        for(i = 0 + (cp -1) * 12, j = 0 ; (i < len) && (i < cp*12); i++, j++)
        {
            memset(fdp,'\0',sizeof(FD));
            fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
            fread(fdp, sizeof(FD),1,fp);

            setcolor(BLUE);
            puthz(150,88+j*30,fdp->name,16,18,BLUE);
            puthz(220,88+j*30,fdp->type,16,18,BLUE);
            puthz(290,88+j*30,fdp->s,16,18,BLUE);
            outtextxy(400,88+j*30,fdp->p);
            puthz(470,88+j*30,fdp->unit,16,18,BLUE);
            if (*(fdp->est) == '0') 
                outtextxy(528,88+j*30,"0");
            else 
                outtextxy(528,88+j*30,fdp->est);
            puthz(603,88+j*30,"采购",16,18,BLUE);
        }            
    }
    else 
    {
        switch (type)
        {
            case 1:
                sprintf(ctype, "蔬菜");
                break;
            case 2:
                sprintf(ctype, "肉类");
                break;
            case 3:
                sprintf(ctype, "水产");
                break;
            case 4:
                sprintf(ctype, "调料");
                break;
            case 5:
                sprintf(ctype, "粮油面");
                break;
            case 6:
                sprintf(ctype, "其它");
                break;
            default:
                break;
        }
        n = 0;
        for(i = 0 + (cp -1) * 12, j = 0 ; (i < len) && (n < cp*12); i++, j++)
        {
            memset(fdp,'\0',sizeof(FD));
            fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
            fread(fdp, sizeof(FD),1,fp);
            if (strcmp(fdp->type,ctype) == 0)
            {
                setcolor(BLUE);
                puthz(150,88+n*30,fdp->name,16,18,BLUE);
                puthz(220,88+n*30,fdp->type,16,18,BLUE);
                puthz(290,88+n*30,fdp->s,16,18,BLUE);
                outtextxy(400,88+n*30,fdp->p);
                puthz(470,88+n*30,fdp->unit,16,18,BLUE); 

                if (*(fdp->est) == '0') 
                    outtextxy(528,88+n*30,"0");
                else 
                    outtextxy(528,88+n*30,fdp->est);

                puthz(603,88+n*30,"采购",16,18,BLUE);
                n++;
            } //end if

        } //end for
        page = (n / 12) + 1;
        itoa(cp,length,10);
        itoa(page,tlength,10);   
        setfillstyle(SOLID_FILL,WHITE);
        bar(320,444,338,480);
        bar(390,444,408,480);
        setcolor(BLUE);
        outtextxy(325,452,length);
        outtextxy(395,452,tlength);    
    } //end if

    free(fdp);
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close plist.dat,show_plist");
        delay(3000);
        exit(1);
    }

    return page;
}

/************************************************************************
FUNCTION:show_order
DESCRIPTION: 显示采购单
INPUT:cp：当前页码
RETURN:总页数
************************************************************************/
int show_order(int cp, int day)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    int md, mm;
    float tp;//total price
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
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    sprintf(stime2,"%d.%d",1+mm,md);
    outtextxy(50,220,stime2);
    if (day == 0)
        bar(75,245,135,270);
    else if (day == -4)
        bar(5,245,70,270);

    setcolor(BLUE);
    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FD)+1);//数据条数
    page = (len / 12) + 1;
    itoa(cp,length,10);
    itoa(page,tlength,10);   
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,444,338,480);
    bar(390,444,408,480);
    outtextxy(325,452,length);
    outtextxy(395,452,tlength);

    for(i = 0 + (cp -1) * 12, j = 0 ; (i < len) && (i < cp*12); i++, j++)
    {
        memset(fdp,'\0',sizeof(FD));
        fseek(fp, i * (sizeof(FD)+1), SEEK_SET);
        fread(fdp, sizeof(FD),1,fp);
        //fscanf(fp,"%s %s %s",fdp->name,fdp->type,fdp->s);
        //get_plist(i + 1, &fdp);

        tp = atof(fdp->num)*atof(fdp->p); 
        setcolor(BLUE);
        puthz(150,88+j*30,fdp->name,16,18,BLUE);
        puthz(230,88+j*30,fdp->type,16,18,BLUE);
        puthz(300,88+j*30,fdp->s,16,18,BLUE);
        outtextxy(400,88+j*30,fdp->p);
        puthz(460,88+j*30,fdp->unit,16,18,BLUE);
        outtextxy(510,88+j*30,fdp->num); 
        sprintf(temp,"%f",tp);
        outtextxy(570,88+j*30,temp);
        if (tp < 10000.0)
            bar(623,82+i*30,640,108+i*30);
        else 
            bar(633,82+i*30,640,108+i*30);

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
FUNCTION:show_flist
DESCRIPTION: 显示预测界面
INPUT:num：食堂序号，cp：当前页码
RETURN:page：总页数
************************************************************************/
int show_flist(int num, int cp)
{
    FILE *fp;
    FF *ffp;
    int errNum;
    int len, page;
    int i, j, k;
    int tempyy7;
    int y[7], yy[7];
    char length[10], tlength[10];
    char floc[40];
    char day8[7], tempy[8];

    time_t timep;//文件时间
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

    if ((ffp = (FF*)malloc(sizeof(FF))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in ffp,show_forecast");
        delay(3000);
        exit(1);
    }

    sprintf(floc,"c:\\test\\data\\canteen\\ct%d\\%sf.dat",num,stime);
    if ((fp = fopen(floc, "rb+" )) == NULL) //flist
    {
        errNum = errno;
        closegraph();
        printf("cannot open file flist,show_forecast\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FF)+1);//数据条数
    page = (len / 2) + 1;
    itoa(cp,length,10);
    itoa(page,tlength,10);   
    setfillstyle(SOLID_FILL,WHITE);
    bar(320,444,338,480);
    bar(390,444,408,480);
    outtextxy(325,451,length);
    outtextxy(395,451,tlength);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    switch (num)
    {
        case 1:
            puthz(40,225,"百景园",16,20,WHITE);
            bar(5,245,70,270);
            break;
        case 2:
            puthz(50,225,"韵苑",16,20,WHITE);
            break;
        case 3:
            puthz(50,225,"喻园",16,20,WHITE);
            break;
        case 4:
            puthz(30,225,"学二食堂",16,18,WHITE);
            bar(75,245,135,270);
            break;
    }

    for(i = 0 + (cp -1) * 2, j = 0 ; (i < len) && (i < cp*2); i++, j++)
    {
        //memset(ffp,'\0',sizeof(FF));
        fseek(fp, i * (sizeof(FF)+1), SEEK_SET);
        fread(ffp, sizeof(FF),1,fp);

        setcolor(BLUE);
        puthz(150,58+j*195,ffp->name,16,18,BLUE);
        puthz(210,58+j*195,ffp->type,16,18,BLUE);
        puthz(280,58+j*195,"单位：",16,18,BLUE);
        puthz(340,58+j*195,ffp->unit,16,18,BLUE);
        
        puthz(150,140+j*195,"预测曲线",16,18,BLUE);
        puthz(570,88+j*195,"预测值",16,20,LIGHTRED);
        puthz(390,58+j*195,"当前已分配：",16,18,BLUE);
        outtextxy(500, 57+j*195,ffp->dis);
        setlinestyle(SOLID_LINE,0,1);
        line(140,80+j*195,640,80+j*195);
        puthz(560,58+j*195,"点击分配",16,18,BLUE);

        y[0] = atoi(ffp->d1)/10;
        y[1] = atoi(ffp->d2)/10;
        y[2] = atoi(ffp->d3)/10;
        y[3] = atoi(ffp->d4)/10;
        y[4] = atoi(ffp->d5)/10;
        y[5] = atoi(ffp->d6)/10;
        y[6] = atoi(ffp->d7)/10;

        forecast(y,yy); //calculate

        tempyy7 = yy[7]; //write result
        itoa(yy[7]*10, day8, 10); 
        fseek(fp, i * (sizeof(FF)+1), SEEK_SET);
        fseek(fp, 26, SEEK_CUR);
        k = 0;
        while (*(day8+k) != '\0')
        {
            *(ffp->d8+k) = *(day8+k);
            fputc(*(day8+k), fp);
            k++;
        }
        
        setcolor(LIGHTBLUE); //*output calculation number
        puthz(148, 222+j*195,"拟合计算", 16,18,BLUE); 
        for (k = 0; k < 7; k++)
        {
            itoa(yy[k]*10, tempy, 10);
            outtextxy(240+50*k, 222+j*195, tempy);
        }      
        setcolor(LIGHTRED);
        outtextxy(580, 105+j*195, day8);

		setcolor(DARKGRAY); //*output number
        puthz(148, 201+j*195,"七日消耗", 16,18,DARKGRAY);
        outtextxy(240,202+j*195,ffp->d1);
        outtextxy(240+50,202+j*195,ffp->d2);
        outtextxy(240+50*2,202+j*195,ffp->d3);
        outtextxy(240+50*3,202+j*195,ffp->d4);
        outtextxy(240+50*4,202+j*195,ffp->d5);
        outtextxy(240+50*5,202+j*195,ffp->d6);
        outtextxy(240+50*6,202+j*195,ffp->d7);

        y[0] = atoi(ffp->d1)/10;
        setcolor(LIGHTGRAY); //*output original chart
        for (k = 0; k < 7; k++)
        {
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            fillellipse(250+k*50, 200 - y[k]/10 + 195*j, 4, 4);
        }
        for (k = 0; k < 6; k++)
        {
            setcolor(LIGHTGRAY);
            setlinestyle(SOLID_LINE,0,3);
            line(250+k*50, 202 - y[k]/10 +195*j, 250+(k+1)*50, 200 - y[k+1]/10 + 195*j);
        }

        setcolor(LIGHTBLUE); //*out forecast chart
        for (k = 0; k < 7; k++)
        {
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            fillellipse(250+k*50, 200 - yy[k]/10 + 195*j, 2, 2);
        }
        for (k = 0; k < 6; k++)
        {
            setcolor(LIGHTBLUE);
            setlinestyle(SOLID_LINE,0,1);
            line(250+k*50, 200 - yy[k]/10 + 195*j, 250+(k+1)*50, 200 - yy[k+1]/10 + 195*j);
        }

        setcolor(LIGHTRED); //out forecast chart red
        setfillstyle(SOLID_FILL,LIGHTRED);
        fillellipse(250+7*50, 200 - tempyy7/10 + 195*j, 2, 2);
        setlinestyle(SOLID_LINE,0,1);
        line(250+6*50, 200 - yy[6]/10 + 195*j, 250+7*50, 200 - tempyy7/10 + 195*j);
    }

    free(ffp);
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close flist,show_flist");
        delay(3000);
        exit(1);
    }

    return page;
}
