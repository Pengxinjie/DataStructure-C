#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "����1.h"

int main(void)
{
	Queue q = initQueue();
	
	int boo = 1,
		te;
	while (boo)
	{
		int temp;
		printf("1.���Ԫ�أ���ӣ�\n2.ɾ��Ԫ�أ����ӣ�\n3.��ʾ����Ԫ��\n4.���ٶ��в��˳�������\n");
		printf("��������Ҫ���еĶ��в�����");
		scanf("%d", &temp);
		switch (temp) {
		case 1:
			printf("������Ҫ��ӵ�Ԫ�أ�");
			int value;
			scanf("%d", &value);
			enQueue(&q, value);
			break;
		case 2:
			deQueue(&q, &te);
			break;
		case 3:
			showFront(&q);
			break;
		case 4:
			destoryQueue(&q);
			boo = 0;
			break;
		default:
			printf("������Ч��\n");
		}

	}

	system("pause");
	return 0;
}

//1.�󳤶�
int getLength(Queue q) {
	return ((q.front + MAXSIZE) - q.rear) % MAXSIZE;
}

//2.��ʼ��
Queue initQueue(void) {
	Queue q;
	q.queue = (ElementType*)malloc(MAXSIZE * sizeof(ElementType));
	if (!q.queue) { 
		printf("��ʼ������ռ�ʧ�ܣ�");
	}
	q.front = 0;
	q.rear = 0;
	return q;
}

//3.���
void enQueue(Queue* q, ElementType e) {
	if (isFull(q)) {
		printf("�������������ʧ�ܣ�\n");
		return;
	}
	q->queue[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

//4.����
void deQueue(Queue* q,ElementType *e) {
	if (isEmpty(&q))
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return;
	}
	*e = q->queue[q->front];
	printf("���ڳ��ӵ��ǣ�%d\n", *e);
	q->front = (q->front + 1) % MAXSIZE;
}

//5.��ʾ����Ԫ��
void showFront(Queue* q) {
	if (isEmpty(&q))
	{
		printf("����Ϊ�գ�\n");
		return ;
	}
	printf("���ڶ�����%d\n", q->queue[q->front]);
}
//6.���ٶ���
void destoryQueue(Queue* q) {
	if(q->queue)
		free(q->queue);
	q->queue = NULL;
	q->front = 0;
	q->rear = 0;
}

//7.�п�
int isEmpty(Queue* q) {
	return q->front == q->rear;
}

//8.����
int isFull(Queue* q) {
	return (q->rear + 1) % MAXSIZE == q->front;
}
