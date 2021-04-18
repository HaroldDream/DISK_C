#include "common.h"
#include "admain.h"
#include "drawadmin.h"
#include "storage.h"

void storage_ad(int *fun)
{
    int num = 1,i;
    int recent = 1,all = 1;
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(0,0);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1) //库存
        {
            num = 1;
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(0,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)//入库
        {
            num = 2;
            recent = 1;
            all = 1;
            delay(100);
            clrmous(MouseX, MouseY);
            cleardevice();
            drawad(0,1);
            delay(50);
            storagerd(recent,&all);//数据显示
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)//出库
        {
            num = 3;
            delay(100);
            clrmous(MouseX, MouseY);
            cleardevice();
            drawad(0,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(num == 2)
        {
            for(i=0;i<12;i++)
            {
                if (mouse_press(457,80+30*(i+1),457+60,80+30*(i+2)) == 1)
                {
                    ruku(i,recent);
                }
            }
            
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//下一页
            {
                while(mouse_press(570,450,630,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent++;
                cleardevice();
                drawad(0,1);
                delay(50);
                storagerd(recent,&all);			
            }	
            
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//上一页
            {
                while(mouse_press(510,450,565,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent--;
                cleardevice();
                drawad(0,1);
                delay(50);
                storagerd(recent,&all);
            }
                
        }
        if(mouse_press(300,0,400,40) == 1)//采购
        {

            *fun = 1;
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

void storage_us(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawuser(0,0);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 0;
            return;
        }
        /*if(mouse_press(0,51,140,89) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(0,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(0,1);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(0,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }

        if(mouse_press(300,0,400,40) == 1)//采购
        {

            *fun = 1;
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
        */
    }
}