#include "DlList.h"

int main()
{
    DLinkList L;
    DNode p;
    elem student;
    InitList(&L);
    printf("尾插法建立双链表:\n");
    TailInsert(&L,5);
    PrintList(L);
    printf("反转双链表:\n");
    ListReverse(&L);
    PrintList(L);
    printf("删除第三个元素后的双链表:\n");
    ListDelete(&L,3,&student);
    PrintList(L);
    printf("被删除的元素:\n");
    p.data = student;
    PrintNode(p);
    printf("双链表第一个位置插入:\n");
    ListInsert(&L,1,student);
    PrintList(L);
    return 0;
}