#include<stdio.h>
#include<stdlib.h>

#define INF INT_MAX               //�������ֵ��������
#define MAXVEX 30                 //��󶥵���
typedef char VertexType[4];       //���� VertexTypeΪ�ַ�������

typedef struct vertex
{
	int adjvex;                   //������
	VertexType data;              //�������Ϣ
} VType;                          //��������

typedef struct graph 
{
	int n, e;                     //nΪʵ�ʶ�������eΪʵ�ʱ���
	VType vexs[MAXVEX];           //���㼯��
	int edges[MAXVEX][MAXVEX];    //�ߵļ���
}MGraph;                          //ͼ���ڽӾ�������

//1.����ͼ���ڽӾ����㷨
/*˵�������ڽӾ�������A��������n�ͱ���e����ͼG���ڽӾ���洢�ṹ*/
void CreatGraph(MGraph& g, int A[][MAXVEX], int n, int e)
{
	int i, j;
	g.n = n;
	g.e = e;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g.edges[i][j] = A[i][j];
}

//2.�󶥵�ȵ��㷨
/*��������ͼ������ͼ���󶥵�Ķ�������ͬ*/

//��������ͼ
int Degree1(MGraph g, int v)//������ͼ�ж���Ķ�
{
	int i, d = 0;
	if (v < 0 || v >= g.n)
		return -1;
	for (i = 0; i < g.n; i++)
		if (g.edges[v][i] > 0 && g.edges[v][i] < INF)
			d++;
	return d;
}
//������ͼ
int Degree2(MGraph g, int v)
{
	int i, d = 0;
	if (v < 0 || v >= g.n)
		return -1;
	for (i = 0; i < g.n; i++)
		if (g.edges[v][i] > 0 && g.edges[v][i] < INF)//�������
			d++;
	for (i = 0; i < g.n; i++)
		if (g.edges[i][v] > 0 && g.edges[i][v] < INF)//�������
			d++;
	return d;
}

