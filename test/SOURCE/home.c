#include "common.h"
#include "home.h"
#include "userdata.h"

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

