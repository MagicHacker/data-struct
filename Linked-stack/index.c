/**
 * 链栈
 */
#include <stdio.h>
#include <stdlib.h>
#define Size 6
// 创建结点
typedef struct LinkNode {
    // 数据域
    int data;
    // 指针域
    struct LinkNode * next;
}LinkNode;

// 初始化
// 栈顶元素必须有值 链栈不需要头结点
LinkNode * intLinkNode() {
    // 头指针
    LinkNode * head = NULL;
    // 首元结点
    LinkNode * temp = (LinkNode*)malloc(sizeof(LinkNode));
    temp->data = 0;
    temp->next = NULL;
    head = temp;
    // 栈顶在链表头部 采用头插法
    for (int i = 1; i < Size; i++) {
        // 创建结点
        LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = i;
        temp->next = node;
        temp = temp->next;
    }
    return head;
}
// 打印链栈
void printLink(LinkNode * link) {
    // 头指针
    LinkNode * temp = link;
    while(temp) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main() {
    LinkNode * link = intLinkNode();
    printLink(link);
    return 0;
}