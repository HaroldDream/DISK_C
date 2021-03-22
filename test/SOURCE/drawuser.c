#include "common.h"
#include "drawuser.h"

void drawuser(void)
{
    time_t timep;
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
	sprintf(stime,"%d.%d.%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday-1);

    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,49,140,480);//左侧功能区

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,140,50);//头像区

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(220,36,280,40);//小横线
    bar(320,36,380,40);
    bar(420,36,480,40);
    bar(520,36,580,40);  

    setcolor(WHITE);//头像区
    circle(22,26,15);
    puthz(15,18,"食",16,20,WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(48,8,stime);
    
    switch(p->tm_wday) //显示星期
    {
        case 0:
            puthz(47,27,"周六",16,20,WHITE);
            break;
        case 1:
            puthz(47,27,"周日",16,20,WHITE);
            break;
        case 2:
            puthz(47,27,"周一",16,20,WHITE);
            break;
        case 3:
            puthz(47,27,"周二",16,20,WHITE);
            break;
        case 4:
            puthz(47,27,"周三",16,20,WHITE);
            break;
        case 5:
            puthz(47,27,"周四",16,20,WHITE);
            break;
        case 6:
            puthz(47,27,"周五",16,20,WHITE);
            break;
    }


    puthz(212+8,12,"仓储管理",16,20,DARKGRAY);
    puthz(352+8,12,"物流管理",16,20,DARKGRAY);
    puthz(492+8,12,"信息管理",16,20,DARKGRAY);
    puthz(8,450,"退出",16,20,WHITE);

    puthz(300,450,"第",16,18,BLUE);
    puthz(340,450,"页",16,18,BLUE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,1);
    line(368,450,358,465);
    puthz(370,450,"共",16,18,BLUE);
    puthz(410,450,"页",16,18,BLUE);
    puthz(510,450,"上一页",16,18,BLUE);
    puthz(570,450,"下一页",16,18,BLUE);
    puthz(8,450,"退出",16,20,WHITE);

    setcolor(DARKGRAY); //横线
    setlinestyle(SOLID_LINE,0,3);
    line(0,51,640,51); //标题行
    line(140,80+30*12,640,80+30*12); //底行
    setlinestyle(SOLID_LINE,0,1);
    line(140,50+30,640,50+30); //表格横线
    line(140,80+30*1,640,80+30*1);
    line(140,80+30*2,640,80+30*2);
    line(140,80+30*3,640,80+30*3);
    line(140,80+30*4,640,80+30*4);
    line(140,80+30*5,640,80+30*5);
    line(140,80+30*6,640,80+30*6);
    line(140,80+30*7,640,80+30*7);
    line(140,80+30*8,640,80+30*8);
    line(140,80+30*9,640,80+30*9);
    line(140,80+30*10,640,80+30*10);
    line(140,80+30*11,640,80+30*11);
    line(0,479,640,479);

    setcolor(WHITE);//左侧白线
    setlinestyle(SOLID_LINE,0,1);
    line(1,50,139,50);
    line(1,90,139,90);
    line(1,130,139,130);
    line(1,170,139,170);
}