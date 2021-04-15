void cgml(int *fun)
{
    int page = 1;
    int func = 1;

    clrmous(MouseX,MouseY);
    delay(100);
    cleardevice();
    drawad(1,1);
    show_plist(1);

    while(1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if(mouse_press(0,440,45,480) == 1)//退出
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//系统预测
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(1,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 0;
        }
        
        if(mouse_press(0,91,140,129) == 1)//采购目录
        {
            delay(100);
            //cleardevice();
            drawad(1,1);
            show_plist(1);
            page = 1;
            func = 1;
            while (1)
            {
                if ((mouse_press(510,445,560,480) == 1) && (page > 1))//上一页
                {
                    drawad(1,1);
                    show_plist(page - 1);
                    page -= 1;
                }
                if ((mouse_press(560,445,610,480) == 1) && (page < show_plist(page)))//下一页
                {
                    drawad(1,1);
                    show_plist(page + 1);
                    page += 1;
                }
            }
        }


        if(mouse_press(0,131,140,169) == 1)//采购单
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 2;
        }
        if(mouse_press(10,390,130,430) == 1)//todo条件筛选
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,3);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(200,0,300,40) == 1)//仓储
        {
            *fun = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//物流
        {
            *fun = 2;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//信息
        {
            *fun = 3;
            return;
        }
    }
}