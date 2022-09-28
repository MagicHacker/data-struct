/**
 * 顺序结构存储二叉树
 * 普通二叉树转化完全二叉树
 * 从根结点开始按层次存储
 */
#include <stdio.h>
#include <stdlib.h>

// 二叉树中结点的数量
#define NodeNum 7
// 结点值类型
#define ElemType int
// 二叉树
typedef ElemType BiTree[NodeNum];

// 初始化二叉树
void initBiTree(BiTree T) {
    ElemType node;
    int i = 0;
    while(scanf("%d", &node)) {
        T[i] = node;
        i++;
    }
}

int main() {
    BiTree T = { 0 };
    initBiTree(T);
    return 0;
}