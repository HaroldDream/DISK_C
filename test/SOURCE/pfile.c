#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "purchase.h"

/************************************************************************
FUNCTION:show_plist
DESCRIPTION: 显示采购目录
INPUT:cp：当前页码
RETURN:总页数
************************************************************************/
int show_plist(int cp)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    int errNum;
    char length[10];
    char tlength[10];
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

        setcolor(BLUE);
        puthz(150,88+j*30,fdp->name,16,18,BLUE);
        puthz(220,88+j*30,fdp->type,16,18,BLUE);
        puthz(290,88+j*30,fdp->s,16,18,BLUE);
        outtextxy(400,88+j*30,fdp->p);
        //outtextxy(425,86+j*30,"/");
        puthz(470,88+j*30,fdp->unit,16,18,BLUE);
        //outtextxy(453,86+j*30,fdp->num); 
        outtextxy(528,88+j*30,fdp->est);
        puthz(603,88+j*30,"采购",16,18,BLUE);
    }

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
int show_order(int cp)
{
    FILE *fp;
    FD *fdp;
    int i = 0, j = 0;
    int len = 1, page = 0;
    float tp;//total price
    char length[10];
    char tlength[10];
    char floc[50];
    char temp[20];

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
FUNCTION:up_order
DESCRIPTION: 更新采购单
INPUT:n:当前页第几个，a：采购数量，page：当前页码
RETURN:0：新采购，1：已采购，添加
************************************************************************/
int up_order(int n, int a,int page)
{
    FILE *fp;
    FILE *fp2;
    FD *fdp;
    FD *fdp2;    
    int errNum;
    int i = 0;
    int cn = 0;//总位置
	int len = 0;
    char ca[8];
    char floc[40], floc2[40];
    char temp[10];
    char temp2[10];

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
        printf("memoryallocation runs wrong in fdp,up_order");
        delay(3000);
        exit(1);
    }
    if ((fdp2 = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,up_order");
        delay(3000);
        exit(1);
    }

    sprintf(floc,"c:\\test\\data\\plist\\%sp.dat",stime);
    if ((fp = fopen(floc, "rb+" )) == NULL) //plist
    {
        errNum = errno;
        closegraph();
        printf("cannot open file plist.dat,up_order\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }

    sprintf(floc2,"c:\\test\\data\\order\\%so.dat",stime);
    if ((fp2 = fopen(floc2, "rb+" )) == NULL) //order
    {
        errNum = errno;
        closegraph();
        printf("cannot open file order,up_order\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }        
    
    fseek(fp, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    //len = ftell(fp) / (sizeof(FD)+1);//采购目录数据条数
    len = ftell(fp2) / (sizeof(FD)+1);//采购单数据条数

    cn = (page - 1)*12 + n;//position in plist
    fseek(fp,(cn-1) * (sizeof(FD)+1),SEEK_SET);
    fread(fdp, sizeof(FD),1,fp);
    
    xouttextxy(300,400,fdp->state,BLUE);
    sprintf(temp2,"%d",len);
    xouttextxy(300,420,temp2,BLUE);
    sprintf(temp2,"%d",ftell(fp2));
    xouttextxy(320,420,temp2,BLUE);
    //sprintf(temp,"%d",strcmp(fdp->state,"0\0"));
    //xouttextxy(300,440,fdp->state,BLUE);

    if (strcmp(fdp->state,"0") == 0) //haven't been purchased
    {
        fseek(fp, (cn - 1)*(sizeof(FD)+1)+49, SEEK_SET);//change plist state
        fputc('1',fp);
        fputc('\0',fp);

        fseek(fp2, 0, SEEK_END);//change order
        fwrite(fdp,sizeof(FD),1,fp2);
        fputc('\n',fp2);
        fseek(fp2,-29,SEEK_END);
        itoa(a,ca,10);
        fputs(ca,fp2);
        //fwrite(ca,sizeof(ca),1,fp2);
        fseek(fp2,-10,SEEK_END); //state->1
        fputc('1',fp2);

        free(fdp);
        free(fdp2);
        if (fclose(fp) != 0)
        {
            errNum = errno;
            closegraph();
            printf("\n cannot close plist.dat,up_order 1\n");
            printf("close fail errno = %d reason = %s \n", errNum, strerror(errNum));
            delay(3000);
            exit(1);
        }       
        if (fclose(fp2) != 0)
        {
            errNum = errno;
            closegraph();
            printf("\n cannot close olist.dat,up_order 1\n");
            printf("close fail errno = %d reason = %s \n", errNum, strerror(errNum));
            delay(5000);
            exit(1);
        }
        return 0;
    }
    else if (strcmp(fdp->state,"1") == 0)//have been purchased, add
    {
        
        fseek(fp2,0,SEEK_SET);
        for (i = 0; i < len; i++) //find the same one
        {
            fseek(fp2, i*(sizeof(FD)+1),SEEK_SET);
            fread(fdp2, sizeof(FD),1,fp2);
            //bar(20,290,100,360);
            //puthz(20,300,fdp->name,16,18,BLUE);
            //puthz(20,320,fdp2->name,16,18,BLUE);
            //delay(1000);
            if (strcmp(fdp->name,fdp2->name)==0)
            {
                /*sprintf(temp,"%d",a);
                xouttextxy(30,300,temp,BLUE);
                
                xouttextxy(30,320,fdp2->num,BLUE);
                sprintf(temp,"%d",a);
                xouttextxy(30,340,temp,BLUE);
                delay(3000);*/
                a += atoi(fdp2->num);
                fseek(fp2,-28,SEEK_CUR);
                itoa(a,ca,10);
                fwrite(ca,sizeof(ca),1,fp2);

                free(fdp);
                free(fdp2);
                if (fclose(fp) != 0)
                {
                    errNum = errno;
                    closegraph();
                    printf("\n cannot close plist,up_order\n");
                    printf("close fail errno = %d reason = %s \n", errNum, strerror(errNum));
                    delay(5000);
                    exit(1);
                }
                if (fclose(fp2) != 0)
                {
                    errNum = errno;
                    closegraph();
                    printf("\n cannot close olist,up_order\n");
                    printf("close fail errno = %d reason = %s \n", errNum, strerror(errNum));
                    delay(5000);
                    exit(1);
                }
                return 1;
            }
        }
    }
    else
    {
        free(fdp);
        free(fdp2);
        if (fclose(fp) != 0)
        {
            closegraph();
            printf("\n cannot close olist.dat,up_order");
            delay(3000);
            exit(1);
        }
        if (fclose(fp2) != 0)
        {
            closegraph();
            printf("\n cannot close olist.dat,up_order");
            delay(3000);
            exit(1);
        }
        xouttextxy(40,360,"error",BLUE);
        return 2;        
        //error
    }
    return 3;
}

/************************************************************************
FUNCTION:show_flist
DESCRIPTION: 显示预测界面
INPUT:num：食堂序号
RETURN:
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
        
        puthz(150,108+j*195,"预测曲线",16,18,BLUE);
        puthz(570,88+j*195,"预测值",16,20,LIGHTRED);
        puthz(390,58+j*195,"当前已分配：",16,18,BLUE);
        outtextxy(500, 57+j*195,ffp->dis);
        setlinestyle(SOLID_LINE,0,1);
        line(140,80+j*195,640,80+j*195);
        puthz(560,58+j*195,"点击分配",16,18,BLUE);
        
		setcolor(DARKGRAY);
        puthz(148, 201+j*195,"七日消耗", 16,18,DARKGRAY); //output number
        outtextxy(240,202+j*195,ffp->d1);
        y[0] = atoi(ffp->d1)/10;
        outtextxy(240+50,202+j*195,ffp->d2);
        y[1] = atoi(ffp->d2)/10;
        outtextxy(240+50*2,202+j*195,ffp->d3);
        y[2] = atoi(ffp->d3)/10;
        outtextxy(240+50*3,202+j*195,ffp->d4);
        y[3] = atoi(ffp->d4)/10;
        outtextxy(240+50*4,202+j*195,ffp->d5);
        y[4] = atoi(ffp->d5)/10;
        outtextxy(240+50*5,202+j*195,ffp->d6);
        y[5] = atoi(ffp->d6)/10;
        outtextxy(240+50*6,202+j*195,ffp->d7);
        y[6] = atoi(ffp->d7)/10;
        

        forecast(y,yy); //calculate
        tempyy7 = yy[7];

        itoa(yy[7]*10, day8, 10); //write result
        fseek(fp, i * (sizeof(FF)+1), SEEK_SET);
        fseek(fp, 26, SEEK_CUR);
        k = 0;
        while (*(day8+k) != '\0')
        {
            *(ffp->d8+k) = *(day8+k);
            fputc(*(day8+k), fp);
            k++;
        }
        
        setcolor(LIGHTBLUE);
        puthz(148, 222+j*195,"拟合计算", 16,18,BLUE); //output calculation number
        for (k = 0; k < 7; k++)
        {
            itoa(yy[k]*10, tempy, 10);
            outtextxy(240+50*k, 222+j*195, tempy);
        }      
        setcolor(LIGHTRED);
        outtextxy(580, 105+j*195, day8);

        y[0] = atoi(ffp->d1)/10;
        setcolor(LIGHTGRAY); //output original chart
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

        setcolor(LIGHTBLUE); //out forecast chart
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

/************************************************************************
FUNCTION:forecast
DESCRIPTION: 根据数组x[], y[]的数据，用最小二乘法求拟合曲线
    近似解析表达式y = a0 + a1 * x + a2 * x^2 + a3 * x^3;
INPUT:
RETURN:预测值
************************************************************************/
int forecast(int *y,int *yy)
{
    int maxn = 7;
    int rank = 3;
    int column;
    float mainelement, tempa, tempb, Mik, result;
    float sum;
    int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    float atemp[2 * (3 + 1)] = {0};
    float b[3 + 1] = {0};
    float a[3 + 1][3 + 1];
    int i, j, k;
    char fx[50];

    for(i = 0; i < maxn; i++)
    {
        atemp[1] += x[i];
        atemp[2] += pow(x[i], 2);
        atemp[3] += pow(x[i], 3);
        atemp[4] += pow(x[i], 4);
        atemp[5] += pow(x[i], 5);
        atemp[6] += pow(x[i], 6);
        b[0] += y[i];
        b[1] += x[i] * y[i];
        b[2] += pow(x[i], 2) * y[i];
        b[3] += pow(x[i], 3) * y[i];
    }

    atemp[0] = maxn;
    for(i = 0; i < rank + 1; i++)  //构建线性方程组系数矩阵，b[]不变
    {  
        k = i;
        for(j = 0; j < rank + 1; j++)
        {
            a[i][j] = atemp[k];
            k++;
        }  
    }

    //高斯列主元消去法解线性方程组
    for(k = 0; k < rank + 1 - 1; k++) //n - 1列
    { 
        column = k;
        mainelement = a[k][k];

        for(i = k; i < rank + 1; i++) //找主元素
        {
            if(fabs(a[i][k]) > mainelement)
            {
                mainelement = fabs(a[i][k]);
                column = i;
            }
        }
            
        for(j = k; j < rank + 1; j++) //交换两行
        { 
            tempa = a[k][j];
            a[k][j] = a[column][j];
            a[column][j] = tempa;
        }
        tempb = b[k];
        b[k] = b[column];
        b[column] = tempb;

        for(i = k + 1; i < rank + 1; i++) //消元
        { 
            Mik = a[i][k] / a[k][k];
            for(j = k; j < rank + 1; j++)  
            {
                a[i][j] -= Mik * a[k][j];
            }
            b[i] -= Mik * b[k];
        }
    }
    b[rank + 1 - 1] /= a[rank + 1 - 1][rank + 1 - 1];  //回代
    for(i = rank + 1 - 2; i >= 0; i--)
    {
        sum = 0;
        for(j = i + 1; j < rank + 1; j++)  
        {
            sum += a[i][j] * b[j];
        }
        b[i] = (b[i] - sum) / a[i][i];
    }//高斯列主元消去法结束
    
    //sprintf(fx,"%d +%dx+%dx^2+%dx^3", b[0], b[1], b[2], b[3]);
    //outtextxy(200,300,fx);
    //printf("P(x) = %f%+fx%+fx^2%+fx^3\n\n", b[0], b[1], b[2], b[3]);
    for(i = 0; i < maxn + 1; i++)
    { 
        *(yy + i)= b[0] + b[1]*x[i] + b[2]*x[i]*x[i] + b[3]*x[i]*x[i]*x[i];
        //temp = b[0] + b[1] * x[i] + b[2] * x[i] * x[i] + b[3] * x[i] * x[i] * x[i];
        //printf("%f    %f    error: %f\n", y[i], temp, temp - y[i]);
    }

    result = b[0] + b[1]*8 + b[2]*64 + b[3]*512;
    return result;
}


/*
int read_flist()
{

}
*/

//todo ad_plist（显示建议）


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