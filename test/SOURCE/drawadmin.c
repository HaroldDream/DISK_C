#include "common.h"

void drawadmin(int num)
{
    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,39,180,480);//左侧功能区

    //setfillstyle(SOLID_FILL,BLUE);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,180,40);//头像区

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(228,32,286,36);
    bar(328,32,386,36);
    bar(428,32,486,36);
    bar(528,32,586,36);  

    setcolor(WHITE);
    circle(20,20,15);
    puthz(12,12,"后",16,20,WHITE);

    puthz(212+8,12,"仓储管理",16,20,DARKGRAY);
    puthz(312+8,12,"食材采购",16,20,DARKGRAY);
    puthz(412+8,12,"物流管理",16,20,DARKGRAY);
    puthz(512+8,12,"信息管理",16,20,DARKGRAY);

    puthz(80,60,"欢迎登录后勤管理界面",24,30,DARKGRAY);
    puthz(30,120,"点击上方选项卡选择相应功能",24,30,DARKGRAY);

    puthz(6,450,"退出",16,20,WHITE);

    switch(num)
    {
        case 0://仓储
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(228,32,286,36);
        case 1://采购
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(328,32,386,36);
        case 2://物流
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(428,32,486,36);
        case 3://信息
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(528,32,586,36);
    }

}