//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<string.h>
//
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
//_Bool isEmpty(void) {
//	if (g_pHead->pNext == NULL)
//	{
//		printf("����Ϊ�գ�");
//		return true;
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
//
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