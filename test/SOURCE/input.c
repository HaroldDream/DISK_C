#include "input.h"
#include "common.h"


/********************************************
FUNCTION:input
DESCRIPTION: 账号、用户名等信息输入
INPUT:id，x1，y1，charnum,color
RETURN:无
********************************************/
void input(char* id, int x1, int y1, int charnum, int color)//输入的字符串，输入的xy，输入的字符限制，输入框的颜色
{

	int i = 0;
	char s;
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(1,0,2);
	setcolor(WHITE);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 34);//光标

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
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 26); //遮盖光标
					outtextxy(x1 + 8 + i * 18, y1+3, id + i);//输出s字符(16)
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 26);
				}
				else if (s == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1+3, x1 + 12 + i * 18, y1 + 28);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 28);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 28);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 26);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//Esc
			{
				if (s == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 3, x1 + 7 + i * 18, y1 + 26);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 26);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 3, x1 + 12 + i * 18, y1 + 26);//遮盖光标
				break;
			}
		}
	}
}

/********************************************
DESCRIPTION: 密码等信息输入
INPUT:id,x1,y1,charnum,color
RETURN:无
********************************************/
void inputmm(char* id, int x1, int y1, int charnum, int color)
{

	int i = 0;
	char s;
	setfillstyle(SOLID_FILL, color);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(WHITE);
	line(x1 + 10, y1 + 6, x1 + 10, y1 + 26);

	while (1)
	{
		s = bioskey(0);//读取键值
		if (i < charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//033表示Esc
			{
				if (s != '\b')
				{
					*(id + i) = s;
					*(id + i + 1) = '\0';
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					setfillstyle(SOLID_FILL, BLACK);
					setcolor(BLACK);
					fillellipse(x1+12+i*18,y1+15,7,7);
					setfillstyle(SOLID_FILL, color);
					setcolor(WHITE);
					i++;
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 26);
				}
				else if (s == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
					bar(x1 - 14 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 26);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 26);//绘制光标
					*(id + i) = '\0';
					*(id + i + 1) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 26);//遮盖光标
				break;
			}
		}
		else if (i >= charnum)
		{
			if (s != '\n'&& s != '\r'&& s != ' '&& s != 033)//Esc
			{
				if (s == '\b' && i > 0)//退格键
				{
					bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
					bar(x1 - 10 + i * 18, y1 + 4, x1 + 7 + i * 18, y1 + 22);//遮盖文字
					i--;//减少一个字数
					line(x1 + 10 + i * 18, y1 + 6, x1 + 10 + i * 18, y1 + 20);//绘制光标
					*(id + i) = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, color);
				bar(x1 + 8 + i * 18, y1 + 4, x1 + 12 + i * 18, y1 + 22);//遮盖光标
				break;
			}
		}
	}
}
