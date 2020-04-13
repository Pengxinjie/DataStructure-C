//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//typedef char TELemType;
//typedef struct BiTNode {
//	TELemType data;
//	BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;
//
////------------------------栈------------------------
//typedef BiTree ElemType;
//typedef struct node {
//	ElemType data;
//	struct node* next;
//} LinkStack;
//
//void InitStack(LinkStack*& top)
//{
//	top = NULL;
//}
//
//void DestroyStack(LinkStack*& top)
//{
//	LinkStack* pre = top, * p;
//	if (pre == NULL) return; //考虑空栈的情况
//	p = pre->next;
//	while (p != NULL)
//	{
//		free(pre); //释放pre结点
//		pre = p;
//		p = p->next; //pre、p同步后移
//	}
//	free(pre); //释放尾结点
//}
//
//int Push(LinkStack*& top, ElemType x)
//{
//	LinkStack* p;
//	p = (LinkStack*)malloc(sizeof(LinkStack));
//	p->data = x; //创建结点p用于存放x
//	p->next = top; //插入p结点作为栈顶结点
//	top = p;
//	return 1;
//}
//
//int Pop(LinkStack*& top, ElemType& x)
//{
//	LinkStack* p;
//	if (top == NULL) //栈空,下溢出返回0
//		return 0;
//	else //栈不空时出栈元素x并返回1
//	{
//		p = top; //p指向栈顶结点
//		x = p->data; //取栈顶元素x
//		top = p->next; //删除结点p
//		free(p); //释放p结点
//		return 1;
//	}
//}
//
//int GetTop(LinkStack* top, ElemType& x)
//{
//	if (top == NULL) //栈空,下溢出时返回0
//		return 0;
//	else //栈不空,取栈顶元素x并返回1
//	{
//		x = top->data;
//		return 1;
//	}
//}
//
//int StackEmpty(LinkStack* top)
//{
//	if (top == NULL)
//		return 1;
//	else
//		return 0;
//}
////------------------------栈------------------------
//
//
////二叉树的递归创建
////须添加虚节点‘#’
//void CreatBiTree(BiTree &T) {
//	TELemType ch;
//	scanf("%c", &ch);
//
//	if (ch == '#')
//		T = NULL;
//	else {
//		T = (BiTree)malloc(sizeof(BiTNode));
//		if (!T)
//			exit(-1);
//		T->data = ch;
//		CreatBiTree(T->lchild);
//		CreatBiTree(T->rchild);
//	}
//}
//
//
///*销毁二叉树*/
//void DestroyBTree(BiTNode* bt) {
//	if (bt == NULL) {
//		return;
//	}
//	else
//	{
//		DestroyBTree(bt->lchild);
//		DestroyBTree(bt->rchild);
//		free(bt);
//	}
//}
//
////二叉树的非递归遍历-->利用栈
//void PreOrder1(BiTNode* b)
//{
//	BiTNode* p;
//	LinkStack* st;
//	InitStack(st);
//	if (b != NULL) {
//		Push(st, b);
//		while (!StackEmpty(st))
//		{
//			Pop(st, p);
//			printf("%c", p->data);
//			if (p->rchild != NULL) {
//				Push(st, p->rchild);
//			}
//			if (p->lchild != NULL)
//				Push(st, p->lchild);
//		}
//	}
//}
//
//void PreOrder2(BiTNode* b) {
//	BiTNode* p;
//	LinkStack* st;
//	InitStack(st);
//	p = b;
//	while (!StackEmpty(st) || p != NULL) {
//		while (p != NULL) {
//			printf("%c", p->data);
//			Push(st, p);
//			p = p->lchild;
//		}
//		if (!StackEmpty(st)) {
//			Pop(st, p);
//			p = p->rchild;
//		}
//	}
//}
//
//void InOrder1(BiTNode* b) {
//	BiTNode* p;
//	LinkStack* st;
//	InitStack(st);
//	p = b;
//	while (!StackEmpty(st) || p != NULL) {
//		while (p != NULL) {
//			Push(st, p);
//			p = p->lchild;
//		}
//		if (!StackEmpty(st)) {
//			Pop(st, p);
//			printf("%c", p->data);
//			p = p->rchild;
//		}
//	}
//}
//
//int main() {
//	BiTree bt;
//	printf("\n建立二叉树，请输入结点值的序列：\n");
//	CreatBiTree(bt);
//	PreOrder1(bt);
//	PreOrder2(bt);
//	printf("\n");
//	//InOrder(bt);
//	//printf("\n");
//	//PostOrder(bt);
//	//printf("\n");
//
//	/*printf("---------------------\n");
//	printf("该树的层数为：%d(%d)\n",bt_height(bt),bt_height2(bt));
//	printf("该树的结点数为：%d\n", NodeCount(bt));
//	printf("该树的叶子结点数为：%d\n", LeftNodeCount(bt));
//	char &a = bt->data;
//	minNode(bt, a);
//	printf("该树的最小值为：%c\n",a);
//	printf("该树中单分支结点的个数为：%d\n", SingleNodeCount(bt));*/
//	return 0;
//}