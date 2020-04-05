#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*其他代码*/
//-----二叉树的二叉链表存储表示-----
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;

void CreateBiTree(BiTree& T)
{//按先序次序输入二叉树中结点的值
 //构造二叉链表表示的二叉树T
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#') //空树
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) //检测是否申请结点成功
			exit(-1);
		T->data = ch; //生成根节点
		CreateBiTree(T->lchild); //构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}

}
//先序遍历
void PreOrder(BiTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
//中序遍历
void InOrder(BiTNode* bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%c", bt->data);
		InOrder(bt->rchild);
	}
}

//后序遍历
void PostOrder(BiTNode* bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		InOrder(bt->rchild);
		printf("%c", bt->data);
	}
}

int main()
{
	BiTree bt;
	printf("\n建立二叉树，请输入结点值系列：\n");
	CreateBiTree(bt);
	printf("\n先序遍历序列：\n");
	PreOrder(bt);
	printf("\n中序遍历序列：\n");
	InOrder(bt);
	printf("\n后序遍历序列：\n");
	PostOrder(bt);
	printf("\n\n");
}