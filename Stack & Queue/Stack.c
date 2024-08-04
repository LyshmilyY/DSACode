# include "./Stack.h"

// 1. 顺序栈实现
// 初始化
Status InitSqStack(SqStack *S)
{
    if (S == NULL)
        return ERROR;
    S->top = -1;
    return OK;
}

// 判空
Status SqEmpty(SqStack S)
{
    if (S.top == -1)
        return OK;
    return ERROR;
}

// 压栈
Status SqPush(SqStack *S, int e)
{
    
    if (S->top == MAXSIZE -1)
        return ERROR;
    S->top ++;
    S->data[S->top] = e;
    return OK;
}

// 出栈
Status SqPop(SqStack *S, int *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top --;
    return OK;
}

// 获取栈顶元素
Status SqGetTop(SqStack S, int *e)
{
    if (S.top == -1)
        return ERROR;
    *e = S.data[S.top];
    return OK; 
}

// 栈中元素个数
int SqLength(SqStack S)
{
    return S.top + 1;
}

// 打印栈中元素
void PrintSqStack(SqStack S)
{
    for (int i = S.top; i>=0; i--)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
}

// 2. 链栈实现 (不带头节点)

// 初始化栈
Status InitStack(Stack *S)
{
    (*S) = NULL;
    return OK;
}

// 判空
Status Empty(Stack S)
{
    if (S == NULL)
        return OK;
    return ERROR;
}

// 压栈
Status Push(Stack *S, int e)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    if (p == NULL)
        return ERROR;
    p->data = e;
    if ((*S) == NULL)
    {
        p->next = NULL;
        (*S) = p;
        return OK;
    }
    p->next = (*S);
    (*S) = p;
    return OK;
}

// 出栈
Status Pop(Stack *S, int *e)
{
    if ((*S) == NULL)
        return ERROR;
    *e = (*S)->data;
    (*S) = (*S)->next;
    return OK;
}

// 获取栈顶元素
Status GetTop(Stack S, int * e)
{
    if (S == NULL)
        return ERROR;
    *e = S->data;
    return OK;
}

// 栈中元素个数
int Length(Stack S)
{
    int len = 0;
    while(S != NULL)
    {
        len++;
        S = S->next;
    }
    return len;
}

// 打印栈中元素
void PrintStack(Stack S)
{
    while(S != NULL)
    {
        printf("%d ",S->data);
        S = S->next;
    }
    printf("\n");
}

// 3. 共享栈实现
// 初始化
Status InitShareStack(ShareStack *S)
{
    if (S == NULL)
        return ERROR;
    S->Ttop = -1;
    S->Dtop = SHARESIZE;
    return OK;
}

// 判空
Status ShareEmpty(ShareStack S)
{
    if (S.Ttop == -1 && S.Dtop == SHARESIZE)
        return OK;
    return ERROR;
}

// T 压栈
Status ShareTPush(ShareStack *S, int e)
{
    
    if (S->Ttop + 1 >= S->Dtop)
        return ERROR;
    S->Ttop ++;
    S->data[S->Ttop] = e;
    return OK;
}

// D 压栈
Status ShareDPush(ShareStack *S, int e)
{
    
    if (S->Ttop + 1 >= S->Dtop)
        return ERROR;
    S->Dtop --;
    S->data[S->Dtop] = e;
    return OK;
}

// T 出栈
Status ShareTPop(ShareStack *S, int *e)
{
    if (S->Ttop == -1)
        return ERROR;
    *e = S->data[S->Ttop];
    S->Ttop --;
    return OK;
}

// D 出栈
Status ShareDPop(ShareStack *S, int *e)
{
    if (S->Dtop == SHARESIZE)
        return ERROR;
    *e = S->data[S->Dtop];
    S->Dtop ++;
    return OK;
}

// 获取 T 栈顶元素
Status ShareTGetTop(ShareStack S, int *e)
{
    if (S.Ttop == -1)
        return ERROR;
    *e = S.data[S.Ttop];
    return OK; 
}

// 获取 D 栈顶元素
Status ShareDGetTop(ShareStack S, int *e)
{
    if (S.Dtop == SHARESIZE)
        return ERROR;
    *e = S.data[S.Dtop];
    return OK; 
}

// T 栈中元素个数
int LengthT(ShareStack S)
{
    return S.Ttop + 1;
}

// D 栈中元素个数
int LengthD(ShareStack S)
{
    return SHARESIZE - S.Dtop;
}

// 打印 T 栈中元素
void PrintTStack(ShareStack S)
{
    for (int i = S.Ttop; i>=0; i--)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
}

// 打印 D 栈中元素
void PrintDStack(ShareStack S)
{
    for (int i = S.Dtop; i<=SHARESIZE-1; i++)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
}
