# include "./Stack.h"

int main()
{
    // 顺序栈 
    SqStack S;
    Stack LS;
    ShareStack SS;
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
    printf("\n");
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
    printf("\n");

    // 共享栈
    InitShareStack(&SS);
    for (int i = 1; i <= MAXSIZE; i++)
    {
        if (i%2 == 0)
        {
            ShareDPush(&SS,i);
        }
        else
        {   
            ShareTPush(&SS,i);
        }
    }
    printf("共享栈 SS.T 中的元素个数: %d\n", LengthT(SS));
    printf("共享栈 SS.T 中元素:");
    PrintTStack(SS);
    printf("共享栈 SS.D 中的元素个数: %d\n", LengthD(SS));
    printf("共享栈 SS.D 中元素:");
    PrintDStack(SS);
    ShareTPop(&SS,&e);
    printf("弹出共享栈 SS.T 中元素: %d\n",e);
    ShareDPop(&SS,&e);
    printf("弹出共享栈 SS.D 中元素: %d\n",e);
    return 0;
}