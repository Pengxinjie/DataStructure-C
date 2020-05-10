#include<stdio.h>
#include<stdlib.h>

typedef char VertexType[10];          //VertexType为字符串类型
#define MAXVEX 30                     //最大顶点数
#define INF INT_MAX                   //整型最大值代表无穷
typedef struct edgenode
{
	int adjvex;                       //相邻点序号
	int weight;                       //边的权值
	struct edgenode* nextarc;         //下一条边的顶点
}ArcNode;                             //每个顶点建立的单链表中边结点的类型

typedef struct vexnode
{
	VertexType data;                  //存放一个顶点的信息
	ArcNode* firstarc;                //指向第一条边结点
}VHeadNode;                           //单链表的头结点类型

typedef struct
{
	int n, e;                         //n为实际顶点数，e为实际边数
	VHeadNode adjlist[MAXVEX];		  //单链表的头结点数组
}ALGraph;                             //图的邻接表类型


//1.建立图的邻接表算法
/*由邻接矩阵A、顶点数n和边数e建立图G的邻接表存储结构。
	基本思路：
		1.先创建邻接表的头结点数组，并置所有头结点的firstarc为NULL
		2.遍历邻接矩阵数组A，当A[i][j]≠0且A[i][j]≠无穷时，说明有一条从顶点i到顶点j的边，建立一个边结点p，置其adjvex域为j，其weight域
	为A[i][j],将p结点插入到顶点i的单链表头部。
*/

void CreatGraph(ALGraph*& G, int A[][MAXVEX], int n, int e)
{
	int i, j;//循环控制变量
	ArcNode* p;//普通结点
	G = (ALGraph*)malloc(sizeof(ALGraph));//创建图
	G->n = n;
	G->e = e;
	for (i = 0; i < G->n; i++)//邻接表中所有头结点的指针域质空
		G->adjlist[i].firstarc = NULL;

	//完成值的插入
	for(i = 0;i < G->n;i++)
		for(j = G->n - 1;j >= 0;j--)
			if (A[i][j] > 0 && A[i][j] < INF)//如果存在一条边
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));//创建结点p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;//头插法插入p
				G->adjlist[i].firstarc = p;
			}
}

//2.销毁图算法
/*基本思路：通过adjlist数组遍历每个链表，释放所有结点，最后释放adjlist数组的空间*/
void DestroyGraph(ALGraph *&G)
{
	int i;
	ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)//遍历所有的头结点
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)//释放adjlist[i]的所有边结点
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);//释放G所指的头结点数组的内存空间
}

//求顶点度的算法
//①无向图
int Degree1(ALGraph* G, int v)
{
	int d = 0;
	ArcNode* p;
	if (v < 0 || v > G->n)	
		return -1;
	p = G->adjlist[v].firstarc;
	while (p != NULL)//统计V顶点的单链表中边结点个数即为度
	{
		d++;
		p = p->nextarc;
	}
	return d;
}

//②有向图
int Degree2(ALGraph* G, int v)
{
	int i,
		d1 = 0,
		d2 = 0,
		d;
	ArcNode* p;
	if (v < 0 || v >= G->n)
		return -1;

	p = G->adjlist[v].firstarc;
	while (p != NULL)//计算出度
	{
		d1++;
		p = p->nextarc;
	}

	for (i = 0; i < G->n; i++)//计算入度
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			if (p->adjvex == v)
				d2++;
			p = p->nextarc;
		}
	}
	d = d1 + d2;
	return d;
}


//对于具有n个结点的有向图G，设计一个将邻接矩阵g转换成邻接表的算法
/*	1、先分配G的内存空间并将所有头结点的firstarc域置为NULL
	2、遍历邻接矩阵g，查找元素值不为0且不为无穷的元素g.egdes[i][j],
	找到这样的元素后创建一个边结点p，将其插入G.adjlist[i]单链表的首部。
*/  




//图的深度优先遍历（DFS）
int visited[MAXVEX] = { 0 };//全局变量
void DFS(ALGraph* G, int v)
{
	int w;
	ArcNode* p;
	printf("%d ", v);//访问v结点
	visited[v] = 1;
	p = G->adjlist[v].firstarc;//找v的第一个邻接点
	while (p != NULL)//找v的所有邻接点
	{
		w = p->adjvex;//找到顶点v的邻接点w
		if (visited[w] == 0)//如果未被访问过
			DFS(G, w);//从w开始深度优先遍历
		p = p->nextarc;
	}
}

//图的广度优先遍历（BFS）
void BFS(ALGraph* G, int vi)
{
	int i, v, visited[MAXVEX];
	ArcNode* p;
	int Q[MAXVEX], front = 0, rear = 0;//定义一个循环数组Q
	for (i = 0; i < G->n; i++)
		visited[i] = 0;//visited数组置初值为0
	printf("%d ", vi);//访问初始顶点
	rear = (rear + 1) % MAXVEX;
	Q[rear] = vi;//初始顶点进队
	while(front != rear)//队列不为空时循环
	{
		front = (front + 1) % MAXVEX;
		v = Q[front];//出队顶点v

		p = G->adjlist[v].firstarc;//查找v的第一个邻接点
		while (p != NULL)//查找v的所有邻接点
		{
			if (visited[p->adjvex] == 0)//若未访问
			{
				printf("%d ", p->adjvex);//访问该点并入队
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXVEX;
				Q[rear] = p->adjvex;
			}
			p = p->nextarc;//查找v的下一个邻接点
		}
	}
}


//判断图是否连通的算法
int Connect(ALGraph* G)
{
	int i, flag = 1;
	DFS(G, 0);//调用DES算法，从顶点0开始深度优先遍历

	for (i = 0; i < G->n; i++)
	{
		if (visited[i] == 0)//这里visited是全局变量
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

//判断简单路径
int HasaPath(ALGraph* G, int u, int v)
{
	ArcNode* p;
	int w;
	visited[u] = 1;
	p = 
}