#include "common.h"

void drawuser(void)
{
    cleardevice();
    setbkcolor(WHITE);

    setfillstyle(SOLID_FILL,LIGHTBLUE);
    bar(0,0,240,40);
    bar(260,40,380,40);
    bar(390,40,510,40);
    bar(520,40,640,40);


    setfillstyle(SOLID_FILL,BLUE);
    bar(500,40,640,480);


    setcolor(DARKGREY);
    circle(20,20,15);
    puthz(18,18,"ºó",16,20,DARKGRAY);

    
}