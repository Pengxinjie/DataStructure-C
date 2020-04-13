//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<math.h>
//using namespace std;
//
//typedef char TELemType;
//
//typedef struct BiTNode {
//	TELemType data;
//	BiTNode *lchild,*rchild;
//}BiTNode,*BiTree;
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
///*����������н��ĺ�*/
//int Sum(BiTNode* bt) {
//	if (bt == NULL) {
//		return 0;
//	}
//	else {
//		return bt->data + Sum(bt->lchild) + Sum(bt->rchild);
//	}
//}
//
///*�������ı���*/
//
////�������
//void PreOrder(BiTNode* bt) {
//	if (bt != NULL) {
//		printf("%c ", bt->data);
//		PreOrder(bt->lchild);
//		PreOrder(bt->rchild);
//	}
//}
//
////�������
//void InOrder(BiTNode* bt) {
//	if (bt != NULL) {
//		InOrder(bt->lchild);
//		printf("%c ", bt->data);
//		InOrder(bt->rchild);
//	}
//}
//
////�������
//void PostOrder(BiTNode* bt) {
//	if (bt != NULL) {
//		PostOrder(bt->lchild);
//		PostOrder(bt->rchild);
//		printf("%c ", bt->data);
//	}
//}
//
//int max(int a, int b) {
//	if (a > b) {
//		return a;
//	}
//	else {
//		return b;
//	}
//}
//
///*��������м�����㷨*/
//int bt_height(BiTNode* T)
//{
//	if (T == NULL) {
//		return 0;
//	}
//	else {
//		if (T->lchild == NULL && T->rchild == NULL)
//			return 1;
//		else {
//			return 1 + max(bt_height(T->lchild), bt_height(T->rchild));
//		}
//	}
//}
//
///*��������㷨2*/
//int bt_height2(BiTNode* T)
//{
//	int lh, rh;
//	if (T == NULL)
//		return 0;
//	else {
//		lh = bt_height2(T->lchild);
//		rh = bt_height2(T->rchild);
//		return max(lh, rh) + 1;
//	}
//}
//
///*����������㷨*/
//int NodeCount(BiTNode* T)
//{
//	int lnum, rnum;
//	if (T == NULL)
//		return 0;
//	else {
//		lnum = NodeCount(T->lchild);
//		rnum = NodeCount(T->rchild);
//		return lnum + rnum + 1;
//	}
//}
//
///*�������Ҷ�ӽ��������㷨*/
//int LeftNodeCount(BiTNode* T)
//{
//	int lnum, rnum;
//	if (T == NULL)
//		return 0;
//	else if (T->lchild == NULL && T->rchild == NULL)
//		return 1;
//	else {
//		lnum = LeftNodeCount(T->lchild);
//		rnum = LeftNodeCount(T->rchild);
//		return (lnum + rnum);
//	}
//}
//
///*�����������ĺ��ӽ��*/
//void Exchange(BiTNode* T)
//{
//	if (T == NULL) {
//		if (T->lchild != NULL || T->rchild != NULL)
//		{
//			BiTNode* temp = T->lchild;
//			T->lchild = T->rchild;
//			T->rchild = temp;
//			Exchange(T->lchild);
//			Exchange(T->rchild);
//		}
//	}
//}
//
///*��������е���֧���ĸ���*/
//int SingleNodeCount(BiTNode* T) {
//	int lnum, rnum,n;
//	if (T == NULL)
//		return 0;
//	else {
//		if ((T->lchild == NULL && T->rchild != NULL) ||
//			T->lchild != NULL && T->rchild == NULL) {
//			n = 1;
//		}
//		else
//			n = 0;
//	}
//	lnum = SingleNodeCount(T->lchild);
//	rnum = SingleNodeCount(T->rchild);
//	return lnum + rnum + n;
//}
//
///*��������е���Сֵ*/
//void minNode(BiTNode* T, char& a) {
//	if (T != NULL) {
//		if (T->data < a)
//			a = T->data;
//		minNode(T->lchild, a);
//		minNode(T->rchild, a);
//	}
//}
//
//int main() {
//	BiTree bt;
//	printf("\n��������������������ֵ�����У�\n");
//	CreatBiTree(bt);
//	PreOrder(bt);
//	printf("\n");
//	InOrder(bt);
//	printf("\n");
//	PostOrder(bt);
//	printf("\n");
//
//	printf("---------------------\n");
//	printf("�����Ĳ���Ϊ��%d(%d)\n",bt_height(bt),bt_height2(bt));
//	printf("�����Ľ����Ϊ��%d\n", NodeCount(bt));
//	printf("������Ҷ�ӽ����Ϊ��%d\n", LeftNodeCount(bt));
//	char &a = bt->data;
//	minNode(bt, a);
//	printf("��������СֵΪ��%c\n",a);
//	printf("�����е���֧���ĸ���Ϊ��%d\n", SingleNodeCount(bt));
//	return 0;
//}