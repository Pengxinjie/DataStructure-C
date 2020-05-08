#include<stdio.h>
#include<stdlib.h>

#define INFINITY INT_MAX         //用整型最大值代表无穷
#define MAX_NAME 4               //顶点字符串的最大长度+1
#define MAX_VERTEX_NUM 30        //最大顶点个数
enum GraphKind
{
	DG,//有向图
	DN,//有向网
	UDG,//无向图
	UDN//无向网
};

typedef int VRType;   
typedef char VertexType[MAX_NAME];

typedef struct {
	VRType adj;//顶点关系类型。对无权图，用1/0来表示相邻否；带权图则用权值
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组

typedef struct Graph {
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//图的当前顶点数和弧数
	GraphKind kind;//图的种类标志
}MGraph;