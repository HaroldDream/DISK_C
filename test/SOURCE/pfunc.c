#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "purchase.h"
#include "pfunc.h"
#include "pfile.h"

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

    cn = (page - 1)*12 + n + 1;//position in plist
    fseek(fp,(cn-1) * (sizeof(FD)+1),SEEK_SET);
    fread(fdp, sizeof(FD),1,fp);

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
FUNCTION:forecast
DESCRIPTION: 根据数组x[], y[]的数据，用最小二乘法求拟合曲线
            近似解析表达式y = a0 + a1 * x + a2 * x^2 + a3 * x^3;
INPUT:
RETURN:result:预测值
************************************************************************/
int forecast(int *y,int *yy)
{
    int maxn = 7;
    int rank = 3;
    int column;
    float mainele, tempa, tempb, m, result;
    float sum;
    int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    float atemp[2 * (3 + 1)] = {0};
    float b[3 + 1] = {0};
    float a[3 + 1][3 + 1];
    int i, j, k;
    char fx[50];

    for(i = 0; i < maxn; i++) //准备的值
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
    for(i = 0; i < rank+1; i++)  //线性方程组系数矩阵a
    {  
        k = i;
        for(j = 0; j < rank+1; j++)
        {
            a[i][j] = atemp[k];
            k++;
        }  
    }

    //高斯列主元消去法解线性方程组
    for(k = 0; k < rank+1-1; k++) //n - 1列
    { 
        column = k;
        mainele = a[k][k];

        for(i = k; i < rank+1; i++) //找主元
        {
            if(fabs(a[i][k]) > mainele)
            {
                mainele = fabs(a[i][k]);
                column = i;
            }
        }
            
        for(j = k; j < rank+1; j++) //交换两行
        { 
            tempa = a[k][j];
            a[k][j] = a[column][j];
            a[column][j] = tempa;
        }
        tempb = b[k];
        b[k] = b[column];
        b[column] = tempb;

        for(i = k+1; i < rank+1; i++) //消元
        { 
            m = a[i][k] / a[k][k];
            for(j = k; j < rank+1; j++)  
            {
                a[i][j] -= m * a[k][j];
            }
            b[i] -= m * b[k];
        }
    }
    b[rank +1-1] /= a[rank +1-1][rank +1-1];  //回代
    for(i = rank +1-2; i >= 0; i--)
    {
        sum = 0;
        for(j = i+1; j < rank+1; j++)  
        {
            sum += a[i][j] * b[j];
        }
        b[i] = (b[i] - sum) / a[i][i];
    }
    
    //sprintf(fx,"%d +%dx+%dx^2+%dx^3", b[0], b[1], b[2], b[3]);
    //outtextxy(200,300,fx);
    //printf("P(x) = %f%+fx%+fx^2%+fx^3\n\n", b[0], b[1], b[2], b[3]);
    for(i = 0; i < maxn+1; i++)
    { 
        *(yy + i)= b[0] + b[1]*x[i] + b[2]*x[i]*x[i] + b[3]*x[i]*x[i]*x[i];
        //temp = b[0] + b[1] * x[i] + b[2] * x[i] * x[i] + b[3] * x[i] * x[i] * x[i];
        //printf("%f    %f    error: %f\n", y[i], temp, temp - y[i]);
    }

    result = b[0] + b[1]*8 + b[2]*64 + b[3]*512;
    return result;
}

/************************************************************************
FUNCTION:up_flist
DESCRIPTION: 系统预测界面分配数量函数
INPUT:ctn：食堂编号，n：第一个或第二个，page：当前页码，a：数量
RETURN:
************************************************************************/
int up_flist(int ctn, int n, int page, int a)
{
    FILE *fp;
    FF *ffp;    
    int errNum;
    int i = 0;
    int cn = 0;//总位置
	int len = 0;
    char ca[8];
    char floc[40];
    char temp[10];

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
        printf("memoryallocation runs wrong in fdp,up_order");
        delay(3000);
        exit(1);
    }

    sprintf(floc,"c:\\test\\data\\canteen\\ct%d\\%sf.dat", ctn, stime);
    if ((fp = fopen(floc, "rb+" )) == NULL)
    {
        errNum = errno;
        closegraph();
        printf("cannot open file flist,up_flist\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / (sizeof(FF)+1);

    cn = (page - 1)*2 + n;//position in file
    fseek(fp,(cn-1) * (sizeof(FF)+1),SEEK_SET);
    fseek(fp, 33, SEEK_CUR);

    itoa(a, ca, 10);
    i = 0;
    while (*(ca+i) != '\0')
    {
        *(ffp->dis+i) = *(ca+i);
        fputc(*(ca+i), fp);
        i++;
    }

    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close flist,up_flist");
        delay(3000);
        exit(1);
    }

    return 0;
}


