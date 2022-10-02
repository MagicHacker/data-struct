/**
 * 链表 二叉树
 */

#include <stdio.h>
#include <stdlib.h>
#define NodeNum 7;
// 二叉树结点
typedef struct BiNode {
    // 数据域
    TElemType data;
    // 左右孩子指针
    struct BiNode *lchild,*rchild;
}BiNode, *BiTree;

// 手动初始化链表二叉树
void initBiTree(BiTree *T) {
    // 申请空间，创建结点
    *T = (BiNode*)malloc(sizeof(BiNode));
    (*T)->data = 1;
    (*T)->lchild = (BiNode*)malloc(sizeof(BiNode));
    (*T)->lchild->data = 2;
    (*T)->rchild = (BiNode*)malloc(sizeof(BiNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;
    (*T)->lchild->lchild = (BiNode*)malloc(sizeof(BiNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->rchild = NULL;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// 后序遍历二叉树 左-》右-》根
void postOrderTree(BiTree T) {
    if (T) {
        postOrderTree(T->lchild);
        postOrderTree(T->rchild);
        printf("%d", T->data);
    }
}
int main() {
    BiTree tree;
    initBiTree(&tree);
    return 0;
}