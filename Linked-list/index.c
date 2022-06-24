/**
 * 单链表
 */
#include <stdio.h>
#include <stdlib.h>

#define Size 5

/**
 * 定义链表节点
 * 每个节点都是LinkNode结构体
 * 指针指向的后继元素也是结点结构体
 * 故指针的类型为struct LinkNode
 */
typedef struct LinkNode {
    // 数据域
    int data;
    // 指针域
    struct LinkNode * next;
}LinkNode;

/**
 * 尾插法
 * 新增结点插到链表尾部
 */
LinkNode * initByRear() {
    // 创建头结点
    LinkNode * head = (LinkNode*)malloc(sizeof(LinkNode));
    // 头结点指针域
    head->next = NULL;
    // 尾指针 始终指向尾结点
    LinkNode * rear;
    // 初始指向头结点
    rear = head;
    if (head == NULL) {
        printf("申请空间失败");
        exit(0);
    }
    // 创建链表
    for (int i = 1; i < Size; i++) {
        LinkNode * item = (LinkNode*)malloc(sizeof(LinkNode));
        item->data = i;
        rear->next = item;
        // 尾指针指向当前结点
        rear = item;
    }
    return head;
}
/**
 * 头插法
 * 新增结点插到链表头部
 */
LinkNode * initByHead() {
    // 头结点
    LinkNode * head = (LinkNode*)malloc(sizeof(LinkNode));
    // 头结点指针域
    head->next = NULL;
    if (head == NULL) {
        printf("申请空间失败");
        exit(0);
    }
    // 创建链表
    for (int i = 1; i < Size; i++) {
        LinkNode * item = (LinkNode*)malloc(sizeof(LinkNode));
        // 数据域
        item->data = i;
        // 将当前head指向的地址赋给新元素的指针
        item->next = head->next;
        // head指向新元素的地址
        head->next = item;
    }
    return head;
}
// 查找元素的位置
int getItem(LinkNode *link, int item) {
    LinkNode *p = link;
    int i = 0;
    while(p->next) {
        p = p->next;
        if (p->data == item) {
            return i;
        }
        i++;
    }
    return -1;
}
// 删除元素
LinkNode * deleteItem(LinkNode *link, int item) {
    // 快指针
    LinkNode * head = link->next;
    // 慢指针
    LinkNode * temp = link;
    while(head->data != item) {
        temp = head;
        head = head->next;
    }
    temp->next = head->next;
    free(head);
    return link;
}
// 清空链表
void clearLinkList(LinkNode *link) {
    int i = 0;
    // 临时指针
    LinkNode *p,*q;
    p = link->next;
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
}
// 插入元素
LinkNode * insertItem(LinkNode *link, int index, int item) {
    // 判断插入位置
    if (index < 0) {
        printf("插入位置错误");
        exit(0);
    }
    // 临时指针
    LinkNode * temp = link;
    // 找到插入的上一个元素
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    // 创建插入结点
    LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = item;
    node->next = temp->next;
    temp->next = node;
    return link;
}
// 查找元素
int findItem(LinkNode *link, int item) {
    // 临时指针
    LinkNode * p = link;
    int i = 1;
    while(p->next) {
        p = p->next;
        if (p->data == item) {
            return i;
        }
        i++;
    }
    return -1;
}
// 打印链表
void printLinkList(LinkNode *p) {
    // 可移动指针，初始指向链表
    LinkNode *temp = p;
    while(temp) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main() {
    LinkNode * linkList = initByRear();
    LinkNode * insertedLink = insertItem(linkList, 1, 5);
    LinkNode * delLinkList = deleteItem(insertedLink, 2);
    printLinkList(delLinkList);
    return 0;
}