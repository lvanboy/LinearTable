#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqlist.h"

typedef struct _Teacher{
	char name[64];
	int age;
}Teacher;

int main(){
	SeqList *list = NULL;
	Teacher t1, t2, t3;
	strcpy(t1.name, "lvanboy");
	t1.age = 20;
	strcpy(t2.name, "joen");
	t2.age = 18;
	strcpy(t3.name, "monika");
	t3.age = 16;
	list = Create_SeqList(5);
	printf("length = %d\n", SeqList_Length(list));
	Insert_SeqList(list, &t1, SeqList_Length(list));

	Insert_SeqList(list, &t2, SeqList_Length(list));

	Insert_SeqList(list, &t3, SeqList_Length(list));

	for (int i = 0; i < SeqList_Length(list); i++){
		Teacher *tmp = (Teacher *)Get_Node(list, i);
		if (tmp != NULL){
			printf("the name is %s ,the age is %d \n", tmp->name, tmp->age);
		}
	}
	while (SeqList_Length(list)){
		Teacher *tmp = (Teacher *)Delete_Node(list, 0);
		printf("delete element is : %s\n", tmp->name);
	}
	Destory_SeqList(list);
}
