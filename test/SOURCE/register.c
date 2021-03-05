#include "common.h"
#include "data.h"
#include "drawhome.h"
#include "register.h"
#include "input.h"
#include "judge.h"

/********************************************
DESCRIPTION:注册
INPUT:*func
RETURN:
********************************************/

void registermain (int *page)
{
    char UNAME[15] = { '\0' };   //*6-10位，用户名
	char PHONE[20] = { '\0' };   //*11位，联系方式
	char PASSWORD[20] = { '\0' };   //*6-10位，密码
	char CPASSWORD[20] = { '\0' };  //*6-10位，确认密码
	int box1 = 0;            //*输入框状态
	int box2 = 0;
	int box3 = 0;
	int box4 = 0;
	int num;
	int mode;       //*1为食堂2为后勤

	clrmous(MouseX,MouseY);
	delay(100);
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
				UNAME[0] = '\0';
				input(UNAME, 240 , 120 , 10, LIGHTGRAY);//后期输入函数
				if(strlen(UNAME) != 0)                  //判断是否输入
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
				PHONE[0] = '\0';
				input(PHONE, 240 , 120+60 , 11, LIGHTGRAY);
				if(strlen(PHONE) != 0)            //判断是否输入
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
				PASSWORD[0] = '\0';
				inputmm(PASSWORD, 240 , 120+120 , 10, LIGHTGRAY);
				if(strlen(PASSWORD) != 0)            //判断是否输入
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
				CPASSWORD[0] = '\0';
				inputmm(CPASSWORD, 240 , 120+180 , 10, LIGHTGRAY);
				if(strlen(CPASSWORD) != 0)             //判断是否输入
					box4 = 1; 
				else
					box4 = 0;
				continue;
			}
		}

		if (MouseX > 182+60 && MouseX < 290+60 && MouseY> 362+2 && MouseY < 380+2)  //*选择注册后勤模式
        {
            if(mouse_press(182+60,362+2,290+60,380+2) == 2)          
		    {
			    if (num == 0) 
			    {
				    MouseS = 1;	
			    }
		    	continue;
		    }
		    else if (mouse_press(182+60,362+2,290+60,380+2) == 1)
		    {
			    MouseS = 0;
				mode = 1; 
				selectmode_register(5);
                recoverbutton_register(6);   //*将之前选中的端按钮恢复
			    continue;
		    }
		}

		if (MouseX > 302+60 && MouseX < 410+60 && MouseY> 362+2 && MouseY < 380+2)     //*选择注册食堂模式
        {
            if(mouse_press(302+60,362+2,410+60,380+2) == 2)          
		    {
			    if (num == 0)
			    {
				    MouseS = 1;
			    }
		    	continue;
		    }
		    else if (mouse_press(302+60,362+2,410+60,380+2) == 1)
		    {
			    MouseS = 0;
				mode = 2; 
				selectmode_register(6);
                recoverbutton_register(5);   //*将之前选中的端按钮恢复
			    continue;
		    }
		}
		
		if (MouseX > 280 && MouseX < 280+140 && MouseY>120+240+50 && MouseY < 120+240+40+50) //*注册键
	    {
			if(mouse_press(280,120+240+50,280+140,120+240+40+50) == 2)  
	        {
			    MouseS = 1;
		        continue;
		    }
		    else if(mouse_press(280,120+240+50,280+140,120+240+40+50) == 1 && box1*box2*box3*box4 == 1)    //需要四个框都输入点击注册键才有效
		    {
			    MouseS = 0;
				if (register_success(UNAME, PHONE , PASSWORD, CPASSWORD,mode))    //判断四个注册输入是否符合条件
				{
					setcolor(WHITE);
	                setfillstyle(SOLID_FILL, WHITE);  
                    bar(560+30-90-5,120+240+50-5,560+30-10+5,120+240+40+5);     
	                puthz(560+30-90-15,120+240+50+8,"注册成功",24,25,RED);
					delay(1000);
					*page = 0;
					return;
				}
				else
				{
					delay(1000);
					continue;
				}
		    }
		}
		
		if(mouse_press(560-90+30,120+240+50,560+30-10,120+240+40+50) == 2) //*返回键  
		{
			MouseS = 1;
		    continue;
		}
		else if(mouse_press(560+30-90,120+240+50,560-10+30,120+240+40+50) == 1)
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
	case 1: //*用户名框
		break;
	case 2: //*联系电话框	    
	    break;
	case 3: //*密码框
		break;
	case 4: //*确认密码框
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
	case 1:   //*用户名框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120,240+220,120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120,240+220,120+40);
		break;
	case 2:   //*联系电话框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+60,240+220,120+60+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+60,240+220,120+60+40);
		break;
	case 3:   //*密码框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+120,240+220,120+120+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+120,240+220,120+120+40);
	    break;
	case 4:   //*确认密码框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,120+180,240+220,120+180+40);
		setcolor(BLUE);
	    setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,120+180,240+220,120+180+40);
	    break;  
	case 5://*后勤端恢复
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(189+60,370+2,6,6);
	    break;  
	case 6://*食堂端恢复
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(309+60,370+2,6,6);
	    break;  

	}
}

/********************************************
FUNCTION:selectmode_register
DESCRIPTION: 显示端口被选择状态函数
INPUT:num
RETURN:无
********************************************/
void selectmode_register(int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL,RED);
	
	switch (num)
	{
	case 5:   //*后勤端选择
	    fillellipse(189+60,370+2,5,5);
		//puthz(320,140,"后",48,30,WHITE);
		break;
	case 6:   //*食堂端选择
	    fillellipse(309+60,370+2,5,5);
	    //puthz(320,140,"食",48,30,WHITE);
	    break;
	default:
		closegraph();
		printf("something runs wrong in selectmode_home");
		exit(1);
	}
}