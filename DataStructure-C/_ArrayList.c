//#include<stdio.h>
//typedef int ElemType;
//
//void del_sameElem_1(Sqlist L, ElemType value) {
//	//先定位，找元素赋值法
//	int k = -1;
//	for (int i = 0; i < L.length; i++) {
//		if (value != L.data[i]) {
//			k++; //定位下标 
//			L.data[k] = L.data[i];
//		}
//	}
//	L.length = k + 1;//长度为下标+1 
//}


//判空
//if (NULL == g_pHead->pNext) {
//	printf("链表为空！");
//	return;
//}
////寻找结点（index）
//struct Node* pTemp = SelectNode(index);
//
//if (NULL == pTemp) {
//	printf("无此结点！");
//	return;
//}
//
//if (pTemp == g_pEnd) {//是尾结点
//	DelTailNode();
//}
//else {
//	//寻找index的前一个结点
//	struct Node* p = g_pHead;
//	while (p != NULL)
//	{
//		if (pTemp == p->pNext)
//			break;
//		pTemp = pTemp->pNext;
//	}
//	//删除
//	p->pNext = pTemp->pNext;
//	//释放
//	free(pTemp);
//}