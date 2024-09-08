# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# define MAXSIZE 20
typedef struct Stack{
    char data[MAXSIZE];
    int top;
}Stack;

bool InitStack(Stack* S);
bool Push(Stack* S, char ch);
bool Pop(Stack* S, char* ch);
bool bracketmatch(char s[]);

// 初始化
bool InitStack(Stack* S)
{
    S->top = -1;
    return true;
}

// 压栈
bool Push(Stack* S, char ch)
{
    if (S->top == MAXSIZE -1)
        return false;
    S->top++;
    S->data[S->top] = ch;
    return true;
}

// 出栈
bool Pop(Stack* S, char* ch)
{
    if (S->top == -1)
        return false;
    
    *ch = S->data[S->top];
    S->top--;
    return true;
}
bool bracketmatch(char s[])
{
    Stack S;
    char ch;
    InitStack(&S);
    for (int i = 0; *(s+i) != '\0'; i++)
    {
        if (*(s+i) == '(' || *(s+i) == '[' || *(s+i) == '{')
        {    
            Push(&S, *(s+i));
        }
        else
        {
            if (Pop(&S, &ch))
            {
                if ((ch == '(' && *(s+i) != ')') || (ch == '[' && *(s+i) != ']') || (ch == '{' && *(s+i) != '}'))
                    return false;
            }
            else
            {
                return false;
            }

        }
    }
    if (S.top == -1)
        return true;
    else
        return false;

}


int main()
{
    // 测试样例个数
    int n;
    scanf("%d", &n);
    char s[n][MAXSIZE];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",s[i]);
        if (bracketmatch(s[i]))
            printf("第 %d 个测试样例括号匹配\n", i+1);
        else
            printf("第 %d 个测试样例括号不匹配\n", i+1);
    }
    return 0;
}
