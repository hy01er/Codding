// 2. 链表的初始化  增加  删除 查询 打印全部 删除链表

#include "stdlib.h"
#include "stdio.h"

#define DEFAULT_ID 999
#define INIT_NODE_NUM 0
#define SUCCESS 1
#define FAIL 0

// 链表定义
typedef struct Node {
    int id; // 保留，未使用，默认为999
    int score; // 头结点存储链表的节点数目，初始化为0
    struct Node *next; // init is null, 用于基本操作中默认尾结点是空
} LinkListNode, *PointNode;

PointNode LinkListInit()
{
    PointNode pHead = NULL;
    pHead = (LinkListNode *)malloc(sizeof(LinkListNode));
    if (pHead == NULL) {
        printf("ERROR malloc head node null!!\n");
        return NULL;
    }
    pHead->id = DEFAULT_ID;
    pHead->score = INIT_NODE_NUM;
    pHead->next = NULL;
    return pHead;
}

int GetLinkListNodeNum(PointNode root)
{
    if (root == NULL) {
        printf("ERROR\n");
        return FAIL;
    }
    return root->score;
}

// 尾插法
int LinkListAddNode(PointNode root, LinkListNode nodeData)
{
    if (root == NULL) {
        return FAIL;
    }
    PointNode newNode = (PointNode)malloc(sizeof(LinkListNode));
    if (newNode == NULL) {
        printf("malloc fail");
        return 0;
    }
    newNode->id = nodeData.id;
    newNode->score = nodeData.score;
    newNode->next = NULL;
    PointNode p = root;
    while(p->next) {
        p = p->next;
    }
    p->next = newNode;
    nodeData.next = NULL;
    root->score++; // store linklist node data num
    return SUCCESS;
}

int LinkListDelNode(PointNode root, int id)
{
    if (root == NULL) {
        return FAIL;
    }
    PointNode p, f;
    f = root; // point front node
    p = root->next; // point current node
    while(p) {
        if (p->id == id) {
            f->next = p->next;
            root->score--;
            free(p);
            return SUCCESS;
        }
        f = p;
        p = p->next;
    }
    return SUCCESS;
}

PointNode LinkListFindNode(PointNode root, int id)
{
    if (root == NULL) {
        return NULL;
    }
    PointNode p = root->next;
    while(p) {
        if (p->id == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int LinkListPrintAllData(PointNode root)
{
    if (root == NULL) {
        return FAIL;
    }
    int nums = 0;
    PointNode p = root->next;
    printf("node nums:%d\n", root->score);
    while(p) {
        printf("index:%4d, id:%4d, score:%4d\n",++nums, p->id, p->score);
        p = p->next;
    }
    return SUCCESS;
}

int LinkListMakeEmpty(PointNode root) // keep head node
{
    if (root == NULL) {
        return FAIL;
    }
    if (root->next == NULL) {
        return SUCCESS; // 如果已经是空链表，那么任务已经完成
    }
    PointNode p1 = root->next;
    PointNode p2 = p1->next;
    while(p1) {
        free(p1);
        p1 = p2;
        if (p2 != NULL) { // 防止对NULL指针解引用
           p2 = p2->next;
        }
    }
    return SUCCESS;
}

int main()
{
    PointNode root = LinkListInit();
    printf("root id:%d, init node nums:%d\n\n", root->id, root->score);
    LinkListNode data;
    int result = 0;
    data.id = 1;
    data.score = 90;
    data.next = NULL;
    result |= LinkListAddNode(root, data);
    data.id = 2;
    data.score = 85;
    result |= LinkListAddNode(root, data);
    data.id = 3;
    data.score = 88;
    result |= LinkListAddNode(root, data);
    data.id = 4;
    data.score = 81;
    result |= LinkListAddNode(root, data);
    LinkListPrintAllData(root);

    // delete node which its id = 2
    printf("\n\ndelete id = 2\n");
    result |= LinkListDelNode(root, 2);
    LinkListPrintAllData(root);

    printf("\nlist中是否含有id为3的元素？");
    printf(LinkListFindNode(root, 3) != NULL ? " YES" : " NO");
    putchar('\n');

    // delete node which its id = 4
    printf("\n\ndelete id = 4\n");
    result |= LinkListDelNode(root, 4);
    LinkListPrintAllData(root);
    LinkListMakeEmpty(root);
    free(root);
    return 0;
}
