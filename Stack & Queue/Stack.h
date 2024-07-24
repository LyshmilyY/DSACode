# include "../common.h"
# define MAXSIZE 10

// 顺序栈定义
typedef struct SqStack{
    int data[MAXSIZE];
    int top;
}SqStack;

// 链栈定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Stack;

// 共享栈定义

// 顺序栈函数声明

Status InitSqStack(SqStack *S); // 初始化栈
Status DestroySqStack(SqStack *S); // 销毁栈
Status SqEmpty(SqStack S); // 判空
Status SqPush(SqStack *S, int e); // 压栈
Status SqPop(SqStack *S, int *e); // 出栈
Status SqGetTop(SqStack S, int * e); // 获取栈顶元素
int SqLength(SqStack S); // 栈中元素个数
void PrintSqStack(SqStack S); // 打印栈中元素


// 链栈函数声明
Status InitStack(Stack *S); // 初始化栈
Status DestroyStack(Stack *S); // 销毁栈
Status Empty(Stack S); // 判空
Status Push(Stack *S, int e); // 压栈
Status Pop(Stack *S, int *e); // 出栈
Status GetTop(Stack S, int * e); // 获取栈顶元素
int Length(Stack S); // 栈中元素个数
void PrintStack(Stack S); // 打印栈中元素

// 共享栈函数声明