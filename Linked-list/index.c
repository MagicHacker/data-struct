/**
 * 定义链表
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * 定义单链表节点
 * 指针域指向的是下一个节点整体
 * 所以next指针类型也为结构体
 */
typedef struct LinkNode {
    int elem;
    struct LinkNode * next;
}LinkNode;

/**
* 初始化链表
* 定义头指针
* 创建多个存储数据的节点
* 创建过程中要随时与前驱节点建立联系
*/
LinkNode * initLink() {
    // 定义头指针 指针类型为结构体LinkNode
    LinkNode * p = NULL;
    // 定义首元节点 节点类型是LinkNode结构体
    // malloc申请一个节点空间
    // firstNode是一个指针，指向的是结构体LinkNode的实例
    LinkNode * firstNode = (LinkNode *) malloc(sizeof (LinkNode));
    // 初始化首元节点
    firstNode->elem = 0;
    firstNode->next = NULL;
    // 头指针指向首元节点
    p = firstNode;
    // 从第二个节点开始创建
    for (int i = 1; i < 5; i++) {
        LinkNode * node = (LinkNode *) malloc(sizeof (LinkNode));
        node->elem = i;
        node->next = NULL;
        // 将首元节点与新建立的节点建立关系
        firstNode->next = node;
        // 指针firstNode每次都指向新链表的最后一个节点
        firstNode = firstNode->next;
    }
    // 返回头指针，通过头指针即可找到整个链表
    return p;
}

/**
 * 打印链表
 */
void printLink(LinkNode *p) {
    // 将temp指针指向头节点
    LinkNode * temp = p;
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkNode *p = NULL;
    printf("初始链表为:\n");
    p = initLink();
    printLink(p);
    return 0;
}