#include "common.h"

void drawadmin(int num)
{
    cleardevice();
    setbkcolor(WHITE);

    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,49,140,480);//��๦����

    //setfillstyle(SOLID_FILL,BLUE);

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,140,50);//ͷ����

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(220,36,280,40);
    bar(320,36,380,40);
    bar(420,36,480,40);
    bar(520,36,580,40);  

    setcolor(WHITE);//ͷ����
    circle(22,26,15);
    puthz(15,18,"��",16,20,WHITE);

    puthz(212,16,"�ִ�����",16,20,DARKGRAY);
    puthz(312,16,"ʳ�Ĳɹ�",16,20,DARKGRAY);
    puthz(412,16,"��������",16,20,DARKGRAY);
    puthz(512,16,"��Ϣ����",16,20,DARKGRAY);

    puthz(6,450,"�˳�",16,20,WHITE);

    switch(num)
    {
        case 0://�ִ�
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(220,36,280,40);
            break;
        case 1://�ɹ�
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
            
            line(140,50+30,640,50+30);//������
            line(140,80+30*1,640,80+30*1);//����
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
            
            line(0,50,0,480);//����
            line(140,50,140,480);//����
            line(200,50,200,440);//����
            line(300,50,300,440);//��Ӧ��
            line(400,50,400,440);//�۸�
            line(460,50,460,440);//����
            line(520,50,520,440);//Ԥ������
            line(600,50,600,440);//����

            puthz(155,58,"����",16,18,BLUE);
            puthz(235,58,"����",16,18,BLUE);
            puthz(325,58,"��Ӧ��",16,18,BLUE);
            puthz(415,58,"�۸�",16,18,BLUE);
            puthz(475,58,"����",16,18,BLUE);
            puthz(525,58,"Ԥ������",16,18,BLUE);
            puthz(605,58,"����",16,18,BLUE);

            puthz(300,450,"��",16,18,BLUE);
            puthz(340,450,"ҳ",16,18,BLUE);
            line(368,450,358,465);
            puthz(370,450,"��",16,18,BLUE);
            puthz(410,450,"ҳ",16,18,BLUE);
            puthz(510,450,"��һҳ",16,18,BLUE);
            puthz(570,450,"��һҳ",16,18,BLUE);

            break;
        case 2://����
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(420,36,480,40);
            break;
        case 3://��Ϣ
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(520,36,580,40);
            break;
    }
}