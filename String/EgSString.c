#include "SString.h"

int main()
{
    SString S,T;
    StrAssign(&S, "abaabaabcabaabc");
    StrAssign(&T, "abaabc");
    // 朴素模式匹配
    printf("%d\n", Index(S,T));
    // KMP
    int next[T.Length];
    Get_Next(T,next);
    printf("%d\n",KMP(S, T, next));
    return 0;
}