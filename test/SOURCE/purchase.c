#include "common.h"
#include "admain.h"
#include "drawadmin.h"

void purchase(int *fun)
{
    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawadmin(1,1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,40,480) == 1)//ÍË³ö
        {
            return;
        }
        
        
    }
}