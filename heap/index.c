/**
 * 堆
 * 堆必须是一棵完全二叉树
 */

#include <sdtio.h>
#include <stdlib.h>
// 创建小顶堆结构
typedef struct MinHeap {
    // 元素的实际个数
    int size;
    int data[20];
}heap;

// 初始化一个堆
void initHeap(heap *h) {
    h->size = 0;
}

// 向堆中插入元素
void insertHeap(heap *h, int item) {
    if (h->size == 20) {
        printf("堆已经满了");
    } else {
        h->size++;
        for (int i = h->size; i>=1; i / 2) {
            if (item < h->data[i / 2]) {
                h->data[i] = h->data[i / 2];
            } else {
                break;
            }
        }
        h->data[i] = item;
    }
}



int main() {
    int a[] = {67,8,4,34,86,87,6,45,7,864,56,1,3,78,9,13};
    insertHeap(a, 2);
    return 0;
}
