#include "SqList.h"

// 初始化
Status InitList(SqList * L)
{
    L->data = malloc(INITSIZE * sizeof(elem));
    if (!L->data) exit(OVERFLOW);
    L->length = 0;
    return OK;
}

// 增加表长
Status IncreaseSize(SqList * L, int len)
{
    elem *p = L->data;
    L->data = (elem *)malloc((L->MaxSize + len) * sizeof(elem));
    if (!L->data) exit(OVERFLOW);
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize += len;
    free(p);
    return OK;
}

// 插入
Status ListInsert(SqList * L, int i, elem e)
{
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= L->MaxSize) IncreaseSize(L, INITSIZE);
    for (int j = L->length - 1; j >= i-1; j--)
    {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

// 删除
Status ListDelete(SqList * L, int i, elem * e)
{
    if (i < 1 || i > L->length) return ERROR;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return OK;
}

// 按值查找
int LocateElem(SqList L, elem e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i].name == e.name) 
            return i + 1;
    }
    return ERROR;
}

// 按位查找
Status GetElem(SqList L, int i, elem * e)
{
    if (i < 1 || i > L.length) return ERROR;
    *e = L.data[i - 1];
    return OK;
}

// 表长
int Length(SqList L)
{
    return L.length;
}

// 判空
Status Empty(SqList L)
{
    if (L.length == 0) return OK;
    else return ERROR;
}

// 打印
void PrintList(SqList L)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
    for (int i = 0; i < L.length; i++)
    {
        printf("%5s %10d %15d %15d %20d\n",L.data[i].name,L.data[i].Math,L.data[i].English,L.data[i].Politics,L.data[i].Computer);
    }
    printf("\n");
} 

void Printelem(elem e)
{
    printf("%5s %15s %15s %15s %20s\n","Name", "Score:Math", "Score:English", "Score:Politics", "Score:Computer");
printf("%5s %10d %15d %15d %20d\n",e.name,e.Math,e.English,e.Politics,e.Computer);
printf("\n");
}