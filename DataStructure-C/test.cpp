#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*��������*/
//-----�������Ķ�������洢��ʾ-----
typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;

void CreateBiTree(BiTree& T)
{//�������������������н���ֵ
 //������������ʾ�Ķ�����T
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#') //����
		T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) //����Ƿ�������ɹ�
			exit(-1);
		T->data = ch; //���ɸ��ڵ�
		CreateBiTree(T->lchild); //����������
		CreateBiTree(T->rchild);//����������
	}

}
//�������
void PreOrder(BiTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
//�������
void InOrder(BiTNode* bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%c", bt->data);
		InOrder(bt->rchild);
	}
}

//�������
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
	printf("\n��������������������ֵϵ�У�\n");
	CreateBiTree(bt);
	printf("\n����������У�\n");
	PreOrder(bt);
	printf("\n����������У�\n");
	InOrder(bt);
	printf("\n����������У�\n");
	PostOrder(bt);
	printf("\n\n");
}