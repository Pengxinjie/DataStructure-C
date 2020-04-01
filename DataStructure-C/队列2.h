#pragma once
typedef int ElemType;

typedef struct QNode
{
	ElemType data; //存放队中元素
	struct QNode* next; //指向下一个结点
} QNode, * QueuePtr;

typedef struct
{
	QNode* front; //队头指针
	QNode* rear; //队尾指针
} LinkQueue;

void initQueue(LinkQueue& Q);

void destroyQueue(LinkQueue& Q);

void enQueue(LinkQueue& Q, ElemType e);

void deQueue(LinkQueue& Q, ElemType& e);

void showFront(LinkQueue Q, ElemType& e);