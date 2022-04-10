/**
 * 定义链表
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 定义链表节点
 * 每个节点都是LinkNode结构体
 * 指针指向的后继元素也是节点结构体
 * 故指针的类型为struct LinkNode
 */
typedef struct LinkNode {
    // 数据域
    int age;
    // 指针域
    struct LinkNode * next;
}LinkNode;

/**
 * 初始化链表
 * 无头节点单链表
 */
LinkNode * initLink() {
    // 定义头指针
    LinkNode *p = NULL;
    // 定义首元节点
    // 首元节点也是一个指针，用来指向内存随机开辟的一块空间
    LinkNode *firstNode = (LinkNode*) malloc(sizeof (LinkNode));
    // 初始化首元节点
    firstNode->age = 0;
    firstNode->next = NULL;
    // 头指针指向首元节点
    p = firstNode;
    for(int i = 1; i < 5; i++) {
        // 创建一个新节点并初始化
        LinkNode * node = (LinkNode*) malloc(sizeof (LinkNode));
        node->age = i;
        node->next = NULL;
        // 将首元节点链接上node节点
        firstNode->next = node;
        // 指针firstNode每次都指向新链表的的最后一个节点
        firstNode = node;
    }
    // 返回建立的节点，返回头指针p即可
    return p;
}

/**
 * 打印链表
 */
void printLink(LinkNode *p) {
    // 将temp指针指向头指针p
    LinkNode * temp = p;
    while(temp) {
        printf("%d,", temp->age);
        // 指针移动
        temp = temp->next;
    }
}

int main() {
    LinkNode * p = NULL;
    printf("初始化链表为：\n");
    p = initLink();
    printLink(p);
    return 0;
}