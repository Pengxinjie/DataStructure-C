#include<stdio.h>
#include<stdlib.h>

typedef char VertexType[10];          //VertexTypeΪ�ַ�������
#define MAXVEX 30                     //��󶥵���
#define INF INT_MAX                   //�������ֵ��������
typedef struct edgenode
{
	int adjvex;                       //���ڵ����
	int weight;                       //�ߵ�Ȩֵ
	struct edgenode* nextarc;         //��һ���ߵĶ���
}ArcNode;                             //ÿ�����㽨���ĵ������б߽�������

typedef struct vexnode
{
	VertexType data;                  //���һ���������Ϣ
	ArcNode* firstarc;                //ָ���һ���߽��
}VHeadNode;                           //�������ͷ�������

typedef struct
{
	int n, e;                         //nΪʵ�ʶ�������eΪʵ�ʱ���
	VHeadNode adjlist[MAXVEX];		  //�������ͷ�������
}ALGraph;                             //ͼ���ڽӱ�����


//1.����ͼ���ڽӱ��㷨
/*���ڽӾ���A��������n�ͱ���e����ͼG���ڽӱ�洢�ṹ��
	����˼·��
		1.�ȴ����ڽӱ��ͷ������飬��������ͷ����firstarcΪNULL
		2.�����ڽӾ�������A����A[i][j]��0��A[i][j]������ʱ��˵����һ���Ӷ���i������j�ıߣ�����һ���߽��p������adjvex��Ϊj����weight��
	ΪA[i][j],��p�����뵽����i�ĵ�����ͷ����
*/

void CreatGraph(ALGraph*& G, int A[][MAXVEX], int n, int e)
{
	int i, j;//ѭ�����Ʊ���
	ArcNode* p;//��ͨ���
	G = (ALGraph*)malloc(sizeof(ALGraph));//����ͼ
	G->n = n;
	G->e = e;
	for (i = 0; i < G->n; i++)//�ڽӱ�������ͷ����ָ�����ʿ�
		G->adjlist[i].firstarc = NULL;

	//���ֵ�Ĳ���
	for(i = 0;i < G->n;i++)
		for(j = G->n - 1;j >= 0;j--)
			if (A[i][j] > 0 && A[i][j] < INF)//�������һ����
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));//�������p
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;//ͷ�巨����p
				G->adjlist[i].firstarc = p;
			}
}

//2.����ͼ�㷨
/*����˼·��ͨ��adjlist�������ÿ�������ͷ����н�㣬����ͷ�adjlist����Ŀռ�*/
void DestroyGraph(ALGraph *&G)
{
	int i;
	ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)//�������е�ͷ���
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)//�ͷ�adjlist[i]�����б߽��
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);//�ͷ�G��ָ��ͷ���������ڴ�ռ�
}

//�󶥵�ȵ��㷨
//������ͼ
int Degree1(ALGraph* G, int v)
{
	int d = 0;
	ArcNode* p;
	if (v < 0 || v > G->n)	
		return -1;
	p = G->adjlist[v].firstarc;
	while (p != NULL)//ͳ��V����ĵ������б߽�������Ϊ��
	{
		d++;
		p = p->nextarc;
	}
	return d;
}

//������ͼ
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
	while (p != NULL)//�������
	{
		d1++;
		p = p->nextarc;
	}

	for (i = 0; i < G->n; i++)//�������
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


//���ھ���n����������ͼG�����һ�����ڽӾ���gת�����ڽӱ���㷨
/*	1���ȷ���G���ڴ�ռ䲢������ͷ����firstarc����ΪNULL
	2�������ڽӾ���g������Ԫ��ֵ��Ϊ0�Ҳ�Ϊ�����Ԫ��g.egdes[i][j],
	�ҵ�������Ԫ�غ󴴽�һ���߽��p���������G.adjlist[i]��������ײ���
*/  




//ͼ��������ȱ�����DFS��
int visited[MAXVEX] = { 0 };//ȫ�ֱ���
void DFS(ALGraph* G, int v)
{
	int w;
	ArcNode* p;
	printf("%d ", v);//����v���
	visited[v] = 1;
	p = G->adjlist[v].firstarc;//��v�ĵ�һ���ڽӵ�
	while (p != NULL)//��v�������ڽӵ�
	{
		w = p->adjvex;//�ҵ�����v���ڽӵ�w
		if (visited[w] == 0)//���δ�����ʹ�
			DFS(G, w);//��w��ʼ������ȱ���
		p = p->nextarc;
	}
}

//ͼ�Ĺ�����ȱ�����BFS��
void BFS(ALGraph* G, int vi)
{
	int i, v, visited[MAXVEX];
	ArcNode* p;
	int Q[MAXVEX], front = 0, rear = 0;//����һ��ѭ������Q
	for (i = 0; i < G->n; i++)
		visited[i] = 0;//visited�����ó�ֵΪ0
	printf("%d ", vi);//���ʳ�ʼ����
	rear = (rear + 1) % MAXVEX;
	Q[rear] = vi;//��ʼ�������
	while(front != rear)//���в�Ϊ��ʱѭ��
	{
		front = (front + 1) % MAXVEX;
		v = Q[front];//���Ӷ���v

		p = G->adjlist[v].firstarc;//����v�ĵ�һ���ڽӵ�
		while (p != NULL)//����v�������ڽӵ�
		{
			if (visited[p->adjvex] == 0)//��δ����
			{
				printf("%d ", p->adjvex);//���ʸõ㲢���
				visited[p->adjvex] = 1;
				rear = (rear + 1) % MAXVEX;
				Q[rear] = p->adjvex;
			}
			p = p->nextarc;//����v����һ���ڽӵ�
		}
	}
}


//�ж�ͼ�Ƿ���ͨ���㷨
int Connect(ALGraph* G)
{
	int i, flag = 1;
	DFS(G, 0);//����DES�㷨���Ӷ���0��ʼ������ȱ���

	for (i = 0; i < G->n; i++)
	{
		if (visited[i] == 0)//����visited��ȫ�ֱ���
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

//�жϼ�·��
int HasaPath(ALGraph* G, int u, int v)
{
	ArcNode* p;
	int w;
	visited[u] = 1;
	p = 
}