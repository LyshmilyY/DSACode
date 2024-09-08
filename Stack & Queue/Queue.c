# include "./Queue.h"

// 1. 循环队列
// 初始化队列

Status InitSqQueue(SqQueue *Q)
{
    if (Q == NULL)
        return ERROR;
    Q->font = 0;
    Q->rear = 0;
    return OK;
}

// 判空

Status EmptySqQueue(SqQueue *Q)
{
    if (Q->font == Q->rear)
        return OK;
    return ERROR;
} 

 //入队

Status EnSqQueue(SqQueue *Q, int e)
{
    if ((Q->rear+1)%MAXSIZE == Q->font)
    {
        printf("循环队列已满, 入队失败!\n");
        return ERROR;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return OK;
}

//出队

Status DeSqQueue(SqQueue *Q, int* e)
{
    if (EmptySqQueue(Q)){
        printf("循环队列已空, 出队失败!\n");
        return ERROR;
    }
    *e = Q->data[Q->font];
    Q->font = (Q->font+1)%MAXSIZE;
    return OK;
}

//获取队头元素

Status SqGetHead(SqQueue *Q, int* e)
{
    if (EmptySqQueue(Q))
    {
        printf("循环队列已空, 获取队头元素失败!\n");
        return ERROR;
    }
    *e = Q->data[Q->font];
    return OK;
}

//队列长队

int LengthSqQueue(SqQueue Q)
{
    return (Q.rear-Q.font+MAXSIZE)%MAXSIZE;
} 

// 打印队列
void PrintSqQueue(SqQueue Q)
{
    if (Q.font == Q.rear)
        return;
    for (int i = Q.font; i!=Q.rear; i=(i+1)%MAXSIZE)
    {
        printf("%d ",Q.data[i]);
    }
    printf("\n");
}

// 2. 链表实现队列 (不带头节点)

// 初始化队列

Status InitQueue(Queue *Q)
{
    (*Q).font = NULL;
    (*Q).rear = NULL;
    (*Q).size = 0;
    return OK;
}

// 判空

Status EmptyQueue(Queue *Q)
{
    if ((*Q).font == NULL)
        return OK;
    return ERROR;
}

//入队

Status EnQueue(Queue *Q, int e)
{
    LNode* p = (LNode*)malloc(sizeof(LNode));
    if (p == NULL)
    {
        printf("内存不足, 分配失败!\n");
        return OVERFLOW;
    }
    p->data = e;
    p->next = NULL;
    if ((*Q).font == NULL)
    {
        (*Q).font = p;
        (*Q).rear = p;
        (*Q).size++;
        return OK;
    }
    (*Q).rear->next = p;
    (*Q).rear = p;
    Q->size++;
    return OK;
}

// 出队
Status DeQueue(Queue *Q,int* e)
{
    if ((*Q).font == NULL)
    {
        printf("链表队列已空, 出队失败!\n");
        return ERROR;
    }
    *e = (*Q).font->data;
    LNode *p = (*Q).font;
    if (p->next == NULL)
    {
        (*Q).font = NULL;
        (*Q).rear = NULL;
        free(p);
    }
    (*Q).font = p->next;
    (*Q).size--;
    return OK;
}

//获取队头元素

Status GetHead(Queue Q, int* e)
{
    if (Q.font == NULL)
    {
        printf("链表队列已空, 获取队头元素失败!\n");
        return ERROR;
    }
    *e = Q.font->data;
    return OK;
}

//队列长队

int LengthQueue(Queue Q)
{
    return Q.size;
}

// 打印队列

void PrintQueue(Queue Q)
{
    LNode *p = Q.font;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}