# include "../common.h"
# define MAXSIZE 10

// 循环队列定义
typedef struct{
    int data[MAXSIZE];
    int font,rear;
}SqQueue;

// 链表队列定义
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;
typedef struct Queue{
    int size;
    LNode *font, *rear;
}Queue;


// 循环队列函数声明
Status InitSqQueue(SqQueue *Q); // 初始化队列
Status DestroySqQueue(SqQueue *Q); // 销毁队列
Status EmptySqQueue(SqQueue *Q); // 判空
Status EnSqQueue(SqQueue *Q, int e); //入队
Status DeSqQueue(SqQueue *Q, int* e); //出队
Status SqGetHead(SqQueue *Q, int* e); //获取队头元素

int LengthSqQueue(SqQueue Q); //队列长队

Status PrintSqQueue(SqQueue Q); // 打印队列

// 链表队列函数声明

Status InitQueue(Queue *Q); // 初始化队列
Status DestroyQueue(Queue *Q); // 销毁队列
Status EmptyQueue(Queue *Q); // 判空
Status EnQueue(Queue *Q, int e); //入队
Status DeQueue(Queue *Q, int* e); //出队
Status GetHead(Queue Q,int* e); //获取队头元素

int LengthQueue(Queue Q); //队列长队

void PrintQueue(Queue Q); // 打印队列


