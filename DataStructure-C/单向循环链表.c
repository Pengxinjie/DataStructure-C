#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElementType;

//创建结点结构体
struct Node {
	ElementType a;
	struct Node* pNext;
};

struct Node* g_pHead = NULL;//头指针
struct Node* g_pEnd = NULL;//尾指针

//创建一个节点
struct Node* CreatNode(ElementType value)
{
	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
	//节点成员赋值
	pTemp->a = value;
	pTemp->pNext = NULL;
}

//尾添加
void AddListTail(ElementType value)
{
	struct Node*pTemp=CreatNode(value);
	g_pEnd->pNext = pTemp;
	g_pEnd = pTemp;
	g_pEnd->pNext = g_pHead;
}

//头添加
void AddListHead(ElementType value)
{
	struct Node* pTemp = CreatNode(value);
	//连接->先连后断
	pTemp->pNext = g_pHead->pNext;
	g_pHead->pNext = pTemp;
}

//链表空头初始化
void InitListHead(void)
{
	g_pHead = (struct Node*)malloc(sizeof(struct Node));
	g_pEnd = g_pHead;
	g_pEnd->pNext = g_pEnd;
}

//判空
_Bool isEmpty(void) {
	if (g_pEnd == g_pHead)
	{
		printf("链表为空！");
		return true;
	}
}

//遍历链表
void PrintList(void)
{
	if (isEmpty() == true)
		return;
	//临时指针
	struct Node* temp = g_pHead;
	//直到没有下一个结点
	while (temp->pNext != g_pHead)
	{
		printf("%d  ", temp->pNext->a);
		//指向下一个
		temp = temp->pNext;
	}
	printf("\n");
}

//查找任意位置节点
struct Node* SelectNode(int index)
{
	struct Node* pTemp = g_pHead;
	for (int i = 1; i < index; i++)
	{
		pTemp = pTemp->pNext;
		if (pTemp == g_pHead)
		{
			printf("无此节点！\n");
			return NULL;
		}
	}
	return pTemp;
}

//任意位置添加节点
void AddNodeIndex(int index, ElementType value)
{
	struct Node* pTemp = g_pHead->pNext;
	if (pTemp == g_pEnd)
	{
		AddListHead(value);
		return;
	}

	//找到要插入的位置
	pTemp = SelectNode(index);

	if (pTemp != NULL)
	{
		if (pTemp->pNext == g_pHead) {
			AddListTail(value);
			return;
		}
		struct Node* pt = CreatNode(value);
		//先连后断
		pt->pNext = pTemp->pNext;
		pTemp->pNext = pt;
	}
}

//删除首结点
void DelFirstNode(void) {
	//判空
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
		//释放结点
		free(pTemp);
	}
}

//删除尾结点
void DelTailNode(void) {
	//判空
	if (true == isEmpty()) {
		return;
	}
	struct Node* pTemp = g_pHead->pNext;
	//只有一个结点
	if (g_pHead->pNext == g_pEnd) {
		g_pHead->pNext = g_pEnd;
		free(pTemp);
		return;
	}
	else {
		//找到尾结点的上一个
		struct Node* pTemp = g_pHead->pNext;
		while (pTemp->pNext != NULL)
		{
			if (g_pEnd == pTemp->pNext)
				break;
			pTemp = pTemp->pNext;
		}
		//现在是尾结点的前一个结点
		free(pTemp->pNext);
		pTemp->pNext = g_pHead;
		g_pEnd = pTemp;
	}
}

//删除指定结点
void DelNodeIndex(int index) {
	struct Node* ptmp = g_pHead;
	struct Node* k;//临时存储
	//判空
	if (true == isEmpty()) {
		return;
	}
	//只有一个结点
	if (g_pHead == g_pEnd)
	{
		DelFirstNode();
	}

	//找到目标结点的前一个结点
	for (int i = 1; i < index; i++)
		ptmp = ptmp->pNext;
	k = ptmp->pNext;
	if (k->pNext == g_pHead) {
		DelTailNode();
		return;
	}
	//目标结点的前一个结点指向目标结点的后一个结点
	ptmp->pNext = ptmp->pNext->pNext;
	free(k);
}

//链表清空：遍历每一个结点，逐一释放
void Freelist()
{
	//记录节点，防止头被破坏，丢内存
	struct Node* pTemp = g_pHead->pNext;

	while (pTemp != g_pHead)
	{
		struct Node* pt = pTemp;//记住pTemp的值
		pTemp = pTemp->pNext;//pTemp指向下一个节点
		free(pt);
	}

	//头尾清空，下一次才能重新创建链表
	g_pHead = NULL;
	g_pEnd = NULL;
}

int main(void)
{
	//初始化
	InitListHead();

	//尾添加
	AddListTail(1);
	AddListTail(2);
	AddListTail(3);
	AddListTail(4);
	AddListTail(5);

	//遍历
	PrintList();//结果：1 2 3 4 5

	//头添加
	AddListHead(100);

	//遍历链表瞧瞧
	PrintList();//结果：100 1 2 3 4 5

	//任意位置添加节点
	AddNodeIndex(1, 99);
	
	//再遍历瞧瞧
	PrintList();//结果：99 100 1 2 3 4 5

	//删除首结点
	DelFirstNode();

	//遍历
	PrintList();//结果：100 1 2 3 4 5

	//删除尾结点
	DelTailNode();

	//遍历
	PrintList();//结果：100 1 2 3 4

	//删除任意位置的结点
	DelNodeIndex(1);

	//遍历
	PrintList();//结果：1 2 3 4

	//释放整个链表
	Freelist();

	//over

	system("pause");
	return 0;
}