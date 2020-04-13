#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//typedef char ElementType;
//
////创建结点结构体
//struct Node {
//	ElementType a;
//	struct Node* pNext;
//};
//
//struct Node* g_pHead = NULL;//头指针
//
////创建一个节点
//struct Node* CreatNode(ElementType value)
//{
//	struct Node* pTemp = (struct Node*)malloc(sizeof(struct Node));
//	//节点成员赋值
//	pTemp->a = value;
//	pTemp->pNext = NULL;
//
//}
//
////入栈
//void push(ElementType value)
//{
//	struct Node* pTemp = CreatNode(value);
//	//连接
//	pTemp->pNext = g_pHead->pNext;
//	g_pHead->pNext = pTemp;
//}
//
////栈空头初始化
//void InitStackHead(void)
//{
//	g_pHead = (struct Node*)malloc(sizeof(struct Node));
//	g_pHead->pNext = NULL;
//}
//
////判空
//int isEmpty(void) {
//	if (g_pHead->pNext == NULL)
//	{
//		printf("链表为空！");
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
////出栈
//ElementType pop(void) {
//	//判空
//	if (true == isEmpty()) {
//		return;
//	}
//	else {
//		struct Node* pTemp = g_pHead->pNext;
//		ElementType elem = pTemp->a;
//		g_pHead->pNext = g_pHead->pNext->pNext;
//		//释放结点
//		free(pTemp);
//		return elem;
//	}
//}
//
////清空栈：遍历每一个结点，逐一释放
//void FreeList()
//{
//	//记录节点，防止头被破坏，丢内存
//	struct Node* pTemp = g_pHead;
//
//	while (pTemp)
//	{
//		struct Node* pt = pTemp;//记住pTemp的值
//		pTemp = pTemp->pNext;//pTemp指向下一个节点
//		free(pt);
//	}
//
//	//头尾清空，下一次才能重新创建链表
//	g_pHead = NULL;
//}

//int main1(void)
//{
//	//初始化栈
//	InitStackHead();
//
//	//是否,默认是,约定:若只有一个字母也是回文
//	bool flag = true;
//
//	char str[20] = "";
//	printf("请输入一个字符串：");
//	scanf("%s", str);
//
//	//将一半字符入栈
//	int i = 0;
//	for (; i < strlen(str) / 2; i++)
//	{
//		push(str[i]);
//	}
//
//	if (strlen(str) % 2 != 0)
//	{
//		//如果字符个数是奇数，跳过中间值
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
//		printf("%s是回文。\n", str);
//	}
//	else {
//
//		printf("%s不是回文。\n", str);
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
	if (pre == NULL) return; //考虑空栈的情况
	p = pre->next;
	while (p != NULL)
	{
		free(pre); //释放pre结点
		pre = p;
		p = p->next; //pre、p同步后移
	}
	free(pre); //释放尾结点
}

int Push(LinkStack*& top, ElemType x)
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x; //创建结点p用于存放x
	p->next = top; //插入p结点作为栈顶结点
	top = p;
	return 1;
}

int Pop(LinkStack*& top, ElemType& x)
{
	LinkStack* p;
	if (top == NULL) //栈空,下溢出返回0
		return 0;
	else //栈不空时出栈元素x并返回1
	{
		p = top; //p指向栈顶结点
		x = p->data; //取栈顶元素x
		top = p->next; //删除结点p
		free(p); //释放p结点
		return 1;
	}
}

int GetTop(LinkStack* top, ElemType& x)
{
	if (top == NULL) //栈空,下溢出时返回0
		return 0;
	else //栈不空,取栈顶元素x并返回1
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