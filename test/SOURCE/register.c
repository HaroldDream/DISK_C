#include "common.h"
#include "data.h"
#include "drawhome.h"
#include "register.h"
#include "input.h"

/********************************************
DESCRIPTION:注册
INPUT:*func
RETURN:
********************************************/

void registermain (int *page)
{
    char U[15] = { '\0' };   //*6-12位，用户名
	char C[20] = { '\0' };   //*11位，联系方式
	char P[20] = { '\0' };   //*8-16位，密码
	char CP[20] = { '\0' };  //*8-16位，确认密码
	int box1 = 0;            //*输入框状态
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
		
        if (MouseX > 240 && MouseX < 240+220 && MouseY>120 && MouseY < 120+40) //*用户名框
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
				input(U, 240 , 120 , 12, LIGHTGRAY);//后期输入函数
				if(strlen(U) != 0)
					box1 = 1;
				else
					box1 = 0;
				continue;
			}
		}

		
         if (MouseX > 240 && MouseX < 240+220 && MouseY>120+60 && MouseY < 120+60+40) //*联系电话框
		{    
			if (mouse_press(240,120+60,240+220,120+60+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box2 == 0)                  //num = 0防止重复标亮
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
        
       
	    if (MouseX > 240 && MouseX < 240+220 && MouseY>120+120 && MouseY < 120+120+40) //*密码框
		{    
			if (mouse_press(240,120+120,240+220,120+120+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box3 == 0)                  //num = 0防止重复标亮
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
       
	    if (MouseX > 240 && MouseX < 240+220 && MouseY>120+180 && MouseY < 120+180+40) //*确认密码框
		{    
			if (mouse_press(240,120+180,240+220,120+180+40) == 2)     
			{
				MouseS = 2;
				if (num == 0 && box4 == 0)                  //num = 0防止重复标亮
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

		if (MouseX > 280 && MouseX < 280+140 && MouseY>120+240 && MouseY < 120+240+40) //*注册键
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
		
		if(mouse_press(560-90+30,120+240,560+30-10,120+240+40) == 2) //*返回键  
		{
			MouseS = 1;
		    continue;
		}
		else if(mouse_press(560+30-90,120+240,560-10+30,120+240+40) == 1)
		{
			*page = 0;
			return;
		}
		
		else //*循环恢复
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
DESCRIPTION: 注册界面按钮变成选中状态函数
INPUT:x1,y1,x2,y2,color1,num
RETURN:无
********************************************/
void selectbutton_register(int x1, int y1, int x2, int y2, int color1, int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
    setcolor(WHITE);
	setfillstyle(SOLID_FILL, color1);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);	//*绘制边框

	switch (num)
	{
	case 1://*用户名框
		break;
	case 2://*联系电话框	    
	    break;
	case 3://*密码框
		break;
	case 4://*确认密码框
		break;
	default:
		closegraph();
		printf("something runs wrong in selectbutton_register");
		exit(1);
	}
}

/********************************************
FUNCTION:recoverbutton_register
DESCRIPTION: 注册界面恢复按钮最初状态函数
INPUT:num
RETURN:无
********************************************/
void recoverbutton_register(int num)
{
	clrmous(MouseX, MouseY);
	switch (num)
	{
	case 1:									//*用户名框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120,240+220,120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120,240+220,120+40);
		break;
	case 2:									//*联系电话框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+60,240+220,120+60+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+60,240+220,120+60+40);
		break;
	case 3:									//*密码框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+120,240+220,120+120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+120,240+220,120+120+40);
	    break;
	case 4:									//*确认密码框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+180,240+220,120+180+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+180,240+220,120+180+40);
	    break;  
	}
}
