/**
 * 链表
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
LinkNode deleteItem() {}
// 清空链表
void clearLinkList() {}
// 插入元素
void insertItem() {}
// 查找元素
LinkNode findItem() {}
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
    LinkNode * linkList = initByHead();
    printLinkList(linkList);
    return 0;
}