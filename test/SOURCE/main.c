#include "common.h"
#include "main.h"
#include "home.h"
#include "register.h"
#include "admain.h"
#include "usermain.h"


void main()
{
	USER u;
	//ADMIN ad;

	int page   = 0;
	int driver = VGA;
	int mode   = VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\bgi");
	mouseinit();

	memset(&u,'\0',sizeof(USER));
	//memset(&ad,'\0',sizeof(ADMIN));

    while (1)
	{
		switch (page)
		{
			case 0:    //*最初界面
			    memset(&u,'\0',sizeof(USER));
				home(&page,&u);  
				break; //回到最初界面

			case 1:    //*关闭系统
				delay(1000);
				closegraph();//关闭画图
				exit(1);
			
			case 2:   //*注册页面
				registermain(&page);  
				break;   

			case 3:   //*后勤管理员主页面
			    admain(&page,&u);
				break;

			case 4:   //*食堂用户主页面
			    usermain(&page,&u);
				break;
		}
	}


 }