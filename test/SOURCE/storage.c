#include "common.h"
#include "admain.h"
#include "drawad.h"

void storage_ad(int *fun)
{
    int op = 2;
    while (1)
    {
        switch(op)
        {
            case 0: 
                *fun= 0;				//�˳�����¼����
				return ;
            case 1: 
                kccx(&op);         //����ѯ
                break;
            case 2: 
                rk(&op);         //���
                break;
            case 3: 
                ck(&op);         //����
                break;
            case 4:
                *fun = 1; //�ɹ�
                return;
            case 5:
                *fun = 2; //����
                return;
            case 6:
                *fun = 3; //��Ϣ
                return;
            case 7:
                *fun = 4; //�ִ�
                return;
        }
    }
}
void kccx(int *op)
{
    int recent = 1,all = 1;
   // int dqfn = 1,dqt = 0;//��ǰ�ļ����ƣ���ǰ�ļ���ȡ����
    int tp = 1,otype;//����
    int i;

    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(0,0);
    kucunrd(recent,&all,tp);
    
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if(mouse_press(3,360,110,376) == 1)//����ɸѡ:��ѯ�����л�
        {
            typemenu_lg(2);
            while(1)
            {
                newmouse(&MouseX, &MouseY, &press);
                otype = tp;
                for(i=0;i<6;i++)
                {
                    if (mouse_press(20,162+30*i,100,162+30*(i+1)) == 1)
                    {
                        tp = i+1;
                        delay(100);
                        drawad(0,0);
                        recent = 1;
                        all = 1;
                        kucunrd(recent,&all,tp);
                    }
                     
                }
                if(otype != tp)
                {
                    break;
                }
            }
        }    
        if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
        {
            recent++;
            cleardevice();
            drawad(0,0);
            delay(50);
            kucunrd(recent,&all,tp);			
        }	
        
        if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
        {
            recent--;
            cleardevice();
            drawad(0,0);
            delay(50);
            kucunrd(recent,&all,tp);
        }

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,91,140,129) == 1)//���
        {
            *op = 2;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//����
        {
            *op = 3;
            return;
        }

        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//����
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}
void rk(int *op)
{
    int recent = 1,all = 1;
    int chos = 0,i;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(0,1);
    storagerd(recent,&all);//������ʾ

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);   
        
        for(i=1;i<13;i++)
        {
            if (mouse_press(457,80+30*(i-1),457+60,80+30*i) == 1)
            {
                while(mouse_press(457,80+30*(i-1),457+60,80+30*i) ==1 )
                {
                    newmouse(&MouseX, &MouseY, &press);
                }
				if(chos == 0) chos = i;
            }
        }
        if(chos!= 0) 											//�������
		{
            ruku(chos,recent);
            drawad(0,1);
            delay(50);
            storagerd(recent,&all);//������ʾ
			chos = 0;
			continue;
		}

        if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
        {
            recent++;
            cleardevice();
            drawad(0,1);
            delay(50);
            storagerd(recent,&all);			
        }	
        
        if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
        {
            recent--;
            cleardevice();
            drawad(0,1);
            delay(50);
            storagerd(recent,&all);
        }

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//����ѯ
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//����
        {
            *op = 3;
            return;
        }

        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//����
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}
void ck(int *op)
{
    int recent = 1,all = 1;
    int canteennum = 1,oct;
    int i;
    char type[6];
    char name[10];

    time_t timep;//�ļ�ʱ��
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    sprintf(stime,"%d.%d.%d %d:%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour-4,p->tm_min);   

    memset(type,'\0',sizeof(type));
    memset(name,'\0',sizeof(name));
    clrmous(MouseX,MouseY);
    delay(100);
    drawad(0,2);
    chukurd(recent,&all,canteennum);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    
        if(mouse_press(3,360,110,376) == 1)//����ɸѡ:��ѯʳ���л�
        {
            typemenu_lg(3);
            while(1)
            {
                newmouse(&MouseX, &MouseY, &press);
                oct = canteennum;
                for(i=0;i<4;i++)
                {
                    if (mouse_press(20,222+30*i,100,222+30*(i+1)) == 1)
                    {
                        canteennum = i+1;
                        delay(100);
                        drawad(0,2);
                        recent = 1;
                        all = 1;
                        chukurd(recent,&all,canteennum);
                    }
                     
                }
                if(oct != canteennum)
                {
                    break;
                }
            }
        }
        if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
        {
            recent++;
            cleardevice();
            drawad(0,2);
            delay(50);
            chukurd(recent,&all,canteennum);		
        }	
        
        if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
        {
            recent--;
            cleardevice();
            drawad(0,2);
            delay(50);
            chukurd(recent,&all,canteennum);
        }

        if((mouse_press(20,392,120,422)==1))//ȷ�ϳ���
        {
            cleardevice();
            drawad(0,2);
            delay(50);
            chukurd(recent,&all,canteennum);
            setcolor(BLUE);
	        outtextxy(495,88,stime);
            chuku(canteennum);
            ckmanage(type,name);
            //!!!!!!���ѿ�浯��		
        }

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,91,140,129) == 1)//���
        {
            *op = 2;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//����ѯ
        {
            *op = 1;
            return;
        }

        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//����
        {
            *op = 5;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}
/*void storage_ad(int *fun)
{
    int num = 1,i,withdw = 1;
    int recent = 1,all = 1;
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(0,0);
    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1) //���
        {
            num = 1;
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(0,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,91,140,129) == 1)//���
        {
            num = 2;
            recent = 1;
            all = 1;
            delay(100);
            clrmous(MouseX, MouseY);
            cleardevice();
            drawad(0,1);
            delay(50);
            storagerd(recent,&all);//������ʾ
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(0,131,140,169) == 1)//����
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
            
            while(withdw)
            {
                newmouse(&MouseX, &MouseY, &press);
                for(i=0;i<12;i++)
                {
                    if (mouse_press(457,80+30*(i),457+60,80+30*(i+1)) == 1)
                    {
                        ruku(i,recent);
                        withdw = 0;
                        drawad(0,1);
                        delay(50);
                        storagerd(recent,&all);//������ʾ
                    }
                }
                
            }
            withdw = 1;
            if((mouse_press(570,450,630,480)==1)&&(all>recent))//��һҳ
            {
                recent++;
                cleardevice();
                drawad(0,1);
                delay(50);
                storagerd(recent,&all);			
            }	
            
            if((mouse_press(510,450,565,480)==1)&&(recent>1))//��һҳ
            {
                recent--;
                cleardevice();
                drawad(0,1);
                delay(50);
                storagerd(recent,&all);
            }
                
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
        
    }
}*/

void storage_us(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawuser(0,0);

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