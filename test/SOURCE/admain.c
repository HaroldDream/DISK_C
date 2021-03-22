#include "common.h"
#include "admain.h"
#include "drawadmin.h"
#include "info.h"

void admain(int *page,USER *u)
{
    int fun = 1;
    
    while(1)
    {
        switch(fun)
        {
            case 0: 
                storage_ad(&fun);
                break;
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
                *page = 0;				//退出至登录界面
				return ;
        }
    }
}
