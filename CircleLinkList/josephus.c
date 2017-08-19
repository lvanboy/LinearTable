#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"

typedef struct person{
	CircleListNode head;
	int v;
}Person;
//方程式
int josephus(int n, int k) { 
	int s = 1;
	for (int i = 2; i <= n; i++)
		s = (s + k) % i;
	printf("the num of the survival is %d", s);
	return s;
}
//循环链表解法
void joseph(CircleListNode *list, int k){
	Reset_CircleList(list);

	while (Get_Length(list)){
		Person *p = NULL;
		for (int i = 1; i < 3; i++){
			Next_CircleList(list);
		}
		p = (Person *)Current_CircleList(list);
		printf("the value of person is :%d\n", p->v);
		DeleteByNode_CircleList(list, (CircleListNode *)p);
	}
}
int main(){
	CircleList *list = Create_CircleList();
	Person p1, p2, p3, p4, p5, p6, p7, p8, p9;
	p1.v = 1;
	p2.v = 2;
	p3.v = 3;
	p4.v = 4;
	p5.v = 5;
	p6.v = 6;
	p7.v = 7;
	p8.v = 8;
	p9.v = 9;
	Insert_CircleList(list, (CircleListNode *)&p1, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p2, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p3, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p4, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p5, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p6, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p7, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p8, Get_Length(list));
	Insert_CircleList(list, (CircleListNode *)&p9, Get_Length(list));
	
	joseph(list, 3);
	josephus(9, 5);
	getchar();
	return 0;
}
