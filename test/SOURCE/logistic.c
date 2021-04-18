#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void logistic_ad(int *fun)
{
    int num = 1,i;
    int t[6] = {0,0,0,0,0,0};//t为当前校外数据条数
    int t2[6] = {0,0,0,0,0,0};//t为当前校内数据条数
    int code = 1;//num功能切换，code物流状态模式选择1为校外，0为校内
    int type = 1;//物流查询种类
    int recent = 1,all = 1;
    char gys[30][12];
    memset(gys,'\0',sizeof(gys));
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(2,0);
    logisticsrd(recent,&all,code,type,t[type-1]);//物流状态显示

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//物流查询
        {
            num = 1;
            type = 1;//物流查询种类
            code = 1;//num功能切换，code物流状态模式选择
            delay(100);
            clrmous(MouseX, MouseY);
            cleardevice();
            drawad(2,0);
            delay(50);
            logisticsrd(recent,&all,code,type,t[type-1]);//物流状态显示
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)//收货
        {
            num = 2;
            recent = 1;
            all = 1;
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(2,1);
            shouhuo(t);		
            delay(50);
            shourd(recent,&all);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)//发货
        {
            num = 3;
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(2,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        
        if(num == 1)//物流查询
        {
            type = 1;//物流查询种类
            code = 1;//num功能切换，code物流状态模式选择
            if(mouse_press(3,360,109,376) == 1)//状态刷新
            {
                if(code == 1 )
                {
                    t[type-1] = t[type-1]+1;
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//校外物流状态显示
                }
                else
                {
                    t2[type-1] = t2[type-1]+1;
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//校内物流状态显示
                }
                
            }
            if(mouse_press(310,50,410,80) == 1)//校内外物流切换
            {
                code = 1-code;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//校外物流状态显示
                }
                else if(code == 0)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//校内物流状态显示
                } 
                
            }
            if(mouse_press(510,50,610,80) == 1)//!!!!!!!查询种类切换
            {
                typemenu_lg(1);
                for(i=0;i<6;i++)
                {
                    newmouse(&MouseX, &MouseY, &press);
                    if (mouse_press(520,80+30*i,600,80+30*(i+1)) == 1)
                    {
                        type = i+1;
                        closegraph();
                        printf("%d",type);
                        delay(3000);
                        if(code == 1)
                        {
                            delay(100);
                            drawad(2,0);
                            logisticsrd(recent,&all,code,type,t[type-1]);//校外物流状态显示
                        }
                        else if(code == 0)
                        {
                            delay(100);
                            drawad(2,3);
                            logisticsrd(recent,&all,code,type,t2[type-1]);//校内物流状态显示
                        }
                    }
                }
            }
           
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//下一页
            {
                while(mouse_press(570,450,630,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent++;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//校外物流状态显示
                }
                else if(code == 3)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//校内物流状态显示
                }		
            }	
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//上一页
            {
                while(mouse_press(510,450,565,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent--;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//校外物流状态显示
                }
                else if(code == 3)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//校内物流状态显示
                }
            }   
        }
        if(num == 2)//收货
        {
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//下一页
            {
                while(mouse_press(570,450,630,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent++;
                drawad(2,1);
                delay(50);
                shourd(recent,&all);
            }	
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//上一页
            {
                while(mouse_press(510,450,565,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent--;
                drawad(2,1);
                delay(50);
                shourd(recent,&all);
            }   
        }
        if(mouse_press(300,0,400,40) == 1)//采购
        {
            *fun = 1;
            return;
        }
        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *fun = 4;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *fun = 3;
            return;
        }
    }
}

void logistic_us(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawuser(1,0);

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