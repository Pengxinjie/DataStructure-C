#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType value;//����
	struct Node* pre;//ǰ��
	struct Node* next;//���
}Node;

Node* Search(int index);

Node* pHead = NULL;//ͷָ��
Node* pEnd = NULL;//βָ��

//��ʼ������
void Init(void) {
	//��ʼ��ͷ���
	pHead = (Node*)malloc(sizeof(Node));
	pHead->next = NULL;
	pHead->pre = NULL;
	pEnd = pHead;
}

//���
int Length(void) {
	if (pHead->next == NULL) {
		return 0;
	}
	int sum = 0;

	Node* temp = pHead->next;
	while (temp != NULL) {
		sum++;
		temp = temp->next;
	}
}

//����ͷ���Ԫ�أ�
void AddValueHead(ElementType value) {
	//����һ�����
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;
	if (pHead->next == NULL) {
		pHead->next = node;
		node->pre = pHead;
		node->next = NULL;
		pEnd = node;
	}
	else {
		node->pre = pHead;
		node->next = pHead->next;
		pHead->next->pre = node;
		pHead->next = node;
	}
}

//����β���Ԫ�أ�
void AddValueTail(ElementType value) {
	//����һ�����
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	pEnd->next = node;
	node->pre = pEnd;
	pEnd = node;
	pEnd->next = NULL;
}

//��������λ��index-��ӣ�
void AddValue(ElementType value,int index) {
	//����һ�����
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	if (index == Length()) {
		AddValueTail(value);
		return;
	}

	Node* temp = Search(index);
	//�ҵ�index��-->�������
	node->next = temp;
	temp->pre->next = node;
	node->pre = temp->pre;
	temp->pre = node;
}

//ɾ��ɾ��indexλ�õĽ�㣩
void DeleteIndexNode(int index) {
	Node* temp = Search(index);
	//�ҵ�index��
	//���ж�index�ǲ������һ�����
	if (temp->next == NULL) {
		temp->pre->next = NULL;
		temp->pre = NULL;
		return;
	}

	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
}

//�ģ��޸�indexλ�õĽ���ֵΪvalue��
void Change(int index, ElementType value) {
	Node* temp = Search(index);
	temp->value = value;
}

//�飨����indexλ�õĽ�㣬�ҵ����ظý���ָ�룬���򷵻�NULL��
Node* Search(int index) {
	if (pHead->next == NULL)
	{
		printf("����Ϊ�գ�");
		return NULL;
	}
	//����ָ���ҵ�indexλ�õĽ��
	Node* temp = pHead;

	while (index-- > 0 && temp != NULL) {
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("��Ч��index��");
		return NULL;
	}
	return temp;
}

//����������������������ݣ�
void PrintDoubleList(void) {
	if (pHead->next == NULL) {
		printf("����Ϊ�գ�");
		return;
	}
	Node* temp = pHead->next;

	while (temp != NULL)
	{
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

//������գ�����ÿһ����㣬��һ�ͷ�
void FreeList()
{
	//��¼�ڵ㣬��ֹͷ���ƻ������ڴ�
	struct Node* pTemp = pHead;

	while (pTemp)
	{
		struct Node* pt = pTemp;//��סpTemp��ֵ
		pTemp = pTemp->next;//pTempָ����һ���ڵ�
		free(pt);
	}

	//ͷβ��գ���һ�β������´�������
	pHead = NULL;
	pEnd = NULL;
}


int main1(void) {
	//��ʼ������
	Init();

	//����  ͷ���
	AddValueHead(12);
	AddValueHead(13);

	//����  β���
	AddValueTail(456);

	//����
	PrintDoubleList();

	//����  ����λ�����
	AddValue(100, 1);


	//����  ����λ�����
	AddValue(99, 3);

	//����
	PrintDoubleList();

	//ɾ��  ����λ��ɾ��
	DeleteIndexNode(4);

	//����
	PrintDoubleList();

	//�ģ�  3λ��Ԫ�ص�ֵΪ9999
	Change(3, 9999);

	//����
	PrintDoubleList();

	//�飺  �鿴4��Ԫ�ص�ֵ
	Node* temp = Search(4);
	printf("%d\n", temp->value);

	//�ͷ�����
	FreeList();

	//over

	return 0;
}
