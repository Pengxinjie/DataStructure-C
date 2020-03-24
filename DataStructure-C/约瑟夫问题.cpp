//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//
//#define N 100
//
//int main3(void)
//{ 
//    //报数的最大值
//    int m;
//    //总人数
//    int length;
//    printf("请输入总人数length：");
//    scanf("%d", &length);
//    printf("请输入报数的最大值m：");
//    scanf("%d", &m);
//
//    int a[N] = { 0 };
//
//    int i = 0;
//    //num统计是第几个出圈的
//    int num = 0;
//    //给数组按顺序赋值
//    for (; i < length; i++)
//    {
//        a[i] = i + 1;
//    }
//    //剩一个人的时候退出
//    while (length > 1)
//    {
//        //（循环后移）关键一步，后移m-1个，取余实现了循环
//        i = (i + m - 1) % length;
//
//        num++;
//        printf("第%d个出圈的是%d\n", num, a[i]);
//
//        //让数组报到数的后面元素前移 ---->解释了为什么后移m-1个，而不是m个，因为当前的人被覆盖了
//        for (int j = i + 1; j < length; j++)
//        {
//            a[j - 1] = a[j];
//        }
//
//        //实际人数减一
//        length--;
//
//        //实际只剩length个人,数组下标最大length-1，所以回到0，形成一个循环
//        if (i == length)
//        {
//            i = 0;
//        }
//    }
//
//    printf("最后剩下的时%d\n", a[i]);
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
//		//依次比较大小
//		if (tempB->data == tempA->data)
//		{
//			A->next = tempA;
//			A = A->next;
//			
//			//相等的话同时后移
//			tempB = tempB->next;
//			tempA = tempA->next;
//		}
//		else if (tempB->data < tempA->data)
//		{
//			//tmepB小，tempB后移
//			tempB = tempB->next;
//		}
//		else
//		{
//			//tempA小，后移
//			LinkNode* t1 = tempA;
//			tempA = tempA->next;
//			//释放没有被指向的结点，避免内存泄漏
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
