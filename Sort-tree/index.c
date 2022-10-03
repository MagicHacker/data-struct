/**
 * 二叉树的遍历
 * 递归与非递归
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
}BiTNode, *BiTree;

// 递归前序遍历二叉树
void preOrderRecur(BiTree T) {
    if (T) {
        printf("%d", T->data);
        preOrderRecur(T->leftChild);
        preOrderRecur(T->rightChild);
    }
}
int main() {
    BiTree T;
    preOrderRecur(T);
    return 0;
}