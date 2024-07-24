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

// 2. 链栈实现

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


