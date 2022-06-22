/**
 * 链表
 */
#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}