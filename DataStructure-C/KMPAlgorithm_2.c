//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXSIZE 40
//
//typedef char string[40];
//
//
////�����Ӵ���next����
//void get_next(string T, int* next) {
//	
//	int i, j;//i��ʾ��׺��j��ʾǰ׺
//	i = 1;//0��λ��ͬ���洢����Ĵ�С
//	j = 0;
//	
//	//��һ��λ����Զ��0
//	next[1] = 0;
//
//	while (i < T[0]) {//��׺С�����鳤��ʱ
//		if (j == 0 || T[i] == T[j]) {
//			i++;
//			j++;
//			next[i] = j;	
//		}
//		else {
//			j = next[j];//�ַ��������j����
//		}
//	}
//}
//
//void get_nextVal(string T, int* nextVal) {
//	int i = 1;
//	int j = 0;
//
//	nextVal[1] = 0;
//
//	while (i < T[0]) {
//		if (T[i]==T[j]|| j == 0)
//		{
//			i++;
//			j++;
//			if (T[i] != T[j]) {
//				nextVal[i] = j;
//			}
//			else
//				nextVal[i] = nextVal[j];
//		}
//		else {
//			j = nextVal[j];
//		}
//	}
//}
//
//
//int KMP_2(string S, string T, int pos) {
//	int i=pos;//׷��S��
//	int j=0;//׷��T��
//
//	int next[MAXSIZE];//��¼T��Ӧ��next����ֵ
//	get_next(T, next);//��ȡnext����
//
//	while (i<=S[0]&&j<=T[0])
//	{
//		if (j==0||S[i] == T[j]) {
//			i++;
//			j++;
//		}
//		else {
//			j = next[j];
//		}
//	}
//	if (T > T[0])
//		return i - T[0];
//	else
//		return 0;
//}
//
