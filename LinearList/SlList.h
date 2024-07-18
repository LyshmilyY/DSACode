#include "../common.h"
// 定义链表节点
typedef struct LNode
{
    elem data;
    struct LNode *next;
}LNode,*LinkList;

// 函数声明 

Status InitList(LinkList *L); // 初始化
Status Empty(LinkList L);// 判空

LNode * LocateElem(LinkList L, elem e); // 按值查找
LNode * GetElem(LinkList *L, int i); // 按位查找

Status InsertNextNode(LNode *p,elem e); //指定元素后插入
Status InsertPreNode(LNode *p,elem e); //指定元素前插入
Status ListInsert(LinkList *L, int i, elem e); // 按位置插入

Status ListDelete(LinkList *L, int i, elem * e); // 删除
Status DeleteNode(LNode *p); // 删除指定节点

int Length(LinkList L); // 表长
void PrintList(LinkList L); // 打印链表
void PrintNode(LNode p); // 打印节点

LinkList TailInsert(LinkList *L,int n); // 尾插法
LinkList HeadInsert(LinkList *L,int n); // 头插法

void ListReverse(LinkList *L); //翻转链表
