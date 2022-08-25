/**
 * 链表 二叉树
 */

#include <stdio.h>
#include <stdlib.h>
// 二叉树结点
typedef struct BiTNode {
    // 数据域
    int data;
    // 左树指针
    struct BiTNode * leftChild;
    // 右树指针
    struct BiTNode * rightChild;
}BiTNode, * BiTree;

// 手动添加数据
void createBiTreeByManual(BiTree * T) {
    // 创建根结点
    * T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    // 创建左子树
    (*T)->leftChild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->leftChild->data = 2;
    // 创建右子树
    (*T)->rightChild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rightChild->data = 3;
    (*T)->rightChild->leftChild = NULL;
    (*T)->rightChild->rightChild = NULL;
    (*T)->leftChild->leftChild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->leftChild->leftChild->data = 4;
    (*T)->leftChild->rightChild = NULL;
    (*T)->leftChild->leftChild->leftChild = NULL;
    (*T)->leftChild->leftChild->rightChild = NULL;
}

// 后序遍历二叉树 释放内存
void destroyBiTree(BiTree T) {
    if (T) {
        destroyBiTree(T->leftChild);
        destroyBiTree(T->rightChild);
        free(T);
    }
}
int main () {
    BiTree Tree;
    createBiTreeByManual(&Tree);
    printf("根节点的左孩子结点为：%d\n", Tree->leftChild->data);
    printf("根节点的右孩子结点为：%d\n", Tree->rightChild->data);
    destroyBiTree(Tree);
    return 0;
}