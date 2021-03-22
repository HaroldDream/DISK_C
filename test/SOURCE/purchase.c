#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void purchase(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(1,1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 4;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(1,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,1);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(10,390,130,430) == 1)
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
            *fun = 0;
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