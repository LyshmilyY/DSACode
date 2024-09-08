#include "SqList.h"

int main()
{
    SqList L;
    int e;
    InitList(&L);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d ", &e);
        ListInsert(&L, i+1, e);
    }
    printf("初始顺序表:\n");
    PrintList(L);
    ListInsert(&L, 2, e);
    printf("在第二个位置插入新元素:\n");
    PrintList(L);
    ListDelete(&L, 3, &e);
    printf("删除第三个元素:\n");
    Printelem(e);
    printf("\n");
    printf("删除后的顺序表:\n");
    PrintList(L);
    printf("\n");
    return 0;
}