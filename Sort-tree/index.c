/**
 * 二叉树的遍历
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
}BiTNode, * BiTree;
// 递归前序遍历
void preOrder(BiTree T) {
    if (T) {
        printf("%d:", T->data);
        preOrder(T->leftChild);
        preOrder(T->rightChild);
    }
}
// 迭代前序遍历 创建栈 模拟递归
// 全局变量 记录栈顶位置
int top = -1;
// 入栈
void push(BiTree *T, BiTree item) {
    T[++top] = item;
}
// 出栈
void pop() {
    if (top == -1) {
        return;
    }
    top--;
}
// 获取栈顶元素
BiTNode * getTopItem(BiTree * T) {
    return T[top];
}
void preOrderItera(BiTree T) {
    // 定义栈
    BiTNode* arr[20];
    // 临时指针
    BiTNode* temp;
    // 根节点入栈
    push(arr, T);
    while(top != -1) {
        // 获取栈顶元素
        temp = getTopItem(arr);
        // 出栈
        pop();
        while(temp) {
            printf("%d", temp->data);
            // 右子树入栈
            if (temp->rightChild) {
                push(arr, temp->rightChild);
            }
            temp = temp->leftChild;
        }
    }
}
int main() {
    return 0;
}