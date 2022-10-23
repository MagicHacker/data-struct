/**
    插入排序
    对于未排序的数据，在已排序的序列中从后向前扫描
    找到相应的位置并插入。
    在从后向前扫描的过程中，需要反复把已排序元素逐步向后移位
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
 * 外层循环用于遍历除第一个元素外的所有元素
 * 内层循环用于在当前元素前面的已排序的序列中查找位置，并进行移动。
*/
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 当前元素
        int current = arr[i];
        // 前一个位置
        int preIndex = i - 1;
        // 从后向前扫描 3 1
        while (preIndex >= 0 && arr[preIndex] > current) {
            // 将前一个元素的值复制给挨着的后一个元素，以便插入元素的时候，后续元素向右移动
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        // 找到位置了，将其插入
        arr[preIndex + 1] = current;
        printTable(arr, n, i);
    }
}

int main() {
    int a[8] = {3,1,7,5,2,4,9,6};
    insertSort(a, 8);
    return 0;
}