#include "common.h"
#include "usermain.h"
#include "drawuser.h"

void usermain(int *page, USER *u)
{
    



    clrmous(MouseX,MouseY);
    delay(100);
    drawuser();

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        
    }

}