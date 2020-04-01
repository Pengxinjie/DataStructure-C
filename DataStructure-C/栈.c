//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<string.h>
//
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
//_Bool isEmpty(void) {
//	if (g_pHead->pNext == NULL)
//	{
//		printf("链表为空！");
//		return true;
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
//
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