//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include "����2.h"
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
//		printf("1.���Ԫ�أ���ӣ�\n2.ɾ��Ԫ�أ����ӣ�\n3.��ʾ����Ԫ��\n4.���ٶ��в��˳�������\n");
//		printf("��������Ҫ���еĶ��в�����");
//		scanf("%d", &temp);
//		switch (temp) {
//		case 1:
//			printf("������Ҫ��ӵ�Ԫ�أ�");
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
//			printf("������Ч��\n");
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
//	// ����һ���ն���Q
//	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
//		return;
//	Q.front->next = NULL;
//}
//
//void destroyQueue(LinkQueue& Q)
//{ // ���ٶ���Q(���ۿշ����)
//	while (Q.front) {
//		Q.rear = Q.front->next;
//		free(Q.front);
//		Q.front = Q.rear;
//	}
//}
//
//void enQueue(LinkQueue& Q, ElemType e)
//{ // ����Ԫ��eΪQ���µĶ�βԪ��
//	QueuePtr p;
//	if (!(p = (QueuePtr)malloc(sizeof(QNode)))) //�洢����ʧ��
//		return;
//	p->data = e;
//	p->next = NULL;
//	Q.rear->next = p;
//	Q.rear = p;
//}
//
//void deQueue(LinkQueue& Q, ElemType& e)
//{ // �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
//// ���򷵻�ERROR
//	QueuePtr p;
//	if (Q.front == Q.rear) {
//		printf("���пգ�����ʧ�ܣ�\n");
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
//{ // �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK��
//// ���򷵻�ERROR
//	QueuePtr p;
//	if (Q.front == Q.rear)
//	{
//		printf("���пգ�\n");
//		return;
//	}
//	p = Q.front->next;
//	e = p->data;
//	printf("���ڶ���Ԫ���ǣ�%d\n", e);
//}