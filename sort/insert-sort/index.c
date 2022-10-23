/**
    插入排序
*/

#include <stdio.h>
#include <stdlib.h>


// 打印每次排序后的结果
void printTable(int a[], int n, int i) {
    printf("%d:", i);
    for (int j = 0; j < 8; j++) {
        printf("%d", a[j]);
    }
     printf("\n");
}

/**
 * 第一个元素看成是有序序列，第二个元素到最后一个元素为无序序列
 * 扫描，找到合适位置插入
*/
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 当前元素
        int current = arr[i];
        // 前一个位置
        int preIndex = i - 1;
        // 从后向前扫描 3 1
        while (preIndex >= 0 && arr[preIndex] > current) {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = current;
        printTable(arr, n, i);
    }
}

int main() {
    int a[8] = {3,1,7,5,2,4,9,6};
    insertSort(a, 8);
    return 0;
}