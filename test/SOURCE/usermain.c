#include "common.h"
#include "usermain.h"

void usermain(int *page)
{
    int fun = 1;
    
    while(1)
    {
        switch(fun)
        {
            case 0: 
                *page = 0;				//退出至登录界面
				return;
            case 1: 
                storage_us(&fun);
                break;
            case 2: 
                logistic_us(&fun);
                break;
            case 3: 
                info_us(&fun);
                break;


        }
    }

}