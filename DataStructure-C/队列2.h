#pragma once
typedef int ElemType;

typedef struct QNode
{
	ElemType data; //��Ŷ���Ԫ��
	struct QNode* next; //ָ����һ�����
} QNode, * QueuePtr;

typedef struct
{
	QNode* front; //��ͷָ��
	QNode* rear; //��βָ��
} LinkQueue;

void initQueue(LinkQueue& Q);

void destroyQueue(LinkQueue& Q);

void enQueue(LinkQueue& Q, ElemType e);

void deQueue(LinkQueue& Q, ElemType& e);

void showFront(LinkQueue Q, ElemType& e);