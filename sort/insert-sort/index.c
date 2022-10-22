/**
    插入排序
*/

#include <stdio.h>
#include <stdlib.h>


// 打印每次排序后的结果
void printTable(int a[], int n, int i) {
    printf("%d：", i);
    for (int j = 0; j < 8; j++) {
        printf("%d", a[j]);
    }
     printf("\n");
}

// 插入排序函数
void insertSort(int a[], int n) {
    for (int i = 1; i < 8; i++) {
        // 若第i个元素比第i-1大则直接插入，反之找到合适位置插入
        if (a[i] < a[i - 1]) {
            int j = i - 1;
            int x = a[i];
            //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移
            while(j > -1 && x < a[j]) {
                a[i + 1] = a[j];
                j--;
            }
            // 插入正确位置
            a[j + 1] = x;
        }
        printTable(a,n,i);
    }
}

int main() {
    int a[8] = {3,1,7,5,2,4,9,6};
    insertSort(a, 8);
    return 0;
}