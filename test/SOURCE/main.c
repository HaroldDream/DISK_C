#include "common.h"
#include "main.h"
#include "home.h"
#include "register.h"
#include "admain.h"
#include "usermain.h"


void main()
{
	USER u;
	//ADMIN ad;

	int page   = 0;
	int driver = VGA;
	int mode   = VGAHI;
	initgraph(&driver,&mode,"C:\\BORLANDC\\bgi");
	mouseinit();

	memset(&u,'\0',sizeof(USER));
	//memset(&ad,'\0',sizeof(ADMIN));

    while (1)
	{
		switch (page)
		{
			case 0:    //*�������
			    memset(&u,'\0',sizeof(USER));
				home(&page,&u);  
				break; //�ص��������

			case 1:    //*�ر�ϵͳ
				delay(1000);
				closegraph();//�رջ�ͼ
				exit(1);
			
			case 2:   //*ע��ҳ��
				registermain(&page);  
				break;   

			case 3:   //*���ڹ���Ա��ҳ��
			    admain(&page,&u);
				break;

			case 4:   //*ʳ���û���ҳ��
			    usermain(&page,&u);
				break;
		}
	}


 }