#ifndef _JUDGE_H_
#define _JUDGE_H_

int register_success(char* u,char *c, char* p, char* cp); //*用来判断注册信息是否输入完全和正确
void judgelength(char* str, int* box, int num); //*判断各个输入框长度是否符合要求
void recover (int num); //*恢复输入框提示
int judge_sameuser(char* new_user); //*判断账户是否出现重名


#endif