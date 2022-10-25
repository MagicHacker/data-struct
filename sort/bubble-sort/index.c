/**
 * 各种排序
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    // 动态数组
    int *data;
    // 表长度
    int length;
    // 表容量
    int size;
}List;
// 冒泡排序

void bubbleSort1(List *l) {
    for (int i = 0; i < l->length; i++) {
        for (int j = i + 1; j < l->length; j++) {
            if (l->data[i] > l->data[j]) {
                // 交换
                int temp = l->data[i];
                l->data[i] = l->data[j];
                l->data[j] = temp;
            }
        }
    }
}

// 冒泡优化
void bubbleSort2(List *l) {
    for (int i = 0; i < l->length; i++) {
        for (int j = l->length - 1; j >= i; j--) {
            if (l->data[j] > l->data[j+1]) {
                // 交换
                int temp = l->data[j];
                l->data[j] = l->data[j+1];
                l->data[j+1] = temp;
            }
        }
    }
}
int main() {
    return 0;
}