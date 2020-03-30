#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;


typedef struct tNode
{
	ElementType data;
	struct tNode* lTNode, rTNode;

}Node,*tree;


int main(void)
{

	system("pause");
	return 0;
}