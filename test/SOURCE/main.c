#include "common.h"
#include "main.h"


void main()
{
	int page   = 0;
	int driver = VGA;
	int mode   = VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\bgi");
	mouseinit();
    while (1)
	{
		switch (page)
		{
			case 0:    //*�������
				home(&page);  
				break;     //�ص��������

			case 1:    //*�ر�ϵͳ
				delay(1000);
				closegraph();//�رջ�ͼ
				exit(1);
			
			case 2:   //todoע��ҳ��
				rgst();
			case 3: 

			case 4: 

		}
	}


 }