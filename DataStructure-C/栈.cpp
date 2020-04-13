#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//typedef char ElementType;
//
////�������ṹ��
//struct Node {
//	ElementType a;
//	struct Node* pNext;
//};
//
//struct Node* g_pHead = NULL;//ͷָ��
//
////����һ���ڵ�
//struct Node* CreatNode(ElementType value)
//{
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	//�ڵ��Ա��ֵ
//	pTemp->a = value;
//	pTemp->pNext = NULL;
//
//}
//
////��ջ
//void push(ElementType value)
//{
//	struct Node* pTemp = CreatNode(value);
//	//����
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
//
////ջ��ͷ��ʼ��
//void InitStackHead(void)
//{
//	g_pHead = (struct Node*)malloc(sizeof(struct Node));
//	g_pHead->pNext = NULL;
//}
//
////�п�
//int isEmpty(void) {
//	if (g_pHead->pNext == NULL)
//	{
//		printf("����Ϊ�գ�");
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
////��ջ
//ElementType pop(void) {
//	//�п�
//	if (true == isEmpty()) {
//		return;
//	}
//	else {
//		struct Node* pTemp = g_pHead->pNext;
//		ElementType elem = pTemp->a;
//		g_pHead->pNext = g_pHead->pNext->pNext;
//		//�ͷŽ��
//		free(pTemp);
//		return elem;
//	}
//}
//
////���ջ������ÿһ����㣬��һ�ͷ�
//void FreeList()
//{
//	//��¼�ڵ㣬��ֹͷ���ƻ������ڴ�
//	struct Node* pTemp = g_pHead;
//
//	while (pTemp)
//	{
//		struct Node* pt = pTemp;//��סpTemp��ֵ
//		pTemp = pTemp->pNext;//pTempָ����һ���ڵ�
//		free(pt);
//	}
//
//	//ͷβ��գ���һ�β������´�������
//	g_pHead = NULL;
//}

//int main1(void)
//{
//	//��ʼ��ջ
//	InitStackHead();
//
//	//�Ƿ�,Ĭ����,Լ��:��ֻ��һ����ĸҲ�ǻ���
//	bool flag = true;
//
//	char str[20] = "";
//	printf("������һ���ַ�����");
//	scanf("%s", str);
//
//	//��һ���ַ���ջ
//	int i = 0;
//	for (; i < strlen(str) / 2; i++)
//	{
//		push(str[i]);
//	}
//
//	if (strlen(str) % 2 != 0)
//	{
//		//����ַ������������������м�ֵ
//		i++;
//	}
//
//	while (i < strlen(str))
//	{
//		if (str[i] != pop())
//		{
//			flag = false;
//		}
//		i++;
//	}
//
//	if (flag) {
//		printf("%s�ǻ��ġ�\n", str);
//	}
//	else {
//
//		printf("%s���ǻ��ġ�\n", str);
//	}
//
//	system("pause");
//	return 0;
//}

typedef char ElemType;
typedef struct node {
	ElemType data;
	struct node* next;
} LinkStack;

void InitStack(LinkStack*& top)
{
	top = NULL;
}

void DestroyStack(LinkStack*& top)
{
	LinkStack* pre = top, * p;
	if (pre == NULL) return; //���ǿ�ջ�����
	p = pre->next;
	while (p != NULL)
	{
		free(pre); //�ͷ�pre���
		pre = p;
		p = p->next; //pre��pͬ������
	}
	free(pre); //�ͷ�β���
}

int Push(LinkStack*& top, ElemType x)
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x; //�������p���ڴ��x
	p->next = top; //����p�����Ϊջ�����
	top = p;
	return 1;
}

int Pop(LinkStack*& top, ElemType& x)
{
	LinkStack* p;
	if (top == NULL) //ջ��,���������0
		return 0;
	else //ջ����ʱ��ջԪ��x������1
	{
		p = top; //pָ��ջ�����
		x = p->data; //ȡջ��Ԫ��x
		top = p->next; //ɾ�����p
		free(p); //�ͷ�p���
		return 1;
	}
}

int GetTop(LinkStack* top, ElemType& x)
{
	if (top == NULL) //ջ��,�����ʱ����0
		return 0;
	else //ջ����,ȡջ��Ԫ��x������1
	{
		x = top->data;
		return 1;
	}
}

int StackEmpty(LinkStack* top)
{
	if (top == NULL)
		return 1;
	else
		return 0;
}