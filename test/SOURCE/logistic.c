#include "common.h"
#include "admain.h"
#include "drawad.h"

void logistic_ad(int *fun)
{
    int op = 1;
    int t[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int t2[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int insided[6] = {0,0,0,0,0,0};//�ж�У���Ƿ񷢻�
    while (1)
    {
        switch(op)
        {
            case 0: 
                *fun= 0;				//�˳�����¼����
				return ;
            case 1: 
                wlcx(&op,t,t2,insided);         //������ѯ
                break;
            case 2: 
                sh(&op,t);         //�ջ�
                break;
            case 3: 
                fh(&op,insided);         //����
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
void wlcx(int *op,int *t,int*t2,int *insided)
{
    int recent = 1,all = 1;
    int code = 1;//code����״̬ģʽѡ��1ΪУ�⣬0ΪУ��
    int type = 1,otype;//������ѯ����
    int i;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(2,0);
    delay(50);
    logisticsrd(recent,&all,code,type,*(t+type-1));//����״̬��ʾ

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    
        if(mouse_press(3,360,109,376) == 1)//״̬ˢ��
        {
            if(code == 1 )
            {
                *(t+type-1) = *(t+type-1)+1;
                delay(100);
                drawad(2,0);
                logisticsrd(recent,&all,code,type,*(t+type-1));//У������״̬��ʾ
            }
            else if (code == 0 && *(insided+type-1))
            {
                *(t2+type-1) = *(t2+type-1)+1;
                delay(100);
                drawad(2,3);
                logisticsrd(recent,&all,code,type,*(t2+type-1));//У������״̬��ʾ
            }
        }
        if(mouse_press(310,50,410,80) == 1)//У���������л�
        {
            code = 1-code;
            if(code == 1)
            {
                delay(100);
                drawad(2,0);
                logisticsrd(recent,&all,code,type,*(t+type-1));//У������״̬��ʾ
            }
            else if(code == 0)
            {
                delay(100);
                drawad(2,3);
                logisticsrd(recent,&all,code,type,*(t2+type-1));//У������״̬��ʾ
            }         
        }
        if(mouse_press(510,50,610,80) == 1)//��ѯ�����л�
        {
            typemenu_lg(1);
            while(1)
            {
                newmouse(&MouseX, &MouseY, &press);
                otype = type;
                for(i=0;i<6;i++)
                {
                    if (mouse_press(520,80+30*i,600,80+30*(i+1)) == 1)
                    {
                        type = i+1;
                        if(code == 1)
                        {
                            delay(100);
                            drawad(2,0);
                            recent = 1;
                            all = 1;
                            logisticsrd(recent,&all,code,type,*(t+type-1));//У������״̬��ʾ
                        }
                        else if(code == 0)
                        {
                            delay(100);
                            drawad(2,3);
                            recent = 1;
                            all = 1;
                            logisticsrd(recent,&all,code,type,*(t2+type-1));//У������״̬��ʾ
                        }
                    } 
                }
                if(otype != type)
                {
                    break;
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
                logisticsrd(recent,&all,code,type,*(t+type-1));//У������״̬��ʾ
            }
            else if(code == 0)
            {
                delay(100);
                drawad(2,3);
                logisticsrd(recent,&all,code,type,*(t2+type-1));//У������״̬��ʾ
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
                logisticsrd(recent,&all,code,type,*(t+type-1));//У������״̬��ʾ
            }
            else if(code == 0)
            {
                delay(100);
                drawad(2,3);
                logisticsrd(recent,&all,code,type,*(t2+type-1));//У������״̬��ʾ
            }
        }
        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,91,140,129) == 1)//�ջ�
        {
            *op = 2;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//����
        {
            *op = 3;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
            return;
        }
        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}
void sh(int *op,int *t)
{
    int recent = 1,all = 1;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(2,1);
    shouhuo(t);		
    delay(50);
    shourd(recent,&all);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    
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
        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//������ѯ
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//����
        {
            *op = 3;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
            return;
        }
        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}
void fh(int *op,int *insided)
{
    int recent = 1,all = 1;
    int chos = 0,i;

	time_t timep;//�ļ�ʱ��
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
    sprintf(stime,"%d.%d %d:%d",1+p->tm_mon,p->tm_mday,p->tm_hour-4,p->tm_min);   
   
    clrmous(MouseX,MouseY);
    delay(100);
    drawad(2,2);
    fahuord(recent,&all);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);
        for(i=1;i<7;i++) //��������
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
        if(chos!= 0) 				
		{
            delay(100);
            drawad(2,2);
            fahuord(recent,&all);
            setfillstyle(SOLID_FILL,WHITE);
            bar(468,55+30*chos,525,55+30*(chos+1));
            puthz(470,58+30*chos,"�ѷ���",16,18,BLUE);
            setcolor(BLUE);
	        outtextxy(547,58+30*chos,stime);
            *(insided+chos-1) = 1;
			chos = 0;
			continue;
		}
    
        
        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//������ѯ
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,91,140,129) == 1)//�ջ�
        {
            *op = 2;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
            return;
        }
        if(mouse_press(300,0,400,40) == 1)//�ɹ�
        {
            *op = 4;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *op = 6;
            return;
        }
    }
}

/*void logistic_ad(int *fun)
{
    int num = 1,i;
    int t[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int t2[6] = {0,0,0,0,0,0};//tΪ��ǰУ����������
    int code = 1;//num�����л���code����״̬ģʽѡ��1ΪУ�⣬0ΪУ��
    int type = 1,otype;//������ѯ����
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
            if(mouse_press(510,50,610,80) == 1)//��ѯ�����л�
            {
                typemenu_lg(1);
                while(1)
                {
                    newmouse(&MouseX, &MouseY, &press);
                    otype = type;
                    for(i=0;i<6;i++)
                    {
                        if (mouse_press(520,80+30*i,600,80+30*(i+1)) == 1)
                        {
                            type = i+1;
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
                    if(otype != type)
                    {
                        break;
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
*/
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