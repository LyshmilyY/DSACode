# include "../common.h"
# define MAXSIZE 10
# define SHARESIZE 20

// 顺序栈定义
typedef struct SqStack{
    int data[MAXSIZE];
    int top;
}SqStack;

// 链栈定义
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;
typedef LNode* Stack;

// 共享栈定义
typedef struct ShareStack{
    int data[SHARESIZE];
    int Ttop;
    int Dtop;
}ShareStack;

// 顺序栈函数声明
Status InitSqStack(SqStack *S); // 初始化栈
Status SqEmpty(SqStack S); // 判空
Status SqPush(SqStack *S, int e); // 压栈
Status SqPop(SqStack *S, int *e); // 出栈
Status SqGetTop(SqStack S, int * e); // 获取栈顶元素
int SqLength(SqStack S); // 栈中元素个数
void PrintSqStack(SqStack S); // 打印栈中元素

// 链栈函数声明
Status InitStack(Stack *S); // 初始化栈
Status Empty(Stack S); // 判空
Status Push(Stack *S, int e); // 压栈
Status Pop(Stack *S, int *e); // 出栈
Status GetTop(Stack S, int * e); // 获取栈顶元素
int Length(Stack S); // 栈中元素个数
void PrintStack(Stack S); // 打印栈中元素

// 共享栈函数声明
Status InitShareStack(ShareStack *S); // 初始化共享栈
Status DestroyShareStack(ShareStack *S); // 销毁栈
Status ShareEmpty(ShareStack S); // 判空
Status ShareTPush(ShareStack *S, int e); // T 栈压栈
Status ShareTPop(ShareStack *S, int *e); // T 栈出栈
Status ShareDPush(ShareStack *S, int e); // D 栈压栈
Status ShareDPop(ShareStack *S, int *e); // D 栈出栈
Status ShareTGetTop(ShareStack S, int * e); // 获取 T 栈顶元素
Status ShareDGetTop(ShareStack S, int * e); // 获取 D 栈顶元素
int LengthT(ShareStack S); // 栈中元素个数
int LengthD(ShareStack S); // 栈中元素个数
void PrintTStack(ShareStack S); // 打印 T 栈中元素
void PrintDStack(ShareStack S); // 打印 D 栈中元素