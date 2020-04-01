#pragma once
typedef int ElementType;
#define MAXSIZE 10
typedef struct Node {
	ElementType* queue;
	int front, rear;
} Queue;

//1.求长度
int getLength(Queue q);

//2.初始化
Queue initQueue(void);

//3.入队
void enQueue(Queue* q, ElementType e);

//4.出队
void deQueue(Queue* q, ElementType* e);

//5.显示队首元素
void showFront(Queue* q);

//6.销毁队列
void destoryQueue(Queue* q);

//7.判空
int isEmpty(Queue* q);

//8.队满
int isFull(Queue* q);