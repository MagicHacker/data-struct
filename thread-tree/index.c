/**
 * 线索二叉树
 */
#include <stdio.h>
#include <stdlib.h>

// 结点数据域类型
typedef char TElemType;
// 枚举 Link = 0表示指向左右孩子指针 Thread = 1表示指向前驱或后继的线索
typedef enum { Link, Thread } PointerTag;
typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    // 左标志 为0时指向左子树，为1时指向前驱
    PointerTag LTag;
    // 右标志 为0时指向右子树，为1时指向后继
    PointerTag RTag;
} BiThrNode, *BiThrTree;
/**
 * 中序遍历初始化线索二叉树
 * 原理：遍历过程中修改空指针的指向
 */
// 临时指针 始终指向刚访问过的结点
BiThrTree pre;
void initThreadTree(BiThrTree T) {
    if (T) {
        // 递归左子树线索化
        initThreadTree(T->lchild);
        // 没有左子树 指向前驱
        if (!T->lchild) {
            T->LTag = Thread;
            // 指向前驱
            T->lchild = pre;
        }
        // 当前结点没有右子树
        if (!pre->rchild) {
            pre->RTag = Thread;
            // 前驱右子树指向后继
            pre->rchild = T;
        }
        // pre始终指向T的前驱
        pre = T;
        // 递归右子树线索化
        initThreadTree(T->rchild);
    }
}

int main() {
    initThreadTree();
    return 0;
}