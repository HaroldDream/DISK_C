#include "common.h"
#include "data.h"
#include "drawhome.h"


/*
DESCRIPTION:登录
INPUT:*func
RETURN:无
*/
void user_login(int *func)
{
	int num;
	char name[15]      = {'\0'};  //6-12位，用户名
	char id[20]        = {'\0'};  //18位，身份证
	char password[20]  = {'\0'};  //6-16位，密码
	char password2[20] = {'\0'};  //6-16位，确认密码

	draw_home();


}




/*
DESCRIPTION:注册
INPUT:*func
RETURN:无
*/
void user_register(int *func)
{
    int num;
	char str[6]        = {'\0'};
	char name[15]      = {'\0'};  //6-12位，用户名
	char id[20]        = {'\0'};  //18位，身份证
	char password[20]  = {'\0'};  //6-16位，密码
	char password2[20] = {'\0'};  //6-16位，确认密码
	//char code[6] = { '\0' };      //5位，验证码
	int state  = 0;  //弹窗模式
	int state1 = 0;  //内容输入判断参数
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;
	int state5 = 0;

	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	draw_login();

	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 1 && MouseX < 1 && MouseY>1 && MouseY < 1)
		{    
			if (mouse_press(1,1,1,1) == 2)           //未点击账号框
			{
				MouseS = 2;
				if (num == 0 && state1 == 0)                  //num = 0防止重复标亮
				{
					lightbutton_register(1,1,1,1,LIGHTGRAY,1);
					num = 1;
				}
				continue;
			}

			else if (mouse_press(1,1,1,1) == 1)      //点击账号框
			{
				MouseS = 0;
				lightbutton_register(1,1,1,1, LIGHTGRAY, 1);
				name[0] = '\0';
				input(name, 95, 85+30, 12, LIGHTGRAY);//后期输入函数
				if(strlen(name) != 0)
					state1 = 1;
				else
					state1 = 0;
				continue;
			}
		}
		if (MouseX > 95 && MouseX < 545 && MouseY>145+28 && MouseY < 170+32)
		{
			if (mouse_press(95,145+28,545,170+32) == 2)     //未点击密码框
			{
				MouseS = 2;
				if (num == 0 && state2 == 0)
				{
					lightbutton_register(95,145+28,545,170+32, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(95,145+28,545,170+32) == 1)     //点击密码框
			{
				lightbutton_register(95,145+28,545,170+32, LIGHTGRAY, 2);
				MouseS = 0;
				password[0] = '\0';
				inputmm(password, 95, 145+30, 16, LIGHTGRAY);//输入函数
				if(strlen(password) != 0)
					state2 = 1;
				else
					state2 = 0;
				continue;
			}
		}
		if (MouseX > 95 && MouseX < 545 && MouseY>205+28 && MouseY < 230+32)
		{
			if (mouse_press(95,205+28,545,230+32) == 2)     //未点击确认密码框
			{
				MouseS = 2;
				if (num == 0 && state3 == 0)
				{
					lightbutton_register(95,205+28,545,230+32, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(95,205+28,545,230+32) == 1)      //点击确认密码框
			{
				lightbutton_register(95,205+28,545,230+32, LIGHTGRAY, 3);
				MouseS = 0;
				password2[0] ='\0';
				inputmm(password2, 95, 205+30, 16, LIGHTGRAY);
		
				//输入函数
				if(strlen(password2) != 0)
					state3 = 1;
				else
					state3 = 0;
				continue;
			}
		}
		if (MouseX > 95 && MouseX < 545 && MouseY>265+28 && MouseY < 290+32)
		{
			if (mouse_press(95,265+28,545,290+32) == 2)      //未点击身份证框
			{
				MouseS = 2;
				if (num == 0 && state4 == 0)
				{
					lightbutton_register(95,265+28,545,290+32, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(95,265+28,545,290+32) == 1)
			{
				lightbutton_register(95,265+28,545,290+32,LIGHTGRAY, 4);
				MouseS = 0;
				id[0] = '\0';
				input(id, 95, 265+30, 18, LIGHTGRAY);
				//输入函数
				if(strlen(id) != 0)
					state4 = 1;
				else 
					state4 = 0;
				continue;
			}
		}
		if (mouse_press(95, 355, 175, 380) == 1)
		{
			clrmous(MouseX, MouseY);
			delay(10);
			setfillstyle(1, WHITE);
			bar(95, 355, 175, 380);
			random_str(str);
			//setcolor(BLUE);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			settextstyle(1, HORIZ_DIR, 1);
			outtextxy(105, 355, str);
			rectangle(95, 353, 175, 382);
			continue;
		}
		if (MouseX > 175 && MouseX < 545 && MouseY>353 && MouseY < 382)
		{
			MouseS = 2;
			if (mouse_press(175, 353, 545, 382) == 2)            //未点击验证码输入框
			{
				if (num == 0 && state5 == 0)
				{
					lightbutton_register(175, 353, 545, 382, LIGHTGRAY, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(175, 353, 545, 382) == 1)
			{
				lightbutton_register(175, 353, 545, 382, LIGHTGRAY, 5);
				MouseS = 0;
				code[0] = '\0';
				input(code, 175, 355, 5, LIGHTGRAY);
				//输入函数
				if(strlen(code) != 0)
					state5 = 1;
				else 
					state5 = 0;
				continue;
			}
		}
		if (MouseX > 143 && MouseX < 237 && MouseY>400 && MouseY < 430)
		{
			if (mouse_press(143, 400, 237, 430) == 2)                //未点击重置框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(143, 400, 237, 430,RED, 6);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(143, 400, 237, 430) == 1)
			{
				MouseS = 0;
				cleardevice();
				draw_signin(str);
				num = 0;
				state1 = 0;
				state2 = 0;
				state3 = 0;
				state4 = 0;
				state5 = 0;
				name[0] = '\0';
				id[0] = '\0';
				password[0] = '\0';
				password2[0] = '\0';
				code[0] = '\0';	
				//重置
				continue;
			}
		}
		if (MouseX > 273 && MouseX < 367 && MouseY>400 && MouseY < 430)
		{
			if (mouse_press(273, 400, 367, 430) == 2)					//未点击注册框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(273, 400, 367, 430,  RED, 7);
					num = 7;
				}
				continue;
			}			
			else if (mouse_press(273, 400, 367, 430) == 1)
			{
				MouseS = 0;
				if (register_complete(name, password, password2, id, code, str))
				{
					state=4;
					tanchuang(state);
					*func = 0;
					return;
				}
				else
				{
					continue;
				}
			}
		}
		if (MouseX > 403 && MouseX < 497 && MouseY>400 && MouseY < 430)
		{
			if (mouse_press(403, 400, 497, 430) == 2)				//未点击返回框
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_register(403, 400, 497, 430, RED, 8);
					num = 8;
				}
				continue;
			}
			else if (mouse_press(403, 400, 497, 430) == 1)
			{
				MouseS = 0;
				*func = 0;
				return; //返回
			}
		}
		if (num != 0)
		{
			MouseS = 0;	
			if (state1 == 0)
			{
				recoverbutton_register(1);
			}
			if (state2 == 0)
			{
				recoverbutton_register(2);
			}
			if (state3 == 0)
			{
				recoverbutton_register(3);
			}
			if (state4 == 0)
			{
				recoverbutton_register(4);
			}
			if (state5 == 0)
			{
				recoverbutton_register(5);
			}
			if (num == 6 || num == 7 || num == 8)
			{
				recoverbutton_register(num);
			}
			num = 0;
		}
		if (MouseS != 0)
		{
			MouseS = 0;
		}
	}
}