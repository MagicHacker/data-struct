/**
 * 链式队列
 */
#include <stdio.h>
#include <stdlib.h>
#define Size 5

// 结点
typedef struct QueueNode {
    int data;
    struct QueueNode * next;
}QueueNode;

// 初始化链队列
QueueNode * initQueueLink() {
    // 头结点
    QueueNode * head = (QueueNode*)malloc(sizeof(QueueNode));
    head->next = NULL;
    return head;
}

// 入队
QueueNode * pushQueue(QueueNode * rear, int item) {
    // 创建结点
    QueueNode * node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = item;
    node->next = NULL;
    rear->next = node;
    rear = node;
    // 为后续入队做处理
    return rear;
}
int main() {
    return 0;
}