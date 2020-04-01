//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include "队列2.h"
//
//int main()
//{
//	LinkQueue q;
//	initQueue(q);	
//	int boo = 1,
//		te;
//	while (boo)
//	{
//		int temp;
//		printf("1.添加元素（入队）\n2.删除元素（出队）\n3.显示队首元素\n4.销毁队列并退出本程序\n");
//		printf("请输入您要进行的队列操作：");
//		scanf("%d", &temp);
//		switch (temp) {
//		case 1:
//			printf("请输入要入队的元素：");
//			int value;
//			scanf("%d", &value);
//			enQueue(q, value);
//			break;
//		case 2:
//			deQueue(q,te);
//			break;
//		case 3:
//			showFront(q,te);
//			break;
//		case 4:
//			destroyQueue(q);
//			boo = 0;
//			break;
//		default:
//			printf("输入无效！\n");
//		}
//	
//	}
//
//	system("pause");
//	return 0;
//}
//
//void initQueue(LinkQueue& Q)
//{
//	// 构造一个空队列Q
//	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
//		return;
//	Q.front->next = NULL;
//}
//
//void destroyQueue(LinkQueue& Q)
//{ // 销毁队列Q(无论空否均可)
//	while (Q.front) {
//		Q.rear = Q.front->next;
//		free(Q.front);
//		Q.front = Q.rear;
//	}
//}
//
//void enQueue(LinkQueue& Q, ElemType e)
//{ // 插入元素e为Q的新的队尾元素
//	QueuePtr p;
//	if (!(p = (QueuePtr)malloc(sizeof(QNode)))) //存储分配失败
//		return;
//	p->data = e;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//}
//
//void deQueue(LinkQueue& Q, ElemType& e)
//{ // 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，
//// 否则返回ERROR
//	QueuePtr p;
//	if (Q.front == Q.rear) {
//		printf("队列空，出队失败！\n");
//		return;
//	}
//	p = Q.front->next;
//	e = p->data;
//	Q.front->next = p->next;
//	if (Q.rear == p)
//		Q.rear = Q.front;
//	free(p);
//	return;
//}
//
//void showFront(LinkQueue Q, ElemType& e)
//{ // 若队列不空，则用e返回Q的队头元素，并返回OK，
//// 否则返回ERROR
//	QueuePtr p;
//	if (Q.front == Q.rear)
//	{
//		printf("队列空！\n");
//		return;
//	}
//	p = Q.front->next;
//	e = p->data;
//	printf("现在队首元素是：%d\n", e);
//}