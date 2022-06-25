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

// 插入元素
LinkNode * insertItem(LinkNode * link, int index, int item) {
    if (index < 0) {
        printf("插入位置非法");
    }
    // 创建结点
    LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
    node->prev = NULL;
    node->data = item;
    node->next = NULL;
    // 插入到表头成为新的表头元素 只需与原表头元素建立双层逻辑关系
    if (index == 0) {
        node->next = link;
        link->prev = node;
        link = node;
    } else {
        // 临时指针
        LinkNode * temp = link;
        // 查找位置
        for (int i = 1; i < index - 1; i++) {
            temp = temp->next;
        }
        // 插到表尾
        if (temp->next == NULL) {
            node->prev = temp;
            temp->next = node;
        } else {
            node->next = temp->next;
            temp->next->prev = node;
            temp->next = node;
            node->prev = temp;
        }
    }
    return link;
}
// 删除元素
LinkNode * deleteItem(LinkNode * link, int item) {
    LinkNode * temp = link;
    while(temp) {
        if (temp->data != item) {
            printf("删除的元素不在链表中");
            exit(0);
        } else {
            // 删除元素是表头
            if (temp->prev == NULL) {
                temp->next->prev = NULL;
                temp->next = NULL;
                free(temp);
            } else if (temp->next == NULL) { // 删除的元素是表尾
                temp->prev->next = NULL;
                temp->prev = NULL;
                free(temp);
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
            }
        }
    }
    return link;
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