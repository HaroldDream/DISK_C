#include "common.h"
#include "drawad.h"

void drawad(int num, int op)
{
    time_t timep;
    struct tm *p;
    char stime[20];
    time(&timep);
	p = gmtime(&timep);
	sprintf(stime,"%d.%d.%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday);

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
    puthz(15,18,"后",16,20,WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(48,10,stime);
    
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

    puthz(212,16,"仓储管理",16,20,DARKGRAY);
    puthz(312,16,"食材采购",16,20,DARKGRAY);
    puthz(412,16,"物流管理",16,20,DARKGRAY);
    puthz(512,16,"信息管理",16,20,DARKGRAY);

    puthz(300,452,"第",16,18,BLUE);
    puthz(340,452,"页",16,18,BLUE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,1);
    line(368,452,358,467);
    puthz(370,452,"共",16,18,BLUE);
    puthz(410,452,"页",16,18,BLUE);
    puthz(510,452,"上一页",16,18,BLUE);
    puthz(570,452,"下一页",16,18,BLUE);
    puthz(8,452,"退出",16,20,WHITE);

    setcolor(DARKGRAY); //横线
    setlinestyle(SOLID_LINE,0,3);
    line(140,50,640,50); //标题行
    line(140,440,640,440); //底行
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
            bar(220,36,280,40);

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

            drawad_storage(op);
            break;
        case 1://采购
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(320,36,380,40);

            puthz(15,60,"系统预测",24,28,WHITE);            
            puthz(15,100,"采购目录",24,28,WHITE);
            puthz(27,140,"采购单",24,32,WHITE);

            drawad_purchase(op);  
            break;
        case 2://物流
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(420,36,480,40); 

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

            drawad_logistic(op);
            break;
        case 3://信息
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(520,36,580,40);
            puthz(15,60,"订单查询",24,28,WHITE);            
            puthz(27,140,"供应商",24,32,WHITE);
            puthz(15,100,"财务信息",24,28,WHITE);

            drawad_info(op);
            break;
    }
}

void drawad_purchase(int op)
{           
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,51,139,89);
            puthz(15,60,"系统预测",24,28,WHITE); 

            setfillstyle(SOLID_FILL,WHITE);
            bar(141,51,640,439); //cover
            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,3);
            line(140,245,640,245);

            puthz(28,200,"当前食堂",16,20,WHITE);
            puthz(15,250,"上一个",16,18,WHITE);
            puthz(80,250,"下一个",16,18,WHITE);

            
            break;
        case 1://采购目录
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(15,100,"采购目录",24,28,WHITE);

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//竖线
            line(140,50,140,480);//名称
            line(210,50,210,440);//种类
            line(280,50,280,440);//供应商
            line(385,50,385,440);//价格
            line(450,50,450,440);//单位
            line(515,50,515,440);//预测需求
            line(600,50,600,440);//操作

            puthz(160,58,"名称",16,18,BLUE);
            puthz(230,58,"种类",16,18,BLUE);
            puthz(305,58,"供应商",16,18,BLUE);
            puthz(400,58,"价格",16,18,BLUE);
            puthz(465,58,"单位",16,18,BLUE);
            puthz(525,58,"分配统计",16,18,BLUE);
            puthz(605,58,"操作",16,18,BLUE);

            puthz(43,208,"种类筛选",16,20,WHITE);
            setcolor(WHITE);//筛选图标
            setfillstyle(SOLID_FILL,WHITE);
            bar(16,207,30,209);
            line(16,209,22,217);
            line(30,209,24,217);
            bar(22,217,24,225);
            floodfill(23,211,WHITE);
            
            break;
        case 2://采购单
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(27,140,"采购单",24,32,WHITE);

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//竖线
            line(140,50,140,480);//名称
            line(220,50,220,440);//种类
            line(290,50,290,440);//供应商
            line(390,50,390,440);//价格
            line(440,50,440,440);//单位
            line(490,50,490,440);//数量
            line(560,50,560,440);//总价

            puthz(160,58,"名称",16,18,BLUE);
            puthz(235,58,"种类",16,18,BLUE);
            puthz(315,58,"供应商",16,18,BLUE);
            puthz(400,58,"单价",16,18,BLUE);
            puthz(450,58,"单位",16,18,BLUE);
            puthz(500,58,"数量",16,18,BLUE);
            puthz(590,58,"总价",16,18,BLUE);
            /*
            puthz(35,200,"当前日期",16,20,WHITE);
            puthz(15,250,"前一天",16,18,WHITE);
            puthz(80,250,"后一天",16,18,WHITE);*/

            break;
        case 3://条件筛选
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,171,139,209);
            break;

    }
}

