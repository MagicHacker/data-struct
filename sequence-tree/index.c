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
    printf("按照层次从左往右输入树中结点的值，0 表示空结点，# 表示输入结束:");
    while(scanf("%d", &node)) {
        T[i] = node;
        i++;
    }
}

// 查找某个结点的双亲结点的值
ElemType Parent(BiTree T, ElemType e) {
    int i;
    if (T[0] == 0) {
        printf("存储的是一颗空树");
    } else {
        if (T[0] == e) {
            printf("当前结点是根结点，没有双亲结点");
            return 0;
        }
        for (i = 1; i < NodeNum; i++) {
            if (T[i] == e) {
                return T[(i + 1) / 2 - 1];
            }
        }
        printf("二叉树中没有指定结点\n");
    }
    return -1;
}

int main() {
    BiTree T = { 0 };
    initBiTree(T);
    return 0;
}