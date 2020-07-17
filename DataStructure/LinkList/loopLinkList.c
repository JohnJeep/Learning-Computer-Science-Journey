/*
 * @Author: your name
 * @Date: 2019-07-28 23:35:45
 * @LastEditTime: 2020-07-14 21:33:16
 * @LastEditors: Please set LastEditors
 * @Description: 双链表实现
 */ 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}ListLode, *PtrNode;

// 创建单循环链表
// 函数输入：链表结点数组，结点数
// 函数输出：循环链表尾结点q地址
PtrNode creatList(int a[], int n)
{
    ListLode *p, *q, *head;
    head = (PtrNode)malloc(sizeof(PtrNode));
    p = head;
    for(int i = 0; i < n; i++){
        q = (PtrNode)malloc(sizeof(PtrNode));
        q->data = a[i];
        p->next = q;
        p = q;       // 移动指针p,指向下一个结点
    }
    q->next = head;  // 尾节点的指针域指向头结点
    return q;
}

// 创建两个循环单链表连接成一个循环链表
// 函数输入：Ta循环单链表尾指针，Tb循环单链表尾指针
// 函数输出：无
void linkLoopList(ListLode *Ta, ListLode *Tb)
{
    ListLode *p;
    p = (ListLode *)malloc(sizeof(ListLode));
    p = Ta->next;    // Ta链表的尾节点指向头指针
    Ta->next = Tb->next->next;  // Ta链表尾节点指针域指向Tb链表头节点的地址
    free(Tb->next);   // 释放Tb链表的头结点地址
    Tb->next = p;     // Tb链表尾节点地址指向p结点
}

// 遍历链表数据
void traverseList(PtrNode head)
{
    PtrNode p;
    p = (PtrNode)malloc(sizeof(PtrNode));
    p = head->next;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main()
{
    int N = 5;
    int a[] = {3, 6, 7, 5, 8};
    int b[] = {2, 4, 9, 1, 10};
    
    ListLode *Ta, *Tb, *head;
    //head = (PtrNode)malloc(sizeof(PtrNode));
    Ta = creatList(a, N);
    Tb = creatList(b, N);
    linkLoopList(Ta, Tb);
    printf("结束运行！");
    //traverseList(head);

    return 0;
}

