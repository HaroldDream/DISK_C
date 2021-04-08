#include "common.h"
#include "drawuser.h"

void drawuser(int num, int op)
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
    bar(228,36,286,40);//小横线
    bar(368,36,426,40);
    bar(508,36,566,40);  

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


    puthz(212+8,16,"仓储管理",16,20,DARKGRAY);
    puthz(352+8,16,"物流管理",16,20,DARKGRAY);
    puthz(492+8,16,"信息管理",16,20,DARKGRAY);
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


    switch(num)
    {
        case 0://仓储
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(228,36,286,40);

            setcolor(WHITE);//筛选图标
            setfillstyle(SOLID_FILL,WHITE);
            bar(16,357,30,359);
            line(16,359,22,367);
            line(30,359,24,367);
            bar(22,367,24,375);
            floodfill(23,361,WHITE);

            puthz(15,60,"库存查询",24,28,WHITE);            
            puthz(35,100,"入库",24,40,WHITE);
            puthz(35,140,"出库",24,40,WHITE);
            puthz(43,358,"条件筛选",16,20,WHITE);   

            drawuser_storage(op);
            break;
        case 1://物流
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(368,36,426,40); 

            setcolor(WHITE);//刷新图标
            setfillstyle(SOLID_FILL,WHITE);
            setlinestyle(SOLID_LINE,0,3);
            ellipse(24,368,120,240,12,12);
            ellipse(23,368,0,60,12,12);
            ellipse(23,368,300,0,12,12);
            line(18,358,9,359);
            line(18,358,18,365);
            line(30,379,38,373);
            line(30,379,30,370);

            puthz(15,60,"物流查询",24,28,WHITE);            
            puthz(35,100,"收货",24,40,WHITE);
            puthz(35,140,"发货",24,40,WHITE);
            puthz(45,360,"状态刷新",16,21,WHITE);

            drawuser_logistic(op);
            break;
        case 2://信息
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(508,36,566,40);
   
            puthz(15,60,"订单来往",24,28,WHITE);            
            puthz(15,140,"食材反馈",24,28,WHITE);
            puthz(15,100,"财务信息",24,28,WHITE);

            drawuser_info(op);
            break;
    }
}

void drawuser_info(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,51,139,89);
            puthz(15,60,"库存查询",24,28,WHITE); 

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(156,58,"库存编号",16,18,BLUE);
            puthz(272,58,"名称",16,20,BLUE);
            puthz(357,58,"入库时间",16,18,BLUE);
            puthz(457,58,"库存总数",16,18,BLUE);
            puthz(565,58,"单位",16,20,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"入库",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(157,58,"入库单号",16,18,BLUE);
            puthz(273,58,"种类",16,20,BLUE);
            puthz(373,58,"数量",16,20,BLUE);
            puthz(457,58,"是否入库",16,18,BLUE);
            puthz(557,58,"操作时间",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"出库",24,40,WHITE);

            setcolor(DARKGRAY);
            line(260,50,260,440);
            line(320,50,320,440);
            line(420,50,420,440);
            line(510,50,510,440);

            puthz(168,58,"出库单号",16,18,BLUE);
            puthz(273,58,"食堂",16,20,BLUE);
            puthz(340,58,"物流状态",16,18,BLUE);
            puthz(430,58,"是否出库",16,18,BLUE);
            puthz(540,58,"操作时间",16,18,BLUE);
            break;
    }
}

void drawuser_logistic(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,51,139,89);
            puthz(15,60,"物流查询",24,28,WHITE); 
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"收货",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1); 
            line(240,50,240,440);
            line(340,50,340,440);
            line(450,50,450,440);
            line(540,50,540,440);

            puthz(159,58,"订单编号",16,18,BLUE);
            puthz(275,58,"种类",16,18,BLUE);
            puthz(370,58,"供应商",16,18,BLUE);
            puthz(459,58,"签收状态",16,18,BLUE);
            puthz(557,58,"操作时间",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"发货",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE, 0, 1);
            line(140+150,50,140+150,440);
            line(140+150+125,50,140+150+125,440);
            line(140+150+125+100,50,140+150+125+100,440);
            
            puthz(180,58,"运输单号",16,18,BLUE);
            puthz(335,58,"类别",16,20,BLUE);
            puthz(432,58,"是否发货",16,18,BLUE);
            puthz(547,58,"操作时间",16,18,BLUE);
            break;
    }
}

void drawuser_storage(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,51,139,89);
            puthz(15,60,"库存查询",24,28,WHITE); 

            setcolor(DARKGRAY);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(156,58,"库存编号",16,18,BLUE);
            puthz(272,58,"名称",16,20,BLUE);
            puthz(357,58,"入库时间",16,18,BLUE);
            puthz(457,58,"库存总数",16,18,BLUE);
            puthz(565,58,"单位",16,20,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"入库",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(157,58,"入库单号",16,18,BLUE);
            puthz(273,58,"种类",16,20,BLUE);
            puthz(373,58,"数量",16,20,BLUE);
            puthz(457,58,"是否入库",16,18,BLUE);
            puthz(557,58,"操作时间",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"出库",24,40,WHITE);

            setcolor(DARKGRAY);
            line(260,50,260,440);
            line(320,50,320,440);
            line(420,50,420,440);
            line(510,50,510,440);

            puthz(168,58,"出库单号",16,18,BLUE);
            puthz(273,58,"食堂",16,20,BLUE);
            puthz(340,58,"物流状态",16,18,BLUE);
            puthz(430,58,"是否出库",16,18,BLUE);
            puthz(540,58,"操作时间",16,18,BLUE);
            break;
    }
}

