#include "common.h"
#include "drawuser.h"

void drawuser(void)
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
    bar(368,32,426,36);
    bar(508,32,566,36);


    setcolor(WHITE);
    circle(20,20,15);
    puthz(12,12,"ʳ",16,20,WHITE);

    puthz(212+8,12,"�ִ�����",16,20,DARKGRAY);
    puthz(352+8,12,"��������",16,20,DARKGRAY);
    puthz(492+8,12,"��Ϣ����",16,20,DARKGRAY);

    puthz(6,450,"�˳�",16,20,WHITE);
}