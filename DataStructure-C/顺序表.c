////#include<stdio.h>
////#include<stdlib.h>
////
/////*
////��̬���䷽ʽ��
////*/
////#define LIST_INIT_SIZE 100 //���Ա�ռ�ĳ�ʼ������
////#define LIST_INCREENT 10  //���Ա�Ŀռ�ķ�������
////typedef int ElementType; //Ԫ�ص���������
////
////typedef struct {
////	ElementType* elem;//�洢�ռ���׵�ַ
////	int length;//��ǰ����
////	int listsize;//��ǰ����ĳ���
////} SqList;
////
////
////#define MaxSize 100
////#define TRUE 1
////#define FALSE 0
////#define OK 1
////#define ERROR 0
////
////typedef int Status;//����״̬���ɹ��򲻳ɹ�
////
/////*
//////���Ա�ľ�̬����洢�ṹ
////typedef int ElemType;
////typedef struct {
////	ElemType data[MaxSize];
////	int length;
////} SqList;
////*/
////
////
//////1.��ʼ�����Ա�
////Status InitList(SqList L)
////{
////	L.elem = (ElementType*)malloc(sizeof(ElementType) * LIST_INIT_SIZE);
////	if (!L.elem)return ERROR;
////	L.length = 0;
////	L.listsize = LIST_INIT_SIZE;
////	return OK;
////}
////
//////2.�������Ա�
////
////Status DestroyList(SqList *L)
////{
////	free(L->elem);
////	L->elem = NULL;
////	L->length = 0;
////	L->listsize = 0;
////	return OK;
////}
////
//////3.�����Ա�ĳ���
////int GetListLength(SqList* L)
////{
////	return L->length;
////}
////
//////4.�����Ա��еĵ�i��Ԫ��
////Status GetValueOfIndex(SqList* L, int i, ElementType* e)
////{
////	if (i > L->length || i <= 0)return ERROR;
////	*e = L->elem[i-1];
////	return OK;
////}
////
//////5.��ֵ�����㷨
////int LocateElem(SqList L, ElementType e)
////{
////	ElementType* p;
////	int i = 1;
////	p = L.elem;
////
////	while (i <= L.length && (*p++ != e))
////	{
////		i++;
////	}
////
////	if (i > L.length)return 0;
////	else return i; 
////}
////
////int LocateElem2(SqList L, ElementType e)
////{
////	int i = 1;
////	while (L.elem[i] != e && i <= L.length)
////	{
////		i++;
////	}
////	if (i > L.length)return 0;
////	else return i;
////}
////
//////6.�����㷨
////Status ListInsert(SqList* L, int index, ElementType e)
////{
////	if (index < 1 || index >= L->length + 1)return ERROR;
////
////	if (L->length >= L->listsize) {
////		//�����ǰ�洢�ռ䲻����-->����
////		ElementType* newbase = (ElementType*)realloc(L->elem,sizeof(ElementType) * (L->listsize + LIST_INCREENT));
////		if (!newbase) return ERROR;
////		L->elem = newbase;
////		L->listsize += LIST_INCREENT;
////	}
////	int temp = L->length-1;
////	for (; temp > index - 1; temp--)
////	{
////		L->elem[temp + 1] = L->elem[temp];
////	}
////	L->elem[index - 1] = e;
////	++L->length;
////	return OK;
////}
////
//////7.ɾ���㷨
////Status ListDelete(SqList* L, int index, ElementType* e)
////{
////	if (index < 1 && index > L->length)
////		return ERROR;
////	*e = L->elem[index - 1];
////
////	for (int i = index; i < L->length; i++)
////		L->elem[i - 1] = L->elem[i];
////	L->length--;
////	return OK;
////}
////
//////8.�������Ա�
////void dispList(SqList L)
////{
////	for (size_t i = 0; i <= L.length; i++)
////	{
////		printf("%d ", L.elem[i - 1]);
////	}
////}
////
////
////int main(void)
////{
////	SqList *L = 0;
////	InitList(*L);
////	ListInsert(L, 1, 3);
////
////
////	system("pause");
////}
//
//#include "stdio.h"    
//
//#include "stdlib.h"   
//#include "io.h"  
//#include "math.h"  
//#include "time.h"
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
//
//typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */
//
//
//Status visit(ElemType c)
//{
//    printf("%d ", c);
//    return OK;
//}
//
//typedef struct
//{
//    ElemType data[MAXSIZE];        /* ���飬�洢����Ԫ�� */
//    int length;                                /* ���Ա�ǰ���� */
//}SqList;
//
///* ��ʼ��˳�����Ա� */
//Status InitList(SqList* L)
//{
//    L->length = 0;
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//Status ListEmpty(SqList L)
//{
//    if (L.length == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
//Status ClearList(SqList* L)
//{
//    L->length = 0;
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//int ListLength(SqList L)
//{
//    return L.length;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
///* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
//Status GetElem(SqList L, int i, ElemType* e)
//{
//    if (L.length == 0 || i<1 || i>L.length)
//        return ERROR;
//    *e = L.data[i - 1];
//
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
///* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
//int LocateElem(SqList L, ElemType e)
//{
//    int i;
//    if (L.length == 0)
//        return 0;
//    for (i = 0; i < L.length; i++)
//    {
//        if (L.data[i] == e)
//            break;
//    }
//    if (i >= L.length)
//        return 0;
//
//    return i + 1;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
///* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
//Status ListInsert(SqList* L, int i, ElemType e)
//{
//    int k;
//    if (L->length == MAXSIZE)  /* ˳�����Ա��Ѿ��� */
//        return ERROR;
//    if (i<1 || i>L->length + 1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
//        return ERROR;
//
//    if (i <= L->length)        /* ����������λ�ò��ڱ�β */
//    {
//        for (k = L->length - 1; k >= i - 1; k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
//            L->data[k + 1] = L->data[k];
//    }
//    L->data[i - 1] = e;          /* ����Ԫ�ز��� */
//    L->length++;
//
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
///* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
//Status ListDelete(SqList* L, int i, ElemType* e)
//{
//    int k;
//    if (L->length == 0)               /* ���Ա�Ϊ�� */
//        return ERROR;
//    if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
//        return ERROR;
//    *e = L->data[i - 1];
//    if (i < L->length)                /* ���ɾ���������λ�� */
//    {
//        for (k = i; k < L->length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
//            L->data[k - 1] = L->data[k];
//    }
//    L->length--;
//    return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* ������������ζ�L��ÿ������Ԫ����� */
//Status ListTraverse(SqList L)
//{
//    int i;
//    for (i = 0; i < L.length; i++)
//        visit(L.data[i]);
//    printf("\n");
//    return OK;
//}
//
//void unionL(SqList* La, SqList Lb)
//{
//    int La_len, Lb_len, i;
//    ElemType e;
//    La_len = ListLength(*La);
//    Lb_len = ListLength(Lb);
//    for (i = 1; i <= Lb_len; i++)
//    {
//        GetElem(Lb, i, &e);
//        if (!LocateElem(*La, e))
//            ListInsert(La, ++La_len, e);
//    }
//}
//
//int main5()
//{
//
//    SqList L;
//    SqList Lb;
//
//    ElemType e;
//    Status i;
//    int j, k;
//    i = InitList(&L);
//    printf("��ʼ��L��L.length=%d\n", L.length);
//    for (j = 1; j <= 5; j++)
//        i = ListInsert(&L, 1, j);
//    printf("��L�ı�ͷ���β���1��5��L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n", L.length);
//    i = ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    i = ClearList(&L);
//    printf("���L��L.length=%d\n", L.length);
//    i = ListEmpty(L);
//    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//    for (j = 1; j <= 10; j++)
//        ListInsert(&L, j, j);
//    printf("��L�ı�β���β���1��10��L.data=");
//    ListTraverse(L);
//
//    printf("L.length=%d \n", L.length);
//
//    ListInsert(&L, 1, 0);
//    printf("��L�ı�ͷ����0��L.data=");
//    ListTraverse(L);
//    printf("L.length=%d \n", L.length);
//
//    GetElem(L, 5, &e);
//    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
//    for (j = 3; j <= 4; j++)
//    {
//        k = LocateElem(L, j);
//        if (k)
//            printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
//        else
//            printf("û��ֵΪ%d��Ԫ��\n", j);
//    }
//
//
//    k = ListLength(L); /* kΪ�� */
//    for (j = k + 1; j >= k; j--)
//    {
//        i = ListDelete(&L, j, &e); /* ɾ����j������ */
//        if (i == ERROR)
//            printf("ɾ����%d������ʧ��\n", j);
//        else
//            printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//    }
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    j = 5;
//    ListDelete(&L, j, &e); /* ɾ����5������ */
//    printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//
//    printf("�������L��Ԫ�أ�");
//    ListTraverse(L);
//
//    //����һ����10������Lb
//    i = InitList(&Lb);
//    for (j = 6; j <= 15; j++)
//        i = ListInsert(&Lb, 1, j);
//
//    unionL(&L, Lb);
//
//    printf("��������ϲ���Lb��L��Ԫ�أ�");
//    ListTraverse(L);
//
//    return 0;
//}