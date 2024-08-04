#include "../common.h"
// 定义链表节点
typedef struct{
    elem data;
    struct DNode *prior;
    struct DNode *next;
}DNode;

typedef DNode* DLinkList;

// 函数声明 

Status InitList(DLinkList *L); // 初始化
Status Empty(DLinkList L);// 判空

DNode * LocateElem(DLinkList L, elem e); // 按值查找
DNode * GetElem(DLinkList *L, int i); // 按位查找

Status InsertNextNode(DNode *p,elem e); //指定元素后插入
Status InsertPreNode(DNode *p,elem e); //指定元素前插入
Status ListInsert(DLinkList *L, int i, elem e); // 按位置插入

Status ListDelete(DLinkList *L, int i, elem * e); // 删除
Status DeleteNode(DNode *p); // 删除指定节点

int Length(DLinkList L); // 表长
void PrintList(DLinkList L); // 打印链表
void PrintNode(DNode p); // 打印节点

DLinkList TailInsert(DLinkList *L,int n); // 尾插法
DLinkList HeadInsert(DLinkList *L,int n); // 头插法

void ListReverse(DLinkList *L); //翻转链表