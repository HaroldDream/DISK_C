#include "common.h"
#include "home.h"
#include "drawhome.h"


//��ҳ
void home(int *page)
{
    int flag = 0;		//*�ж�ģʽ��1Ϊ���ڣ�2Ϊʳ��
	int num = 0;		//*������ţ�1��ע�� 2����¼ 3���˺� 4������ 5:���� 6��ʳ��
	int pre1 = 0;       //*�Ƿ������ڶ�
	int pre2 = 0;        //*�Ƿ���ʳ�ö�
    int content1 =0;     //*�˺ſ��Ƿ�������
	int content2 =0;     //*������Ƿ�������

	clrmous(MouseX,MouseY);
	delay(100);
	drawhome();
	
    while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//*���ڶ�
		if (MouseX > 182 && MouseX < 290 && MouseY> 362 && MouseY < 380)
        {
            if(mouse_press(182,362,290,380) == 2)          
		    {
			    if (num == 0) 
			    {
				    MouseS = 1;
					num = 5;
					selectmode_home(num);
			    }
		    	continue;
		    }
		    else if (mouse_press(182,362,290,380) == 1)
		    {
			    MouseS = 0;
				flag = 1; 
				pre1 = 1;
				selectmode_home(5);
                recoverbutton_home(6);   //*��֮ǰѡ�еĶ˰�ť�ָ�
				setfillstyle(SOLID_FILL,LIGHTBLUE);
                fillellipse(340,160,50,50);
				puthz(320,140,"��",48,30,WHITE);
			    continue;
		    }
			/*else if (mouse_press(182,362,290,380) == 2 && flag == 2)
			{
				MouseS = 1;
				setfillstyle(SOLID_FILL,RED);
				fillellipse(189,370,5,5);
				num = 6;
				continue;
			}*/
		}

        //*ʳ�ö�
		if (MouseX > 302 && MouseX < 410 && MouseY> 362 && MouseY < 380)
        {
            if(mouse_press(302,362,410,380) == 2)          
		    {
			    if (num == 0)
			    {
				    MouseS = 1;
					num = 6;
					selectmode_home(num);
			    }
		    	continue;
		    }
		    else if (mouse_press(302,362,410,380) == 1)
		    {
			    MouseS = 0;
				flag = 2; 
				pre2 = 1;
				selectmode_home(6);
                recoverbutton_home(5);   //*��֮ǰѡ�еĶ˰�ť�ָ�
				setfillstyle(SOLID_FILL,LIGHTBLUE);
                fillellipse(340,160,50,50);
				puthz(320,140,"ʳ",48,30,WHITE);
			    continue;
		    }
            /*else if (mouse_press(302,362,410,380) == 2 && flag == 1)
			{
				MouseS = 1;
				setfillstyle(SOLID_FILL,RED);
				fillellipse(309,370,5,5);
				num = 5;
				continue;
			}*/
		}

        //*ע��
		if (MouseX > 439 && MouseX < 495 && MouseY> 357 && MouseY < 383)
        {
            if(mouse_press(439,357,495,383) == 2)
           
		    {
				MouseS = 1;
			    if (num == 0) 
			    {
					num = 1;
					selectbutton_home(439,357,495,383,WHITE,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(439,357,495,383) == 1)
		    {
			    MouseS = 0;
				*page = 2;     //todoע�����
			    return;
		    }
		}

        //*��¼
		if (MouseX > 421 && MouseX < 461 && MouseY> 299 && MouseY < 341)
        {
            if(mouse_press(421,299,461,341) == 2)
           
		    {
				MouseS = 1;
			    if (num == 0) 
			    {
					num = 2;
					selectbutton_home(421,299,461,341,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(421,299,461,341) == 1)
		    {
			    MouseS = 0;
				*page = 1;     //todo��¼�ж�
			    return;
		    }
		}

	    //*�˺ſ�
		if (MouseX > 240 && MouseX < 460 && MouseY> 240 && MouseY < 280)
        {
            if(mouse_press(240,240,460,280) == 2)
           
		    {
				MouseS = 2;
			    if (num == 0&&content1 == 0) 
			    {
					num = 3;
					selectbutton_home(240,240,460,280,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(240,240,460,280) == 1)
		    {
			    MouseS = 0;
				selectbutton_home(240,240,460,280,LIGHTGRAY,3);   
			    //todo�û�����
				content1 = 0;
		    }
		}	

        //*�����
		if (MouseX > 240 && MouseX < 420 && MouseY> 300 && MouseY < 340)
        {
            if(mouse_press(240,300,420,340) == 2)
           
		    {
				MouseS = 2;
			    if (num == 0&&content2 == 0) 
			    {
					num = 4;
					selectbutton_home(240,300,420,340,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(240,300,420,340) == 1)
		    {
			    MouseS = 0;
				selectbutton_home(240,300,420,340,LIGHTGRAY,4);   
			    //todo�û�����
				content2 = 0;
		    }
		}	
		
        //*�˳�
		if(mouse_press(608, 2, 638, 32) == 1)
		{
			*page = 1;
			return;
		}

		//*ѭ���ָ�
        else 
		{
			if (num != 0)
			{
				MouseS = 0;
                if(num == 1||num == 2)
                {
                    recoverbutton_home(num);
                }
				if(num == 5 && pre1 == 0)
				{
					recoverbutton_home(5);
				}
				if(num ==6 && pre2 == 0)
				{
					recoverbutton_home(6);
				}			
				if (content1 == 0)
                {
                    recoverbutton_home(3);
                }
                if (content2 == 0)
                {
                    recoverbutton_home(4);
                }
				num = 0;
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
FUNCTION:selectbutton_home
DESCRIPTION: ��¼���水ť���ѡ��״̬����
INPUT:x1,y1,x2,y2,color1,num
RETURN:��
********************************************/
void selectbutton_home(int x1, int y1, int x2, int y2, int color1, int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
    setcolor(WHITE);
	setfillstyle(SOLID_FILL, color1);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);	//*���Ʊ߿�

	switch (num)
	{
	case 1: //*ѡ��ע��
		puthz(440,358,"ע��",24,30,RED);
		break;
	case 2: //*ѡ�е�¼��
	    setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE, 0, 3);
	    line(430,320,450,320);   
	    moveto(440,310);
	    lineto(450,320);
	    lineto(440,330);
	    break;
	case 3: //*ѡ���˺ſ�
		break;
	case 4: //*ѡ�������
		break;
	default: 
		closegraph();
		printf("something runs wrong in selectbutton_home");
		exit(1);
	}
}

/********************************************
FUNCTION:recoverbutton_home
DESCRIPTION: ��¼����ָ���ť���״̬����
INPUT:num
RETURN:��
********************************************/
void recoverbutton_home(int num)
{
	clrmous(MouseX, MouseY);
	switch (num)
	{
	case 1://*ע����ָ�
		puthz(440,358,"ע��",24,30,LIGHTBLUE);  
		break;
	case 2://*��¼���ָ�
	    setfillstyle(SOLID_FILL,BLUE);    
	    bar(421,299,461,341);
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(430,320,450,320);
	    moveto(440,310);
	    lineto(450,320);
	    lineto(440,330);
		break;
	case 3://*�˺ſ�ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,240,460,280);
	    setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,240,460,280);
	    break;
	case 4://*�����ָ�
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,300,420,340);
	    setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, 3);	
	    rectangle(240,300,420,340);
	    break;  
	case 5://*���ڶ˻ָ�
	    /*setfillstyle(SOLID_FILL,LIGHTBLUE);
        fillellipse(340,160,50,50);*/
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(189,370,6,6);
	    break;  
	case 6://*ʳ�ö˻ָ�
	    /*setfillstyle(SOLID_FILL,LIGHTBLUE);
        fillellipse(340,160,50,50);*/
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(309,370,6,6);
	    break;  
	}
}

/********************************************
FUNCTION:selectmode_home
DESCRIPTION: ��ʾ�˿ڱ�ѡ��״̬����
INPUT:num
RETURN:��
********************************************/
void selectmode_home(int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL,RED);
	
	switch (num)
	{
	case 5:   //*���ڶ�ѡ��
	    fillellipse(189,370,5,5);
		//puthz(320,140,"��",48,30,WHITE);
		break;
	case 6:   //*ʳ�ö�ѡ��
	    fillellipse(309,370,5,5);
	    //puthz(320,140,"ʳ",48,30,WHITE);
	    break;
	default:
		closegraph();
		printf("something runs wrong in selectmode_home");
		exit(1);
	}
}