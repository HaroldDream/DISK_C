#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void logistic_ad(int *fun)
{
    int num = 1,i;
    int t[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int t2[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int code = 1;//num�����л���code����״̬ģʽѡ��1ΪУ�⣬0ΪУ��
    int type = 1;//������ѯ����
    int recent = 1,all = 1;
    char gys[30][12];
    memset(gys,'\0',sizeof(gys));
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(2,0);
    logisticsrd(recent,&all,code,type,t[type-1]);//����״̬��ʾ

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//������ѯ
        {
            num = 1;
            type = 1;//������ѯ����
            code = 1;//num�����л���code����״̬ģʽѡ��
            delay(100);
            clrmous(MouseX, MouseY);
            cleardevice();
            drawad(2,0);
            delay(50);
            logisticsrd(recent,&all,code,type,t[type-1]);//����״̬��ʾ
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)//�ջ�
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
        if(mouse_press(0,131,140,169) == 1)//����
        {
            num = 3;
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(2,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        
        if(num == 1)//������ѯ
        {
            type = 1;//������ѯ����
            code = 1;//num�����л���code����״̬ģʽѡ��
            if(mouse_press(3,360,109,376) == 1)//״̬ˢ��
            {
                if(code == 1 )
                {
                    t[type-1] = t[type-1]+1;
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//У������״̬��ʾ
                }
                else
                {
                    t2[type-1] = t2[type-1]+1;
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//У������״̬��ʾ
                }
                
            }
            if(mouse_press(310,50,410,80) == 1)//У���������л�
            {
                code = 1-code;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//У������״̬��ʾ
                }
                else if(code == 0)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//У������״̬��ʾ
                } 
                
            }
            if(mouse_press(510,50,610,80) == 1)//!!!!!!!��ѯ�����л�
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
                            logisticsrd(recent,&all,code,type,t[type-1]);//У������״̬��ʾ
                        }
                        else if(code == 0)
                        {
                            delay(100);
                            drawad(2,3);
                            logisticsrd(recent,&all,code,type,t2[type-1]);//У������״̬��ʾ
                        }
                    }
                }
            }
           
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
            {
                while(mouse_press(570,450,630,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent++;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//У������״̬��ʾ
                }
                else if(code == 3)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//У������״̬��ʾ
                }		
            }	
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
            {
                while(mouse_press(510,450,565,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent--;
                if(code == 1)
                {
                    delay(100);
                    drawad(2,0);
                    logisticsrd(recent,&all,code,type,t[type-1]);//У������״̬��ʾ
                }
                else if(code == 3)
                {
                    delay(100);
                    drawad(2,3);
                    logisticsrd(recent,&all,code,type,t2[type-1]);//У������״̬��ʾ
                }
            }   
        }
        if(num == 2)//�ջ�
        {
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
            {
                while(mouse_press(570,450,630,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent++;
                drawad(2,1);
                delay(50);
                shourd(recent,&all);
            }	
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
            {
                while(mouse_press(510,450,565,480) ==1 )	
                newmouse(&MouseX, &MouseY, &press);
                recent--;
                drawad(2,1);
                delay(50);
                shourd(recent,&all);
            }   
        }
        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *fun = 1;
            return;
        }
        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *fun = 4;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
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

        if(mouse_press(0,440,45,480) == 1)//�˳�
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

        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {

            *fun = 1;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//����
        {
            *fun = 2;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *fun = 3;
            return;
        }
        */
    }
}