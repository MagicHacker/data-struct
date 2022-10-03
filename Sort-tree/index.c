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
void push(BiTree *p, BiTree item) {
    p[++top] = item;
}
// 出栈
void pop() {
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
    push(a, T);
    while(top != -1) {
        // 获取栈顶元素
        p = getTop(a);
        // 出栈
        pop();
        while(p) {
            printf("%d", p->data);
            // 右子树进栈
            if (p->rightChild) {
                push(a, p->rightChild);
            }
            p = p->leftChild;
        }
    }
}

// 递归中序遍历二叉树
void inOrderRecur(BiTree T) {
    if (T) {
        inOrderRecur(T->leftChild);
        printf("%d", T->data);
        inOrderRecur(T->rightChild);
    }
}

/**
 * 非递归中序遍历二叉树
 * 方案一：从根结点开始， 不断遍历当前结点的左子树并将该结点压入栈中，直到不再有左子树，
 * 然后从栈顶取出一个结点访问，然后将它的右孩子结点压入栈中，继续以同样的方式遍历该结点的右子树。
 * 方案二：与方案一不同之处在于，压入栈中的是每个结点的左孩子，右孩子不需要入栈。
 */

// 非递归中序遍历 方案一
void inOrderNoRecur1(BiTree T) {
    // 定义栈
    BiTNode * a[20];
    // 临时指针
    BiTNode *p;
    // 根结点先进栈
    push(a, T);
    while(top != -1) {
        while((p = getTop(a)) && p) {
            // 该结点左孩子入栈
            // 没有左孩子，NULL入栈
            push(a, p->leftChild);
        }
        // 栈顶肯定为NULL，将NULL出栈
        pop();
        if (top != -1) {
            p = getTop(a);
            // 栈顶出栈
            pop();
            printf("%d", p->data);
            // 该结点右孩子入栈
            push(a, p->rightChild);
        }
    }
}

// 非递归中序遍历 方案二
void inOrderNoRecur2(BiTree T) {
    // 定义栈
    BiTNode * a[20];
    // 临时指针
    BiTNode *p;
    p = T;
    while(p || top != -1) {
        // 将当前结点入栈并遍历其左子树
        if (p) {
            push(a, p);
            p = p->leftChild;
        } else {
            // 左子树遍历完成，需要遍历上一层结点的右子树
            p = getTop(a);
            pop();
            printf("%d", p->data);
            p = p->rightChild;
        }
    }

}

// 后序递归遍历
void postOrderRecur(BiTree T) {
    if (T) {
        postOrderRecur(T->leftChild);
        postOrderRecur(T->rightChild);
        printf("%d", T->data);
    }
}

/**
 * 非递归后序遍历二叉树
 * 在遍历完当前结点的左右孩子之后才访问该结点，需要在当前结点入栈时配备一个标志位，
 * 当遍历该结点的左孩子时，设置当前结点标志位为0；
 * 当遍历该结点的右孩子时，设置当前结点标志位为1，入栈。
 * 这样当遍历完该结点的左右子树并将其出栈时，标志位如果为0，表示该结点的右孩子还没有遍历，
 * 如果是1，表示该结点的左右孩子都遍历完成，可以访问此结点。
 */
typedef struct SNode {
    int tag;
    BiTree p;
}
void postOrderNoRecur(BiTree T) {
    // 定义栈
    SNode a[20];
    // 临时指针
    BiTNode *p;
    // 标记位
    int tag;
    SNode sdata;
    p = T;
    while(p || top != -1) {
        while(p) {
            sdata.p = p;
            sdata.tag = 0;
            push(a, sdata);
            p = p->leftChild;
        }
        // 获取栈顶元素
        sdata = a[top];
        // 栈顶出栈
        pop();
        p = sdata.p;
        tag = sdata.tag;
        // tag = 0，该结点还没有遍历它的右孩子
        if (tag == 0) {
            sdata.p = p;
            sdata.tag = 1;
            push(a, sdata);
            p = p->rightChild;
        } else {
            printf("%d", p->data);
            p = NULL;
        }
    }
}
int main() {
    BiTree T;
    preOrderRecur(T);
    preOrderNoRecur(T);
    return 0;
}