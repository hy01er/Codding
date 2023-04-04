/* 3.栈
 *
 * 栈是非常重要的数据结构，在操作系统中栈作为局部变量的一种存储形式，有很多很重要的应用，比如递归中函数调用的保存。
 * 需要记住，它被称为 限制性线性表，特性是只在一头操作，进出都只能在一头，操作特性是“先进后出”或者说“后进先出”，又被
 * 称为LIFO表（即last in first out），它和队列一样是非常常用和重要的数据结构。
 *
 * 栈（stack）是限制删除和插入只能在一个位置上的表，该位置是表的末端，叫做栈的顶（top）。对栈的基本操作有：Push（入栈）
 * 和Pop（出栈），前者相当于插入，后者则是删除最后插入的元素。对空栈执行Pop一般可以认为错误，Push时空间用尽时一种实现上的
 * 错误，但不是ADT的错误
 */

#include "stdio.h"
#include "stdlib.h"

#define WAIN_MSG 99999

struct Node;
typedef struct Node *PtrToNode; // Pointer to Node
typedef PtrToNode Stack;

struct Node {
    int data;
    PtrToNode next;
};

Stack CreateStack(void)
{
    Stack s;
    s = (Stack)malloc(sizeof(struct Node));
    if (s == NULL) {
        printf("out of space\n");
        return NULL;
    }
    s->data = 0; // init 0,保留
    s->next = NULL;
    return s;
}

int IsEmpty(Stack s)
{
    if (s == NULL) {
        printf("please create stack first.");
        return WAIN_MSG;
    }
    return s->next == NULL;
}

void Push(Stack s, int x)
{
    if (s == NULL) {
        printf("please create stack first.");
        return;
    }
    PtrToNode p;
    p = (PtrToNode)malloc(sizeof(struct Node));
    if (p == NULL) {
        printf("out of space\n");
        return;
    }
    p->data = x;
    p->next = s->next;
    s->next = p;
    return;
}

int Top(Stack s)
{
    if (s == NULL) {
        printf("please create stack first.");
        return WAIN_MSG;
    }
    if (IsEmpty(s)) {
        return WAIN_MSG;
    }
    return s->next->data;
}

void Pop(Stack s)
{
    if (s == NULL) {
        printf("please create stack first.");
        return;
    }
    if (IsEmpty(s)) {
        return;
    }
    PtrToNode p = s->next;
    s->next = p->next;
    free(p);
    return;
}

void MakeEmpty(Stack s)
{
    if (s == NULL) {
        printf("please create stack first.");
        return;
    }
    while(!IsEmpty(s)) {
        Pop(s);
    }
    return;
}



int main()
{
    Stack s = CreateStack();
    if (s == NULL) {
        printf("out of space!");
        return 0;
    }
    Push(s, 56);
    Push(s, 8);
    Push(s, 6);
    Push(s, 2);
    Push(s, 3);
    printf("top:%d\n", Top(s));
    Pop(s);
    printf("Pop,top:%d\n", Top(s));
    Pop(s);
    printf("Pop,top:%d\n", Top(s));
    Pop(s);
    printf("Pop,top:%d\n", Top(s));

    MakeEmpty(s);
    printf(Top(s) == WAIN_MSG ? "empty stack" : "not empty stack");
    free(s);
    return 0;
}
