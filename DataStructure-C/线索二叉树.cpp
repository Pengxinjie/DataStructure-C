#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
typedef char TELemType;

enum PointerTag { Link, Thread }; // Link(0)��ָ�룬Thread(1)������
struct BiThrNode {
	TELemType data;
	BiThrNode* lchild, * rchild; // ���Һ���ָ��
	PointerTag ltag, rtag; // ���ұ�־
};
typedef BiThrNode* BiThrTree;

BiThrNode* pre; //����preΪȫ�ֱ���
void Thread(BiThrNode*& p)
//����pΪ�����Ķ�������������������
{
	if (p != NULL) {
		Thread(p->lchild); //������������
		if (p->lchild == NULL) { //ǰ������
			p->lchild = pre; //�����p���ǰ������
			p->ltag = (enum PointerTag)1;
		}
		else
			p->ltag = (enum PointerTag)0;
		if (pre->rchild == NULL) {
			pre->rchild = p; //�����pre��Ӻ������
			pre->rtag = (enum PointerTag)1;
		}
		else
			pre->rtag = (enum PointerTag)0;
		pre = p;
		Thread(p->rchild); //������������
	}
}

BiThrNode* CreaThread(BiThrNode* bt)
//����btΪ�����Ķ���������������,������һ��ͷ���head
{
	BiThrNode* head;
	head = (BiThrNode*)malloc(sizeof(BiThrNode));
	head->ltag = (enum PointerTag)0;
	head->rtag = (enum PointerTag)1; //����ͷ���head
	head->rchild = bt;
	if (bt == NULL) //btΪ����ʱ
		head->lchild = head;
	else {
		head->lchild = bt;
		pre = head; //pre��p��ǰ�����,����������
		Thread(bt); //�������������������
		pre->rchild = head; //�����,����ָ�����������
		pre->rtag = (enum PointerTag)1;
		head->rchild = pre; //�������������
	}
	return head;
}