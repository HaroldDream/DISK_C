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

        if(mouse_press(0,440,45,480) == 1)//�˳�
        {
            *fun = 0;
            return;
        }
        if(mouse_press(0,51,140,89) == 1)//ϵͳԤ��
        {
            delay(100);
            clrmous(MouseX, MouseY);
            drawad(1,0);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 0;
        }
        
        if(mouse_press(0,91,140,129) == 1)//�ɹ�Ŀ¼
        {
            delay(100);
            //cleardevice();
            drawad(1,1);
            show_plist(1);
            page = 1;
            func = 1;
            while (1)
            {
                if ((mouse_press(510,445,560,480) == 1) && (page > 1))//��һҳ
                {
                    drawad(1,1);
                    show_plist(page - 1);
                    page -= 1;
                }
                if ((mouse_press(560,445,610,480) == 1) && (page < show_plist(page)))//��һҳ
                {
                    drawad(1,1);
                    show_plist(page + 1);
                    page += 1;
                }
            }
        }


        if(mouse_press(0,131,140,169) == 1)//�ɹ���
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,2);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
            func = 2;
        }
        if(mouse_press(10,390,130,430) == 1)//todo����ɸѡ
        {
            delay(100);
            clrmous(MouseX, MouseY);
            //cleardevice();
            drawad(1,3);
            delay(50);
            newmouse(&MouseX, &MouseY, &press);
        }
        if(mouse_press(200,0,300,40) == 1)//�ִ�
        {
            *fun = 4;
            return;
        }
        if(mouse_press(400,0,500,40) == 1)//����
        {
            *fun = 2;
            return;
        }
        if(mouse_press(500,0,600,40) == 1)//��Ϣ
        {
            *fun = 3;
            return;
        }
    }
}



int get_plist(int line, FD *fdp)
{
	FILE *fp;
	int row=1, len = 0;//row����, length�ļ����ֽ���,��������
	char ch, *n;
    char length[10], tlength[10];
	int i, j;
	
	//���ļ�
    if ((fp = fopen("c:\\test\\data\\plist.txt", "rt+" )) == NULL)
    {
        closegraph();
        printf("cannot open file plist.txt,show_p1");
        delay(3000);
        exit(1);
    }
	
	fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(FD);//��������
    itoa(len,length,10);
    itoa(ftell(fp),tlength,10);    
    outtextxy(500,180,tlength);
    outtextxy(500,200,length);
	
    //��ȡ����
    fseek(fp, line * sizeof(FD), SEEK_SET);
    //fread(fdp, sizeof(char), 4, fp);
    
    //��ȡ����2
    for(j = 0; ch != ' '; j++)
    {
        fseek(fp, (line+j)*sizeof(char), SEEK_SET);
        fread(&ch, sizeof(char), 1, fp);
        fdp->name[j] = ch;
    }
    
    
    for(j = 0; ch != '\t'; j++)
    {
        fseek(fp, j*sizeof(char), SEEK_CUR);
        fread(&ch, sizeof(char), 1, fp);
        fdp->type[j] = ch;
    }
    
    for(j = 0; ch != '\t'; j++)
    {
        fseek(fp, j*sizeof(char), SEEK_CUR);
        fread(&ch, sizeof(char), 1, fp);
        fdp->type[j] = ch;
    }
    //�����������
    n = strstr(fdp->name, " ");
    stpcpy(n, "\0");

	
    if (fclose(fp) != 0)
    {
        closegraph();
        printf("\n cannot close plist.dat,show_p1");
        delay(3000);
        exit(1);
    }
	
	return 1;
}


int pop(int n)
{
	int a = 0, len = 0;//����
    char i[10];
    void *buffer;
	unsigned s;
    clrmous(MouseX, MouseY);

    setlinestyle(SOLID_LINE,0,1);
    setfillstyle(SOLID_FILL, WHITE);
    bar(200,180,440,300);
    rectangle(200,180,440,300);

    switch(n)
    {
        case 1:
            rectangle(240,220,400,250);
            puthz(247,227,"�ɹ�������",16,18,BLUE);	
            rectangle(340,265,380,285);
            rectangle(260,265,300,285);
            puthz(344,267,"����",16,20,BLUE);
            puthz(264,267,"ȷ��",16,20,BLUE);
            break;
        case 2:
            puthz(260,230,"�ɹ��ɹ�",16,20,BLUE);
            delay(1000);
            return 1;
    }

	while (n == 1)
	{
		newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(240,220,400,250) == 1)
        {
            clrmous(MouseX,MouseY);
            len= hz_input(335,220,400,250,i,len,WHITE);
        }

		if (mouse_press(260,265,300,285) == 1)//ȷ��
		{
            if (len != 0)
            {
                clrmous(MouseX, MouseY);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                puthz(260,230,"�ɹ��ɹ�",16,20,BLUE);
                delay(1000);
                a = atoi(i);
                return a;
            }
            else 
            {
                clrmous(MouseX, MouseY);
                delay(10);
                bar(200,180,440,300);
                rectangle(200,180,440,300);
                puthz(250,230,"����������",16,20,BLUE);
                delay(1000);
                return 0;                
            }
		}
        
		if (mouse_press(340,265,380,285) == 1)//����
		{
			clrmous(MouseX, MouseY);
			delay(10);
			return 0;
		}
    }
}

        for (i = 0; i < 12; i++)
        {
            if (mouse_press(600,80+30*i,640,110+30*i) == 1) //purchase
            {
                n = i;
                f = 1;
                a = pop(1); //amount of purchase
                if (a != 0) 
                {
                    up_order(n,a,page);
                    a = 0;
                    page = 1;
                    break;
                }
                else 
                    break;                
            }
            if (f == 1) 
            {
                return;
            }
        }