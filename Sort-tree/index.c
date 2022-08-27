/**
 * 二叉树的遍历
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    // 数据域
    int data;
    // 左树指针
    struct BiTNode * leftChild;
    // 右树指针
    struct BiTNode * rightChild;
}BiTNode, * BiTree;
// 递归前序遍历
void preOrder(BiTree T) {
    if (T) {
        printf("%d:", T->data);
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    }
}
int main() {
    return 0;
}