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

/**
 * 非递归前序遍历二叉树
 * 递归底层借助的是栈结构
 * 手动创建栈 模拟递归
 */
// 栈顶指针
int top = -1;
// 进栈
void prePush(BiTree *p, BiTree item) {
    p[++top] = item;
}
// 出栈
void prePop() {
    if (top == -1) {
        return;
    }
    top--;
}
// 获取栈顶元素
BiTNode * getTop(BiTree *p) {
    return p[top];
}
// 非递归前序遍历二叉树 根-》左-》右
void preOrderNoRecur(BiTree T) {
    // 定义一个顺序栈
    BiTNode * a[20];
    // 临时指针
    BiTNode * p;
    // 根结点先进栈
    prePush(a, T);
    while(top != -1) {
        // 获取栈顶元素
        p = getTop(a);
        // 出栈
        prePop();
        while(p) {
            printf("%d", p->data);
            // 右子树进栈
            if (p->rightChild) {
                prePush(a, p->rightChild);
            }
            p = p->leftChild;
        }
    }
}
int main() {
    BiTree T;
    preOrderRecur(T);
    preOrderNoRecur(T);
    return 0;
}