#include "common.h"

void drawadmin()
{
    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);//δѡ��ѡ�
    bar(228,32,286,36);//ѡ��ѡ�  
    bar(0,39,180,480);//��๦����
    setfillstyle(SOLID_FILL,BLUE);


    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,180,40);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(328,32,386,36);
    bar(428,32,486,36);
    bar(528,32,586,36);  


    setcolor(WHITE);
    circle(20,20,15);
    puthz(12,12,"��",16,20,WHITE);

    puthz(212+8,12,"�ִ�����",16,20,DARKGRAY);
    puthz(312+8,12,"ʳ�Ĳɹ�",16,20,DARKGRAY);
    puthz(412+8,12,"��������",16,20,DARKGRAY);
    puthz(512+8,12,"��Ϣ����",16,20,DARKGRAY);

    puthz(6,450,"�˳�",16,20,WHITE);

}