#ifndef _RECORD_H_
#define _RECORD_H_

void storagerd(int recent,int *all);//读取入库信息
void storage_in(FD *f);//数据入库
void ruku(int i,int recent);//单击入库
void logisticsrd(int recent,int *all,int code,int type,int i);//读取物流状态信息
int countline(int type);//计算该类物流状态总数
void searchtype(FD *f,CKFD *ckf);//查询种类编号
void shouhuo(int *t);//收货数据编写
void shourd(int recent,int *all);//读取收货信息
#endif

