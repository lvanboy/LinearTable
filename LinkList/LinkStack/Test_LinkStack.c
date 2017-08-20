#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"
#include "LinkStack.h"
//业务数据,自定义
typedef struct student{
	char name[64];
	int age;
}Stu;

int main(){
	LinkStack *stack = Create_LinkStack();
	Stu s1, s2, s3;
	strcpy(s1.name, "lvanboy");
	s1.age = 19;
	strcpy(s2.name, "john");
	s2.age = 13;
	strcpy(s3.name, "monika");
	s3.age = 23;
	Push(stack, &s1);
	Push(stack, &s2);
	Push(stack, &s3);
	while (Get_Length(stack) > 0){
		Stu *temp = ((Stu *)Top(stack));
		printf("the name of student is %s,age is %d\n", temp->name, temp->age);
		Pop(stack);
	}
	Clear_LinkStack(stack);
	Destory_LinkStack(stack);
	getchar();
	return 0;
}