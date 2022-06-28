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
void popQueue(int * a, int front, int rear) {

}
// 打印队列
void printQueue(int * a, int rear) {
    for (int i = 0; i < rear; i++) {
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
    printQueue(data, rear);
    return 0;
}