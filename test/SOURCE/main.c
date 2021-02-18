#include "common.h"
#include "main.h"


void main()
{
	int page   = 0;
	int driver = VGA;
	int mode   = VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\bgi");
	mouseinit();
    while (1)
	{
		switch (page)
		{
			case 0:    //*最初界面
				home(&page);  
				break;     //回到最初界面

			case 1:    //*关闭系统
				delay(1000);
				closegraph();//关闭画图
				exit(1);
			
			case 2:   //todo注册页面
				rgst();
			case 3: 

			case 4: 

		}
	}


 }