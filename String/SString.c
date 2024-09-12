#include "SString.h"

//初始化
void StrAssign(SString*T, char * chars)
{
    T->Length = 0;
    for(int i = 0; chars[i] != '\0'; i++)
    {
        T->ch[i] = chars[i];
        T->Length ++;
    }
}

//复制
void StrCopy(SString *T, SString S)
{
    for(int i = 0; i < S.Length; i++)
    {
        T->ch[i] = S.ch[i];
    }
    T->Length = S.Length;
}

//连接
bool Concat(SString *T, SString S1, SString S2)
{
    if (S1.Length + S2.Length > MAXSIZE)
    {
        printf("字符串长度过长, 连接失败!\n");
        return false;
    }
    for(int i = 0; i < S1.Length; i++)
    {
        T->ch[i] = S1.ch[i];
    }
    for(int j = 0; j < S2.Length; j++)
    {
        T->ch[S1.Length + j] = S2.ch[j];
    }
    T->Length = S1.Length + S2.Length;
    return true;
}

// 插入
bool StrInsert(SString* S, int pos, SString T)
{
    if (S->Length + T.Length > MAXSIZE)
    {
        printf("字符串长度过长, 插入失败!\n");
        return false;
    }
    for (int i = S->Length + T.Length -1; i >= pos + T.Length -1; i--)
    {   
        S->ch[i] = S->ch[i - T.Length];
    }
    for (int j = 0; j < T.Length; j++)
    {
        S->ch[j + pos -1] = T.ch[j];
    }
    return true;

}
// 删除
bool StrDelete(SString* S, int pos, int length)
{
    if (S->Length < pos + length -1)
    {
        printf("子串长度过长, 删除失败!\n");
        return false;
    }
    for (int i = pos - 1 + length; i <= S->Length - 1; i++)
    {
        S->ch[i - length] = S->ch[i];
    }
    S->Length -= length;
    return true;
}

//求子串
bool SubString(SString *Sub, SString S, int pos, int len)
{
    if (S.Length < pos + len - 1)
    {
        printf("子串位置不合法, 获取子串失败!\n");
        return false;
    }
    for(int i = 0; i < len; i++)
    {
        Sub->ch[i] = S.ch[pos + i - 1];
    }
    Sub->Length = len;
    return true;
}

//定位 (朴素匹配)
int Index(SString S, SString T)
{
    int i = 0, j = 0;
    while (i <= S.Length -1 && j <= T.Length - 1)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
		}
	}
    if (j == T.Length)
        return i - T.Length + 1;
    else
        return 0;
}



void Get_Next(SString T, int next[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T.Length)
    {
        if (j == -1 || T.ch[j] == T.ch[i])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void Get_NextVal(SString T, int nextval[])
{
    int i = 0, j = -1;
    nextval[0] = -1;
    while (i < T.Length)
    {
        if (j == -1 || T.ch[j] == T.ch[i])
        {
            i++;
            j++;
            if (T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}
int KMP(SString S, SString T, int next[])
{
    int i = 0, j = 0;
    while (i < S.Length && j < T.Length)
    {
        if (j == -1 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == T.Length)
        return i - T.Length + 1;
    else
        return 0;
}

// 辅助函数
//判空
bool StrEmpty(SString S)
{
    return (S.Length == 0);
}

//比较
bool StrCompare(SString S, SString T)
{
    if (S.Length != T.Length)
        return false;
    for(int i = 0; i < S.Length && i < T.Length; i++)
    {
        if(S.ch[i] != T.ch[i])
            return false;
    }
    return true;
    
}

//求串长
int StrLength(SString S)
{
    return S.Length;
}

//清空
void ClearString(SString *S)
{
    S->Length = 0;
}

// 打印

void Print(SString S)
{
    for (int i = 0; i < S.Length; i++)
    {
        printf("%c",S.ch[i]);
    }
    printf("\n");
}