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