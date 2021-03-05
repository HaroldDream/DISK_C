#ifndef _REGISTER_H_
#define _REGISTER_H_

void registermain(int* page);
void selectbutton_register(int x1, int y1, int x2, int y2, int color1, int num);//*注册界面按钮变成选中状态函数
void recoverbutton_register(int num);//* 注册界面恢复按钮最初状态函数
void selectmode_register(int num);//*显示端口被选择状态函数

#endif