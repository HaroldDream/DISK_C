#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "drawuser.h"
#include "infof.h"
#include "info.h"

void info_ad(int *fun)
{
    int op = 1;
    //int num = 1;
    int day = 0;
    //int type = 0;
    while (1)
    {
        switch(op)
        {
            case 0: 
                *fun= 0; //退出至登录界面
				return ;
            case 1: 
                ddcx(&op, &day);
                break;
            /*case 2: 
                gys(&op);
                break;
            case 3: 
                cgd(&op, &day);
                break;*/
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


void ddcx(int *op, int *day)
{
    int page = 1;
    int i = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(3,0);
    show_ddcx(1,*day);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    

        if ((mouse_press(210,80,275,110) == 1) && (*day > -6))
        {
            *day = *day - 1;
            return;
        }
        if ((mouse_press(280,80,340,110) == 1) && (*day < 0))
        {
            *day = *day + 1;
            return;
        }
        if ((mouse_press(160,80,200,110) == 1) && (*day > -6))
        {
            *day = -6;
            return;
        }
        if ((mouse_press(350,80,390,110) == 1) && (*day < 0))
        {
            *day = 0;
            return;
        }


        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//上一页
        {
            drawad(3,0);
            show_ddcx(page - 1, *day);
            page -= 1;
        }
		if ((mouse_press(560,445,610,480) == 1) && (page < show_ddcx(page, *day)))//下一页
        {
            drawad(3,0);
            show_ddcx(page + 1, *day);
            page += 1;
        }


        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *op = 0;
            return;
        }

        /*if(mouse_press(0,91,140,129) == 1)//供应商
        {
            *op = 2;
            return;
        }*/

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
        if(mouse_press(300,0,400,40) == 1)//采购
        {
            *op = 4;
            return;
        }
    }

}

void stsb(int *op, int *num)
{
    int page = 1;
    int i = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(3,1);
    show_ddcx(1,*day);
}

void kccx(int *op, int *num)
{
    int page = 1;
    int i = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(3,2);
    show_ddcx(1,*day);
}