//#include<stdio.h>
//typedef int ElemType;
//
//void del_sameElem_1(Sqlist L, ElemType value) {
//	//�ȶ�λ����Ԫ�ظ�ֵ��
//	int k = -1;
//	for (int i = 0; i < L.length; i++) {
//		if (value != L.data[i]) {
//			k++; //��λ�±� 
//			L.data[k] = L.data[i];
//		}
//	}
//	L.length = k + 1;//����Ϊ�±�+1 
//}


//�п�
//if (NULL == g_pHead->pNext) {
//	printf("����Ϊ�գ�");
//	return;
//}
////Ѱ�ҽ�㣨index��
//struct Node* pTemp = SelectNode(index);
//
//if (NULL == pTemp) {
//	printf("�޴˽�㣡");
//	return;
//}
//
//if (pTemp == g_pEnd) {//��β���
//	DelTailNode();
//}
//else {
//	//Ѱ��index��ǰһ�����
//	struct Node* p = g_pHead;
//	while (p != NULL)
//	{
//		if (pTemp == p->pNext)
//			break;
//		pTemp = pTemp->pNext;
//	}
//	//ɾ��
//	p->pNext = pTemp->pNext;
//	//�ͷ�
//	free(pTemp);
//}

#define MAXSIZE 20
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

//�����鳤�ȣ�Ĭ�Ͻ�����ĳ��ȴ洢��˳����±�Ϊ0��λ��
int ListLength(ElementType* list) {
	return list[0];
}

//ɾ��ָ��Ԫ��
void ListDelete(ElementType* list, int Index) {
	if (ListLength(list) == 0) {
		printf("��գ�");
		return;
	}
	//��Index�����Ԫ��ǰ��
	for (int i = Index; i < ListLength(list); i++) {
		list[i] = list[i + 1];
	}
	//���ȼ�һ
	list[0] -= 1;
}

//ɾ�����е���ͬԪ��
void purge(ElementType* list) {
	//ListLengthΪ����ĺ���
	int temp = 1;

	for (int i = 1; i < ListLength(list); i++)
	{
		for (int j = i + 1; j < ListLength(list) + 1; j++)
		{
			if (list[i] == list[j]) {
				ListDelete(list, j);

				if (list[i] == list[j])
					j--;

				printf("���ǵ��õĵ�%d��,��ʱ���i=%d,j=%d\n", temp++, i, j);
			}
		}
	}
}

//�������Ա�
void PrintList(ElementType* list) {
	for (int i = 1; i <= ListLength(list); i++) {
		printf("%d\t", list[i]);
	}
	printf("\n");
}

int main(void) {

	ElementType list[10] = { 4,2,5,2,2 };

	//����
	PrintList(list);
	printf("���鳤��Ϊ��%d\n", list[0]);

	purge(list);
	PrintList(list);

	printf("���鳤��Ϊ��%d\n", list[0]);

	system("pause");
	return 0;
}