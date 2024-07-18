#include "DlList.h"

// 初始化
Status InitList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof(DNode));
    if ((*L) == NULL)
        return ERROR;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return OK;
}

// 判空
Status Empty(DLinkList L)
{
    if (L->next == NULL)
        return OK;
    return ERROR;
}

// 按值查找
DNode * LocateElem(DLinkList L, elem e)
{
    DNode *p = L->next;
    while (p != NULL)
    {
        if (p->data.name == e.name)
            return p;
        p = p->next;
    }
    return p;

}

// 按位查找
DNode * GetElem(DLinkList *L, int i)
{
    DNode * p = (*L);
    int j = 0;
    while (p->next != NULL && j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 指定元素后插入
Status InsertNextNode(DNode *p,elem e)
{
    DNode *q = (DNode*)malloc(sizeof(DNode));
    if (q == NULL || p == NULL)
        return ERROR;
    q->data = e;
    p->next->prior = q;
    q->next = p->next;
    q->prior = p;
    p->next = q;
    return OK;
}

//指定元素前插入
Status InsertPreNode(DNode *p,elem e)
{
    DNode *q = (DNode*)malloc(sizeof(DNode));
    if (q == NULL || p ==NULL)
        return ERROR;
    q->data = e;
    p->prior->next = q;
    q->prior = p->prior;
    q->next = p;
    p->prior = q;
    return OK;
}

// 按位置插入
Status ListInsert(DLinkList *L, int i, elem e)
{
    if (i < 1)
        return ERROR;
    DNode *p = (DNode*)malloc(sizeof(DNode));
    if (p == NULL)
        return ERROR;
    if (i == 1)
    {
        p->data = e;
        p->next = (*L)->next;
        (*L)->next->prior = p;
        (*L)->next = p;
        p->prior = (*L);
        return OK;
    }
    p = GetElem(L,i-1);
    return InsertNextNode(p,e);

} 

// 删除
Status ListDelete(DLinkList *L, int i, elem * e)
{
    if (i < 1)
        return ERROR;
    DNode *p = (*L)->next;
    if (i == 1)
    {
        if (p == NULL)
            return ERROR;
        (*L)->next = p->next;
        *e = p->data;
        if (p->next != NULL)
            p->next->prior = (*L);
        free(p);
        return OK;
    }
    p = GetElem(L,i);
    if (p == NULL)
        return ERROR;
    *e = p->data;
    return DeleteNode(p);
}

// 删除指定节点
Status DeleteNode(DNode *p)
{
    if (p == NULL)
        return ERROR;
    DNode *q = p->next;
    DNode *s = p->prior;
    if (q == NULL && s == NULL)
        return ERROR;
    if (q == NULL)
        s->next =NULL;
    s->next = q;
    q->prior =s;
    free(p);
    return OK;
}

// 表长
int Length(DLinkList L)
{
    int len = 0;
    while (L->next != NULL)
    {
        len++;
        L = L->next;
    }
    return len;
}

// 打印链表
void PrintList(DLinkList L)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
    DNode *p = L->next;
    while(p != NULL)
    {
        printf("%5s %10d %15d %15d %20d\n",p->data.name,p->data.Math,p->data.English,p->data.Politics,p->data.Computer);
        p = p->next;
    }
    printf("\n");
}

// 打印节点
void PrintNode(DNode p)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
    printf("%5s %10d %15d %15d %20d\n",p.data.name,p.data.Math,p.data.English,p.data.Politics,p.data.Computer);
    printf("\n");
}

// 尾插法
DLinkList TailInsert(DLinkList *L,int n)
{
    for (int i = 0; i < n; i++)
    {
        DNode *r = *L;
        elem e;
        scanf("%s %d %d %d %d\n",e.name,&(e.Math),&(e.English),&(e.Politics),&(e.Computer));
        DNode *p = (DNode*)malloc(sizeof(DNode));
        if (p == NULL)
            return NULL;
        p->data = e;
        p->next = r->next;
        if (r->next != NULL)
            r->next->prior = p;
        r->next = p;
        p->prior = r;
        r = p; 
    }
    return *L;
}

// 头插法
DLinkList HeadInsert(DLinkList *L,int n)
{
    for (int i = 0; i < n; i++)
    {
        elem e;
        scanf("%s %d %d %d %d\n",e.name,&(e.Math),&(e.English),&(e.Politics),&(e.Computer));
        DNode *p = (DNode*)malloc(sizeof(DNode));
        if (p == NULL)
            return NULL;
        p->data = e;
        p->next = (*L)->next;
        p->prior = (*L);
        if ((*L)->next != NULL)
            (*L)->next->prior = p;
    }
    return *L;
}

//翻转链表
void ListReverse(DLinkList *L)
{
    DNode *p,*q;
    p = (*L)->next;
    (*L)->next = NULL;
    while(p != NULL)
    {
        q = p->next;
        p->next = (*L)->next;
        p->prior = (*L);
        if ((*L)->next != NULL)
            (*L)->next->prior = p;
        (*L)->next = p;
        p = q;
    }
}
