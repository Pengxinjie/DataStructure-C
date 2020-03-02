//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAXSIZE 40
//
//typedef char string[40];
//
//
////返回子串的next数组
//void get_next(string T, int* next) {
//	
//	int i, j;//i表示后缀，j表示前缀
//	i = 1;//0号位置同样存储数组的大小
//	j = 0;
//	
//	//第一个位置永远是0
//	next[1] = 0;
//
//	while (i < T[0]) {//后缀小于数组长度时
//		if (j == 0 || T[i] == T[j]) {
//			i++;
//			j++;
//			next[i] = j;	
//		}
//		else {
//			j = next[j];//字符不相符，j回溯
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
//	int i=pos;//追踪S串
//	int j=0;//追踪T串
//
//	int next[MAXSIZE];//记录T对应的next数组值
//	get_next(T, next);//获取next数组
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
