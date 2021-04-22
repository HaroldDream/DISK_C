#include "common.h"
#include "admain.h"
#include "drawad.h"
#include "pfile.h"

void purchase(int *fun)
{
    int op = 2;
    int num = 1;
    int day = 0;
    while (1)
    {
        switch(op)
        {
            case 0: 
                *fun= 0;				//�˳�����¼����
				return ;
            case 1: 
                xtyc(&op,&num);
                break;
            case 2: 
                cgml(&op);
                break;
            case 3: 
                cgd(&op);
                break;
            case 4:
                *fun = 1;
                return;
            case 5:
                *fun = 2;
                return;
            case 6:
                *fun = 3;
                return;
            case 7:
                *fun = 4;
                return;
        }
    }
}

void cgml(int *op)
{
    int page = 1, n = 0, a = 0;
    int i = 0;
    int f = 0; //�ж��Ƿ���

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(1,1);
    show_plist(1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);   
        
        for (i = 0; i < 12; i++)
        {
            if (mouse_press(600,80+30*i,640,110+30*i) == 1)
            {
                n = i;
                f = 1;
                //break;
                a = pop(1); //amount of purchase
                if (a != 0) 
                {
                    up_order(n,a,page);
                    a = 0;
                    page = 1;
                    break;
                }
                else break;                
            }
            if (f == 1) 
            {
                return;
            }
        }


        if(mouse_press(10,390,130,430) == 1)//todo����ɸѡ
        {
            delay(100);

        }

        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//��һҳ
        {
            delay(100);
            drawad(1,1);
            show_plist(page - 1);
            page--;
        }
        if ((mouse_press(560,445,610,480) == 1) && (page < show_plist(page)))//��һҳ
        {
            delay(100);
            drawad(1,1);
            show_plist(page + 1);
            page++;
        }

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//ϵͳԤ��
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//�ɹ���
        {
            *op = 3;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
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

void xtyc(int *op)
{
    int page = 1;
    //int num = 1; //canteen number
    int n = 1; //current number
    int i = 0, a = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(1,0);
    show_flist(*num,1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    

        
        if (mouse_press(560,50,630,80) == 1) //����1
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
        if (mouse_press(560,245,630,275) == 1) //����2
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
        
        rectangle(5,240,70,260);
        rectangle(75,240,135,260);
        if ((mouse_press(5,240,70,270) == 1) && (*num > 1))
        {
            *num --;
            return;
        }
        if ((mouse_press(75,240,135,270) == 1) && (*num < 4))
        {
            *num ++;
            return;
        }

        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//��һҳ
        {
            drawad(1,0);
            show_flist(*num,page - 1);
            page -= 1;
            delay(100);
        }
        if ((mouse_press(560,445,610,480) == 1) && (page < show_flist(*num, page)))//��һҳ
        {
            drawad(1,0);
            show_flist(*num,page + 1);
            page += 1;
            delay(100);
        }


        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,91,140,129) == 1)//�ɹ�Ŀ¼
        {
            *op = 2;
            return;
        }
        if(mouse_press(0,131,140,169) == 1)//�ɹ���
        {
            *op = 3;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
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
    return;
}

void cgd(int *op)
{
    int page = 1;
    int i = 0;

    clrmous(MouseX,MouseY);
    delay(100);
    drawad(1,2);
    show_order(1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);    




        if ((mouse_press(510,445,560,480) == 1) && (page > 1))//��һҳ
        {
            drawad(1,2);
            show_plist(page - 1);
            page -= 1;
        }
        if ((mouse_press(560,445,610,480) == 1) && (page < show_order(page)))//��һҳ
        {
            drawad(1,2);
            show_plist(page + 1);
            page += 1;
        }


        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *op = 0;
            return;
        }

        if(mouse_press(0,51,140,89) == 1)//ϵͳԤ��
        {
            *op = 1;
            return;
        }
        if(mouse_press(0,91,140,129) == 1)//�ɹ�Ŀ¼
        {
            *op = 2;
            return;
        }

        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *op = 7;
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

/************************************************************************
FUNCTION:pop
DESCRIPTION: �ɹ�������n=1��������д��n=2ʱ���ɹ��ɹ�
INPUT:num
RETURN:0��δ���ģ����أ�1���ɹ������أ�a�� ���زɹ�����
************************************************************************/
int pop(int n)
{
	int a = 0, len = 0;//����
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
            puthz(247,227,"�ɹ�������",16,18,BLUE);	
            rectangle(340,265,380,285);
            rectangle(260,265,300,285);
            puthz(344,267,"����",16,20,BLUE);
            puthz(264,267,"ȷ��",16,20,BLUE);
            break;
        case 2:
            rectangle(240,220,400,250);
            puthz(247,227,"����������",16,18,BLUE);	
            rectangle(340,265,380,285);
            rectangle(260,265,300,285);
            puthz(344,267,"����",16,20,BLUE);
            puthz(264,267,"ȷ��",16,20,BLUE);
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

		if (mouse_press(260,265,300,285) == 1)//ȷ��
		{
            if (len != 0)
            {
                clrmous(MouseX, MouseY);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                if (n == 1)
                    puthz(260,230,"�ɹ��ɹ�",16,20,BLUE);
                else if (n == 2)
                    puthz(260,230,"����ɹ�",16,20,BLUE);
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
                puthz(250,230,"����������",16,20,BLUE);
                delay(1000);
                return 0;                
            }
		}
        
		if (mouse_press(340,265,380,285) == 1)//����
		{
			clrmous(MouseX, MouseY);
			delay(10);
			return 0;
		}
    }

    
}


