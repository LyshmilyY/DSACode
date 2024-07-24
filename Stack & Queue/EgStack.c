# include "./Stack.h"

int main()
{
    // 顺序栈 
    SqStack S;
    Stack LS;
    int e;
    InitSqStack(&S);
    SqPush(&S,2);
    SqPush(&S,4);
    SqPush(&S,6);
    SqPush(&S,9);
    SqPush(&S,10);
    printf("顺序栈 S 中的元素个数: %d\n", SqLength(S));
    printf("顺序栈 S 中的元素:");
    PrintSqStack(S);
    SqGetTop(S,&e);
    printf("顺序栈 S 栈顶元素: %d\n", e);
    
    // 链栈
    InitStack(&LS);
    Push(&LS,1);
    Push(&LS,2);
    Push(&LS,3);
    Push(&LS,4);
    Push(&LS,5);
    printf("链栈 LS 中的元素个数: %d\n", Length(LS));
    printf("链栈 LS 中的元素:");
    PrintStack(LS);
    GetTop(LS,&e);
    printf("链栈 LS 栈顶元素: %d\n", e);
    return 0;
}