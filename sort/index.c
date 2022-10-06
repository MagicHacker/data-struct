/**
 * 各种排序
 */
#include <stdio.h>
#include <stdlib.h>

// 冒泡排序
// 95183742
void bubbleSort(List *l) {
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

int main() {
    return 0;
}