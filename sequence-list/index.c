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
    for(int i = 0; i < t.length; i++) {
        printf("%d\n", t.head[i]);
    }
}
/**
 * 插入元素
 * 1、插入表头
 * 2、插入中间
 * 3、插入表尾
 * 将要插入元素的位置以及后续元素向后移动一位
 * 放入元素
 * @return 更新的表
 */
table insertItemByIndex(table t, int item, int index) {
    // 插入的位置不存在或者插入的位置比t.length + 1还大
    if (index < 1 || index > t.length + 1) {
        printf("插入的位置有问题\n");
        return t;
    }
    // 表没有多余空间，要先申请
    if (t.length == t.size) {
        t.head = (int*) realloc(t.head, (t.size + 1) * sizeof(int));
        if (!t.head) {
            printf("申请空间失败");
            return t;
        }
        t.size += 1;
    }
    // 将元素后移
    for (int i = t.length - 1; i >= index - 1; i--) {
        t.head[i + 1] = t.head[i];
    }
    // 将元素插入
    t.head[index - 1] = item;
    t.length++;
    return t;
}

/**
 * 删除指定位置的元素
 * 遍历找到目标元素，其后续所有元素前移
 * @return 更新后的表
 */
table deleteItemByIndex(table t, int index) {
    // 删除的位置无效
    if (index < 1 || index > t.length) {
        printf("被删除元素的位置有误");
        return t;
    }
    // 后续元素前移
    for (int i = index; i < t.length; i++) {
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
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
    // 向顺序表插入元素
    table insertedTable = insertItemByIndex(t, 6, 3);
    printTable(insertedTable);
    table deletedTable = deleteItemByIndex(insertedTable, 1);
    printf("删除后的元素：\n");
    printTable(deletedTable);
    return 0;
}