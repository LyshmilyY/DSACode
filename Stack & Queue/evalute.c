# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAXSIZE 20

struct Stack{
    int data[MAXSIZE];
    int top;
};
typedef struct Stack Stack;

char opset[7] = {'+', '-', '*', '/', '(', ')', '#'};

// 运算符优先级 1 表示大于, -1 表示小于, 2 表示不可比较, 0 表示相等
int opcmp [7][7] = 
{
    { 1,  1, -1, -1, -1, 1, 1},
    { 1,  1, -1, -1, -1, 1, 1},
    { 1,  1,  1,  1, -1, 1, 1},
    { 1,  1,  1,  1, -1, 1, 1},
    {-1, -1, -1, -1, -1, 0, 2},
    { 1,  1,  1,  1,  2, 1, 1},
    {-1, -1, -1, -1, -1, 2, 0}
}; 

// 栈 函数
bool InitStack(Stack* S);
bool Push(Stack* S, int data);
bool Pop(Stack* S, int* data);
int GetTop(Stack S);

// a Operate b
int Operate(int opt, int a, int b);

int CharToInt(char ch);
// 前、中、后缀表达式求值
int PreValue();
int MidValue();
int SufValue();

// 初始化
bool InitStack(Stack* S)
{
    S->top = -1;
    return true;
}

// 压栈
bool Push(Stack* S, int data)
{
    if (S->top == MAXSIZE -1)
        return false;
    S->top++;
    S->data[S->top] = data;
    return true;
}

// 出栈
bool Pop(Stack* S, int* data)
{
    if (S->top == -1)
        return false;
    *data = S->data[S->top];
    S->top--;
    return true;
}

// 栈顶元素

int GetTop(Stack S)
{
    if (S.top == -1)
        return -100;
    return S.data[S.top];
}

int Operate(int opt, int a, int b)
{
    switch (opt)
    {
    case 0:
        return a+b;
    case 1:
        return a-b;
    case 2:
        return a*b;
    case 3:
        return a/b;
    default:
        return -100;
    }
} 
// char to int
int CharToInt(char ch)
{
    switch (ch)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '#':
        return 6;
    default:
        return -1;
    }
}
int MidValue()
{
    Stack Opt, Num;
    int opt,a,b;
    char ch;
    getchar();
    getchar();
    InitStack(&Opt);
    InitStack(&Num);
    Push(&Opt,6);
    ch = getchar();
    while (ch != '#'||GetTop(Opt) != 6)
    {
        if (CharToInt(ch) == -1)
        {
            Push(&Num,ch-'0');
            ch =getchar();
        }
        else
        {
            switch (opcmp[GetTop(Opt)][CharToInt(ch)])
            {
            case -1:
                Push(&Opt,CharToInt(ch));
                ch = getchar();
                break;
            case 1:
                Pop(&Opt,&opt);
                Pop(&Num,&b);
                Pop(&Num,&a);
                Push(&Num,Operate(opt,a,b));
                break;
            case 0:
                Pop(&Opt,&opt);
                ch = getchar();
                break;
            default:
                break;
            }
        }
        
    }
    return GetTop(Num);
}

int PreValue()
{
    Stack Num;
    char s[MAXSIZE];
    int a,b,len;
    char ch;
    len = 0;
    InitStack(&Num);
    getchar();
    getchar();
    while((ch = getchar()) != '#')
    {
        s[len] = ch;
        len++;
    }
    for (;len >= 0; len--)
    {
        if (CharToInt(s[len]) == -1)
        {
            Push(&Num,s[len] - '0');
        }
        else
        {
            Pop(&Num,&a);
            Pop(&Num,&b);
            Push(&Num,Operate(CharToInt(s[len]), a, b));
        }
    }
    return GetTop(Num);
}

int SufValue()
{
    Stack Num;
    int a,b;
    char ch;
    InitStack(&Num);
    getchar();
    getchar();
    while((ch = getchar()) != '#')
    {
        if (CharToInt(ch) == -1)
        {
            Push(&Num,ch - '0');
        }
        else
        {
            Pop(&Num,&b);
            Pop(&Num,&a);
            Push(&Num,Operate(CharToInt(ch), a, b));
        }
    }
    return GetTop(Num);
}

int main()
{
    int n,p,q;
    scanf("%d",&n);
    printf("中缀表达式: \n");
    for (int i =0; i < n; i++)
    {
        printf("第 %d 个表达式计算结果: %d\n",i+1,MidValue());
    }
    scanf("%d",&p);
    printf("后缀表达式: \n");
    for (int j =0; j < p; j++)
    {
        printf("第 %d 个表达式计算结果: %d\n",j+1,SufValue());
    }
    scanf("%d",&q);
    printf("前缀表达式: \n");
    for (int k =0; k < q; k++)
    {
        printf("第 %d 个表达式计算结果: %d\n",k+1,PreValue());
    }
    return 0;
}