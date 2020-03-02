#include<stdio.h>
#include<stdlib.h>

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

//β����
void AddListTail(ElementType value)
{
	struct Node*pTemp=CreatNode(value);
	g_pEnd->pNext = pTemp;
	g_pEnd = pTemp;
}

//ͷ����
void AddListHead(ElementType value)
{
	struct Node* pTemp = CreatNode(value);
	//����
	pTemp->pNext = g_pHead->pNext;
	g_pHead->pNext = pTemp;
}

//������ͷ��ʼ��
void InitListHead(void)
{
	g_pHead = (struct Node*)malloc(sizeof(struct Node));
	g_pHead->pNext = NULL;
	g_pEnd = g_pHead;
}

//��������
void PrintList(void)
{
	if (g_pHead->pNext == NULL)
	{
		printf("����Ϊ�գ�");
		return;
	}
	//��ʱָ��
	struct Node* temp = g_pHead;
	//ֱ��û����һ�����
	while (temp->pNext != NULL)
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
		if (pTemp == NULL)
		{
			printf("�޴˽ڵ㣡\n");
			return NULL;
		}
	}
	return pTemp;
}

//����λ�����ӽڵ�
void AddNodeIndex(int index, ElementType value)
{
	struct Node* pTemp = g_pHead->pNext;
	if (pTemp->pNext == NULL)
	{
		printf("�������޽ڵ㣡");
		return;
	}

	//�ҵ�Ҫ�����λ��
	pTemp = SelectNode(index);

	if (pTemp != NULL)
	{
		struct Node* pt = CreatNode(value);
		if (pTemp->pNext == NULL) {
			AddListTail(value);
		}
		else {
			//�������
			pt->pNext = pTemp->pNext;
			pTemp->pNext = pt;
		}
	}
}

//ɾ���׽��
void DelFirstNode(void) {
	if (NULL == g_pHead->pNext) {
		printf("����Ϊ�գ�");
	}
	else {
		struct Node* pTemp = g_pHead->pNext;
		g_pHead->pNext = g_pHead->pNext->pNext;
		//�ͷŽ��
		free(pTemp);
	}
}

//ɾ��β���
void DelTailNode(void) {
	if (NULL == g_pHead->pNext) {
		printf("����Ϊ�գ�");
		return;
	}
	//ֻ��һ�����
	if (g_pHead->pNext == g_pEnd) {
		free(g_pEnd);
		g_pHead->pNext = NULL;
		g_pEnd = g_pHead;
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
		free(g_pEnd);
		g_pEnd = pTemp;
		g_pEnd->pNext = NULL;
	}

}

//ɾ��ָ�����
void DelNodeIndex(int a) {
	struct Node* ptmp = g_pHead;
	struct Node* k;
	if (NULL == g_pHead->pNext)
	{
		printf("����������ɾ����\n");
		return;
	}
	if (g_pHead == g_pEnd)
	{
		free(g_pHead);
		g_pHead = NULL;
		g_pEnd = NULL;
		return;
	}

	for (int i = 1; i < a; i++)
		ptmp = ptmp->pNext;
	k = ptmp->pNext;
	ptmp->pNext = ptmp->pNext->pNext;
	free(k);
}

//�������
void FreeList()
{
	//��¼�ڵ㣬��ֹͷ���ƻ������ڴ�
	struct Node* pTemp = g_pHead;

	while (pTemp)
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

	//β����
	AddListTail(1);
	AddListTail(2);
	AddListTail(3);
	AddListTail(4);
	AddListTail(5);

	//ͷ����
	AddListHead(100);

	//������������
	PrintList();

	//����λ�����ӽڵ�
	AddNodeIndex(1, 99);
	
	//�ٱ�������
	PrintList();

	//ɾ���׽��
	DelFirstNode();

	//����
	PrintList();

	//ɾ��β���
	DelTailNode();

	//����
	PrintList();

	//ɾ������λ�õĽ��
	DelNodeIndex(1);

	//����
	PrintList();

	//�ͷ���������
	FreeList();

	//over

	system("pause");
	return 0;
}