void drawad_info(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,51,139,89);
            puthz(15,60,"订单查询",24,28,WHITE); 

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//竖线
            line(140,110,140,480);//名称
            line(220,110,220,440);//种类
            line(290,110,290,440);//供应商
            line(390,110,390,440);//价格
            line(440,110,440,440);//单位
            line(490,110,490,440);//数量
            line(560,110,560,440);//总价

            puthz(160,118,"名称",16,18,BLUE);
            puthz(235,118,"种类",16,18,BLUE);
            puthz(315,118,"供应商",16,18,BLUE);
            puthz(400,118,"单价",16,18,BLUE);
            puthz(450,118,"单位",16,18,BLUE);
            puthz(500,118,"数量",16,18,BLUE);
            puthz(590,118,"总价",16,18,BLUE);

            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(141,51,640,109);
            puthz(200,58,"当前查询日期",16,20,WHITE);
            puthz(500,70,"总价",16,20,WHITE);
            puthz(160,88,"最早",16,18,WHITE);
            puthz(210,88,"前一天",16,18,WHITE);
            puthz(280,88,"后一天",16,18,WHITE);
            puthz(350,88,"最新",16,18,WHITE);

            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(27,100,"食堂上报",24,28,WHITE);

            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(27,140,"库存查询",24,32,WHITE);
            break;
        
        default: break;
    }
}

void drawad_storage(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,51,139,89);
            puthz(15,60,"库存查询",24,28,WHITE); 

            setcolor(DARKGRAY);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3-50,50,140+100*3-50,440);
            line(140+100*4-50,50,140+100*4-50,440);

            puthz(156,58,"库存编号",16,18,BLUE);
            puthz(272,58,"名称",16,20,BLUE);
            puthz(350,58,"单位",16,20,BLUE);
            puthz(407,58,"库存总数",16,18,BLUE);
            puthz(535,58,"入库时间",16,18,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,91,139,129);
            puthz(35,100,"入库",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50,140+50,440);
            line(140+50+100*1,50,140+50+100*1,440);
            line(140+50+100*2,50,140+50+100*2,440);
            line(140+100*4,50,140+100*4,440);

            puthz(150,58,"序号",16,18,BLUE);
            puthz(223,58,"名称",16,20,BLUE);
            puthz(323,58,"数量",16,20,BLUE);
            puthz(430,58,"是否入库",16,18,BLUE);
            puthz(557,58,"操作时间",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,131,139,169);
            puthz(35,140,"出库",24,40,WHITE);

            
            setfillstyle(SOLID_FILL,WHITE);
            bar(140,53,160,78+30*12);
            bar(620,53,640,78+30*12);
            bar(140,53,640,109);
            bar(140,411,640,78+30*12);
            setfillstyle(SOLID_FILL,RED);
            bar(20,392,120,422);
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            line(140,51,140,80+30*12); //左边框
            line(640,51,640,80+30*12); //右边框
            setlinestyle(SOLID_LINE,0,1);
            line(160,110,160,410);
            line(275,110,275,410);
            line(390,110,390,410);
            line(440,110,440,410);
            line(620,110,620,410);

            puthz(33,400,"确认出库",16,20,WHITE);  
            puthz(352,60,"出库单",24,26,BLUE);
            puthz(170,88,"食堂名称",16,20,BLUE);
            puthz(415,88,"出库时间",16,18,BLUE);
            puthz(200,118,"种类",16,20,BLUE);
            puthz(312,118,"名称",16,20,BLUE);
            puthz(395,118,"单位",16,20,BLUE);
            puthz(510,118,"数量",16,20,BLUE);
            
            break;
    }
}

