#pragma once
typedef int ElementType;
#define MAXSIZE 10
typedef struct Node {
	ElementType* queue;
	int front, rear;
} Queue;

//1.�󳤶�
int getLength(Queue q);

//2.��ʼ��
Queue initQueue(void);

//3.���
void enQueue(Queue* q, ElementType e);

//4.����
void deQueue(Queue* q, ElementType* e);

//5.��ʾ����Ԫ��
void showFront(Queue* q);

//6.���ٶ���
void destoryQueue(Queue* q);

//7.�п�
int isEmpty(Queue* q);

//8.����
int isFull(Queue* q);