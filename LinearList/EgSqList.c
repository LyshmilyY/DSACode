#include "SqList.h"

int main()
{
    SqList L;
    elem student;
    InitList(&L);
    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d %d %d %d",student.name, &(student.Math), &(student.English),&(student.Politics),&(student.Computer));
        ListInsert(&L,i+1,student);
    }
    printf("初始顺序表:\n");
    PrintList(L);
    strcpy(student.name,"LY");
    student.Math = 150;
    student.English = 85;
    student.Politics = 75;
    student.Computer = 145;
    ListInsert(&L,2,student);
    printf("在第二个位置插入新元素:\n");
    PrintList(L);
    ListDelete(&L,3,&student);
    printf("删除第三个元素:\n");
    Printelem(student);
    printf("删除后的顺序表:\n");
    PrintList(L);
    return 0;
}