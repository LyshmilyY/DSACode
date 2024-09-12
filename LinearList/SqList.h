#include "../common.h"
#define INITSIZE 10
// 定义顺序表
typedef struct SqList{
    int length;
    int MaxSize;
    int* data;
}SqList;
// 函数声明 

Status InitList(SqList * L); // 初始化
Status IncreaseSize(SqList * L, int len); // 增加表长
Status ListInsert(SqList * L, int i, int e); // 插入
Status ListDelete(SqList * L, int i, int* e); // 删除
int LocateElem(SqList L, int e); // 按值查找
Status GetElem(SqList L, int i, int* e); // 按位查找 
int Length(SqList L); // 表长
Status Empty(SqList L);// 判空
void PrintList(SqList L); // 打印
void Printelem(int e); // 打印单个数据元素