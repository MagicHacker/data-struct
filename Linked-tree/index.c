/**
 * 链表 二叉树
 */

#include <stdio.h>
#include <stdlib.h>
#define NodeNum 7;
// 二叉树结点
typedef struct BiTNode {
    // 数据域
    int data;
    // 左树指针
    struct BiTNode * leftChild;
    // 右树指针
    struct BiTNode * rightChild;
}BiTNode, * BiTree;

// 手动构建二叉树
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

// 动态构建二叉树
int arr[7] = {1,2,3,4,5,6};
int index = 0;
void createBiTreeByAuto(BiTree * T) {
    if (index == 6) {
        T = NULL;
        return;
    }
    // 创建结点
    (*T) = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = arr[1];
    index++;
    createBiTreeByAuto(&((*T)->leftChild));
    createBiTreeByAuto(&((*T)->rightChild));
}
// 后序遍历二叉树 释放内存
void destroyBiTree(BiTree T) {
    if (T) {
        destroyBiTree(T->leftChild);
        destroyBiTree(T->rightChild);
        free(T);
    }
}
// 前序遍历
void preOrder(BiTree T) {
    if (T) {
        printf("输出:%d", T->data);
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    }
}
int main () {
    BiTree Tree;
    // createBiTreeByManual(&Tree);
    createBiTreeByAuto(&Tree);
    preOrder(Tree);
    return 0;
}