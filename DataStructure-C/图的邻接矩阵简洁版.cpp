#include<stdio.h>
#include<stdlib.h>

#define INF INT_MAX               //整型最大值代表无穷
#define MAXVEX 30                 //最大顶点数
typedef char VertexType[4];       //定义 VertexType为字符串类型

typedef struct vertex
{
	int adjvex;                   //顶点编号
	VertexType data;              //顶点的信息
} VType;                          //顶点类型

typedef struct graph 
{
	int n, e;                     //n为实际顶点数，e为实际边数
	VType vexs[MAXVEX];           //顶点集合
	int edges[MAXVEX][MAXVEX];    //边的集合
}MGraph;                          //图的邻接矩阵类型

//1.建立图的邻接矩阵算法
/*说明：由邻接矩阵数组A、顶点数n和边数e建立图G的邻接矩阵存储结构*/
void CreatGraph(MGraph& g, int A[][MAXVEX], int n, int e)
{
	int i, j;
	g.n = n;
	g.e = e;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			g.edges[i][j] = A[i][j];
}

//2.求顶点度的算法
/*对于无向图和有向图，求顶点的度有所不同*/

//①求无向图
int Degree1(MGraph g, int v)//求无向图中顶点的度
{
	int i, d = 0;
	if (v < 0 || v >= g.n)
		return -1;
	for (i = 0; i < g.n; i++)
		if (g.edges[v][i] > 0 && g.edges[v][i] < INF)
			d++;
	return d;
}
//②有向图
int Degree2(MGraph g, int v)
{
	int i, d = 0;
	if (v < 0 || v >= g.n)
		return -1;
	for (i = 0; i < g.n; i++)
		if (g.edges[v][i] > 0 && g.edges[v][i] < INF)//计算出度
			d++;
	for (i = 0; i < g.n; i++)
		if (g.edges[i][v] > 0 && g.edges[i][v] < INF)//计算入度
			d++;
	return d;
}

