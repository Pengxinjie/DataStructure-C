#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType value;//数据
	struct Node* pre;//前驱
	struct Node* next;//后继
}Node;

Node* Search(int index);

Node* pHead = NULL;//头指针
Node* pEnd = NULL;//尾指针

//初始化链表
void Init(void) {
	//初始化头结点
	pHead = (Node*)malloc(sizeof(Node));
	pHead->next = NULL;
	pHead->pre = NULL;
	pEnd = pHead;
}

//求表长
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

//增（头添加元素）
void AddValueHead(ElementType value) {
	//创建一个结点
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

//增（尾添加元素）
void AddValueTail(ElementType value) {
	//创建一个结点
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	pEnd->next = node;
	node->pre = pEnd;
	pEnd = node;
	pEnd->next = NULL;
}

//增（任意位置index-添加）
void AddValue(ElementType value,int index) {
	//创建一个结点
	Node* node = (Node*)malloc(sizeof(Node));
	node->value = value;

	if (index == Length()) {
		AddValueTail(value);
		return;
	}

	Node* temp = Search(index);
	//找到index了-->先连后断
	node->next = temp;
	temp->pre->next = node;
	node->pre = temp->pre;
	temp->pre = node;
}

//删（删除index位置的结点）
void DeleteIndexNode(int index) {
	Node* temp = Search(index);
	//找到index了
	//先判断index是不是最后一个结点
	if (temp->next == NULL) {
		temp->pre->next = NULL;
		temp->pre = NULL;
		return;
	}

	temp->pre->next = temp->next;
	temp->next->pre = temp->pre;
}

//改（修改index位置的结点的值为value）
void Change(int index, ElementType value) {
	Node* temp = Search(index);
	temp->value = value;
}

//查（查找index位置的结点，找到返回该结点的指针，否则返回NULL）
Node* Search(int index) {
	if (pHead->next == NULL)
	{
		printf("链表为空！");
		return NULL;
	}
	//辅助指针找到index位置的结点
	Node* temp = pHead;

	while (index-- > 0 && temp != NULL) {
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("无效的index！");
		return NULL;
	}
	return temp;
}

//遍历（遍历遍历并输出数据）
void PrintDoubleList(void) {
	if (pHead->next == NULL) {
		printf("链表为空！");
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

//链表清空：遍历每一个结点，逐一释放
void FreeList()
{
	//记录节点，防止头被破坏，丢内存
	struct Node* pTemp = pHead;

	while (pTemp)
	{
		struct Node* pt = pTemp;//记住pTemp的值
		pTemp = pTemp->next;//pTemp指向下一个节点
		free(pt);
	}

	//头尾清空，下一次才能重新创建链表
	pHead = NULL;
	pEnd = NULL;
}


int main1(void) {
	//初始化链表
	Init();

	//增：  头添加
	AddValueHead(12);
	AddValueHead(13);

	//增：  尾添加
	AddValueTail(456);

	//遍历
	PrintDoubleList();

	//增：  任意位置添加
	AddValue(100, 1);


	//增：  任意位置添加
	AddValue(99, 3);

	//遍历
	PrintDoubleList();

	//删：  任意位置删除
	DeleteIndexNode(4);

	//遍历
	PrintDoubleList();

	//改：  3位置元素的值为9999
	Change(3, 9999);

	//遍历
	PrintDoubleList();

	//查：  查看4号元素的值
	Node* temp = Search(4);
	printf("%d\n", temp->value);

	//释放链表
	FreeList();

	//over

	return 0;
}
