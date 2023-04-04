/* 4.队列
 *
 * 队列是非常重要的数据结构，生活中也有队列，数据结构中的队列和生活中的类似，用途非常广泛，你可能听说过
 * 消息队列，优先级队列，任务队列等等，用途非常广泛，非常非常非常重要！也是一种限制性线性表，和生活中排队
 * 一样，存在队头和对尾，队尾进，队头出，存在特性“先进先出”，非常重要的数据结构,而且队列要比栈复杂很多
 */

// 4-1以下为队列的链表实现形式，实际中数组形式的队列可能更加常见，见4-2实现

#include"stdio.h"
#include "stdlib.h"

#define WARN_MSG 9999999
#define NULL_QUEUE 0
#define NOT_NULL_QUEUE 1

struct NodeType;
typedef struct NodeType Node;
typedef struct NodeType *PtrToNode;

typedef struct NodeType {
    int data;
    PtrToNode next;
};

typedef struct QueueType {
    PtrToNode ptrFront; // 队首指针
    PtrToNode ptrRear; // 队尾指针
} *Queue; // 队列的定义

// 基本操作的定义
Queue CreateQueue(void); // 队列的链表实现中这里不传参数
int IsEmpty(Queue q);
int IsFull(Queue q); // 这个接口在队列的链表形式下不实现，因为它取决于是否还能申请到空间
void MakeEmpty(Queue q);
void EnQueue(Queue q, int data);
int Front(Queue q); // 获取队首元素
void DeQueue(Queue q);
int FrontAndDeQueue(Queue q); // 出队并返回出队的元素值

// 以下为接口实现
Queue CreateQueue()
{
    Queue q = (Queue)malloc(sizeof(struct QueueType));
    if (q == NULL) {
        printf("malloc out of space\n");
        return NULL;
    }
    q->ptrFront = NULL;
    q->ptrRear = NULL;
    q->ptrFront = (PtrToNode)malloc(sizeof(Node));
    if (q->ptrFront == NULL) {
        printf("malloc out of space\n");
        return NULL;
    }
    q->ptrFront->data = 0; // 用于保存size
    q->ptrFront->next = NULL;
    q->ptrRear = q->ptrFront;
    return q;
}

int GetSize(Queue q) // 获取当前队列中有多少个元素
{
    if (q == NULL) {
        return WARN_MSG;
    }
    // 对于链表形式，且头结点是初始化中分配的，此时q->ptrFront == q->ptrRear在队列有元素的情况下不成立
    if (q->ptrFront == NULL || q->ptrFront->next == NULL || q->ptrFront == q->ptrRear) {
        return 0;
    }
    return q->ptrFront->data;
}

int IsEmpty(Queue q)
{
    //printf("IsEmpty\n");
    int nodeSize = GetSize(q);
    if (nodeSize == WARN_MSG || nodeSize == 0 || nodeSize < 0) {
        //printf("%d %d %d\n", nodeSize == WARN_MSG, nodeSize == 0, nodeSize < 0);
        return NULL_QUEUE;
    }
    return NOT_NULL_QUEUE;
}

int IsFull(Queue q)
{
    return WARN_MSG; // 队列的链表形式不实现这个接口
}

void EnQueue(Queue q, int data)
{
    if (q == NULL) {
        return;
    }
    PtrToNode p = (PtrToNode)malloc(sizeof(Node));
    if (p == NULL) {
        printf("out of space\n");
        return;
    }
    p->data = data;
    p->next = NULL;
    q->ptrRear->next = p;
    q->ptrRear = q->ptrRear->next;
    q->ptrFront->data++;
    return;
}

int Front(Queue q)
{
    if (IsEmpty(q) == NULL_QUEUE) {
        return WARN_MSG;
    }
    return q->ptrFront->next->data;
}

void DeQueue(Queue q)
{
    if (q == NULL) {
        return;
    }
    if (IsEmpty(q) == NULL_QUEUE) {
        return;
    }
    PtrToNode p = q->ptrFront->next;
    q->ptrFront->next = p->next; // 前面判断要保证q->ptrFront->next不是空，否则容易出现空指针解引用
    q->ptrFront->data--;
    free(p);
    return;
}

int FrontAndDeQueue(Queue q)
{
    int frontData = Front(q);
    DeQueue(q);
    return frontData;
}

void MakeEmpty(Queue q)
{
    if (q == NULL) {
        return;
    }
    // 借助出队让队列空
    while(IsEmpty(q) != NULL_QUEUE) {
        DeQueue(q);
    }
}

void QueueFree(Queue q)
{
    if (q == NULL) {
        return;
    }
    MakeEmpty(q);
    free(q->ptrFront);
    free(q);
    return;
}

void printNode(Queue q)
{
    if (IsEmpty(q) == NULL_QUEUE) {
        return;
    }
    PtrToNode p = q->ptrFront->next;
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    putchar('\n');
    return;
}

int main()
{
    Queue q = CreateQueue();
    printf("q.size = %d\n", GetSize(q));
    EnQueue(q, 5);
    EnQueue(q, 8);
    EnQueue(q, 2);
    EnQueue(q, 4);
    EnQueue(q, 6);
    printf("front = %d, q.size = %d\n", Front(q), GetSize(q));
    printNode(q);
    DeQueue(q);
    printf("DeQueue,front is %d,q.size = %d\n", Front(q), GetSize(q));
    int deQueueData = FrontAndDeQueue(q);
    printf("DeQueue is %d,q.size = %d\n", deQueueData, GetSize(q));
    deQueueData = FrontAndDeQueue(q);
    printf("DeQueue is %d,q.size = %d\n", deQueueData, GetSize(q));
    printNode(q);
    MakeEmpty(q);
    QueueFree(q);
    return 0;
}

