#include "common.h"
#include "ad.h"

void purchase(int *f)
{
    clrmous(MouseX,MouseY);
    delay(100);
    drawadmain(1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,40,480) == 1)//ÍË³ö
        {
            return;
        }
        
        
    }
}