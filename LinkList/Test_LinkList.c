#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct _tag_Teacher{
	char name[24];
	int age;
}Teacher;


int main(){
	LinkList *list = Create_LinkList();
	Teacher t1;
	Teacher *node = NULL;
	t1.age = 19;
	strcpy(t1.name, "lvanboy");

	
	printf("the address of name is %p ,age is %p\n", t1.name, t1.age);
	printf("name is %s ,age is %d\n", t1.name, t1.age);
	Insert_LinkList(list, (LinkListNode *)&t1, LinkList_Length(list));

	//printf("length = %d\n", LinkList_Length(list));
	for (int i = 0; i < LinkList_Length(list); i++){
		node = (Teacher *)Get_LinkListNode(list, i);
		printf("the address of name is %p ,age is %p\n", (node),node->age);
		printf("name is %s ,age is %d\n", (node), node->age);
	}
	getchar();
	return 0;
}
