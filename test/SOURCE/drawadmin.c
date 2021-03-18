#include "common.h"

void drawadmin(int num)
{
    cleardevice();
    setbkcolor(WHITE);

    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,49,140,480);//左侧功能区

    //setfillstyle(SOLID_FILL,BLUE);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,140,50);//头像区

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(220,36,280,40);
    bar(320,36,380,40);
    bar(420,36,480,40);
    bar(520,36,580,40);  

    setcolor(WHITE);//头像区
    circle(22,26,15);
    puthz(15,18,"后",16,20,WHITE);

    puthz(212,16,"仓储管理",16,20,DARKGRAY);
    puthz(312,16,"食材采购",16,20,DARKGRAY);
    puthz(412,16,"物流管理",16,20,DARKGRAY);
    puthz(512,16,"信息管理",16,20,DARKGRAY);

    puthz(6,450,"退出",16,20,WHITE);

    switch(num)
    {
        case 0://仓储
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(220,36,280,40);
            break;
        case 1://采购
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(320,36,380,40);
            
            /*setcolor(DARKGRAY);            
            setlinestyle(SOLID_LINE,0,3);
            line(1,320,139,320);
            line(1,360,139,360);
            line(1,400,139,400);
            line(1,440,139,440);*/

            setcolor(WHITE);
            setlinestyle(SOLID_LINE,0,1);
            line(1,319,139,319);
            line(1,359,139,359);
            line(1,399,139,399);
            line(1,439,139,439);   

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(0,50,640,50);
            
            line(140,50+30,640,50+30);//标题行
            line(140,80+30*1,640,80+30*1);//横线
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
            line(140,80+30*12,640,80+30*12);
            line(0,479,640,479);
            
            line(0,50,0,480);//竖线
            line(140,50,140,480);//名称
            line(200,50,200,440);//种类
            line(300,50,300,440);//供应商
            line(400,50,400,440);//价格
            line(460,50,460,440);//数量
            line(520,50,520,440);//预测需求
            line(600,50,600,440);//操作

            puthz(155,58,"名称",16,18,BLUE);
            puthz(235,58,"种类",16,18,BLUE);
            puthz(325,58,"供应商",16,18,BLUE);
            puthz(415,58,"价格",16,18,BLUE);
            puthz(475,58,"数量",16,18,BLUE);
            puthz(525,58,"预测需求",16,18,BLUE);
            puthz(605,58,"操作",16,18,BLUE);

            puthz(300,450,"第",16,18,BLUE);
            puthz(340,450,"页",16,18,BLUE);
            line(368,450,358,465);
            puthz(370,450,"共",16,18,BLUE);
            puthz(410,450,"页",16,18,BLUE);
            puthz(510,450,"上一页",16,18,BLUE);
            puthz(570,450,"下一页",16,18,BLUE);

            break;
        case 2://物流
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(420,36,480,40);
            break;
        case 3://信息
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(520,36,580,40);
            break;
    }
}