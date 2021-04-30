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
    bar(0,49,140,480);//��๦����

    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,140,50);//ͷ����

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(220,36,280,40);//С����
    bar(320,36,380,40);
    bar(420,36,480,40);
    bar(520,36,580,40);  

    setcolor(WHITE);//ͷ����
    circle(22,26,15);
    puthz(15,18,"��",16,20,WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(48,10,stime);
    
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

    puthz(212,16,"�ִ�����",16,20,DARKGRAY);
    puthz(312,16,"ʳ�Ĳɹ�",16,20,DARKGRAY);
    puthz(412,16,"��������",16,20,DARKGRAY);
    puthz(512,16,"��Ϣ����",16,20,DARKGRAY);

    puthz(300,452,"��",16,18,BLUE);
    puthz(340,452,"ҳ",16,18,BLUE);
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,1);
    line(368,452,358,467);
    puthz(370,452,"��",16,18,BLUE);
    puthz(410,452,"ҳ",16,18,BLUE);
    puthz(510,452,"��һҳ",16,18,BLUE);
    puthz(570,452,"��һҳ",16,18,BLUE);
    puthz(8,452,"�˳�",16,20,WHITE);

    setcolor(DARKGRAY); //����
    setlinestyle(SOLID_LINE,0,3);
    line(140,50,640,50); //������
    line(140,440,640,440); //����
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
            bar(220,36,280,40);

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

            drawad_storage(op);
            break;
        case 1://�ɹ�
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(320,36,380,40);

            puthz(15,60,"ϵͳԤ��",24,28,WHITE);            
            puthz(15,100,"�ɹ�Ŀ¼",24,28,WHITE);
            puthz(27,140,"�ɹ���",24,32,WHITE);

            drawad_purchase(op);  
            break;
        case 2://����
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(420,36,480,40); 

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

            drawad_logistic(op);
            break;
        case 3://��Ϣ
            setfillstyle(SOLID_FILL,LIGHTBLUE);
            bar(520,36,580,40);
            puthz(15,60,"������ѯ",24,28,WHITE);            
            puthz(27,140,"��Ӧ��",24,32,WHITE);
            puthz(15,100,"������Ϣ",24,28,WHITE);

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
            puthz(15,60,"ϵͳԤ��",24,28,WHITE); 

            setfillstyle(SOLID_FILL,WHITE);
            bar(141,51,640,439); //cover
            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,3);
            line(140,245,640,245);

            puthz(28,200,"��ǰʳ��",16,20,WHITE);
            puthz(15,250,"��һ��",16,18,WHITE);
            puthz(80,250,"��һ��",16,18,WHITE);

            
            break;
        case 1://�ɹ�Ŀ¼
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(15,100,"�ɹ�Ŀ¼",24,28,WHITE);

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//����
            line(140,50,140,480);//����
            line(210,50,210,440);//����
            line(280,50,280,440);//��Ӧ��
            line(385,50,385,440);//�۸�
            line(450,50,450,440);//��λ
            line(515,50,515,440);//Ԥ������
            line(600,50,600,440);//����

            puthz(160,58,"����",16,18,BLUE);
            puthz(230,58,"����",16,18,BLUE);
            puthz(305,58,"��Ӧ��",16,18,BLUE);
            puthz(400,58,"�۸�",16,18,BLUE);
            puthz(465,58,"��λ",16,18,BLUE);
            puthz(525,58,"����ͳ��",16,18,BLUE);
            puthz(605,58,"����",16,18,BLUE);

            puthz(43,208,"����ɸѡ",16,20,WHITE);
            setcolor(WHITE);//ɸѡͼ��
            setfillstyle(SOLID_FILL,WHITE);
            bar(16,207,30,209);
            line(16,209,22,217);
            line(30,209,24,217);
            bar(22,217,24,225);
            floodfill(23,211,WHITE);
            
            break;
        case 2://�ɹ���
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(27,140,"�ɹ���",24,32,WHITE);

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//����
            line(140,50,140,480);//����
            line(220,50,220,440);//����
            line(290,50,290,440);//��Ӧ��
            line(390,50,390,440);//�۸�
            line(440,50,440,440);//��λ
            line(490,50,490,440);//����
            line(560,50,560,440);//�ܼ�

            puthz(160,58,"����",16,18,BLUE);
            puthz(235,58,"����",16,18,BLUE);
            puthz(315,58,"��Ӧ��",16,18,BLUE);
            puthz(400,58,"����",16,18,BLUE);
            puthz(450,58,"��λ",16,18,BLUE);
            puthz(500,58,"����",16,18,BLUE);
            puthz(590,58,"�ܼ�",16,18,BLUE);
            /*
            puthz(35,200,"��ǰ����",16,20,WHITE);
            puthz(15,250,"ǰһ��",16,18,WHITE);
            puthz(80,250,"��һ��",16,18,WHITE);*/

            break;
        case 3://����ɸѡ
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
            puthz(15,60,"������ѯ",24,28,WHITE); 

            setcolor(DARKGRAY); 
            setlinestyle(SOLID_LINE,0,1);//����
            line(140,110,140,480);//����
            line(220,110,220,440);//����
            line(290,110,290,440);//��Ӧ��
            line(390,110,390,440);//�۸�
            line(440,110,440,440);//��λ
            line(490,110,490,440);//����
            line(560,110,560,440);//�ܼ�

            puthz(160,118,"����",16,18,BLUE);
            puthz(235,118,"����",16,18,BLUE);
            puthz(315,118,"��Ӧ��",16,18,BLUE);
            puthz(400,118,"����",16,18,BLUE);
            puthz(450,118,"��λ",16,18,BLUE);
            puthz(500,118,"����",16,18,BLUE);
            puthz(590,118,"�ܼ�",16,18,BLUE);

            setfillstyle(SOLID_FILL,DARKGRAY);
            bar(141,51,640,109);
            puthz(200,58,"��ǰ��ѯ����",16,20,WHITE);
            puthz(500,70,"�ܼ�",16,20,WHITE);
            puthz(160,88,"����",16,18,WHITE);
            puthz(210,88,"ǰһ��",16,18,WHITE);
            puthz(280,88,"��һ��",16,18,WHITE);
            puthz(350,88,"����",16,18,WHITE);

            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,91,139,129);
            puthz(27,100,"ʳ���ϱ�",24,28,WHITE);

            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(0,131,139,169);
            puthz(27,140,"����ѯ",24,32,WHITE);
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
            puthz(15,60,"����ѯ",24,28,WHITE); 

            setcolor(DARKGRAY);
            line(140+100,50,140+100,440);
            line(140+100*2,50,140+100*2,440);
            line(140+100*3-50,50,140+100*3-50,440);
            line(140+100*4-50,50,140+100*4-50,440);

            puthz(156,58,"�����",16,18,BLUE);
            puthz(272,58,"����",16,20,BLUE);
            puthz(350,58,"��λ",16,20,BLUE);
            puthz(407,58,"�������",16,18,BLUE);
            puthz(535,58,"���ʱ��",16,18,BLUE);
            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,91,139,129);
            puthz(35,100,"���",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50,140+50,440);
            line(140+50+100*1,50,140+50+100*1,440);
            line(140+50+100*2,50,140+50+100*2,440);
            line(140+100*4,50,140+100*4,440);

            puthz(150,58,"���",16,18,BLUE);
            puthz(223,58,"����",16,20,BLUE);
            puthz(323,58,"����",16,20,BLUE);
            puthz(430,58,"�Ƿ����",16,18,BLUE);
            puthz(557,58,"����ʱ��",16,18,BLUE);
            break;
        case 2:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,131,139,169);
            puthz(35,140,"����",24,40,WHITE);

            
            setfillstyle(SOLID_FILL,WHITE);
            bar(140,53,160,78+30*12);
            bar(620,53,640,78+30*12);
            bar(140,53,640,109);
            bar(140,411,640,78+30*12);
            setfillstyle(SOLID_FILL,RED);
            bar(20,392,120,422);
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            line(140,51,140,80+30*12); //��߿�
            line(640,51,640,80+30*12); //�ұ߿�
            setlinestyle(SOLID_LINE,0,1);
            line(160,110,160,410);
            line(275,110,275,410);
            line(390,110,390,410);
            line(440,110,440,410);
            line(620,110,620,410);

            puthz(33,400,"ȷ�ϳ���",16,20,WHITE);  
            puthz(352,60,"���ⵥ",24,26,BLUE);
            puthz(170,88,"ʳ������",16,20,BLUE);
            puthz(415,88,"����ʱ��",16,18,BLUE);
            puthz(200,118,"����",16,20,BLUE);
            puthz(312,118,"����",16,20,BLUE);
            puthz(395,118,"��λ",16,20,BLUE);
            puthz(510,118,"����",16,20,BLUE);
            
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
            puthz(15,60,"������ѯ",24,28,WHITE); 
            
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50+30,140+50,440);
            line(140+50+100*1,50+30,140+50+100*1,440);

            puthz(312,58,"У��������ѯ",16,18,RED);
            puthz(510,58,"��ѯ�����л�",16,18,BLUE);
            puthz(150,88,"���",16,18,BLUE);
            puthz(218,88,"��Ӧ��",16,18,BLUE);
            puthz(423,88,"����״̬",16,20,BLUE);

            break;
        case 1:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,91,139,129);
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
            bar(1,131,139,169);
            puthz(35,140,"����",24,40,WHITE);

            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE, 0, 1);
            line(140+150,50,140+150,440);
            line(140+150+125,50,140+150+125,440);
            line(140+150+125+100,50,140+150+125+100,440);
            
            puthz(180,58,"���䵥��",16,18,BLUE);
            puthz(335,58,"���",16,20,BLUE);
            puthz(325,58+30,"�߲���",16,20,BLUE);
            puthz(325,58+30*2,"����",16,20,BLUE);
            puthz(325,58+30*3,"ˮ����",16,20,BLUE);
            puthz(325,58+30*4,"����",16,20,BLUE);
            puthz(325,58+30*5,"����",16,18,BLUE);
            puthz(325,58+30*6,"������",16,18,BLUE);
            puthz(432,58,"�Ƿ񷢻�",16,18,BLUE);
            puthz(547,58,"����ʱ��",16,18,BLUE);
            break;
        case 3:
            setfillstyle(SOLID_FILL,BLUE);
            bar(1,51,139,89);
            puthz(15,60,"������ѯ",24,28,WHITE); 
            
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,1);
            line(140+50,50+30,140+50,440);
            line(140+50+100*1,50+30,140+50+100*1,440);

            puthz(312,58,"У��������ѯ",16,18,RED);
            puthz(510,58,"��ѯ�����л�",16,18,BLUE);
            puthz(150,88,"���",16,18,BLUE);
            puthz(218,88,"���䳵",16,18,BLUE);
            puthz(423,88,"����״̬",16,20,BLUE);

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
            puthz(533,88,"�߲���",16,18,DARKGRAY);
            puthz(540,88+30,"����",16,18,DARKGRAY);
            puthz(533,88+30*2,"ˮ����",16,18,DARKGRAY);
            puthz(540,88+30*3,"����",16,18,DARKGRAY);
            puthz(540,88+30*4,"����",16,18,DARKGRAY);
            puthz(533,88+30*5,"������",16,18,DARKGRAY);
            break;
           
        case 2:
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(10,162,110,162+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(10,162,110,162+30*6);
            puthz(33,170,"�߲���",16,18,DARKGRAY);
            puthz(40,170+30,"����",16,18,DARKGRAY);
            puthz(33,170+30*2,"ˮ����",16,18,DARKGRAY);
            puthz(40,170+30*3,"����",16,18,DARKGRAY);
            puthz(40,170+30*4,"����",16,18,DARKGRAY);
            puthz(33,170+30*5,"������",16,18,DARKGRAY);
            break;
        case 3:
            setcolor(DARKGRAY);
            setlinestyle(SOLID_LINE,0,3);
            rectangle(10,162+30*2,110,162+30*6);
            setfillstyle(SOLID_FILL,WHITE);
            bar(10,162+30*2,110,162+30*6);
            puthz(33,170+30*2,"�پ�԰",16,18,DARKGRAY);
            puthz(25,170+30*3,"��԰ʳ��",16,18,DARKGRAY);
            puthz(25,170+30*4,"��Էʳ��",16,18,DARKGRAY);
            puthz(25,170+30*5,"ѧ��ʳ��",16,18,DARKGRAY);
            break;     
        default:
            break;
    }
}