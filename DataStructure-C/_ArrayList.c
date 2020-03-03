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

#define MAXSIZE 20
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

//求数组长度，默认将数组的长度存储在顺序表下标为0的位置
int ListLength(ElementType* list) {
	return list[0];
}

//删除指定元素
void ListDelete(ElementType* list, int Index) {
	if (ListLength(list) == 0) {
		printf("表空！");
		return;
	}
	//将Index后面的元素前移
	for (int i = Index; i < ListLength(list); i++) {
		list[i] = list[i + 1];
	}
	//长度减一
	list[0] -= 1;
}

//删除表中的相同元素
void purge(ElementType* list) {
	//ListLength为求表长的函数
	int temp = 1;

	for (int i = 1; i < ListLength(list); i++)
	{
		for (int j = i + 1; j < ListLength(list) + 1; j++)
		{
			if (list[i] == list[j]) {
				ListDelete(list, j);

				if (list[i] == list[j])
					j--;

				printf("这是调用的第%d次,这时候的i=%d,j=%d\n", temp++, i, j);
			}
		}
	}
}

//遍历线性表
void PrintList(ElementType* list) {
	for (int i = 1; i <= ListLength(list); i++) {
		printf("%d\t", list[i]);
	}
	printf("\n");
}

int main(void) {

	ElementType list[10] = { 4,2,5,2,2 };

	//遍历
	PrintList(list);
	printf("数组长度为：%d\n", list[0]);

	purge(list);
	PrintList(list);

	printf("数组长度为：%d\n", list[0]);

	system("pause");
	return 0;
}