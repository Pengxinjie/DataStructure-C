#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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

typedef struct node
{
	int no;//小孩的编号
	struct node* next;
} Child;

//不带头结点的单向循环链表
Child* CreatCicleList(int n)
{
	int i;//为编号赋值
	Child* p, * tc,*L;//tc指向新建循环链表的尾结点
	L = (Child*)malloc(sizeof(Child));
	L->no = 1;//先建立一个no为1结点的单链表
	tc = L;

	for (i = 2; i <= n; i++)
	{
		p = (Child*)malloc(sizeof(Child));
		p->no = i;
		tc->next = p;
		tc = p;
	}
	tc->next = L;
	return L;
}

void Joseph(int n, int m)
{
	int i,
		j;
	Child* L = CreatCicleList(n),
		* p,
		* q;

	for (i = 1; i <= n; i++)//出列n个小孩
	{
		p = L;
		j = 1;
		while (j < m - 1)
		{
			j++;
			p = p->next;
		}

		q = p->next;
		printf("%d ", q->no);//结点出列
		p->next = q->next;//删除该结点
		free(q);//释放空间
		L = p->next;//从下一个结点开始
	}
}

int main(void)
{
	Joseph(6, 5);//6表示有6个小孩，5表示报数到5出圈一个小孩

	system("pause");
	return 0;
}
