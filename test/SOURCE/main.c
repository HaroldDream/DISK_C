#include "common.h"
#include "main.h"
#include "home.h"
#include "register.h"


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
			
			case 2:   //*ע��ҳ��
				registermain(&page);  
				break;   

			case 3:   //*���ڹ���Ա��ҳ��
			    admain(&page);
				break;

			case 4:   //*ʳ���û���ҳ��
			    usermain(&page);
				break;
		}
	}


 }