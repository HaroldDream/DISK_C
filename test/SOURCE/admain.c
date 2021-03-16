#include "common.h"
#include "admain.h"
#include "drawuser.h"

void admain(int *page)
{
    int fun = 0;
    
    while(1)
    {
        switch(fun)
        {
            case 0: 
                storage(&fun);
                break;
            case 1: 
                purchase(&fun);
                break;
            case 2: 
                logistic(&fun);
                break;
            case 3: 
                info(&fun);
                break;
            case 4:
			    *func = 0;				//退出至登录界面
				return ;
        }

    }

}
