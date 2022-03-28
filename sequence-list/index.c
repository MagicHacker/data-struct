/**
 * 自定义顺序表
 */
#include <stdio.h>
#include <stdlib.h>
// 宏定义Size，顺序表申请的空间
#define Size 5;

// 定义顺序表结构体
typedef struct table {
    int *head;
    int length;
    int size;
}table;

// 初始化顺序表
table initTable() {
    table t;
    // 构造空的顺序表，动态申请空间
    t.head = (int*)malloc(5 * sizeof(int));
    if (!t.head) {
        printf("初始化表失败");
        exit(0);
    };
    t.length = 0;
    t.size = Size;
    return t;
}
// 顺序打印顺序表中元素
void printTable(table t) {
    for(int i = 0; i < Size i++) {
        printf("%d\n", t.head[i]);
    }
}
int main() {
    int i;
    table t = initTable();
    // 向顺序表添加元素
    for(i = 0; i < Size i++) {
        t.head[i] = i;
        t.length++;
    }
    printf("顺序表中存储的元素是：\n");
    printTable(t);
    return 0;
}