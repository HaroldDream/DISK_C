#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void logistic_ad(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(2,0);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *fun = 4;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(2,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(2,1);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(2,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }

        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *fun = 1;
            return;
        }
        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *fun = 0;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *fun = 3;
            return;
        }
    }
}