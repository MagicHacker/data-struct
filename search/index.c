/**
 * 各种查找
 */
#include <stdio.h>
#include <stdlib.h>

// 顺序表查找
int sequenceSearch1(int *a, int length, int key) {
    for (int i = 0; i < length; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return 0;
}

// 顺序查找优化
// sequenceSearch1每次循环都需要比较i < length，可以优化
int sequenceSearch2(int *a, int length, int key) {
    int i;
    // 设置哨兵
    a[0] = key;
    i = length;
    while(a[i] != key) {
        i--;
    }
    return i;
}

// 二分查找，数据必须有序
int binarySearch(int *a, int length, int key) {
    int low, high, mid;
    low = 1;
    high = length;
    while(low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return 0;
}

int main() {
    retutn 0;
}