#ifndef _DATA_H_
#define _DATA_H_

typedef struct userinfo //食堂用户
{
    char username[15];
    char password[15];
    char phone[20];
    int mode;
}USER;

typedef struct foodinfo //食材  
{
    char name[7];  //名称
    char type[7];  //种类
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

typedef struct foodfc //食材（预测）  
{
    char name[7];  //名称
    char type[7];  //种类
    char unit[3];  //单位
    char state[2]; //状态

    char num[7]; //上报
    char d8[7]; //预测
    char dis[7]; //分配

    char d1[7];//前七天消耗
    char d2[7];
    char d3[7];
    char d4[7];
    char d5[7];
    char d6[7];
    char d7[7];
}FF;

typedef struct CKfoodinfo //仓库食材  
{
    char cknum[9]; //入库编号
    char name[7];  //名称
    char type[7];  //种类，如蔬菜、肉类
    char typenum[2]; //种类对应编号
    char namenum[3]; //名称对应编号
    char s[11];  //供应商
    char num[8];    //数量
    char unit[3];  //单位
    char state[2]; //状态:0未采购,1已采购,2到达但未入库,3后勤入库,4后勤发货,5食堂入库

    char r1[12]; //后勤仓库收货时间
    char d2[12]; //后勤仓库发货时间
    char r2[12]; //食堂收货时间

}CKFD;

typedef struct supplierinfo //供应商gys
{
    char name[15];  //名称
    char phone[12]; //电话
    FD food[20];    //销售的食材
}SPL;

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

#endif