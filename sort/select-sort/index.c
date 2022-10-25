/**
 * 选择排序
 * 1、在未排序的序列中先找到最小的元素，放到序列起始位置。
 * 2、再从剩余的序列中找到最小的元素，放到已排序序列的末尾。
 * 3、重复第2步。
*/

// 交换位置
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 选择排序
void selectSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        // 外层循环n次，每次都假设第i次的第一个元素为最小
        int min = i;
        // 在剩余的序列中查找最小元素位置
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                min = j;
            }
        }
        // 跳跃着交换两个元素
        swap(&arr[min], &arr[i]);
    }
}

int main() {
    return 0;
}