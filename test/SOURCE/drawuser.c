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
    bar(0,49,140,480);//��๦����

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,140,50);//ͷ����

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(228,36,286,40);//С����
    bar(368,36,426,40);
    bar(508,36,566,40);  

    setcolor(WHITE);//ͷ����
    circle(22,26,15);
    puthz(15,18,"ʳ",16,20,WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(48,8,stime);
    
    switch(p->tm_wday) //��ʾ����
    {
        case 0:
            puthz(47,27,"����",16,20,WHITE);
            break;
        case 1:
            puthz(47,27,"����",16,20,WHITE);
            break;
        case 2:
            puthz(47,27,"��һ",16,20,WHITE);
            break;
        case 3:
            puthz(47,27,"�ܶ�",16,20,WHITE);
            break;
        case 4:
            puthz(47,27,"����",16,20,WHITE);
            break;
        case 5:
            puthz(47,27,"����",16,20,WHITE);
            break;
        case 6:
            puthz(47,27,"����",16,20,WHITE);
            break;
    }


    puthz(212+8,16,"�ִ�����",16,20,DARKGRAY);
    puthz(352+8,16,"��������",16,20,DARKGRAY);
    puthz(492+8,16,"��Ϣ����",16,20,DARKGRAY);
    puthz(8,450,"�˳�",16,20,WHITE);

    puthz(300,450,"��",16,18,BLUE);
    puthz(340,450,"ҳ",16,18,BLUE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,1);
    line(368,450,358,465);
    puthz(370,450,"��",16,18,BLUE);
    puthz(410,450,"ҳ",16,18,BLUE);
    puthz(510,450,"��һҳ",16,18,BLUE);
    puthz(570,450,"��һҳ",16,18,BLUE);
    puthz(8,450,"�˳�",16,20,WHITE);

    setcolor(DARKGRAY); //����
    setlinestyle(SOLID_LINE,0,3);
    line(0,51,640,51); //������
    line(140,80+30*12,640,80+30*12); //����
    setlinestyle(SOLID_LINE,0,1);
    line(140,50+30,640,50+30); //������
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

    setcolor(WHITE);//������
    setlinestyle(SOLID_LINE,0,1);
    line(1,50,139,50);
    line(1,90,139,90);
    line(1,130,139,130);
    line(1,170,139,170);


    switch(num)
    {
        case 0://�ִ�
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(228,36,286,40);

            setcolor(WHITE);//ɸѡͼ��
            setfillstyle(SOLID_FILL,WHITE);
            bar(16,357,30,359);
            line(16,359,22,367);
            line(30,359,24,367);
            bar(22,367,24,375);
            floodfill(23,361,WHITE);

            puthz(15,60,"����ѯ",24,28,WHITE);            
            puthz(35,100,"���",24,40,WHITE);
            puthz(35,140,"����",24,40,WHITE);
            puthz(43,358,"����ɸѡ",16,20,WHITE);   

            drawuser_storage(op);
            break;
        case 1://����
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(368,36,426,40); 

            setcolor(WHITE);//ˢ��ͼ��
            setfillstyle(SOLID_FILL,WHITE);
            setlinestyle(SOLID_LINE,0,3);
            ellipse(24,368,120,240,12,12);
            ellipse(23,368,0,60,12,12);
            ellipse(23,368,300,0,12,12);
            line(18,358,9,359);
            line(18,358,18,365);
            line(30,379,38,373);
            line(30,379,30,370);

            puthz(15,60,"������ѯ",24,28,WHITE);            
            puthz(35,100,"�ջ�",24,40,WHITE);
            puthz(35,140,"����",24,40,WHITE);
            puthz(45,360,"״̬ˢ��",16,21,WHITE);

            drawuser_logistic(op);
            break;
        case 2://��Ϣ
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(508,36,566,40);
   
            puthz(15,60,"��������",24,28,WHITE);            
            puthz(15,140,"ʳ�ķ���",24,28,WHITE);
            puthz(15,100,"������Ϣ",24,28,WHITE);

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
            puthz(15,60,"����ѯ",24,28,WHITE); 

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(156,58,"�����",16,18,BLUE);
            puthz(272,58,"����",16,20,BLUE);
            puthz(357,58,"���ʱ��",16,18,BLUE);
            puthz(457,58,"�������",16,18,BLUE);
            puthz(565,58,"��λ",16,20,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"���",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(157,58,"��ⵥ��",16,18,BLUE);
            puthz(273,58,"����",16,20,BLUE);
            puthz(373,58,"����",16,20,BLUE);
            puthz(457,58,"�Ƿ����",16,18,BLUE);
            puthz(557,58,"����ʱ��",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"����",24,40,WHITE);

            setcolor(DARKGRAY);
            line(260,50,260,440);
            line(320,50,320,440);
            line(420,50,420,440);
            line(510,50,510,440);

            puthz(168,58,"���ⵥ��",16,18,BLUE);
            puthz(273,58,"ʳ��",16,20,BLUE);
            puthz(340,58,"����״̬",16,18,BLUE);
            puthz(430,58,"�Ƿ����",16,18,BLUE);
            puthz(540,58,"����ʱ��",16,18,BLUE);
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
            puthz(15,60,"������ѯ",24,28,WHITE); 
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"�ջ�",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1); 
            line(240,50,240,440);
            line(340,50,340,440);
            line(450,50,450,440);
            line(540,50,540,440);

            puthz(159,58,"�������",16,18,BLUE);
            puthz(275,58,"����",16,18,BLUE);
            puthz(370,58,"��Ӧ��",16,18,BLUE);
            puthz(459,58,"ǩ��״̬",16,18,BLUE);
            puthz(557,58,"����ʱ��",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"����",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE, 0, 1);
            line(140+150,50,140+150,440);
            line(140+150+125,50,140+150+125,440);
            line(140+150+125+100,50,140+150+125+100,440);
            
            puthz(180,58,"���䵥��",16,18,BLUE);
            puthz(335,58,"���",16,20,BLUE);
            puthz(432,58,"�Ƿ񷢻�",16,18,BLUE);
            puthz(547,58,"����ʱ��",16,18,BLUE);
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
            puthz(15,60,"����ѯ",24,28,WHITE); 

            setcolor(DARKGRAY);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(156,58,"�����",16,18,BLUE);
            puthz(272,58,"����",16,20,BLUE);
            puthz(357,58,"���ʱ��",16,18,BLUE);
            puthz(457,58,"�������",16,18,BLUE);
            puthz(565,58,"��λ",16,20,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(35,100,"���",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3,50,140+100*3,440);
            line(140+100*4,50,140+100*4,440);

            puthz(157,58,"��ⵥ��",16,18,BLUE);
            puthz(273,58,"����",16,20,BLUE);
            puthz(373,58,"����",16,20,BLUE);
            puthz(457,58,"�Ƿ����",16,18,BLUE);
            puthz(557,58,"����ʱ��",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(35,140,"����",24,40,WHITE);

            setcolor(DARKGRAY);
            line(260,50,260,440);
            line(320,50,320,440);
            line(420,50,420,440);
            line(510,50,510,440);

            puthz(168,58,"���ⵥ��",16,18,BLUE);
            puthz(273,58,"ʳ��",16,20,BLUE);
            puthz(340,58,"����״̬",16,18,BLUE);
            puthz(430,58,"�Ƿ����",16,18,BLUE);
            puthz(540,58,"����ʱ��",16,18,BLUE);
            break;
    }
}

