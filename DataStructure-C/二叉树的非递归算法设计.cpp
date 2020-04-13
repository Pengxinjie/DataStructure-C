//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//typedef char TELemType;
//typedef struct BiTNode {
//	TELemType data;
//	BiTNode* lchild, * rchild;
//}BiTNode, * BiTree;
//
////------------------------ջ------------------------
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
//	if (pre == NULL) return; //���ǿ�ջ�����
//	p = pre->next;
//	while (p != NULL)
//	{
//		free(pre); //�ͷ�pre���
//		pre = p;
//		p = p->next; //pre��pͬ������
//	}
//	free(pre); //�ͷ�β���
//}
//
//int Push(LinkStack*& top, ElemType x)
//{
//	LinkStack* p;
//	p = (LinkStack*)malloc(sizeof(LinkStack));
//	p->data = x; //�������p���ڴ��x
//	p->next = top; //����p�����Ϊջ�����
//	top = p;
//	return 1;
//}
//
//int Pop(LinkStack*& top, ElemType& x)
//{
//	LinkStack* p;
//	if (top == NULL) //ջ��,���������0
//		return 0;
//	else //ջ����ʱ��ջԪ��x������1
//	{
//		p = top; //pָ��ջ�����
//		x = p->data; //ȡջ��Ԫ��x
//		top = p->next; //ɾ�����p
//		free(p); //�ͷ�p���
//		return 1;
//	}
//}
//
//int GetTop(LinkStack* top, ElemType& x)
//{
//	if (top == NULL) //ջ��,�����ʱ����0
//		return 0;
//	else //ջ����,ȡջ��Ԫ��x������1
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
////------------------------ջ------------------------
//
//
////�������ĵݹ鴴��
////�������ڵ㡮#��
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
///*���ٶ�����*/
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
////�������ķǵݹ����-->����ջ
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
//	printf("\n��������������������ֵ�����У�\n");
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
//	printf("�����Ĳ���Ϊ��%d(%d)\n",bt_height(bt),bt_height2(bt));
//	printf("�����Ľ����Ϊ��%d\n", NodeCount(bt));
//	printf("������Ҷ�ӽ����Ϊ��%d\n", LeftNodeCount(bt));
//	char &a = bt->data;
//	minNode(bt, a);
//	printf("��������СֵΪ��%c\n",a);
//	printf("�����е���֧���ĸ���Ϊ��%d\n", SingleNodeCount(bt));*/
//	return 0;
//}