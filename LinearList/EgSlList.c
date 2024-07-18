#include "SlList.h"

int main()
{
    LinkList L;
    LNode p;
    elem student;
    InitList(&L);
    printf("尾插法建立单链表:\n");
    TailInsert(&L,5);
    PrintList(L);
    printf("反转单链表:\n");
    ListReverse(&L);
    PrintList(L);
    printf("删除第三个元素后的单链表:\n");
    ListDelete(&L,3,&student);
    PrintList(L);
    printf("被删除的元素:\n");
    p.data = student;
    PrintNode(p);
    printf("单链表第一个位置插入:\n");
    ListInsert(&L,1,student);
    PrintList(L);
    return 0;
}