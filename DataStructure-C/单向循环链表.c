#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElementType;

//�������ṹ��
struct Node {
	ElementType a;
	struct Node* pNext;
};

struct Node* g_pHead = NULL;//ͷָ��
struct Node* g_pEnd = NULL;//βָ��

//����һ���ڵ�
struct Node* CreatNode(ElementType value)
{
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//�ڵ��Ա��ֵ
	pTemp->a = value;
	pTemp->pNext = NULL;
}

//β���
void AddListTail(ElementType value)
{
	struct Node*pTemp=CreatNode(value);
	g_pEnd->pNext = pTemp;
	g_pEnd = pTemp;
	g_pEnd->pNext = g_pHead;
}

//ͷ���
void AddListHead(ElementType value)
{
	struct Node* pTemp = CreatNode(value);
	//����->�������
	pTemp->pNext = g_pHead->pNext;
	g_pHead->pNext = pTemp;
}

//�����ͷ��ʼ��
void InitListHead(void)
{
	g_pHead = (struct Node*)malloc(sizeof(struct Node));
	g_pEnd = g_pHead;
	g_pEnd->pNext = g_pEnd;
}

//�п�
_Bool isEmpty(void) {
	if (g_pEnd == g_pHead)
	{
		printf("����Ϊ�գ�");
		return true;
	}
}

//��������
void PrintList(void)
{
	if (isEmpty() == true)
		return;
	//��ʱָ��
	struct Node* temp = g_pHead;
	//ֱ��û����һ�����
	while (temp->pNext != g_pHead)
	{
		printf("%d  ", temp->pNext->a);
		//ָ����һ��
		temp = temp->pNext;
	}
	printf("\n");
}

//��������λ�ýڵ�
struct Node* SelectNode(int index)
{
	struct Node* pTemp = g_pHead;
	for (int i = 1; i < index; i++)
	{
		pTemp = pTemp->pNext;
		if (pTemp == g_pHead)
		{
			printf("�޴˽ڵ㣡\n");
			return NULL;
		}
	}
	return pTemp;
}

//����λ����ӽڵ�
void AddNodeIndex(int index, ElementType value)
{
	struct Node* pTemp = g_pHead->pNext;
	if (pTemp == g_pEnd)
	{
		AddListHead(value);
		return;
	}

	//�ҵ�Ҫ�����λ��
	pTemp = SelectNode(index);

	if (pTemp != NULL)
	{
		if (pTemp->pNext == g_pHead) {
			AddListTail(value);
			return;
		}
		struct Node* pt = CreatNode(value);
		//�������
		pt->pNext = pTemp->pNext;
		pTemp->pNext = pt;
	}
}

//ɾ���׽��
void DelFirstNode(void) {
	//�п�
	if (true == isEmpty()) {
		return;
	}
	else {
		struct Node* pTemp = g_pHead->pNext;
		if (pTemp->pNext->pNext == NULL) {
			g_pHead->pNext = g_pEnd;
			free(pTemp);
			return;
		}
		g_pHead->pNext = g_pHead->pNext->pNext;
		//�ͷŽ��
		free(pTemp);
	}
}

//ɾ��β���
void DelTailNode(void) {
	//�п�
	if (true == isEmpty()) {
		return;
	}
	struct Node* pTemp = g_pHead->pNext;
	//ֻ��һ�����
	if (g_pHead->pNext == g_pEnd) {
		g_pHead->pNext = g_pEnd;
		free(pTemp);
		return;
	}
	else {
		//�ҵ�β������һ��
		struct Node* pTemp = g_pHead->pNext;
		while (pTemp->pNext != NULL)
		{
			if (g_pEnd == pTemp->pNext)
				break;
			pTemp = pTemp->pNext;
		}
		//������β����ǰһ�����
		free(pTemp->pNext);
		pTemp->pNext = g_pHead;
		g_pEnd = pTemp;
	}
}

//ɾ��ָ�����
void DelNodeIndex(int index) {
	struct Node* ptmp = g_pHead;
	struct Node* k;//��ʱ�洢
	//�п�
	if (true == isEmpty()) {
		return;
	}
	//ֻ��һ�����
	if (g_pHead == g_pEnd)
	{
		DelFirstNode();
	}

	//�ҵ�Ŀ�����ǰһ�����
	for (int i = 1; i < index; i++)
		ptmp = ptmp->pNext;
	k = ptmp->pNext;
	if (k->pNext == g_pHead) {
		DelTailNode();
		return;
	}
	//Ŀ�����ǰһ�����ָ��Ŀ����ĺ�һ�����
	ptmp->pNext = ptmp->pNext->pNext;
	free(k);
}

//������գ�����ÿһ����㣬��һ�ͷ�
void Freelist()
{
	//��¼�ڵ㣬��ֹͷ���ƻ������ڴ�
	struct Node* pTemp = g_pHead->pNext;

	while (pTemp != g_pHead)
	{
		struct Node* pt = pTemp;//��סpTemp��ֵ
		pTemp = pTemp->pNext;//pTempָ����һ���ڵ�
		free(pt);
	}

	//ͷβ��գ���һ�β������´�������
	g_pHead = NULL;
	g_pEnd = NULL;
}

int main(void)
{
	//��ʼ��
	InitListHead();

	//β���
	AddListTail(1);
	AddListTail(2);
	AddListTail(3);
	AddListTail(4);
	AddListTail(5);

	//����
	PrintList();//�����1 2 3 4 5

	//ͷ���
	AddListHead(100);

	//������������
	PrintList();//�����100 1 2 3 4 5

	//����λ����ӽڵ�
	AddNodeIndex(1, 99);
	
	//�ٱ�������
	PrintList();//�����99 100 1 2 3 4 5

	//ɾ���׽��
	DelFirstNode();

	//����
	PrintList();//�����100 1 2 3 4 5

	//ɾ��β���
	DelTailNode();

	//����
	PrintList();//�����100 1 2 3 4

	//ɾ������λ�õĽ��
	DelNodeIndex(1);

	//����
	PrintList();//�����1 2 3 4

	//�ͷ���������
	Freelist();

	//over

	system("pause");
	return 0;
}