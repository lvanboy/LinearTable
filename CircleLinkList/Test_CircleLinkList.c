#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleList.h"

typedef struct value{
	CircleListNode address;
	char name[64];
	int age;
}Value;

int main(){
	CircleList *list = Create_CircleList();
	Value v1, v2, v3;
	v1.age = 11;
	strcpy(v1.name, "lvanboy");
	v2.age = 15;
	strcpy(v2.name, "john");
	v3.age = 32;
	strcpy(v3.name, "monika");
	Insert_CircleList(list, (CircleListNode *)&v1, 0);
	Insert_CircleList(list, (CircleListNode *)&v2, 0);
	Insert_CircleList(list, (CircleListNode *)&v3, 0);

	for (int i = 0; i < Get_Length(list); i++){

		Value *temp = (Value *)Get_CircleList(list, i);
		
		printf("insert :age = %d\n", temp->age);
		printf("insert :name = %s\n", temp->name);
	}
	printf("\n");
	while (Get_Length(list) > 0){
		Value *temp = (Value *)DeleteByPos_CircleList(list, 0);
		printf("delete :age is %d\n", temp->age);
		printf("delete :name = %s\n", temp->name);
	}
	printf("insert over and over\n");
	Insert_CircleList(list, (CircleListNode *)&v1, 0);
	Insert_CircleList(list, (CircleListNode *)&v2, 0);
	Insert_CircleList(list, (CircleListNode *)&v3, 0);
	//通过游标遍历元素,因为是从头插入,游标会指向尾部
	for (int i = 0; i < Get_Length(list); i++){
		Value *temp = (Value *)Current_CircleList(list);
		printf("traverse by slider:age is %d\n", temp->age);
		printf("traverse by slider:age is %s\n", temp->name);
		Next_CircleList(list);
	}
	printf("DeleteByNode\n");
	DeleteByNode_CircleList(list, (CircleListNode *)&v1);
	printf("\n");
	for (int i = 0; i < Get_Length(list); i++){
		Value *temp = (Value *)Current_CircleList(list);
		printf("traverse by slider :age is %d\n", temp->age);
		printf("traverse by slider:age is %s\n", temp->name);
		Next_CircleList(list);
	}
	printf("reset slider\n");
	Reset_CircleList(list);
	printf("retrude slider\n");
	Next_CircleList(list);
	printf("start traversing\n");
	while (Get_Length(list)>0){
		
		Value *temp = (Value *)Current_CircleList(list);
		printf("current node :age is %d\n", temp->age);
		printf("current node :name is %s\n", temp->name);
		DeleteByNode_CircleList(list, (CircleListNode *)temp);
		printf("deleted current node\n");
	}
	getchar();
	return 0;
}
