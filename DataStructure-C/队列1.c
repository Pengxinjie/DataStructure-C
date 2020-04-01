#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "队列1.h"

int main(void)
{
	Queue q = initQueue();
	
	int boo = 1,
		te;
	while (boo)
	{
		int temp;
		printf("1.添加元素（入队）\n2.删除元素（出队）\n3.显示队首元素\n4.销毁队列并退出本程序\n");
		printf("请输入您要进行的队列操作：");
		scanf("%d", &temp);
		switch (temp) {
		case 1:
			printf("请输入要入队的元素：");
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
			printf("输入无效！\n");
		}

	}

	system("pause");
	return 0;
}

//1.求长度
int getLength(Queue q) {
	return ((q.front + MAXSIZE) - q.rear) % MAXSIZE;
}

//2.初始化
Queue initQueue(void) {
	Queue q;
	q.queue = (ElementType*)malloc(MAXSIZE * sizeof(ElementType));
	if (!q.queue) { 
		printf("初始化分配空间失败！");
	}
	q.front = 0;
	q.rear = 0;
	return q;
}

//3.入队
void enQueue(Queue* q, ElementType e) {
	if (isFull(q)) {
		printf("队列已满，入队失败！\n");
		return;
	}
	q->queue[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}

//4.出队
void deQueue(Queue* q,ElementType *e) {
	if (isEmpty(&q))
	{
		printf("队列为空！出队失败\n");
		return;
	}
	*e = q->queue[q->front];
	printf("现在出队的是：%d\n", *e);
	q->front = (q->front + 1) % MAXSIZE;
}

//5.显示队首元素
void showFront(Queue* q) {
	if (isEmpty(&q))
	{
		printf("队列为空！\n");
		return ;
	}
	printf("现在队首是%d\n", q->queue[q->front]);
}
//6.销毁队列
void destoryQueue(Queue* q) {
	if(q->queue)
		free(q->queue);
	q->queue = NULL;
	q->front = 0;
	q->rear = 0;
}

//7.判空
int isEmpty(Queue* q) {
	return q->front == q->rear;
}

//8.队满
int isFull(Queue* q) {
	return (q->rear + 1) % MAXSIZE == q->front;
}
