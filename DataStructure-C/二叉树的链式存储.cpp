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
///*求二叉树所有结点的和*/
//int Sum(BiTNode* bt) {
//	if (bt == NULL) {
//		return 0;
//	}
//	else {
//		return bt->data + Sum(bt->lchild) + Sum(bt->rchild);
//	}
//}
//
///*二叉树的遍历*/
//
////先序遍历
//void PreOrder(BiTNode* bt) {
//	if (bt != NULL) {
//		printf("%c ", bt->data);
//		PreOrder(bt->lchild);
//		PreOrder(bt->rchild);
//	}
//}
//
////中序遍历
//void InOrder(BiTNode* bt) {
//	if (bt != NULL) {
//		InOrder(bt->lchild);
//		printf("%c ", bt->data);
//		InOrder(bt->rchild);
//	}
//}
//
////后序遍历
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
///*求二叉树有几层的算法*/
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
///*求层数的算法2*/
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
///*求结点个数的算法*/
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
///*求二叉树叶子结点个数的算法*/
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
///*交换二叉树的孩子结点*/
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
///*求二叉树中单分支结点的个数*/
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
///*求二叉树中的最小值*/
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
//	printf("\n建立二叉树，请输入结点值的序列：\n");
//	CreatBiTree(bt);
//	PreOrder(bt);
//	printf("\n");
//	InOrder(bt);
//	printf("\n");
//	PostOrder(bt);
//	printf("\n");
//
//	printf("---------------------\n");
//	printf("该树的层数为：%d(%d)\n",bt_height(bt),bt_height2(bt));
//	printf("该树的结点数为：%d\n", NodeCount(bt));
//	printf("该树的叶子结点数为：%d\n", LeftNodeCount(bt));
//	char &a = bt->data;
//	minNode(bt, a);
//	printf("该树的最小值为：%c\n",a);
//	printf("该树中单分支结点的个数为：%d\n", SingleNodeCount(bt));
//	return 0;
//}