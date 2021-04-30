#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "pfile.h"
#include "pfunc.h"
#include "purchase.h"

void purchase(int *fun)
{
    int op = 2;
    int num = 1;
    int day = 0;
    int type = 0;
    while (1)
    {
        switch(op)
        {
            case 0: 
                *fun= 0;				//退出至登录界面
				return ;
            case 1: 
                xtyc(&op, &num);
                break;
            case 2: 
                cgml(&op, &type);
                break;
            case 3: 
                cgd(&op, &day);
                break;
            case 4:
                *fun = 1; //采购
                return;
            case 5:
                *fun = 2; //物流
                return;
            case 6:
                *fun = 3; //信息
                return;
            case 7:
                *fun = 4; //仓储
                return;
            default:
                break;
        }
    }
}

void cgml(int *op, int *type)
{
    int page = 1, a = 0;
    int i = 0;
    int flag = 0, flag2 = 0; //判断是否点击

    clrmous(MouseX,MouseY);
    delay(100);
    sum();
    drawad(1,1);
    show_plist(1,*type);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);   
        
        for (i = 0; i < 12; i++)
        {
            if (mouse_press(600,80+30*i,640,110+30*i) == 1) //click purchase
            {
                flag = 1;
                a = pop(1); //amount of purchase
                if (a != 0) 
                {
                    up_order(i,a,page);
                    a = 0;
                    page = 1;
                    break;
                }
                else 
                    break;                
            }
            if (flag == 1) 
            {
                return;
            }
        }


        if(mouse_press(10,200,130,230) == 1)//条件筛选
        {
            delay(100);
            flag2 = 1;

            clrmous(MouseX, MouseY);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(10,230,130,230+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(10,230,130,230+30*6);
            puthz(50,238,"蔬菜",16,18,DARKGRAY);
            puthz(50,238+30,"肉类",16,18,DARKGRAY);
            puthz(50,238+30*2,"水产",16,18,DARKGRAY);
            puthz(50,238+30*3,"调料",16,18,DARKGRAY);
            puthz(45,238+30*4,"粮油面",16,18,DARKGRAY);
            puthz(50,238+30*5,"其他",16,18,DARKGRAY);    
            newmouse(&MouseX, &MouseY, &MouseS);      
        }
        if (flag2 == 1)
        {
            for (i = 0; i < 6; i++)
            {
                if (mouse_press(10,230+i*30,130,260+i*30) == 1)
                {
                    delay(100);
                    *type = i+1;
                    return;
                }
            }
        }

        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//上一页
        {
            delay(100);
            drawad(1,1);
            show_plist(page - 1,*type);
            page--;
        }
        if ((mouse_press(560,445,610,480) == 1) && (page < show_plist(page,*type)))//下一页
        {
            delay(100);
            drawad(1,1);
            show_plist(page + 1,*type);
            page++;
        }

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//系统预测
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//采购单
        {
            *op = 3;
            return;
        }
        if(mouse_press(0,91,140,129) == 1)//采购目录
        {
            *op = 2;
            *type = 0;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *op = 7;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//物流
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *op = 6;
            return;
        }
    }


}

void xtyc(int *op, int *num)
{
    int page = 1;
    //int num = 1; //canteen number
    int n = 1; //current number
    int a = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(1,0);
    show_flist(*num,1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    

        
        if (mouse_press(560,50,630,80) == 1) //分配1
        {
            n = 1;
            a = pop(2); //amount of purchase
            if ((a != 0)) 
            {
                up_flist(*num,n,page,a);
                a = 0;
                break;
            }
            else break;

        }
        if (mouse_press(560,245,630,275) == 1) //分配2
        {
            n = 2;
            a = pop(2); //amount of purchase
            if ((a != 0)) 
            {
                up_flist(*num,n,page,a);
                a = 0;
                break;
            }
            else break;
        }
        

        if ((mouse_press(5,245,70,270) == 1) && (*num > 1)) //last canteen
        {
            *num = *num - 1;
            return;
        }
        if ((mouse_press(75,245,135,270) == 1) && (*num < 4)) //next canteen
        {
            *num = *num + 1;
            return;
        }

        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//上一页
        {
            drawad(1,0);
            show_flist(*num,page - 1);
            page -= 1;
            delay(100);
        }
        if ((mouse_press(560,445,610,480) == 1) && (page < show_flist(*num, page)))//下一页
        {
            drawad(1,0);
            show_flist(*num,page + 1);
            page += 1;
            delay(100);
        }


        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,91,140,129) == 1)//采购目录
        {
            *op = 2;
            //*type = 0;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//采购单
        {
            *op = 3;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *op = 7;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//物流
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *op = 6;
            return;
        }
    }
    return;
}

void cgd(int *op, int *day)
{
    int page = 1;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(1,2);
    show_order(1, *day);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    
        /*
        if ((mouse_press(5,245,70,270) == 1) && (*day > -4))
        {
            *day = *day - 1;
            return;
        }
        if ((mouse_press(75,245,135,270) == 1) && (*day < 0))
        {
            *day = *day + 1;
            return;
        }*/


        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//上一页
        {
            drawad(1,2);
            show_order(page - 1, *day);
            page -= 1;
        }
		if ((mouse_press(560,445,610,480) == 1) && (page < show_order(page, *day)))//下一页
        {
            drawad(1,2);
            show_order(page + 1, *day);
            page += 1;
        }


        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//系统预测
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,91,140,129) == 1)//采购目录
        {
            *op = 2;
            //*type = 0;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *op = 7;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//物流
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *op = 6;
            return;
        }
    }
}

/************************************************************************
FUNCTION:pop
DESCRIPTION: 采购弹窗：n=1，数量填写；n=2时，采购成功
INPUT:num
RETURN:0：未更改，返回；1：成功，返回；a： 返回采购数量
************************************************************************/
int pop(int n)
{
	int a = 0, len = 0;//数量
    char i[10];
    void *buffer;
	unsigned s;
    clrmous(MouseX, MouseY);

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
            puthz(344,267,"返回",16,20,BLUE);
            puthz(264,267,"确定",16,20,BLUE);
            break;
        case 2:
            rectangle(240,220,400,250);
            puthz(247,227,"分配数量：",16,18,BLUE);	
            rectangle(340,265,380,285);
            rectangle(260,265,300,285);
            puthz(344,267,"返回",16,20,BLUE);
            puthz(264,267,"确定",16,20,BLUE);
            break;
    }

	while ((n == 1) || (n == 2))
	{
		newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(240,220,400,250) == 1)
        {
            clrmous(MouseX,MouseY);
            len= hz_input(335,220,400,250,i,len,WHITE);
        }

		if (mouse_press(260,265,300,285) == 1)//确定
		{
            if (len != 0)
            {
                clrmous(MouseX, MouseY);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                if (n == 1)
                    puthz(260,230,"采购成功",16,20,BLUE);
                else if (n == 2)
                    puthz(260,230,"分配成功",16,20,BLUE);
                delay(1000);
                a = atoi(i);
                return a;
            }
            else 
            {
                clrmous(MouseX, MouseY);
                delay(10);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                puthz(250,230,"请输入数量",16,20,BLUE);
                delay(1000);
                return 0;                
            }
		}
        
		if (mouse_press(340,265,380,285) == 1)//返回
		{
			clrmous(MouseX, MouseY);
			delay(10);
			return 0;
		}
    }
    return -1;
}


