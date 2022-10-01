/**
 * 线索二叉树
 * 将已有的二叉树线索化变成线索二叉树
 */
#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;
// Link = 0表示指向左右子树指针 Thread = 1表示指向前驱后继指针
typedef enum { Link, Thread } PointerTag;
typedef struct BiThrNode {
    TElemType data;
    // 左右子树指针
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, * BiThrTree;

// 临时指针
BiThrTree pre;
// 初始化线索二叉树
// 中序遍历线索化
void initThreadTree(BiThrTree T) {
    if (T) {
        // 递归左子树线索化
        initThreadTree(T->lchild);
        // 没有左子树
        if (!T->lchild) {
            // 前驱线索
            T->LTag = Thread;
            T->lchild = pre;
        }
        // 前驱没有右子树
        if (!pre->rchild) {
            // 后继线索
            pre->RTag = Thread;
            pre->rchild = T;
        }
        pre = T;
        // 递归右子树线索化
        initThreadTree(T->rchild);
    }
}

int main() {
    BiThrTree T = 's';
    initThreadTree(BiThrTree T);
    return 0;
}