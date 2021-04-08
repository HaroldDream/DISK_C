#ifndef _INPUT_H_
#define _INPUT_H_

#include "common.h"
#include "data.h"

void input(char* id, int x1, int y1, int charnum, int color);
void inputmm(char* id, int x1, int y1, int charnum, int color);
int xouttextxy(int x,int y,char *s,int color);
int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color);
void pyFrm(int x1,int y1,int x2,int y2);
int input_method(int x,int y,char *str,int value,char *py) ;
char *itostr(int a,char *s);

#endif 