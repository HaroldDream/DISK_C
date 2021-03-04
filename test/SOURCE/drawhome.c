#include "common.h"

void drawhome(void)
{
	cleardevice();
	setbkcolor(WHITE);
	
	setfillstyle(SOLID_FILL, BLUE);
	bar(0,0,639,100);
	bar(179,239,241,281);
	bar(179,299,241,341);
	bar(431,299,471,341);//todo��¼����

	setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, 3);
	rectangle(240,240,470,280);//todo�˺ſ�
	rectangle(240,300,430,340);//todo�����

	setcolor(WHITE);
    circle(210,250,7);//*�˺�ͼ��
	ellipse(210,275,0,180,15,15);
	ellipse(210,317,0,180,10,10);//*����ͼ��
	rectangle(197,320,223,335);

	line(440,320,460,320);//*��¼��ͼ��
	moveto(450,310);
	lineto(460,320);
	lineto(450,330);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    fillellipse(340,170,50,50);//*ͷ��
	setcolor(BLUE);
	circle(340,170,50);
    circle(190,370,8);//todo����ȦȦ
    circle(310,370,8);//todoʳ��ȦȦ
	
	setcolor(RED);
	line(612, 6, 634, 28);
	line(612, 28, 634, 6);

    puthz(30,40,"��ӭ��¼���ڼ���ʳ�ù�Ӧ������ϵͳ",32,35,WHITE);
    puthz(205,358,"���ڶ�",24,30,BLUE);
	puthz(325,358,"ʳ�ö�",24,30,BLUE);
	puthz(440,358,"ע��",24,30,LIGHTBLUE);

}


void drawregister(void)
{
    cleardevice();
	setbkcolor(WHITE);
	
	setcolor(WHITE);
    setfillstyle(SOLID_FILL, BLUE);
	bar(0,0,639,100);
	setcolor(BLUE);
	setlinestyle(SOLID_LINE, 0, 3);
	rectangle(240,120,240+220,120+40);               //*�û�����
	rectangle(240,120+60,240+220,120+60+40);         //*��ϵ�绰��
	rectangle(240,120+120,240+220,120+120+40);       //*�����
    rectangle(240,120+180,240+220,120+180+40);       //*ȷ�������
	setfillstyle(SOLID_FILL, RED);
	bar(280,120+240,280+140,120+240+40);             //*ע���    
    bar(560+30-90,120+240,560+30-10,120+240+40);     //*���ؼ�

	puthz(35,35,"���ڼ���ʳ�ù�Ӧ������ϵͳע�����",32,35,WHITE);
	puthz(280+25,120+240+4,"ע��",32,62,WHITE);
	puthz(560-90+30+3,120+240+4,"����",32,42,WHITE);
	puthz(115+2,120+4,"�û���",32,42,BLUE);
	puthz(100,120+60+4,"��ϵ�绰",32,34,BLUE);
	puthz(120+13,120+120+4,"����",32,62,BLUE);
	puthz(100,120+180+4,"ȷ������",32,34,BLUE);
	puthz(240+220+15,120+14,"����ʮλ�ַ�",16,20,BLUE);
	puthz(240+220+15,120+120+14,"����ʮλ�ַ�",16,20,BLUE);
	
}
