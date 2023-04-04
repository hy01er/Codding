/* 4.队列
 *
 * 队列是非常重要的数据结构，生活中也有队列，数据结构中的队列和生活中的类似，用途非常广泛，你可能听说过
 * 消息队列，优先级队列，任务队列等等，用途非常广泛，非常非常非常重要！也是一种限制性线性表，和生活中排队
 * 一样，存在队头和对尾，队尾进，队头出，存在特性“先进先出”，非常重要的数据结构,而且队列要比栈复杂很多
 */

// 4-2 实现数组形式的队列，更加常见

#include "stdio.h"
#include "stdlib.h"

struct QueueRecord;
typedef struct QueueRecord *Queue;

#define ARR_LENGTH (5)
#define ERROR_MSG  (-99999)
#define FULL_QUEUE (1)
#define NOT_FULL_QUEUE (0)
int arrayData[ARR_LENGTH] = {0};

struct QueueRecord {
    int capacity;
    int front;
    int rear;
    int size;
    int *arrayData;
};

// interface definition
int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int maxElememt);
void makeEmpty(Queue q);
void EnQueue(Queue q);
int Front(Queue q);
void DeQueue(Queue q);
int FrontAndDequeue(Queue q);

// interface realization
Queue CreateQueue(int *array, int arrayMaxSize)
{
    if (array == NULL) {
        return NULL;
    }
    Queue q = (Queue)malloc(sizeof(struct QueueRecord));
    if (q == NULL) {
        printf("not enough space");
        return NULL;
    }
    q->arrayData = array;
    q->capacity = ARR_LENGTH;
    q->front = 1;
    q->rear = 0;
    q->size = 0;
    return q;
}

int IsEmpty(Queue q)
{
    return q->size == 0;
}

int IsFull(Queue q)
{
    if(q->size == q->capacity) {
        return FULL_QUEUE;
    }
    return NOT_FULL_QUEUE;
}

void EnQueue(Queue q, int data)
{
    if (IsFull(q)) {
        printf("Full queue\n");
        return;
    }
    q->size++;
    q->rear = (q->rear + 1) % q->capacity;
    q->arrayData[q->rear] = data;
    return;
}

void DeQueue(Queue q)
{
    if (IsEmpty(q)) {
        printf("empty queue!!");
        return;
    }
    q->size--;
    q->front = (q->front + 1) % q->capacity;
    return;
}

int Front(Queue q)
{
    if (IsEmpty(q)) {
        printf("empty queue!!");
        return ERROR_MSG;
    }
    return q->arrayData[q->front];
}

void MakeEmpty(Queue q)
{
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}

int FrontAndQueue(Queue q)
{
    int front = Front(q);
    DeQueue(q);
    return front;
}

void PrintQueue(Queue q)
{
    printf("---------\n");
    if (q == NULL || IsEmpty(q)) {
        return;
    }
    int temp = q->front;
    for (int i = 0; i < q->size; i++) {
        temp = (q->front + i) % q->capacity;
        if (temp == q->front) {
            printf("[");
        }
        printf("%4d\t", q->arrayData[temp]);
        if (temp == q->rear) {
            printf("]");
        }
    }
    putchar('\n');
    for (int i = 0; i < ARR_LENGTH; i++) {
        printf("%4d\t", arrayData[i]);
    }
    putchar('\n');
    printf("---------\n");
}

int main()
{
    Queue q = CreateQueue(arrayData, ARR_LENGTH);
    EnQueue(q, 63);
    EnQueue(q, 61);
    EnQueue(q, 52);
    EnQueue(q, 88);
    EnQueue(q, 0);
    PrintQueue(q);
    DeQueue(q);
    printf("DeQueue a node\n");
    PrintQueue(q);
    DeQueue(q);
    DeQueue(q);
    printf("DeQueue two node\n");
    EnQueue(q, 44);
    PrintQueue(q);
    EnQueue(q, 61);
    EnQueue(q, 52);
    EnQueue(q, 88);
    EnQueue(q, 0);
    PrintQueue(q);
    free(q);
    return 0;
}
