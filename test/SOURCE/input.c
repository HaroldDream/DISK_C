#include "input.h"
#include "common.h"


/********************************************
FUNCTION:input
DESCRIPTION: �˺š��û�������Ϣ����
INPUT:id��x1��y1��charnum,color
RETURN:��
********************************************/
void input(char* id, int x1, int y1, int charnum, int color)//������ַ����������xy��������ַ����ƣ���������ɫ
{

	int i = 0;
	char s;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(1,0,2);
	setcolor(WHITE);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 34);//���

	while (1)
	{
		s = bioskey(0);
		if (i < charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//Esc
			{
				if (s != '\b')
				{
					*(id + i) = s;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 36); //�ڸǹ��
					outtextxy(x1 + 8 + i * 18, y1+6, id + i);//���s�ַ�(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);
				}
				else if (s == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 36);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//Esc
			{
				if (s == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 36);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
				break;
			}
		}
	}
}

/********************************************
DESCRIPTION: �������Ϣ����
INPUT:id,x1,y1,charnum,color
RETURN:��
********************************************/
void inputmm(char* id, int x1, int y1, int charnum, int color)
{

	int i = 0;
	char s;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 34);

	while (1)
	{
		s = bioskey(0);//��ȡ��ֵ
		if (i < charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//033��ʾEsc
			{
				if (s != '\b')
				{
					*(id + i) = s;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
					setfillstyle(SOLID_FILL, BLACK);
					setcolor(BLACK);
					fillellipse(x1+12+i*18,y1+20,7,7);
					setfillstyle(SOLID_FILL, color);
					setcolor(WHITE);
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);
				}
				else if (s == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
					bar(x1 - 14 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 36);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);//���ƹ��
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 34);//�ڸǹ��
				break;
			}
		}
		else if (i >= charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//Esc
			{
				if (s == '\b' && i > 0)//�˸��
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 36);//�ڸ�����
					i--;//����һ������
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 34);//���ƹ��
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 36);//�ڸǹ��
				break;
			}
		}
	}
}
