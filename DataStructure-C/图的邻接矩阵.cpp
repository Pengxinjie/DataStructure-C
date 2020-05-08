#include<stdio.h>
#include<stdlib.h>

#define INFINITY INT_MAX         //���������ֵ��������
#define MAX_NAME 4               //�����ַ�������󳤶�+1
#define MAX_VERTEX_NUM 30        //��󶥵����
enum GraphKind
{
	DG,//����ͼ
	DN,//������
	UDG,//����ͼ
	UDN//������
};

typedef int VRType;   
typedef char VertexType[MAX_NAME];

typedef struct {
	VRType adj;//�����ϵ���͡�����Ȩͼ����1/0����ʾ���ڷ񣻴�Ȩͼ����Ȩֵ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά����

typedef struct Graph {
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;//ͼ�������־
}MGraph;