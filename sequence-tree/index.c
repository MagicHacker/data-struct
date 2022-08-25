/**
 * 顺序结构 二叉树
 * 添加空结点 拼凑成完全二叉树
 * 根结点开始，按层次存储结点
 */
#include <stdio.h>
// 二叉树结点数量
#define NodeNum 7
// 结点类型
#define ElemType int
// 自定义 BiTree类型表示二叉树
typedef ElemType BiTree[NodeNum];


// 初始化二叉树
void initBiTree(BiTree T) {
    for (int i = 0; i < NodeNum; i++) {
        T[i] = i;
    }
}
int main() {
    BiTree T = {0};
    initBiTree(T);
    for (int i = 0; i < NodeNum; i++) {
        printf("输出:%d", T[i]);
    }
    return 0;
}