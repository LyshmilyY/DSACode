#include "SqList.h"

// 初始化
Status InitList(SqList * L)
{
    L->data = malloc(INITSIZE * sizeof(int));
    if (!L->data)
    {
        printf("内存不足, 分配失败!\n");
        return OVERFLOW;
    }
    L->length = 0;
    return OK;
}

// 增加表长
Status IncreaseSize(SqList * L, int len)
{
    int* p = L->data;
    L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
    if (!L->data)
    {
        printf("内存不足, 分配失败!\n");
        return OVERFLOW;
    }
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize += len;
    free(p);
    return OK;
}

// 插入
Status ListInsert(SqList * L, int i, int e)
{
    if (i < 1 || i > L->length + 1)
    {
        printf("插入位置不合法!\n");
        return ERROR;
    }
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
Status ListDelete(SqList * L, int i, int* e)
{
    if (i < 1 || i > L->length)
    {
        printf("删除位置不合法!\n");
        return ERROR;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return OK;
}

// 按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i]== e) 
            return i + 1;
    }
    printf("查找元素不存在!\n");
    return ERROR;
}

// 按位查找
Status GetElem(SqList L, int i, int* e)
{
    if (i < 1 || i > L.length)
    {
        printf("查找位置不合法!\n");
        return ERROR;
    }
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
    if (L.length == 0) 
        return OK;
    else 
        return ERROR;
}

// 打印
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        Printelem(L.data[i]);
    }
    printf("\n");
} 

void Printelem(int e)
{
    printf("%d ",e);
}