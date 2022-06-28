/**
 * 顺序队列
 */
#include <stdio.h>
#include <stdlib.h>
#define Size 5

// 入队
int pushQueue(int * a, int rear, int data) {
    if (rear == Size) {
        printf("队列已满");
        exit(0);
    }
    a[rear] = data;
    rear++;
    return rear;
}
// 出队
int popQueue(int * a, int front, int rear) {
    if (front == rear) {
        printf("队列为空");
        exit(0);
    }
    while(front != rear) {
        printf("%d", a[front]);
        front++;
    }
    return front;
}
// 打印队列
void printQueue(int * a, int front, int rear) {
    for (int i = front; i < rear; i++) {
        printf("%d", a[i]);
    }
}
int main() {
    int data[Size];
    // 队头指针，队尾指针
    int front,rear;
    // 队列为空 队头和队尾指向同一处
    front = rear = 0;
    // 入队
    rear = pushQueue(data, rear, 1);
    rear = pushQueue(data, rear, 2);
    rear = pushQueue(data, rear, 3);
    rear = pushQueue(data, rear, 4);
    // 出队
    front = popQueue(data, front, rear);
    // 打印队列
    printQueue(data, front, rear);
    return 0;
}