# include "./Queue.h"

int main()
{
    SqQueue S;
    Queue LS;
    int e;
    // 顺序表实现 循环队列
    InitSqQueue(&S);
    for (int i = 2; i < 20; i = i+2)
    {
        EnSqQueue(&S,i);
    }
    printf("循环队列中元素个数: %d\n", LengthSqQueue(S));
    PrintSqQueue(S);
    for (int j = 0; j<6; j++)
    {
        DeSqQueue(&S,&e);
    }
    printf("循环队列中元素个数: %d\n", LengthSqQueue(S));
    PrintSqQueue(S);
    for (int j = 0; j<5; j++)
    {
        EnSqQueue(&S,j);
    }
    printf("循环队列中元素个数: %d\n", LengthSqQueue(S));
    PrintSqQueue(S);
    printf("\n");
    // 链表实现 队列
    InitQueue(&LS);
    for (int i = 2; i < 20; i = i+2)
    {
        EnQueue(&LS,i);
    }
    printf("链式队列中元素个数: %d\n", LengthQueue(LS));
    PrintQueue(LS);
    for (int j = 0; j<6; j++)
    {
        DeQueue(&LS,&e);
    }
    printf("链式队列中元素个数: %d\n", LengthQueue(LS));
    PrintQueue(LS);
    for (int j = 0; j<5; j++)
    {
        EnQueue(&LS,j);
    }
    printf("链式队列中元素个数: %d\n", LengthQueue(LS));
    PrintQueue(LS);
    return 0;
}