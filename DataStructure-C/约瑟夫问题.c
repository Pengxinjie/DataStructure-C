#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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

typedef struct node
{
	int no;//С���ı��
	struct node* next;
} Child;

//����ͷ���ĵ���ѭ������
Child* CreatCicleList(int n)
{
	int i;//Ϊ��Ÿ�ֵ
	Child* p, * tc,*L;//tcָ���½�ѭ�������β���
	L = (Child*)malloc(sizeof(Child));
	L->no = 1;//�Ƚ���һ��noΪ1���ĵ�����
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

	for (i = 1; i <= n; i++)//����n��С��
	{
		p = L;
		j = 1;
		while (j < m - 1)
		{
			j++;
			p = p->next;
		}

		q = p->next;
		printf("%d ", q->no);//������
		p->next = q->next;//ɾ���ý��
		free(q);//�ͷſռ�
		L = p->next;//����һ����㿪ʼ
	}
}

int main(void)
{
	Joseph(6, 5);//6��ʾ��6��С����5��ʾ������5��Ȧһ��С��

	system("pause");
	return 0;
}
