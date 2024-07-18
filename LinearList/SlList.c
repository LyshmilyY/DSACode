#include "SlList.h"

// 初始化
Status InitList(LinkList *L)
{
    *L = (LNode *) malloc (sizeof(LNode));
    if (*L == NULL)
        return ERROR;
    (*L) ->next = NULL;
    return OK;
}

// 判空
Status Empty(LinkList L)
{
    if (L->next == NULL)
        return OK;
    return ERROR;
}

// 按值查找
LNode * LocateElem(LinkList L, elem e)
{
    LNode *p = L->next;
    while(p != NULL && p->data.name != e.name)
        p->next;
    return p;
}

// 按位查找 
LNode * GetElem(LinkList *L, int i)
{
    if (i < 1)
        return NULL;
    LNode *p = *L;
    // 第 j 个节点 p
    int j = 0;
    // 找到第 i 个元素的位置
    while (p !=NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//指定元素后插入
Status InsertNextNode(LNode *p,elem e)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL || p == NULL)
        return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//指定元素前插入
Status InsertPreNode(LNode *p,elem e)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL || p == NULL)
        return ERROR;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return OK;
}

// 按位置插入
Status ListInsert(LinkList *L, int i, elem e)
{
    if (i < 1)
        return ERROR;
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL)
        return ERROR;
    if (i ==1)
        {
            
            p->data = e;
            p->next = (*L)->next;
            (*L)->next = p;
            return OK;
        }
    p = GetElem(L,i-1);
    if (p == NULL)
        return ERROR;
    return InsertNextNode(p,e);
}



// 删除
Status ListDelete(LinkList *L, int i, elem * e)
{
    if (i < 1)
        return ERROR;
    if (i == 1)
    {
        if ((*L)->next == NULL)
            return ERROR;
        *e = (*L)->next->data;
        (*L)->next = (*L)->next->next;
        return OK;
    }
    LNode *p = GetElem(L,i-1);
    if (p == NULL || p->next == NULL)
        return ERROR;
    LNode * q = p->next;
    *e = q->data;
    p->next =q->next;
    //释放删除节点空间
    free(q);
    return OK;
}

// 删除指定节点
Status DeleteNode(LNode *p)
{
    if (p ==NULL)
        return ERROR;
    LNode *q = p->next;
    if (q == NULL)
        p == NULL;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

// 表长
int Length(LinkList L)
{
    int len =0;
    LNode *p = L;
    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
// 打印
void PrintList(LinkList L)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
    LNode *p = L->next;
    while(p != NULL)
    {
        printf("%5s %10d %15d %15d %20d\n",p->data.name,p->data.Math,p->data.English,p->data.Politics,p->data.Computer);
        p = p->next;
    }
    printf("\n");
}

// 打印单个数据元素
void PrintNode(LNode p)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
    printf("%5s %10d %15d %15d %20d\n",p.data.name,p.data.Math,p.data.English,p.data.Politics,p.data.Computer);
    printf("\n");
}

// 尾插法实现单链表
LinkList TailInsert(LinkList *L,int n)
{
    LNode *r = *L;
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        scanf("%s %d %d %d %d\n",p->data.name,&(p->data.Math),&(p->data.English),&(p->data.Politics),&(p->data.Computer));
        p->next = r->next;
        r->next = p;
        r = p;
    }
    return *L;

}

// 头插法实现单链表

LinkList HeadInsert(LinkList *L,int n)
{
    for (int i = 0; i < n; i++)
    {
        LNode *p = (LNode*)malloc(sizeof(LNode));
        scanf("%s %d %d %d %d\n",p->data.name,&(p->data.Math),&(p->data.English),&(p->data.Politics),&(p->data.Computer));
        p->next = (*L)->next;
        (*L)->next = p;
    }
    return *L;
}

// 反转单链表

void ListReverse(LinkList *L)
{
    LNode *p,*q;
    p = (*L)->next;
    (*L)->next = NULL;
    while(p != NULL)
    {
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
}