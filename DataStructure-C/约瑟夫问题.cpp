//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//
//#define N 100
//
//int main3(void)
//{ 
//    //���������ֵ
//    int m;
//    //������
//    int length;
//    printf("������������length��");
//    scanf("%d", &length);
//    printf("�����뱨�������ֵm��");
//    scanf("%d", &m);
//
//    int a[N] = { 0 };
//
//    int i = 0;
//    //numͳ���ǵڼ�����Ȧ��
//    int num = 0;
//    //�����鰴˳��ֵ
//    for (; i < length; i++)
//    {
//        a[i] = i + 1;
//    }
//    //ʣһ���˵�ʱ���˳�
//    while (length > 1)
//    {
//        //��ѭ�����ƣ��ؼ�һ��������m-1����ȡ��ʵ����ѭ��
//        i = (i + m - 1) % length;
//
//        num++;
//        printf("��%d����Ȧ����%d\n", num, a[i]);
//
//        //�����鱨�����ĺ���Ԫ��ǰ�� ---->������Ϊʲô����m-1����������m������Ϊ��ǰ���˱�������
//        for (int j = i + 1; j < length; j++)
//        {
//            a[j - 1] = a[j];
//        }
//
//        //ʵ��������һ
//        length--;
//
//        //ʵ��ֻʣlength����,�����±����length-1�����Իص�0���γ�һ��ѭ��
//        if (i == length)
//        {
//            i = 0;
//        }
//    }
//
//    printf("���ʣ�µ�ʱ%d\n", a[i]);
//    return 0;
//}


//#include <iostream>
//using namespace std;
//struct LinkNode
//{
//	int data;
//	LinkNode* next;
//};
//void minus_LinkList(LinkNode* A, LinkNode* B)
//{
//	LinkNode* finalA = A;
//	LinkNode* tempA = A->next;
//	LinkNode* tempB = B->next;
//	while (tempA && tempB)
//	{
//		//���αȽϴ�С
//		if (tempB->data == tempA->data)
//		{
//			A->next = tempA;
//			A = A->next;
//			
//			//��ȵĻ�ͬʱ����
//			tempB = tempB->next;
//			tempA = tempA->next;
//		}
//		else if (tempB->data < tempA->data)
//		{
//			//tmepBС��tempB����
//			tempB = tempB->next;
//		}
//		else
//		{
//			//tempAС������
//			LinkNode* t1 = tempA;
//			tempA = tempA->next;
//			//�ͷ�û�б�ָ��Ľ�㣬�����ڴ�й©
//			free(t1);
//		}
//	}
//	A->next = NULL;
//	A = finalA;
//}
//void print_LinkList(LinkNode* finalA)
//{
//	while (finalA->next)
//	{
//		finalA = finalA->next;
//		printf("%d  ", finalA->data);
//	}
//	printf("\n");
//}
//LinkNode* Create_LinkList(int* arr, int len)
//{
//	LinkNode* temp = new LinkNode();
//	temp->next = NULL;
//	LinkNode* head = temp;
//	for (int i = 0; i < len; ++i)
//	{
//		LinkNode* newN = new LinkNode();
//		newN->data = arr[i];
//		newN->next = NULL;
//		temp->next = newN;
//		temp = temp->next;
//	}
//	return head;
//}
//int main()
//{
//	int arrA[] = { 1, 3, 5, 7 };
//	int arrB[] = { 2, 3, 4, 5,6,8 };
//	LinkNode* A = Create_LinkList(arrA, 4);
//	LinkNode* B = Create_LinkList(arrB, 6);
//	print_LinkList(A);
//	print_LinkList(B);
//
//	minus_LinkList(A, B);
//
//	print_LinkList(A);
//}
