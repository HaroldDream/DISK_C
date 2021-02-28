#include "common.h"
#include "data.h"
#include "drawhome.h"
#include "register.h"
#include "input.h"

/********************************************
DESCRIPTION:ע��
INPUT:*func
RETURN:
********************************************/

void registermain (int *page)
{
    char U[15] = { '\0' };   //*6-12λ���û���
	char C[20] = { '\0' };   //*11λ����ϵ��ʽ
	char P[20] = { '\0' };   //*8-16λ������
	char CP[20] = { '\0' };  //*8-16λ��ȷ������
	int box1 = 0;            //*�����״̬
	int box2 = 0;
	int box3 = 0;
	int box4 = 0;
	int num;

	clrmous(MouseX,MouseY);
	delay(100);
	cleardevice();
	drawregister();

    while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
        if (MouseX > 240 && MouseX < 240+220 && MouseY>120 && MouseY < 120+40) //*�û�����
		{    
			 if(mouse_press(240,120,240+220,120+40) == 2)
           
		    {
				MouseS = 2;
			    if (num == 0 && box1 == 0) 
			    {
					num = 3;
					selectbutton_register(240,120,240+220,120+40,LIGHTGRAY,num);
			    }
		    	continue;
		    }

			else if (mouse_press(240,120,240+220,120+40) == 1)      
			{
				MouseS = 0;
				selectbutton_register(240,120,240+220,120+40, LIGHTGRAY, 1);
				U[0] = '\0';
				input(U, 240 , 120 , 12, LIGHTGRAY);//�������뺯��
				if(strlen(U) != 0)
					box1 = 1;
				else
					box1 = 0;
				continue;
			}
		}

		
         if (MouseX > 240 && MouseX < 240+220 && MouseY>120+60 && MouseY < 120+60+40) //*��ϵ�绰��
		{    
			if (mouse_press(240,120+60,240+220,120+60+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box2 == 0)                  //num = 0��ֹ�ظ�����
				{
					selectbutton_register(240,120+60,240+220,120+60+40, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}

			else if (mouse_press(240,120+60,240+220,120+60+40) == 1)      
			{
				MouseS = 0;
				selectbutton_register(240,120+60,240+220,120+60+40, LIGHTGRAY, 2);
				C[0] = '\0';
				input(C, 240 , 120+60 , 11, LIGHTGRAY);
				if(strlen(C) != 0)
					box2 = 1;
				else
					box2 = 0;
				continue;
			}
		}
        
       
	    if (MouseX > 240 && MouseX < 240+220 && MouseY>120+120 && MouseY < 120+120+40) //*�����
		{    
			if (mouse_press(240,120+120,240+220,120+120+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box3 == 0)                  //num = 0��ֹ�ظ�����
				{
					selectbutton_register(240,120+120,240+220,120+120+40, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}

			else if (mouse_press(240,120+120,240+220,120+120+40) == 1)      
			{
				MouseS = 0;
				selectbutton_register(240,120+120,240+220,120+120+40, LIGHTGRAY, 3);
				P[0] = '\0';
				inputmm(P, 240 , 120+120 , 16, LIGHTGRAY);
				if(strlen(P) != 0)
					box3 = 1;
				else
					box3 = 0;
				continue;
			}
		}
       
	    if (MouseX > 240 && MouseX < 240+220 && MouseY>120+180 && MouseY < 120+180+40) //*ȷ�������
		{    
			if (mouse_press(240,120+180,240+220,120+180+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box4 == 0)                  //num = 0��ֹ�ظ�����
				{
					selectbutton_register(240,120+180,240+220,120+180+40, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}

			else if (mouse_press(240,120+180,240+220,120+180+40) == 1)      
			{
				MouseS = 0;
				selectbutton_register(240,120+180,240+220,120+180+40, LIGHTGRAY, 4);
				CP[0] = '\0';
				inputmm(CP, 240 , 120+180 , 16, LIGHTGRAY);
				if(strlen(CP) != 0)
					box4 = 1;
				else
					box4 = 0;
				continue;
			}
		}

		if (MouseX > 280 && MouseX < 280+140 && MouseY>120+240 && MouseY < 120+240+40) //*ע���
	    {
			if(mouse_press(280,120+240,280+140,120+240+40) == 2)  
	        {
			    MouseS = 1;
		        continue;
		    }
		    else if(mouse_press(280,120+240,280+140,120+240+40) == 1 && box1*box2*box3*box4 == 1)
		    {
			    MouseS = 0;
				/*if (register_complete(U, C , P, CP,))
				{
					state=4;
					tanchuang(state);
					*page = 0;
					return;
				}
				else
				{
					continue;
				}*/
		    }
		}
		
		if(mouse_press(560-90+30,120+240,560+30-10,120+240+40) == 2) //*���ؼ�  
		{
			MouseS = 1;
		    continue;
		}
		else if(mouse_press(560+30-90,120+240,560-10+30,120+240+40) == 1)
		{
			*page = 0;
			return;
		}
		
		else //*ѭ���ָ�
		{
			if (num != 0)
		    {
			   MouseS = 0;	
			   if (box1 == 0)
			   {
				    recoverbutton_register(1);
			   }
			   if (box2 == 0)
			   {
				    recoverbutton_register(2);
			   }
			   if (box3 == 0)
			   {
				    recoverbutton_register(3);
			   }
			   if (box4 == 0)
			   {
			    	recoverbutton_register(4);
			   }
		    }
		    if (MouseS != 0)
            {
            MouseS = 0;
            }
            continue;
		}
			 
	}
	
}


/********************************************
FUNCTION:selectbutton_register
DESCRIPTION: ע����水ť���ѡ��״̬����
INPUT:x1,y1,x2,y2,color1,num
RETURN:��
********************************************/
void selectbutton_register(int x1, int y1, int x2, int y2, int color1, int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
    setcolor(WHITE);
	setfillstyle(SOLID_FILL, color1);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);	//*���Ʊ߿�

	switch (num)
	{
	case 1://*�û�����
		break;
	case 2://*��ϵ�绰��	    
	    break;
	case 3://*�����
		break;
	case 4://*ȷ�������
		break;
	default:
		closegraph();
		printf("something runs wrong in selectbutton_register");
		exit(1);
	}
}

/********************************************
FUNCTION:recoverbutton_register
DESCRIPTION: ע�����ָ���ť���״̬����
INPUT:num
RETURN:��
********************************************/
void recoverbutton_register(int num)
{
	clrmous(MouseX, MouseY);
	switch (num)
	{
	case 1:									//*�û�����ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120,240+220,120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120,240+220,120+40);
		break;
	case 2:									//*��ϵ�绰��ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+60,240+220,120+60+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+60,240+220,120+60+40);
		break;
	case 3:									//*�����ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+120,240+220,120+120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+120,240+220,120+120+40);
	    break;
	case 4:									//*ȷ�������ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+180,240+220,120+180+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+180,240+220,120+180+40);
	    break;  
	}
}