void drawad_logistic(int op)
{
    switch(op)
    {
        case 0:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,51,139,89);
            puthz(15,60,"物流查询",24,28,WHITE); 
            
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50+30,140+50,440);
            line(140+50+100*1,50+30,140+50+100*1,440);

            puthz(312,58,"校外物流查询",16,18,RED);
            puthz(510,58,"查询种类切换",16,18,BLUE);
            puthz(150,88,"序号",16,18,BLUE);
            puthz(218,88,"供应商",16,18,BLUE);
            puthz(423,88,"物流状态",16,20,BLUE);

            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,91,139,129);
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
            bar(1,131,139,169);
            puthz(35,140,"发货",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE, 0, 1);
            line(140+150,50,140+150,440);
            line(140+150+125,50,140+150+125,440);
            line(140+150+125+100,50,140+150+125+100,440);
            
            puthz(180,58,"运输单号",16,18,BLUE);
            puthz(335,58,"类别",16,20,BLUE);
            puthz(325,58+30,"蔬菜类",16,20,BLUE);
            puthz(325,58+30*2,"肉类",16,20,BLUE);
            puthz(325,58+30*3,"水产类",16,20,BLUE);
            puthz(325,58+30*4,"其他",16,20,BLUE);
            puthz(325,58+30*5,"调料",16,18,BLUE);
            puthz(325,58+30*6,"粮油面",16,18,BLUE);
            puthz(432,58,"是否发货",16,18,BLUE);
            puthz(547,58,"操作时间",16,18,BLUE);
            break;
        case 3:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,51,139,89);
            puthz(15,60,"物流查询",24,28,WHITE); 
            
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50+30,140+50,440);
            line(140+50+100*1,50+30,140+50+100*1,440);

            puthz(312,58,"校内物流查询",16,18,RED);
            puthz(510,58,"查询种类切换",16,18,BLUE);
            puthz(150,88,"序号",16,18,BLUE);
            puthz(218,88,"运输车",16,18,BLUE);
            puthz(423,88,"物流状态",16,20,BLUE);

            break;
    }
}

void typemenu_lg(int op)
{
    switch (op)
    {
        case 1:
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(510,80,610,80+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(510,80,610,80+30*6);
            puthz(533,88,"蔬菜类",16,18,DARKGRAY);
            puthz(540,88+30,"肉类",16,18,DARKGRAY);
            puthz(533,88+30*2,"水产类",16,18,DARKGRAY);
            puthz(540,88+30*3,"其他",16,18,DARKGRAY);
            puthz(540,88+30*4,"调料",16,18,DARKGRAY);
            puthz(533,88+30*5,"粮油面",16,18,DARKGRAY);
            break;
           
        case 2:
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(10,162,110,162+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(10,162,110,162+30*6);
            puthz(33,170,"蔬菜类",16,18,DARKGRAY);
            puthz(40,170+30,"肉类",16,18,DARKGRAY);
            puthz(33,170+30*2,"水产类",16,18,DARKGRAY);
            puthz(40,170+30*3,"其他",16,18,DARKGRAY);
            puthz(40,170+30*4,"调料",16,18,DARKGRAY);
            puthz(33,170+30*5,"粮油面",16,18,DARKGRAY);
            break;
        case 3:
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(10,162+30*2,110,162+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(10,162+30*2,110,162+30*6);
            puthz(33,170+30*2,"百景园",16,18,DARKGRAY);
            puthz(25,170+30*3,"喻园食堂",16,18,DARKGRAY);
            puthz(25,170+30*4,"韵苑食堂",16,18,DARKGRAY);
            puthz(25,170+30*5,"学二食堂",16,18,DARKGRAY);
            break;     
        default:
            break;
    }
}