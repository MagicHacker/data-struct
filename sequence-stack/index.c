/**
 * 顺序栈
 */
#include <stdio.h>
#include <stdlib.h>
#define maxSize 7

typedef struct sqStack {
    // 栈顶指针
    int top;
    int *data;
}sqStack;

// 入栈
sqStack pushStack(sqStack st, int item) {
    if (st.top == maxSize - 1) {
        printf("栈满，无法入栈");
        return st;
    }
    st.top++;
    st.data[st.top] = item;
    return st;
}
// 出栈
sqStack popStack(sqStack st) {
    if (st.top < 0) {
        printf("栈空");
        return st;
    }
    st.top--;
    return st;
}
// 打印栈
void printStack(sqStack st) {
    printf("打印栈:");
    while(st.top >= 0) {
        printf("%d", st.data[st.top]);
        st.top--;
    }
}
int main() {
    // 创建空栈
    sqStack stack;
    stack.data = (int*)malloc(maxSize * sizeof(int));
    stack.top = 0;
    // 初始化
    for (int i = 0; i < maxSize; i++) {
        if (i < maxSize) {
            stack.data[i] = i;
            stack.top = i;
        }
    }
    // 出栈
    stack = popStack(stack);
    // 入栈
    stack = pushStack(stack, 7);
    printStack(stack);
    return 0;
}