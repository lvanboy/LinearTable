#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DListLink.h"

typedef struct _tag_person_{
	DLinkListNode header;
	int age;
}Person;

int main(){
	DLinkList *list = Create_DLinkList();
	Person p1, p2, p3;
	p1.age = 10;
	p2.age = 11;
	p3.age = 12;

	Insert_DLinkList(list, (DLinkListNode *)&p1, 0);
	Insert_DLinkList(list, (DLinkListNode *)&p2, 0);
	Insert_DLinkList(list, (DLinkListNode *)&p3, 0);

	for (int i = 0; i < Get_Length(list); i++){
		Person *temp = (Person *)Get_DLinkListNode(list, i);
		printf("the name of person is %d\n", temp->age);
	}
	printf("delete from rear in one.\n");
	DeleteByPos_DLinkListNode(list, Get_Length(list)-1);
	Reset_DLinkList(list);
	while (Get_Length(list) > 0){
		Person *temp = (Person *)Current_DLinkList(list);
		printf("the name of person is %d\n", temp->age);
		DeleteByNode_DLinkListNode(list, (DLinkListNode *)temp);
	}
	Insert_DLinkList(list, (DLinkListNode *)&p1, 0);
	Insert_DLinkList(list, (DLinkListNode *)&p2, 0);
	Insert_DLinkList(list, (DLinkListNode *)&p3, 0);
	for (int i = 0; i < Get_Length(list); i++){
		Person *temp = (Person *)Current_DLinkList(list);
		printf("the previous person 's age is :%d\n", temp->age);
		Pre_DLinkList(list);
	}
	Clear_DLinkList(list);
	Destory_DLinkList(list);
	getchar();
	return 0;
}