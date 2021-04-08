#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //食堂用户
{
    char username[15];
    char password[15];
    char phone[20];
    int mode;
}USER;

typedef struct supplier //供应商
{
    char name[15];  //名称
    char phone[12]; //电话
}SPL;

typedef struct foodinfo //食材  
{
    char name[7];  //名称
    char type[7];  //种类，如蔬菜、肉类
    char s[11];  //供应商
    char p[5];    //价格
    char num[8];    //数量
    char est[8];   //预测需求
    char unit[3];  //单位
    char state[2]; //状态:0未采购,1已采购,2后勤入库,3后勤发货,4食堂入库

    char d1[7]; //供应商发货时间（采购时间）
    //char r1[7]; //后勤仓库收货时间
    //char d2[7]; //后勤仓库发货时间
    //char r2[7]; //食堂收货时间

}FD;

typedef struct logisticinfo //物流信息
{
    char location[15]; //当前位置
    char state[15]; //当前状态
}LGTC;


#endif