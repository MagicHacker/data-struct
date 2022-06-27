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
    temp->data = 1;
    temp->next = NULL;
    head = temp;
    // 栈顶在链表头部 采用头插法
    for (int i = 2; i < Size; i++) {
        // 创建结点
        LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
        node->data = i;
        temp->next = node;
        temp = temp->next;
    }
    return head;
}
// 打印链栈
void printLink(LinkNode * stack) {
    // 头指针
    LinkNode * temp = stack;
    while(temp) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
// 入栈 头插法
LinkNode * pushLink(LinkNode * stack, int item) {
    // 创建结点
    LinkNode * node = (LinkNode*)malloc(sizeof(LinkNode));
    node->data = item;
    node->next = stack;
    stack = node;
    return stack;
}
// 出栈
LinkNode * popLink(LinkNode * stack) {
    // 栈顶指针
    LinkNode * top = stack;
    stack = stack->next;
    free(top);
    return stack;
}
int main() {
    LinkNode * link = intLinkNode();
    LinkNode * pLink = pushLink(link, 7);
    LinkNode * poLink = popLink(pLink);
    printLink(poLink);
    return 0;
}