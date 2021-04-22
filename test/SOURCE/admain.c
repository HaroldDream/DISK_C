#include "common.h"
#include "admain.h"

void admain(int *page)
{
    int fun = 1;
    
    while(1)
    {
        switch(fun)
        {
            case 0: 
                *page = 0;				//退出至登录界面
				return ;
            case 1: 
                purchase(&fun);
                break;
            case 2: 
                logistic_ad(&fun);
                break;
            case 3: 
                info_ad(&fun);
                break;
            case 4:
                storage_ad(&fun);
                break;
        }
    }
}
