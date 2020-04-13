#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
typedef char TELemType;

enum PointerTag { Link, Thread }; // Link(0)：指针，Thread(1)：线索
struct BiThrNode {
	TELemType data;
	BiThrNode* lchild, * rchild; // 左右孩子指针
	PointerTag ltag, rtag; // 左右标志
};
typedef BiThrNode* BiThrTree;

BiThrNode* pre; //定义pre为全局变量
void Thread(BiThrNode*& p)
//对以p为根结点的二叉树进行中序线索化
{
	if (p != NULL) {
		Thread(p->lchild); //左子树线索化
		if (p->lchild == NULL) { //前驱线索
			p->lchild = pre; //给结点p添加前驱线索
			p->ltag = (enum PointerTag)1;
		}
		else
			p->ltag = (enum PointerTag)0;
		if (pre->rchild == NULL) {
			pre->rchild = p; //给结点pre添加后继线索
			pre->rtag = (enum PointerTag)1;
		}
		else
			pre->rtag = (enum PointerTag)0;
		pre = p;
		Thread(p->rchild); //右子树线索化
	}
}

BiThrNode* CreaThread(BiThrNode* bt)
//对以bt为根结点的二叉树中序线索化,并增加一个头结点head
{
	BiThrNode* head;
	head = (BiThrNode*)malloc(sizeof(BiThrNode));
	head->ltag = (enum PointerTag)0;
	head->rtag = (enum PointerTag)1; //创建头结点head
	head->rchild = bt;
	if (bt == NULL) //bt为空树时
		head->lchild = head;
	else {
		head->lchild = bt;
		pre = head; //pre是p的前驱结点,供加线索用
		Thread(bt); //中序遍历线索化二叉树
		pre->rchild = head; //最后处理,加入指向根结点的线索
		pre->rtag = (enum PointerTag)1;
		head->rchild = pre; //根结点右线索化
	}
	return head;
}