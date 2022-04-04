/**
 * 自定义顺序表
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 宏定义Size，顺序表申请的空间
#define SIZE 5;

// 定义顺序表结构体
typedef struct table {
    // 动态数组 指针指向malloc分配的空间地址
    int * list;
    // 顺序表长度
    int length;
    // 顺序表空间容量
    int size;
}table;

// 初始化顺序表--空表
table initTable() {
    table t;
    // 动态申请空间 --空表
    t.list = (int*) malloc(5 * sizeof (int));
    if (!t.list) {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = SIZE;
    return t;
}

// 打印顺序表
void printTable(table t) {
    for(int i = 0; i< t.length; i++) {
        printf("元素:%d\n", t.list[i]);
    }
    printf("\n");
}

/**
 * 查询表中元素下标
 * @param t 顺序表
 * @param item 元素
 * @return 下标
 */
int searchIndex(table t, int item) {
    for(int i = 0; i < t.length; i++) {
        if (t.list[i] == item) {
            return i;
        }
    }
    return -1;
}

/**
 * 根据下标删除表元素
 * @param t 表
 * @param index 下标
 * @return 删除元素后的表
 * 后续元素前移1位即可
 */
table deleteByIndex(table t, int index) {
    if (index > t.length || index < -1) {
        printf("删除的位置有误");
        exit(0);
    }
    for(int i = index + 1; i < t.length; i++) {
        t.list[i - 1] = t.list[i];
    }
    t.length--;
    return t;
}

/**
 * 根据元素删除表元素
 * @param t 表
 * @param item 待删除元素
 * @return 删除元素后的表
 */
table deleteByItem(table t, int item) {
    int index = searchIndex(t, item);
    table deletedTable = deleteByIndex(t, index);
    return deletedTable;
}

/**
 * 判断表是否为空表
 * @param t 表
 * @return 0-空 1-非空
 */
int tableIsEmpty(table t) {
    if (t.length == 0) {
        return 0;
    }
    return 1;
}

/**
 * 删除整张表
 * @param t 表
 * @return 是否成功 0-成功，1-失败
 */
int dropTable(table t) {
    free(t.list);
    t.list = NULL;
    t.length = 0;
    int flag = tableIsEmpty(t);
    return flag;
}

/**
 * 添加元素
 * @param t 表
 * @param item 元素
 * @param index 下标
 * @return 添加后的表
 */
table insertTable(table t, int item, int index) {
    // 插入位置是否正确
    if (index < 0 || index > t.length + 1) {
        printf("插入的位置有问题");
        exit(0);
    }
    // 表是否有多余空间插入
    if (t.length == t.size) {
        // 申请扩容
        t.list = (int *) realloc(t.list, (t.size + 1) * sizeof (int));
        if (!t.list) {
            printf("存储分配失败");
            return t;
        }
        t.size + 1;
    }
    // 后续元素后移一位
    for(int i = t.length - 1; i >= index; i--) {
        t.list[i + 1] = t.list[i];
    }
    // 插入元素
    t.list[index] = item;
    t.length++;
    return t;
}

int main() {
    table oriTable = initTable();
    // 向顺序表添加元素
    for(int i = 0;i < SIZE i++) {
        oriTable.list[i] = i;
        oriTable.length++;
    }
    // 打印顺序表
    printTable(oriTable);
    // 查找元素的位置
    int index = searchIndex(oriTable, 3);
    printf("元素下标:%d\n", index);
//    // 根据下标删除元素
//    table deletedTable = deleteByIndex(oriTable, index);
//    // 删除某个元素
//    table deletedTable = deleteByItem(oriTable, 3);
//    printTable(deletedTable);
//    // 销毁表
//    int flag = dropTable(oriTable);
//    printf("删除成功:%d", flag);
//    // 插入元素
    table insertedTable = insertTable(oriTable, 7, 0);
    // 打印
    printTable(insertedTable);
}