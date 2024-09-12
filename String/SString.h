#include "../common.h"
#define MAXSIZE 255

// 顺序串
typedef struct SString{
    char ch[MAXSIZE];
    int Length;
}SString;

// 函数声明

void StrAssign(SString* T, char* chars); // 初始化

void StrCopy(SString* T, SString S); // 复制
bool Concat(SString* T, SString S1, SString S2); // 链接
bool StrInsert(SString* S, int pos, SString T); // 插入
bool StrDelete(SString* S, int pos, int length); // 删除
// 模式串匹配
bool SubString(SString* Sub, SString S, int pos, int length); // 求子串
int Index(SString S, SString T); // 子串位置
void Get_Next(SString T, int next[]); 
int KMP(SString S, SString T, int next[]); // KMP算法
void Get_NextVal(SString T, int nextval[]); // next 数组优化
// 辅助函数
bool StrEmpty(SString S); // 判空
bool StrCompare(SString S, SString T); // 比较
int StrLength(SString S); // 长度
void ClearString(SString* S); // 清空
void Print(SString S); // 打印