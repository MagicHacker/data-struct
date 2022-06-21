/**
 * 顺序表
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Size 10

// 表结构体
typedef struct List {
    // 动态数组
    int *data;
    // 表长度
    int length;
    // 表容量
    int size;
}List;
// 初始化空表
List initList() {
    List list;
    // 动态申请空间
    list.data = (int*)malloc(Size * sizeof(int));
    if (!list.data) {
        printf("表初始化失败");
        exit(0);
    }
    list.length = 0;
    list.size = Size;
    return list;
}
// 打印表
void printList(List list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
    }
}
// 判断是否为空表
bool listIsEmpty(List list) {
    // 1-空表
    return list.length == 0;
}
// 清空表
void clearList(List list) {}
// 获取元素
int getItem(List list, int index) {
    if (index < 0) {
        printf("位置错误，获取失败");
    }
    return list.data[index];
}
// 查找元素位置
void findItem(List list, int item) {}
// 插入元素
void listInsert(List list, int index, int item) {}
// 删除元素
void listDelete(List list, int index) {}
// 获取元素个数
int listLength(List list) {
    return list.length;
}
int main() {
    List list = initList();
    // 空表塞入数据
    for (int i = 0; i < Size; i++) {
        list.data[i] = i;
        list.length++;
    }
    // printList(list);
    printf("是否为空表%d\n", listIsEmpty(list));
    printf("元素个数%d\n", listLength(list));
    printf("获取元素%d", getItem(list, 1));
    return 0;
}