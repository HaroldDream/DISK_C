#include "common.h"
#include "home.h"
#include "drawhome.h"
#include "input.h"
#include "judge.h"
#include "data.h"

         
//主页
void home(int *page, USER *u)
{
	int flag = 0;		//*判断模式：1为后勤，2为食堂
	int num = 0;		//*按键序号：1：注册 2：登录 3：账号 4：密码 5:后勤 6：食堂
	int pre1 = 0;       //*是否点击后勤端
	int pre2 = 0;        //*是否点击食堂端
    int content1 =0;     //*账号框是否有内容
	int content2 =0;     //*密码框是否有内容

	clrmous(MouseX,MouseY);
	delay(100);
	drawhome();
	
    while(1)
	{
		newmouse(&MouseX, &MouseY, &press);

		//*后勤端
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
                recoverbutton_home(6);   //*将之前选中的端按钮恢复
				setfillstyle(SOLID_FILL,LIGHTBLUE);
				setcolor(BLUE);
                fillellipse(335,170,50,50);
				puthz(312,145,"后",48,30,WHITE);
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

        //*食堂端
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
                recoverbutton_home(5);   //*将之前选中的端按钮恢复
				setfillstyle(SOLID_FILL,LIGHTBLUE);
				setcolor(BLUE);
                fillellipse(335,170,50,50);
				puthz(312,145,"食",48,30,WHITE);
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

        //*注册
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
				*page = 2;     //转到注册界面
			    return;
		    }
		}

        //*登录
		if (MouseX > 431 && MouseX < 471 && MouseY> 299 && MouseY < 341)
        {
            if(mouse_press(431,299,471,341) == 2)
           
		    {
				MouseS = 1;
			    if (num == 0) 
			    {
					num = 2;
					selectbutton_home(431,299,471,341,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(431,299,471,341) == 1 && content1*content2 == 1)
		    {
			    MouseS = 0;
				if (judge_rightpassword(u->username, u->password, flag)) 
				{
					if (flag == 1)
					{
						//strcpy(ad->username , u->username);
						//strcpy(ad->password, u->password);
						*page = 3; //跳转至后勤管理员界面
						return;
					}
					if (flag == 2)
					{
						*page = 4;  //跳转至食堂用户界面
						return;
					}
				}
				else 
				{
					*page = 0;
					return ;
				}
		    }
		}

	    //*账号框
		if (MouseX > 240 && MouseX < 470 && MouseY> 240 && MouseY < 280)
        {
            if(mouse_press(240,240,470,280) == 2)
           
		    {
				MouseS = 2;
			    if (num == 0&&content1 == 0) 
			    {
					num = 3;
					selectbutton_home(240,240,470,280,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(240,240,470,280) == 1)
		    {
			    MouseS = 0;
				selectbutton_home(240,240,470,280,LIGHTGRAY,3);   
			    u->username[0] = '\0';
				input(u->username, 240, 240, 10, LIGHTGRAY);//输入账号
				if(strlen(u->username) != 0)
					content1 = 1;
				else
					content1 = 0;
				continue;			
		    }
		}	

        //*密码框
		if (MouseX > 240 && MouseX < 430 && MouseY> 300 && MouseY < 340)
        {
            if(mouse_press(240,300,430,340) == 2)
           
		    {
				MouseS = 2;
			    if (num == 0&&content2 == 0) 
			    {
					num = 4;
					selectbutton_home(240,300,430,340,LIGHTGRAY,num);
			    }
		    	continue;
		    }
		    else if (mouse_press(240,300,430,340) == 1)
		    {
			    MouseS = 0;
				selectbutton_home(240,300,430,340,LIGHTGRAY,4);   
			    u->password[0] = '\0';
				inputmm(u->password, 240, 300, 10, LIGHTGRAY);//输入密码
				if(strlen(u->password) != 0)
					content2 = 1;
				else
					content2 = 0;
				continue;
				
		    }
		}	
		
        //*退出
		if(mouse_press(608, 2, 638, 32) == 1)
		{
			*page = 1;
			return;
		}

		//*循环恢复
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
DESCRIPTION: 登录界面按钮变成选中状态函数
INPUT:x1,y1,x2,y2,color1,num
RETURN:无
********************************************/
void selectbutton_home(int x1, int y1, int x2, int y2, int color1, int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
    setcolor(WHITE);
	setfillstyle(SOLID_FILL, color1);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);	//*绘制边框

	switch (num)
	{
	case 1: //*选中注册
		puthz(440,358,"注册",24,30,RED);
		break;
	case 2: //*选中登录键
	    setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE, 0, 3);
	    line(440,320,460,320);//*登录键图案
	    moveto(450,310);
	    lineto(460,320);
     	lineto(450,330);
	    break;
	case 3: //*选中账号框
		break;
	case 4: //*选中密码框
		break;
	default: 
		closegraph();
		printf("something runs wrong in selectbutton_home");
		exit(1);
	}
}

/********************************************
FUNCTION:recoverbutton_home
DESCRIPTION: 登录界面恢复按钮最初状态函数
INPUT:num
RETURN:无
********************************************/
void recoverbutton_home(int num)
{
	clrmous(MouseX, MouseY);
	switch (num)
	{
	case 1://*注册键恢复
		puthz(440,358,"注册",24,30,LIGHTBLUE);  
		break;
	case 2://*登录键恢复
	    setfillstyle(SOLID_FILL,BLUE);    
	    bar(431,299,471,341);
		setcolor(WHITE);
		setlinestyle(SOLID_LINE, 0, 3);
		line(440,320,460,320);//*登录键图案
	    moveto(450,310);
	    lineto(460,320);
     	lineto(450,330);
		break;
	case 3://*账号框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,240,470,280);
	    setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, 3);
	    rectangle(240,240,470,280);
	    break;
	case 4://*密码框恢复
	    setfillstyle(SOLID_FILL,WHITE);
		bar(240,300,430,340);
	    setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, 3);	
	    rectangle(240,300,430,340);
	    break;  
	case 5://*后勤端恢复
	    /*setfillstyle(SOLID_FILL,LIGHTBLUE);
        fillellipse(340,160,50,50);*/
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		fillellipse(189,370,6,6);
	    break;  
	case 6://*食堂端恢复
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
DESCRIPTION: 显示端口被选择状态函数
INPUT:num
RETURN:无
********************************************/
void selectmode_home(int num)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setfillstyle(SOLID_FILL,RED);
	
	switch (num)
	{
	case 5:   //*后勤端选择
	    fillellipse(189,370,5,5);
		//puthz(320,140,"后",48,30,WHITE);
		break;
	case 6:   //*食堂端选择
	    fillellipse(309,370,5,5);
	    //puthz(320,140,"食",48,30,WHITE);
	    break;
	default:
		closegraph();
		printf("something runs wrong in selectmode_home");
		exit(1);
	}
}