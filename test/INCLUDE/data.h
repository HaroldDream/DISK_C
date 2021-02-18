#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //食堂用户
{
    char username[15];
    char password[15];
}UESR;

typedef struct admininfo //后勤管理员用户
{
    char username[15];
    char password[15];
}ADMIN;

typedef struct foodinfo //食材  
{
    char name[15];  //名称
    char type[10];  //种类，如蔬菜、肉类
    int weight;     //重量
    TIME time; 
}FD;

typedef struct supplierinfo //供应商
{
    char name[15];  //名称
    char phone[12]; //电话
    FD food[20];    //销售的食材
}SPL;

typedef struct timeinfo //时间信息
{
    char dlv1[11]; //供应商发货时间
    char rcv1[11]; //后勤仓库收货时间
    char dlv2[11]; //后勤仓库发货时间
    char rcv2[11]; //食堂收货时间
}TIME; 

typedef struct menuinfo //具体菜单信息
{
    char name[15]; //菜名
    char type[15]; //种类，如汤、荤菜、素材、特色菜
    FD food;
}MN;

typedef struct canteeninfo //食堂信息
{
    char name[15];   //食堂名称
    FD food[20];     //食材库存
    MN menu[20];     //具体菜单
}CTN;

typedef struct warehouse //后勤仓库信息
{
    FD food[20];
}WH;

typedef struct logisticinfo //物流信息
{
    char location[15]; //当前位置
    char state[15]; //当前状态
}LGTC;


#endif