/************************************************************************
FUNCTION:sum
DESCRIPTION: 采购目录界面对分配数量求和
INPUT:
RETURN:
************************************************************************/
int sum()
{
    
    FILE *fp;
    FILE *fp2;
    FF *ffp;
    FD *fdp;
    int i, j, k, l= 0;
    int len, len2, errNum;
    long int t, t2;
    char tc[7];
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

    if ((ffp = (FF*)malloc(sizeof(FF))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in ffp,sum");
        delay(3000);
        exit(1);
    }
    if ((fdp = (FD*)malloc(sizeof(FD))) == NULL)
    {
        closegraph();
        printf("memoryallocation runs wrong in fdp,sum");
        delay(3000);
        exit(1);
    }

    sprintf(floc,"c:\\test\\data\\plist\\%sp.dat",stime);
    if ((fp2 = fopen(floc, "rb+" )) == NULL) //plist
    {
        errNum = errno;
        closegraph();
        printf("cannot open file plist,sum\n");
        printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
        delay(5000);
        exit(1);
    }

    fseek(fp2, 0, SEEK_END);
    len2 = ftell(fp2) / (sizeof(FD)+1);//length of plist
    
    for (i = 0; i < len2; i++) //reset plist
    {
        fseek(fp2, i*(sizeof(FD)+1), SEEK_SET);
		fseek(fp2, 38, SEEK_CUR);
        fputc('0', fp2);
        for (j = 0; j < 6; j++)
        {
            fputc('\0', fp2);            
        }
    }

    for (i = 0; i < 4; i++) //4 canteen
    {
        sprintf(floc,"c:\\test\\data\\canteen\\ct%d\\%sf.dat",i+1,stime);
        if ((fp = fopen(floc, "rb+" )) == NULL) //flist
        {
            errNum = errno;
            closegraph();
            printf("cannot open file flist,sum\n");
            printf("open fail errno = %d reason = %s \n", errNum, strerror(errNum));
            delay(5000);
            exit(1);
        }

        fseek(fp, 0, SEEK_END);
        len = ftell(fp) / (sizeof(FF)+1);//length of flist

        for (j = 0; j < len; j++) //food in canteen
        {
            fseek(fp, j*(sizeof(FF)+1), SEEK_SET);
            fread(ffp, sizeof(FF), 1, fp);

            for (k = 0; k < len2; k++) //food in plist
            {
                fseek(fp2, k*(sizeof(FD)+1), SEEK_SET);
                fread(fdp, sizeof(FD), 1, fp2);
                if (strcmp(fdp->name,ffp->name) == 0)
                {
                    t = atol(ffp->dis);
                    t2 = atol(fdp->est);
                    t2 += t;
                    ltoa(t2, tc, 10);
                    fseek(fp2, -20, SEEK_CUR);
                    l = 0;
                    while (*(tc+l) != '\0')
                    {
                        *(fdp->est+l) = *(tc+l);
                        fputc(*(tc+l), fp2);
                        l++;
                    }
                    *(fdp->est+l) = '\0';
                    fputc('\0', fp2);
                    break;
                }                
            } //end of fdp
        } //end of food
        if (fclose(fp) != 0)
        {
            closegraph();
            printf("\n cannot close flist,sum");
            delay(3000);
            exit(1);
        }
    } //end of canteen

    free(ffp);
    free(fdp);

    if (fclose(fp2) != 0)
    {
        closegraph();
        printf("\n cannot close plist,sum");
        delay(3000);
        exit(1);
    }

    return 0;
}
