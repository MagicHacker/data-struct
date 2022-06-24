/**
 * 双向链表
 */
#include <stdio.h>
#include <stdlib.h>
#define Size 5
// 链表结点
typedef struct LinkNode {
    // 前驱指针域
    struct LinkNode * prev;
    // 数据域
    int data;
    // 后继指针域
    struct LinkNode * next;
}LinkNode;

// 初始化链表
LinkNode * initLink() {
    // 头结点 前驱指针为空
    LinkNode * head = (LinkNode *)malloc(sizeof(LinkNode));
    head->prev = NULL;
    head->data = 0;
    head->next = NULL;
    // 临时指针
    LinkNode * temp = head;
    for (int i = 1; i < Size; i++) {
        // 创建结点
        LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = i;
        temp->next = node;
        node->prev = temp;
        // temp = node;
        temp = temp->next;
    }
    return head;
}

// 打印链表
void printLinkList(LinkNode * link) {
    LinkNode * temp = link;
    while(temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main() {
    LinkNode * linkList = initLink();
    printLinkList(linkList);
    return 0;
}