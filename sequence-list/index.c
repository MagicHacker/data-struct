/**
 * 自定义顺序表
 */
#include <stdio.h>
#include <stdlib.h>
// 宏定义Size，顺序表申请的空间
#define Size 5;

// 定义顺序表结构体
typedef struct table {
    // 动态数组 指针指向malloc分配的空间地址
    int * list;
    // 顺序表长度
    int length;
    // 顺序表空间容量
    int size;
}table;

// 初始化顺序表
table initTable() {
    table t;
    // 动态申请空间 --空表
    t.list = (int*) malloc(5 * sizeof (int));
    if (!t.list) {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = Size;
    return t;
}

// 打印顺序表
void printTable(table t) {
    for(int i = 0; i< t.length; i++) {
        printf("元素:%d\n", t.list[i]);
    }
    printf("\n");
}

int main() {
    table oriTable = initTable();
    // 向顺序表添加元素
    for(int i = 0;i < Size i++) {
        oriTable.list[i] = i;
        oriTable.length++;
    }
    printTable(oriTable);
}