#include "common.h"
#include "home.h"

//todo最初界面
void home(int *page)
{

	clrmous(MouseX,MouseY);
	delay(100);
	home_screen();
	
    while(*page == 0)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		if(mouse_press(608, 2, 638, 32) == 1)//鼠标点击退出按钮
		{
			*page = 1;
		}
	}
	return;
}

//todo绘制最初界面
void home_screen(void)
{
	cleardevice();
	setbkcolor(WHITE);
	
	setfillstyle(SOLID_FILL, BLUE);//todo账号密码输入框
	bar(139,239,201,281);
	bar(139,319,201,361);
	bar(421,319,461,361);//todo登录按键
	setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, 3);
	rectangle(200,240,420,280);//todo账号输入框
	rectangle(200,320,420,360);//todo密码输入框
	setcolor(WHITE);
    circle(170,250,7);
	ellipse(170,275,0,180,15,15);
	ellipse(170,337,0,180,10,10);
	rectangle(157,340,183,355);
	line(430,340,450,340);
	moveto(440,330);
	lineto(450,340);
	lineto(440,350);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(300,160,40,40);
	setcolor(BLUE);
	circle(300,160,40);
    circle(150,390,8);//todo食堂端入口提示点
    circle(270,390,8);//todo后勤端入口提示点
	
	setcolor(RED);
	line(612, 6, 634, 28);
	line(612, 28, 634, 6);

    puthz(45,40,"欢迎登录后勤集团食堂供应链管理系统",24,30,1);
	puthz(360,390,"注册"，24，30，1)；

}
